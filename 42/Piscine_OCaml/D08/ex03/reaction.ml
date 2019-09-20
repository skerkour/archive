(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   reaction.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 17:38:21 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:48:24 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual reaction start endd =
object (self)

  val _start : Molecule.molecule list = start
  val _end : Molecule.molecule list = endd

  method virtual get_start : (Molecule.molecule * int) list
  method virtual get_result : (Molecule.molecule * int) list
  method virtual balance : reaction
  method virtual is_balanced: bool
end
