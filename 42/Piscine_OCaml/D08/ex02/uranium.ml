(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   uranium.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:37:10 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:37:48 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class uranium =
object (self)
  inherit Atom.atom
  
  method name =
    "Uranium"

  method symbol =
    "U"

  method atomic_number =
    92

end
