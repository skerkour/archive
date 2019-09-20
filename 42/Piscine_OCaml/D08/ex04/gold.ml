(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gold.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:33:43 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:35:09 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class gold =
object (self)
  inherit Atom.atom
  
  method name =
    "Gold"

  method symbol =
    "Au"

  method atomic_number =
    79

end
