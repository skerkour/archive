(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   carbon_dioxyde.ml                                  :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 13:53:45 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 13:56:26 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class carbon_dioxyde =
object (self)
  inherit Molecule.molecule "Carbon dioxyde" [new Carbon.carbon; new
  Oxygen.oxygen; new Oxygen.oxygen]
  
  method to_string =
    "Carbon dioxide (chemical formula: CO2) is a colorless and odorless gas vital to life on Earth"

end
