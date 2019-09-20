(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 00:32:29 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 17:49:25 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let c = new Carbon.carbon in
  let h = new Hydrogen.hydrogen in
  let o = new Oxygen.oxygen in
  let k = new Potassium.potassium in
  let kr = new Krypton.krypton in
  let hg = new Mercury.mercury in
  let au = new Gold.gold in
  let pt = new Platinium.platinium in
  let pu = new Plutonium.plutonium in
  let n = new Nitrogen.nitrogen in
  let fr = new Francium.francium in
  let na = new Sodium.sodium in
  let cl = new Chlorine.chlorine in
  print_endline c#to_string;
  print_endline h#to_string;
  print_endline o#to_string;
  print_endline k#to_string;
  print_endline kr#to_string;
  print_endline hg#to_string;
  print_endline au#to_string;
  print_endline pt#to_string;
  print_endline pu#to_string;
  print_endline n#to_string;
  print_endline fr#to_string;
  print_endline na#to_string;
  print_endline cl#to_string;
  print_endline "****************************************************";
  let water = new Water.water in
  print_endline water#formula;
  print_endline water#to_string;

  let carbon_dioxyde = new Carbon_dioxyde.carbon_dioxyde in
  print_endline carbon_dioxyde#formula;
  print_endline carbon_dioxyde#to_string;
  
  let acetone_peroxide = new Acetone_peroxide.acetone_peroxide in
  print_endline acetone_peroxide#formula;
  print_endline acetone_peroxide#to_string;
  
  let lsd = new Lysergic_acid_diethylamide.lysergic_acid_diethylamide in
  print_endline lsd#formula;
  print_endline lsd#to_string;

  let cc = new Benzoylmethylecgonine.benzoylmethylecgonine in
  print_endline cc#formula;
  print_endline cc#to_string;
  print_endline "****************************************************";
  
  let me = new Methane.methane in
  print_endline me#formula;
  print_endline me#to_string;

  let et = new Ethane.ethane in
  print_endline et#formula;
  print_endline et#to_string;

  let oc = new Octane.octane in
  print_endline oc#formula;
  print_endline oc#to_string;
  print_endline "****************************************************"
