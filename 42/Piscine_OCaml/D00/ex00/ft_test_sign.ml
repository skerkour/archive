(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_test_sign.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 10:01:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/13 18:48:46 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_test_sign x =
  if x < 0 then
    print_endline "negative"
  else
    print_endline "positive"



let main () =
  print_string "Test with [42] : "; ft_test_sign 42;
  print_string "Test with [0] : "; ft_test_sign 0;
  print_string "Test with [-42] : "; ft_test_sign (-42)

let () = main()
