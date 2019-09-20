(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex01.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/21 16:05:45 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 17:45:40 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module HashedString =
struct
  type t = String.t
  let equal x y = x = y
  let hash str = (
    let explode s = (
      let rec explode_rec i l = (
        if i < 0 then l else explode_rec (i - 1) (s.[i] :: l)
      ) in
        explode_rec (String.length s - 1) []
    ) in

    let rec reduce fn acc lst = (
      match lst with
      | head::tail -> reduce fn (acc + (fn head)) tail
      | [] -> acc
    ) in

    let lst = explode str in
    reduce int_of_char 0 lst
  )
end

module StringHashtbl = Hashtbl.Make (HashedString)

(* tests *)
let () =
  let ht = StringHashtbl.create 5 in
  let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
  let pairs = List.map (fun s -> (s, String.length s)) values in
  List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
  StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
