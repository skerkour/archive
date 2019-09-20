(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   lysergic_acid_diethylamide.ml                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 14:48:59 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 14:58:57 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class lysergic_acid_diethylamide =
object (self)
  inherit Molecule.molecule "Lysergic_acid_diethylamide" [
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen;
    new Nitrogen.nitrogen; new Nitrogen.nitrogen; new Nitrogen.nitrogen;
    new Oxygen.oxygen;
  ]
  
  method to_string =
    "Lysergic acid diethylamide (LSD), also known as acid, is a psychedelic drug known for its psychological effects."

end
