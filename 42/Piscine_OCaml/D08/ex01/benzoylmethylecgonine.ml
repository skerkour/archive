(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   benzoylmethylecgonine.ml                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 14:56:00 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 14:58:53 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class benzoylmethylecgonine =
object (self)
  inherit Molecule.molecule "Benzoylmethylecgonine" [
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
    new Nitrogen.nitrogen;
    new Oxygen.oxygen; new Oxygen.oxygen; new Oxygen.oxygen;
    new Oxygen.oxygen;
  ]
  
  method to_string =
    "Cocaine, also known as benzoylmethylecgonine or coke, is a strong stimulant mostly used as a recreational drug."

end
