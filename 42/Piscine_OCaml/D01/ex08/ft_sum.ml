(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_sum.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 15:53:34 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:58:25 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_sum fn i j =
  if j < i then
    nan
  else (
    let rec ft_sum_aux fn i j acc = (
      if i == j then
        acc +. (fn i)
      else
        ft_sum_aux fn (i+1) j (acc +. (fn i))
    ) in ft_sum_aux fn i j 0.0
  )

let () =
  print_string "Test with [(fun i -> float_of_int (i * i)) 1 10] : ";
  print_float (ft_sum (fun i -> float_of_int (i * i)) 1 10); print_char '\n';
  print_string "Test with [(fun i -> float_of_int (i + i)) 1 10] : ";
  print_float (ft_sum (fun i -> float_of_int (i + i)) 1 10); print_char '\n';
  print_string "Test with [(fun i -> float_of_int (i)) 1 10] : ";
  print_float (ft_sum (fun i -> float_of_int (i)) 1 10); print_char '\n';
  print_string "Test with [(fun i -> float_of_int (i * i)) 4 4] : ";
  print_float (ft_sum (fun i -> float_of_int (i * i)) 4 4); print_char '\n';
  print_string "Test with [(fun i -> float_of_int (i * i)) 4 3] : ";
  print_float (ft_sum (fun i -> float_of_int (i * i)) 4 3); print_char '\n'
