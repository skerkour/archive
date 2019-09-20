use parser;

#[test]
fn enum_token() {
    assert!(parser::Token::MoveFwd == parser::Token::MoveFwd);
    assert!(parser::Token::MoveFwd != parser::Token::MoveBack);
    assert!(parser::Token::Unknown{pos: 42} == parser::Token::Unknown{pos: 42});
    assert!(parser::Token::Unknown{pos: 42} != parser::Token::Unknown{pos: 0});
}
