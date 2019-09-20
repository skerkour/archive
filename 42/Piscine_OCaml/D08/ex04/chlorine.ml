(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   chlorine.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 12:12:35 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 12:13:19 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class chlorine =
object (self)
  inherit Atom.atom
  
  method name =
    "Chlorine"

  method symbol =
    "Cl"

  method atomic_number =
    17

end
