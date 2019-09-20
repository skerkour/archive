(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   platinium.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:34:36 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:35:09 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class platinium =
object (self)
  inherit Atom.atom
  
  method name =
    "Platinium"

  method symbol =
    "Pt"

  method atomic_number =
    78

end
