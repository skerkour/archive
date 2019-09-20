(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   carbon.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 00:37:21 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:11:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class carbon =
object (self)
  inherit Atom.atom
  
  method name =
    "Carbon"

  method symbol =
    "C"

  method atomic_number =
    6

end
