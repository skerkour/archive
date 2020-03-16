package main

import (
	"context"
	"database/sql/driver"
	"encoding/json"
	"errors"
	"fmt"
	"log"
	"os"
	"time"

	"github.com/bloom42/goes"
)

////////////////////////////////////////////////////////////////////////////////////////////////////
// Aggregate definition                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////

// User is our aggregate
type User struct {
	goes.BaseAggregate
	FirstName string
	LastName  string
	Addresses addresses `gorm:"type:jsonb;column:addresses"`
}

// AggregateType is our aggregate type
func (user *User) AggregateType() string {
	return "user"
}

// TableName is our postgres table
func (user *User) TableName() string {
	return "users"
}

type address struct {
	Country string `json:"country"`
	Region  string `json:"region"`
}

// a subfield used as a JSONB column
type addresses []address

// Value is used to serialize to SQL
func (a addresses) Value() (driver.Value, error) {
	j, err := json.Marshal(a)
	return j, err
}

// Scan is used to deserialize from SQL
func (a *addresses) Scan(src interface{}) error {
	if bytes, ok := src.([]byte); ok {
		return json.Unmarshal(bytes, a)

	}
	return errors.New(fmt.Sprint("failed to unmarshal JSONB from DB", src))
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Events definition                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////

// CreatedV1 is our first event
// json tags should be set because the struct will be serialized as JSON when saved in the eventstore
type CreatedV1 struct {
	ID        string `json:"id"`
	FirstName string `json:"first_name"`
	LastName  string `json:"last_name"`
}

// Apply our event to an user aggregate
func (eventData CreatedV1) Apply(agg goes.Aggregate, event goes.Event) {
	user := agg.(*User)
	user.ID = eventData.ID
	user.FirstName = eventData.FirstName
	user.LastName = eventData.LastName
	user.CreatedAt = event.Timestamp
	user.Addresses = addresses{}
}

// AggregateType is our target aggregate type
func (CreatedV1) AggregateType() string {
	return "user"
}

// Action is the performed action, in past tense
func (CreatedV1) Action() string {
	return "created"
}

// Version is the event's verion
func (CreatedV1) Version() uint64 {
	return 1
}

// FirstNameUpdatedV1 is our second event
type FirstNameUpdatedV1 struct {
	FirstName string `json:"first_name"`
}

// Apply our event to an user aggregate
func (eventData FirstNameUpdatedV1) Apply(agg goes.Aggregate, event goes.Event) {
	user := agg.(*User)
	user.FirstName = eventData.FirstName
}

// AggregateType is our target aggregate type
func (FirstNameUpdatedV1) AggregateType() string {
	return "user"
}

// Action is the performed action, in past tense
func (FirstNameUpdatedV1) Action() string {
	return "first_name_updated"
}

// Version is the event's verion
func (FirstNameUpdatedV1) Version() uint64 {
	return 1
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Commands definition                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////////

// ValidationError is a custom validation error type
type ValidationError error

// NewValidationError returns a new ValidationError
func NewValidationError(message string) ValidationError {
	return errors.New(message).(ValidationError)
}

func validateFirstName(firstName string) error {
	length := len(firstName)

	if length < 3 {
		return NewValidationError("FirstName is too short")
	} else if length > 42 {
		return NewValidationError("FirstName is too long")
	}
	return nil
}

// Create is our first command to create an user
type Create struct {
	FirstName string
	LastName  string
}

// Validate the command's validity against our business logic and the current application state
func (c Create) Validate(_ context.Context, tx goes.Tx, agg goes.Aggregate) error {
	// user := *agg.(*User)
	// _ = user
	return validateFirstName(c.FirstName)
}

// BuildEvent returns the CreatedV1 event
func (c Create) BuildEvent(context.Context) (goes.EventData, interface{}, error) {
	return CreatedV1{
		ID:        "0563019f-ade9-4cb1-81a7-4f1bb3213cb0",
		FirstName: c.FirstName,
		LastName:  c.LastName,
	}, nil, nil
}

// AggregateType returns the target aggregate type
func (c Create) AggregateType() string {
	return "user"
}

// UpdateFirstName is our second command to update the user's firstname
type UpdateFirstName struct {
	FirstName string
}

// Validate the command's validity against our business logic and the current application state
func (c UpdateFirstName) Validate(_ context.Context, tx goes.Tx, agg goes.Aggregate) error {
	// user := agg.(*User)
	// _ = user
	return validateFirstName(c.FirstName)
}

// BuildEvent returns the FirstNameUpdatedV1 event
func (c UpdateFirstName) BuildEvent(context.Context) (goes.EventData, interface{}, error) {
	return FirstNameUpdatedV1{
		FirstName: c.FirstName,
	}, nil, nil
}

// AggregateType returns the target aggregate type
func (c UpdateFirstName) AggregateType() string {
	return "user"
}

// We register the User aggregate with all it's associated events
func registerUser() {
	goes.Register(
		&User{},
		FirstNameUpdatedV1{},
		CreatedV1{},
	)
}

func asyncReactorExample(context.Context, goes.Event) {
	time.Sleep(3 * time.Second)
	fmt.Println("hello from async reactor")
}

func syncReactorExample(_ context.Context, _ goes.Tx, event goes.Event) error {
	createdEvent := event.Data.(CreatedV1)
	fmt.Printf("User created: %s %s\n", createdEvent.FirstName, createdEvent.LastName)
	return nil
}

func queryUserEvents(userID string) {
	query := "SELECT * FROM users_events WHERE aggregate_id = ?;"
	events := []goes.StoreEvent{}
	err := goes.DB.Raw(query, userID).Scan(&events).Error
	if err != nil {
		panic(err)
	}

	ret := make([]goes.Event, len(events))
	for i, event := range events {
		ret[i], err = event.Deserialize()
		if err != nil {
			panic(err)
		}
	}
	fmt.Println(ret)
}

func main() {
	// configure the database
	err := goes.Init(os.Getenv("DATABASE_URL"))
	if err != nil {
		log.Fatal(err)
	}
	goes.DB.LogMode(true)

	registerUser()
	goes.On(
		goes.MatchEvent(CreatedV1{}),
		[]goes.SyncReactor{syncReactorExample},
		[]goes.AsyncReactor{asyncReactorExample},
	)

	var user User

	command := Create{
		FirstName: "Sylvain",
		LastName:  "Kerkour",
	}
	metadata := goes.Metadata{
		"request_id": "my_request_id",
	}

	_, err = goes.Execute(context.Background(), command, &user, metadata)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(user)
	// User {
	// 	ID: "0563019f-ade9-4cb1-81a7-4f1bb3213cb0",
	// 	FirstName: "Sylvain",
	// 	LastName: "Kerkour",
	// }

	queryUserEvents(user.ID)
	time.Sleep(5 * time.Second) // for the async reactor
}
