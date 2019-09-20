(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Deck.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 17:38:10 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/19 17:21:16 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Card =
struct

module Color =
struct

type t = Spade | Heart | Diamond | Club

let all = [Spade; Heart; Diamond; Club]

let toString = function
  | Spade -> "S"
  | Heart -> "H"
  | Diamond -> "D"
  | Club -> "C"

let toStringVerbose = function
  | Spade -> "Spade"
  | Heart -> "Heart"
  | Diamond -> "Diamond"
  | Club -> "Club"

end

module Value =
struct

type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

let all = [T2; T3; T4; T5; T6; T7; T8; T9; T10; Jack; Queen; King; As]

let toInt c =
  let rec toInt_aux c i = ( function
    | head::tail -> if head = c then i else toInt_aux c (i+1) tail
    | _ -> 0
  ) in
  toInt_aux c 1 all

let toString = function
  | T2 -> "2"
  | T3 -> "3"
  | T4 -> "4"
  | T5 -> "5"
  | T6 -> "6"
  | T7 -> "7"
  | T8 -> "8"
  | T9 -> "9"
  | T10 -> "10"
  | Jack -> "J"
  | Queen -> "Q"
  | King -> "K"
  | As -> "A"

let toStringVerbose = function
  | T2 -> "2"
  | T3 -> "3"
  | T4 -> "4"
  | T5 -> "5"
  | T6 -> "6"
  | T7 -> "7"
  | T8 -> "8"
  | T9 -> "9"
  | T10 -> "10"
  | Jack -> "Jack"
  | Queen -> "Queen"
  | King -> "King"
  | As -> "As"

let next = function
  | T2 -> T3
  | T3 -> T4
  | T4 -> T5
  | T5 -> T6
  | T6 -> T7
  | T7 -> T8
  | T8 -> T9
  | T9 -> T10
  | T10 -> Jack
  | Jack -> Queen
  | Queen -> King
  | King -> As
  | As -> invalid_arg (toString As)

let previous = function
  | T2 -> invalid_arg (toString T2)
  | T3 -> T2
  | T4 -> T3
  | T5 -> T4
  | T6 -> T5
  | T7 -> T6
  | T8 -> T7
  | T9 -> T8
  | T10 -> T9
  | Jack -> T10
  | Queen -> Jack
  | King -> Queen
  | As -> King

end

type t = (Value.t * Color.t)
type deck

let newCard v c : t = (v, c)

let allSpades = List.map (fun x -> newCard x Color.Spade) Value.all
let allHearts = List.map (fun x -> newCard x Color.Heart) Value.all
let allDiamonds = List.map (fun x -> newCard x Color.Diamond) Value.all
let allClubs = List.map (fun x -> newCard x Color.Club) Value.all

let all = List.concat [allSpades; allHearts; allDiamonds; allClubs]

let getValue ((v, c) : t) : Value.t =
  v

let getColor ((v, c) : t) : Color.t =
  c

let toString (card : t) =
  let (value, color) = card in
  Printf.sprintf "%s%s" (Value.toString value) (Color.toString color)

let toStringVerbose (card : t) =
  let (value, color) = card in
  Printf.sprintf "Card(%s, %s)" (Value.toStringVerbose value)
  (Color.toStringVerbose color)

let compare (card1 : t) (card2 : t) =
  let (value1, _) = card1 in
  let (value2, _) = card2 in
  Value.toInt value1 - Value.toInt value2

let max (x : t) (y : t) =
  if compare x y >= 0 then x else y

let min (x : t) (y : t) =
  if compare x y <= 0 then x else y

let best deck =
  if List.length deck = 0 then invalid_arg "List cannot be empty"
  else
    List.fold_left max (List.hd deck) deck

let isOf (card : t) (color : Color.t) =
  let (_, card_color) = card in
  card_color = color

let isSpade card =
  isOf card Color.Spade

let isHeart card =
  isOf card Color.Heart

let isDiamond card =
  isOf card Color.Diamond

let isClub card =
  isOf card Color.Club

end

type t = Card.t list
type c = Card.t

let rand a b =
  let x = Random.int 2 in
  let y = Random.int 2 in
  if y > 0 then x else -x

let newDeck () : t =
  Random.self_init ();
  List.sort rand Card.all
  

let rec lst_map fn = function
  | head::tail -> (fn head) :: (lst_map fn tail)
  | [] -> []

let toStringList (deck : t) =
  lst_map Card.toString deck

let toStringListVerbose (deck : t) =
  lst_map Card.toStringVerbose deck

let drawCard (deck : t) : (Card.t * t) = 
  match deck with
  | head::tail -> (head, tail)
  | [] -> raise @@ Failure "You cannot draw a card on a empty deck"
