(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   mercury.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:27:30 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:33:18 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class mercury =
object (self)
  inherit Atom.atom
  
  method name =
    "Mercury"

  method symbol =
    "Hg"

  method atomic_number =
    80

end
