(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   army.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/23 21:42:13 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 22:51:08 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a] army =
object
  val _army : 'a list = []

  method add x =
    {< _army = x :: _army >}

  method delete = (
    let delete_aux lst = (
      match lst with
      | [] -> []
      | head::tail -> tail
    ) in
    {< _army = delete_aux _army >}
  )

  method print_length =
    print_endline @@string_of_int @@ List.length _army
end
