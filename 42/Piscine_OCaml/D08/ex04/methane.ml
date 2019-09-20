(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   methane.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 17:27:11 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:28:26 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class methane =
object (self)
  inherit Alkane.alkane 1
  
  method to_string =
    "Methane is a chemical compound with the chemical formula CH4 (one atom of carbon and four atoms of hydrogen)."

end
