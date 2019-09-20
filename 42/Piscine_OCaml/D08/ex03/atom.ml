(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   atom.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 00:32:26 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 00:32:26 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual atom =
object (self)

  method virtual name : string
  method virtual symbol : string
  method virtual atomic_number : int

  method to_string =
    "Atom : " ^ self#name ^ "(" ^ self#symbol ^ "; "
    ^ (string_of_int self#atomic_number) ^ ")"

  method equals (x : atom) =
    self#atomic_number = x#atomic_number

end
