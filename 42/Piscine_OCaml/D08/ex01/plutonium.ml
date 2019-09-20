(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   plutonium.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:38:21 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:39:16 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class plutonium =
object (self)
  inherit Atom.atom
  
  method name =
    "Plutonium"

  method symbol =
    "Pu"

  method atomic_number =
    94

end
