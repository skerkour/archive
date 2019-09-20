(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Tictactoe.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/18 13:22:49 by tpaulmye          #+#    #+#             *)
(*   Updated: 2016/06/19 17:00:39 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Tictac =
struct
	type t = char list

	let newTictac () = ((['-'; '-'; '-'; '-'; '-'; '-'; '-'; '-'; '-'; ]):t)

	let x_win (l:t) = match l with
  	| ['X'; _; _; 'X'; _; _; 'X'; _; _] -> true
  	| [_; 'X'; _; _; 'X'; _; _; 'X'; _] -> true
  	| [_; _; 'X'; _; _; 'X'; _; _; 'X'] -> true
  	| ['X'; 'X'; 'X'; _; _; _; _; _; _] -> true
  	| [_; _; _; 'X'; 'X'; 'X'; _; _; _] -> true
  	| [_; _; _; _; _; _; 'X'; 'X'; 'X'] -> true
  	| ['X'; _; _; _; 'X'; _; _; _; 'X'] -> true
  	| [_; _; 'X'; _; 'X'; _; 'X'; _; _] -> true
  	| _ -> false

  	let o_win (l:t) = match l with
  	| ['O'; _; _; 'O'; _; _; 'O'; _; _] -> true
  	| [_; 'O'; _; _; 'O'; _; _; 'O'; _] -> true
  	| [_; _; 'O'; _; _; 'O'; _; _; 'O'] -> true
  	| ['O'; 'O'; 'O'; _; _; _; _; _; _] -> true
  	| [_; _; _; 'O'; 'O'; 'O'; _; _; _] -> true
  	| [_; _; _; _; _; _; 'O'; 'O'; 'O'] -> true
  	| ['O'; _; _; _; 'O'; _; _; _; 'O'] -> true
  	| [_; _; 'O'; _; 'O'; _; 'O'; _; _] -> true
  	| _ -> false

	let player_win_small (l:t) letter =
   		if letter = 'X' then x_win l
   		else o_win l


	let set_as_won (l:t) letter = List.map (fun x -> letter) l
	let can_insert_at (l:t) n = (n >= 0) && (n <= 8) && (List.nth l n = '-')

  let insert_n letter (l : t) n =
    let rec insert_n_aux l n i acc = (
      match l with
      | [] -> acc
      | head::tail when i = n -> insert_n_aux tail n (i+1) (acc @ [letter])
      | head::tail -> insert_n_aux tail n (i+1) (acc @ [head])
    ) in
    insert_n_aux l n 0 []

	let print_1 (l:t) = match l with
	| [ a; b; c; _; _; _; _; _; _] -> print_char a; print_char ' '; print_char b; print_char ' '; print_char c
	| _ -> ()

	let print_2 (l:t) = match l with
	| [ _; _; _; a; b; c; _; _; _] -> print_char a; print_char ' '; print_char b; print_char ' '; print_char c
	| _ -> ()

	let print_3 (l:t) = match l with
	| [ _; _; _; _; _; _; a; b; c] -> print_char a; print_char ' '; print_char b; print_char ' '; print_char c
	| _ -> ()

	let rec is_tictac_full (tic:t) = match tic with
	| [] -> true
	| tete::queue -> if tete = '-' then false else is_tictac_full queue

end

type t = Tictac.t list

let newGrid () = (([Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac(); Tictac.newTictac()]):t)

let print_grid (g:t) = match g with
| [ a; b; c; d; e; f; g; h; i] -> Tictac.print_1 a; print_string " | "; Tictac.print_1 b; print_string " | "; Tictac.print_1 c; print_char '\n';
								 Tictac.print_2 a; print_string " | "; Tictac.print_2 b; print_string " | "; Tictac.print_2 c; print_char '\n';
								 Tictac.print_3 a; print_string " | "; Tictac.print_3 b; print_string " | "; Tictac.print_3 c; print_char '\n';
								 print_endline "---------------------";
								 Tictac.print_1 d; print_string " | "; Tictac.print_1 e; print_string " | "; Tictac.print_1 f; print_char '\n';
								 Tictac.print_2 d; print_string " | "; Tictac.print_2 e; print_string " | "; Tictac.print_2 f; print_char '\n';
								 Tictac.print_3 d; print_string " | "; Tictac.print_3 e; print_string " | "; Tictac.print_3 f; print_char '\n';
								 print_endline "---------------------";
								 Tictac.print_1 g; print_string " | "; Tictac.print_1 h; print_string " | "; Tictac.print_1 i; print_char '\n';
								 Tictac.print_2 g; print_string " | "; Tictac.print_2 h; print_string " | "; Tictac.print_2 i; print_char '\n';
								 Tictac.print_3 g; print_string " | "; Tictac.print_3 h; print_string " | "; Tictac.print_3 i; print_char '\n';
| _ -> ()

let getTictac (g:t) n = ((List.nth g n):Tictac.t)


let insert_tic_in_grid grid tic n =
  let rec insert_tic_in_grid_aux grid n i acc = (
    match grid with
    | head::tail when n = i -> insert_tic_in_grid_aux tail n (i+1) (acc @ [tic])
    | head::tail -> insert_tic_in_grid_aux tail n (i+1) (acc @ [head])
    | [] -> acc
  ) in
  insert_tic_in_grid_aux grid n 0 []

let insert_move (g: t) (x, y) player : t =
  let rec insert_move_aux grid i = (
    if i = x then (
      let tic = getTictac grid x in
      insert_tic_in_grid grid (Tictac.insert_n player tic y) x
    ) else
      insert_move_aux grid (i + 1)
  ) in
  insert_move_aux g  0

let x_win (l:t) = match l with
	| [['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _] -> true
	| [_; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _] -> true
	| [_; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']] -> true
	| [['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; _; _; _; _] -> true
	| [_; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; _] -> true
	| [_; _; _; _; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; ['X';'X';'X';'X';'X';'X';'X';'X';'X']] -> true
	| [['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']] -> true
	| [_; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; ['X';'X';'X';'X';'X';'X';'X';'X';'X']; _; _] -> true
  	| _ -> false

 let o_win (l:t) = match l with
 	| [['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _] -> true
	| [_; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _] -> true
	| [_; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']] -> true
	| [['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; _; _; _; _] -> true
	| [_; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; _] -> true
	| [_; _; _; _; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; ['O';'O';'O';'O';'O';'O';'O';'O';'O']] -> true
	| [['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']] -> true
	| [_; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; ['O';'O';'O';'O';'O';'O';'O';'O';'O']; _; _] -> true
	| _ -> false

 let player_win_game (grid:t) letter =
   if letter = 'X' then x_win grid else o_win grid

let rec is_grid_full (grid:t) = match grid with
	| [] -> true
	| tete::queue -> if Tictac.is_tictac_full tete then is_grid_full queue else false

;;
