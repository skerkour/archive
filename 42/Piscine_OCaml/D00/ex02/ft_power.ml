(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_power.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 11:12:01 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 20:48:24 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)


let rec ft_power_rec acc x p =
  if p >= 1 then
    ft_power_rec (acc*x) x (p-1)
   else
     acc

let ft_power x p =
  if p == 0 then
    1
  else
    ft_power_rec 1 x p

let main () =
  print_string "Test with [2 4] : "; print_int (ft_power 2 4); print_char '\n';
  print_string "Test with [3 0] : "; print_int (ft_power 3 0); print_char '\n';
  print_string "Test with [0 5] : "; print_int (ft_power 0 5); print_char '\n';
  print_string "Test with [2 1] : "; print_int (ft_power 2 1); print_char '\n';
  print_string "Test with [1 2] : "; print_int (ft_power 1 2); print_char '\n';
  print_string "Test with [4 2] : "; print_int (ft_power 4 2); print_char '\n';
  print_string "Test with [42 6] : "; print_int (ft_power 42 6);
  print_char '\n';
  print_string "Test with [3 3] : "; print_int (ft_power 3 3); print_char '\n'

let () = main ()
