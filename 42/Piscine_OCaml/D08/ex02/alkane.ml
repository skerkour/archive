(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   alkane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 17:05:02 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:34:26 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)


class virtual alkane n =
object (self)

  val _atoms : Atom.atom list = (
    let rec create_n_c n acc =
      match n with
      | x when n > 0 -> create_n_c (n-1) (acc @ [new Carbon.carbon])
      | _ -> acc
    in
    let rec create_n_h n acc =
      match n with
      | x when n > 0 -> create_n_h (n-1) (acc @ [new Hydrogen.hydrogen])
      | _ -> acc
    in
    [] @ (create_n_c n []) @ (create_n_h ((2*n) + 2) [])
  )
  
  val _n : int = n

  method virtual to_string : string
  
  method name =
    match _n with
    | 1 -> "Methane"
    | 2 -> "Ethane"
    | 3 -> "Propane"
    | 4 -> "Butane"
    | 5 -> "Pentane"
    | 6 -> "Hexane"
    | 7 -> "Heptane"
    | 8 -> "Octane"
    | 9 -> "Nonane"
    | 10 -> "Decane"
    | 11 -> "Undecane"
    | 12 -> "Dodecane"
    | _ -> "Alkane"

  method equals (x : alkane) =
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
