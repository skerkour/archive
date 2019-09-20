(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   alkane_combustion.ml                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 18:02:25 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 22:18:55 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class alkane_combustion start endd =
object (self)
  inherit Reaction.reaction start endd

  method get_start =
    if self#is_balanced then self#encode _start
    else (
      invalid_arg "The reaction is not balanced :("
    )

  method get_result =
    if self#is_balanced then self#encode _end
    else (
      invalid_arg "The reaction is not balanced :("
    )
   
  method balance =
   new alkane_combustion _start _end

  method is_balanced = 
    let start = new Arbitraty_molecule.arbitraty_molecule "start" (self#combine_atoms _start) in
    let endd = new Arbitraty_molecule.arbitraty_molecule "end" (self#combine_atoms _end) in
    start#equals endd

  method private combine_atoms molecs =
    let rec combine_aux molecs acc = (
      match molecs with
      | [] -> acc
      | head::tail -> combine_aux tail (acc @ head#atoms)
    ) in
    combine_aux molecs []

  method private encode molecs =  (
    let rec encode_map = ( function
      | head::tail -> (head, 1) :: encode_map tail
      | [] -> []
    ) in

    let rec encode_reduce lst acc = (
      match lst with
      | head::second::tail -> (
        let (x, n) = head in
        let (xx, nn) = second in

        if x#equals xx  && tail = [(x, 1)] then encode_reduce [] (acc @ [(x, n + 2)])
        else if x#equals xx  then encode_reduce ([(x, n + 1)] @ tail) acc
        else encode_reduce ([second] @ tail) (acc @ [head]) 
      )
      | head::tail -> encode_reduce tail (acc @ [head])
      | [] -> acc
    ) in

    let mapped = encode_map molecs in
    encode_reduce mapped []
  )
end
