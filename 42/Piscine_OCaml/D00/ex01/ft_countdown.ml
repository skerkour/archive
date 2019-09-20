(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_countdown.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 10:58:01 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/13 18:50:12 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_countdown x =
  if x > 0 then (
    print_int x; print_char '\n';
    ft_countdown (x-1)
  ) else (
    print_int 0; print_char '\n';
  )


let main () =
  print_endline "Test with [3] :"; ft_countdown 3;
  print_endline "Test with [9] :"; ft_countdown 9;
  print_endline "Test with [0] :"; ft_countdown 0;
  print_endline "Test with [-1] :"; ft_countdown (-1)

let () = main ()
