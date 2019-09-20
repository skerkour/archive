(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex02.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/21 17:35:41 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/22 22:14:23 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type PAIR = sig val pair : (int * int) end
module type VAL = sig val x : int end

module Pair : PAIR = struct let pair = ( 21, 42 ) end

module type MAKEPROJECTION =
  functor (Pair : PAIR) -> VAL

module MakeFst : MAKEPROJECTION = functor (Pair : PAIR) ->
  struct
    let (x, _) = Pair.pair
  end

module MakeSnd : MAKEPROJECTION = functor (Pair : PAIR) ->
  struct
    let (_, x) = Pair.pair
  end

module Fst : VAL = MakeFst (Pair)
module Snd : VAL = MakeSnd (Pair)

let () = Printf.printf "Fst.x = %d, Snd.x = %d\n" Fst.x Snd.x
