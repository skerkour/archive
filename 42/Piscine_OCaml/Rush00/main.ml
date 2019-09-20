(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/18 09:25:07 by tpaulmye          #+#    #+#             *)
(*   Updated: 2016/06/19 15:26:05 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let get_player_input () =
  let digit_to_int c = match c with
  | '1' -> 0
  | '2' -> 1
  | '3' -> 2
  | '4' -> 3
  | '5' -> 4
  | '6' -> 5
  | '7' -> 6
  | '8' -> 7
  | '9' -> 8
  | _   -> (-1)
  in
  let str = read_line () in
  let length = String.length str in
  if length <> 3 then ((-1), (-1))
  else if str.[1] <> ' ' then ((-1), (-1))
  else let coord1 = digit_to_int str.[0] in
  let coord2 = digit_to_int str.[2] in
  if coord1 = (-1) || coord2 = (-1) then ((-1), (-1))
  else (coord1, coord2)

let is_valid grid (a, b) =
  a <> (-1) && b <> (-1) && List.nth (Tictactoe.getTictac grid a) b = '-'

let switch_player letter = if letter = 'X' then 'O' else 'X'

let announce_player player =
  print_string "Player "; print_char player; print_endline "'s turn to play."

let announce_player_win_small player n =
  print_char player; print_string " wins grid "; print_int (n+1); print_endline "!"

let announce_winner player =
  print_char player; print_endline " wins the game!"

let () =
  let rec loop_games () = (
  let x = Tictactoe.newGrid () in
  let rec loop_game player grid =
    Tictactoe.print_grid grid;
    print_char '\n';
    announce_player player;
    let rec loop_get_player_input () = (
      let (x, y) = get_player_input () in
      if is_valid grid (x, y) then
        (x, y)
      else (
        print_endline "Illegal move";
        loop_get_player_input ()
      )
    ) in
    let (x, y) = loop_get_player_input () in
    let grid_modified = Tictactoe.insert_move grid (x, y) player in
    let param2 = if Tictactoe.Tictac.player_win_small (List.nth grid_modified x)
    player  || Tictactoe.Tictac.is_tictac_full (List.nth grid_modified x)  then
       (announce_player_win_small player x; Tictactoe.insert_tic_in_grid grid (Tictactoe.Tictac.set_as_won (List.nth grid_modified x) player) x )
    else grid_modified in
    
    if Tictactoe.player_win_game param2 player then
      (announce_winner player; Tictactoe.print_grid param2)
    else if Tictactoe.is_grid_full param2 then
      (announce_winner player; Tictactoe.print_grid param2)
    else loop_game (switch_player player) param2
  in
  loop_game 'O' x;
  print_endline "Do you want to replay ? (y/n)";
  let choice = read_line () in
  if choice = "y" then loop_games ()
  )
  in loop_games ()
