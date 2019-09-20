(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   arbitraty_molecule.ml                              :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 22:04:55 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 22:09:06 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class arbitraty_molecule name molecs =
object (self)
  inherit Molecule.molecule name molecs
  
  method to_string =
    "Cocaine, also known as benzoylmethylecgonine or coke, is a strong stimulant mostly used as a recreational drug."

end
