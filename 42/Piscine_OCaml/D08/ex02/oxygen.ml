(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   oxygen.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:04:14 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:11:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class oxygen =
object (self)
  inherit Atom.atom
  
  method name =
    "Oxygen"

  method symbol =
    "O"

  method atomic_number =
    8

end
