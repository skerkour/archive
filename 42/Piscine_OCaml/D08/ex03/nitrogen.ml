(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   nitrogen.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:40:35 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:41:25 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class nitrogen =
object (self)
  inherit Atom.atom
  
  method name =
    "Nitrogen"

  method symbol =
    "N"

  method atomic_number =
    7

end
