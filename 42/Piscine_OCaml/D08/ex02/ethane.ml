(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ethane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 17:29:56 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:30:39 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ethane =
object (self)
  inherit Alkane.alkane 2
  
  method to_string =
    "Ethane is an organic chemical compound with chemical formula C2H6."

end
