(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   one_nn.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/21 12:26:10 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/22 22:38:14 by skerkour         ###   ########.fr       *)
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


(* ex07 *)
let one_nn (radars : radar list) (rad : radar) =
  
  let nn = ref @@ List.nth radars 1 in
  let (v, c) = rad in
  for i = 0 to ((List.length radars) - 1) do
    let (nnv, nnc) = !nn in
    let (cv, cc) = List.nth radars i in
    if eu_dist v cv < eu_dist v nnv then nn := List.nth radars i;
  done;
  let (_, c) = !nn in c


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
  print_endline @@ one_nn elems ([|1.; 0.; 0.99539; (-0.05889); 0.85243; 0.02306; 0.83398; (-0.37708); 1.; 0.03760; 0.85243; (-0.17755); 0.59755; (-0.44945); 0.60536; (-0.38223); 0.84356; (-0.38542); 0.58212; (-0.32192); 0.56971; (-0.29674); 0.36946; (-0.47357); 0.56811; (-0.51171); 0.41078; (-0.46168); 0.21266; (-0.34090); 0.42267; (-0.54487); 0.18641; (-0.45300)|], "g")
