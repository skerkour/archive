(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sodium.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 12:11:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 12:12:11 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class sodium =
object (self)
  inherit Atom.atom
  
  method name =
    "Sodium"

  method symbol =
    "Na"

  method atomic_number =
    11

end
