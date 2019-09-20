(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   examples_of_file.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 17:58:30 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 13:55:58 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

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


(* tests *)  
let print_elem (elem : (float array * string)) =
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
  for i = 0 to ((List.length elems) - 1) do
    print_elem (List.nth elems i);
  done;
