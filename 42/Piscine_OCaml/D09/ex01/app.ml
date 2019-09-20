(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   app.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/25 15:11:17 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/25 19:24:21 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module App =
struct
  type project = string * string * int

  let zero : project = ("", "", 0)
  
  let combine (x : project) (y : project) : project = (
    match x with
    | (t, s, g) -> (
      let (tt, ss, gg) = y in
      ((t ^ tt),
      (if ((g + gg) / 2) > 80 then "succeed"
        else "fail"),
      ((g + gg) / 2))
    )
  )

  let fail (x : project) : project =
    match x with
    | (t, _, _) -> (t, "fail", 0)

  let success (x : project) : project =
    match x with
    | (t, _, _) -> (t, "succeed", 80)

end

(* tests *)

let print_project (p : App.project) =
  let (t, s, g) = p in
  print_endline (t ^ " : " ^ s ^ " -> " ^ (string_of_int g))

let () =
  let p = App.zero in
  let pp : App.project = ("lol", "succeed", 42) in

  print_project p;
  print_project pp;
  let pp = App.fail pp in
  print_project pp;
  let pp = App.success pp in
  print_project pp;
  print_project (App.combine p pp)
