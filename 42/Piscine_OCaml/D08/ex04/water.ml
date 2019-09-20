(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   water.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 13:41:54 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 13:44:59 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class water =
object (self)
  inherit Molecule.molecule "Water" [new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Oxygen.oxygen]
  
  method to_string =
    "Water (chemical formula: H2O) is a transparent fluid which forms the world's streams"

end
