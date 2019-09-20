(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   molecule.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 12:16:46 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:11:32 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual molecule name atoms =
object (self)

  val _name : string = name
  val _atoms : Atom.atom list = atoms

  method virtual to_string : string
  
  method name =
    _name

  method equals (x : molecule) =
    self#formula = x#formula

  method formula =
    let sort_encoded_atoms x y = (
      let (_, a) = x in
      let (_, aa) = y in

      if a#symbol = "C" then (-1)
      else if aa#symbol = "C" then 1 else (

      if a#symbol = "H" then (-1)
      else if aa#symbol = "H" then 1
      else
        String.compare a#symbol aa#symbol
      )
    ) in

    let rec formula_aux lst acc = (
      match lst with
      | [] -> acc
      | head::tail -> (
        let (n, a) = head in
        let n_str = if n <= 1 then "" else string_of_int n in
        formula_aux tail (acc ^ a#symbol ^ n_str)
      )
    ) in
    let encoded_atoms = self#encode in
    formula_aux (List.sort sort_encoded_atoms encoded_atoms) ""

  method private encode =  (
    let rec encode_map = ( function
      | head::tail -> (1, head) :: encode_map tail
      | [] -> []
    ) in

    let rec encode_reduce lst acc = (
      match lst with
      | head::second::tail -> (
        let (n, x) = head in
        let (nn, xx) = second in

        if x#equals xx  && tail = [(1, x)] then encode_reduce [] (acc @ [(n + 2, x)])
        else if x#equals xx  then encode_reduce ([(n + 1, x)] @ tail) acc
        else encode_reduce ([second] @ tail) (acc @ [head]) 
      )
      | head::tail -> encode_reduce tail (acc @ [head])
      | [] -> acc
    ) in

    let mapped = encode_map _atoms in
    encode_reduce mapped []
  )
end
