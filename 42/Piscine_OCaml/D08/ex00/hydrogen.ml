(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   hydrogen.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 11:02:26 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 11:11:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class hydrogen =
object (self)
  inherit Atom.atom
  
  method name =
    "Hydrogen"

  method symbol =
    "H"

  method atomic_number =
    1

end
