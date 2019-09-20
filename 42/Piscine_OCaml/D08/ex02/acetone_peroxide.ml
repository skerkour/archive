(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   acetone_peroxide.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 13:59:27 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 14:05:20 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class acetone_peroxide =
object (self)
  inherit Molecule.molecule "Acetone_peroxide" [
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Carbon.carbon; new Carbon.carbon; new Carbon.carbon;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Hydrogen.hydrogen; new Hydrogen.hydrogen; new Hydrogen.hydrogen;
    new Oxygen.oxygen; new Oxygen.oxygen; new Oxygen.oxygen;
    new Oxygen.oxygen; new Oxygen.oxygen; new Oxygen.oxygen
  ]
  
  method to_string =
    "Acetone peroxide is an organic peroxide and a primary high explosive."

end
