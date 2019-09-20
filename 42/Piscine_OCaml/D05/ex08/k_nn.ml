(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   k_nn.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/21 14:01:10 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 19:34:01 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type radar = float array * string

let eu_dist a b =
  let n = (Array.length a) - 1 in
  let sum = ref 0. in
  for i = 0 to n do
    sum := !sum +. ((a.(i) -. b.(i)) ** 2.)
  done;
  !sum

let examples_of_file file_name : (float array * string) list =
  let process_line line : (float array * string) = (
    try (
      let last_comma_index = String.rindex line ',' in
      let v = ref [||] in
      let c = String.sub line (last_comma_index + 1) 1 in
      let index = ref 0 in
      let comma_index = ref (String.index line ',') in
      while !comma_index <> last_comma_index do
        let nb_str = String.sub line !index (!comma_index - !index) in
        let nb = float_of_string nb_str in
        v := Array.append !v [|nb|];
        index := (!comma_index + 1);
        comma_index := String.index_from line !index ',';
      done;
      let nb_str = String.sub line !index (!comma_index - !index) in
      let nb = float_of_string nb_str in
      v := Array.append !v [|nb|];
      (!v, c)
    ) with
    | _ -> ([||], "")
   ) in

  let ret = ref [] in
  let continue = ref true in
  let file = open_in file_name in
  try (
      while !continue = true do
        ret := !ret @ [process_line (input_line file)];
      done;
      close_in file;
      !ret
  ) with
  | _ -> ( continue := false; !ret)


(* ex08 *)
let k_nn (radars : radar list) n (rad : radar) : string =
  let most_frequent_elt lst = (
    let rec loop maxelt maxcount elt count = ( function
      | [] -> if count > maxcount then elt else maxelt
      | x::xs ->
        if elt = x then loop maxelt maxcount elt (count + 1) xs
        else if count > maxcount then loop elt count x 1 xs
        else loop maxelt maxcount x 1 xs
    ) in
    match List.sort compare lst with
    | [] -> ""
    | x::xs -> loop x 0 x 1 xs
  ) in

  let get_class nns = (
    most_frequent_elt @@ List.map (fun x -> let (_, c) = x in c) nns
  ) in

  let try_nn nns elem = (
      let (ref_v, _) = rad in
    for i = 0 to (Array.length nns) - 1 do
      let (v, _) = elem in
      let (tv, _) = nns.(i) in
      if eu_dist v tv < eu_dist ref_v tv then nns.(i) <- elem;
    done;
  ) in

  let nns = Array.init n (fun x -> List.nth radars x) in
  for i = 0 to (List.length radars) - 1 do
    try_nn nns (List.nth radars i);
  done;
  get_class @@ Array.to_list nns


(* tests *)
let print_elem (elem : radar) =
  let (v, c) = elem in
  print_char '[';
  for i = 0 to ((Array.length v) - 1) do
    print_float v.(i);
    if i <> ((Array.length v) - 1) then print_string ", ";
  done;
  print_string "], "; print_endline c

let () =
  let argc = Array.length Sys.argv in
  if argc <> 2 then ()
  else
  let argv = Sys.argv in
  let elems = examples_of_file argv.(1) in
  print_endline @@ k_nn elems 3 ([|1.; 0.; 0.99539; (-0.05889); 0.85243; 0.02306; 0.83398; (-0.37708); 1.; 0.03760; 0.85243; (-0.17755); 0.59755; (-0.44945); 0.60536; (-0.38223); 0.84356; (-0.38542); 0.58212; (-0.32192); 0.56971; (-0.29674); 0.36946; (-0.47357); 0.56811; (-0.51171); 0.41078; (-0.46168); 0.21266; (-0.34090); 0.42267; (-0.54487); 0.18641; (-0.45300)|], "g")
