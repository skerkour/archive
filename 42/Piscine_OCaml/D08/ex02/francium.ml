(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   francium.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 12:10:39 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 12:11:21 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class francium =
object (self)
  inherit Atom.atom
  
  method name =
    "Francium"

  method symbol =
    "Fr"

  method atomic_number =
    87

end
