(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_ref.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 13:13:39 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 14:25:09 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a ft_ref = { mutable contents : 'a }

let return x = { contents = x }

let get ref = ref.contents

let set ref x = ref.contents <- x

let bind ref fn : 'b ft_ref = fn ref.contents

(* tests *)
let lol a =
  return (a * 2)

let () =
  let r = return 42 in
  print_int @@ get r; print_char '\n';
  set r 84;
  print_int @@ get r; print_char '\n';
  print_int @@ get @@ bind r lol; print_char '\n'
