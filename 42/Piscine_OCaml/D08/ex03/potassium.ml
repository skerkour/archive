(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   potassium.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:16:09 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:16:12 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class potassium =
object (self)
  inherit Atom.atom
  
  method name =
    "Potassium"

  method symbol =
    "K"

  method atomic_number =
    19

end
