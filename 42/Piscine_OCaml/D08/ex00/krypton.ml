(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   krypton.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:17:25 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:27:11 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class krypton =
object (self)
  inherit Atom.atom
  
  method name =
    "Krypton"

  method symbol =
    "Kr"

  method atomic_number =
    36

end
