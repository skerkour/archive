(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   octane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 17:32:47 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:34:48 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class octane =
object (self)
  inherit Alkane.alkane 8
  
  method to_string =
    "Octane is a hydrocarbon and an alkane with the chemical formula C8H18."

end
