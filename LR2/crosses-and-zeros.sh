# !/bin/bash

# data
field=("\ " "\ " "\ " "\ " "\ " "\ " "\ " "\ " "\ ") # 9 = 3x3 empty cells
game_in_process=true
cross="x"
zero="o"
current_turn=$cross
turns_count=0
chosen_cell=-1
someone_won=false

# functions
print_field() {
	clear
	echo =====
	echo ${field[0]} ${field[1]} ${field[2]}
	echo ${field[3]} ${field[4]} ${field[5]}
	echo ${field[6]} ${field[7]} ${field[8]}
	echo =====
}


compare_line_values() {
	if  [[ ${field[$1]} == ${field[$2]} ]] && [[ ${field[$2]} == ${field[$3]} ]]; then
    	game_in_process=false
    	someone_won=true
    fi
}

determine_winner_if_game_is_over() {
	if [[ $game_in_process == false ]] && [[ $someone_won == true ]]; then 
		if [[ $current_turn =~ ^[$cross]$ ]] 
			then echo Player $cross wins !
			return
		else 
			echo Player $zero wins !
			return
		fi
	fi		
}

check_all_variants() {
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 0 1 2
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 3 4 5
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 6 7 8
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 0 3 6
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 1 4 7
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 2 5 8
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 0 4 8
	
	if [ $game_in_process == false ]; then return; fi
	compare_line_values 2 4 6
	
	if [ $turns_count == 9 ]; then 
    	game_in_process=false
    	echo "Noone wins; Draw"
  	fi
}

make_turn() {
	if [[ $current_turn == $cross ]]; then
    	echo -n Time for $cross turn " "
  	else
    	echo -n Time for $zero turn " "
  	fi
  	
  	while true
  	do
  		read chosen_cell
  		
  		if [[ ! $chosen_cell =~ ^[0-9]$ ]]; then 
  			echo Not valid cell number, need to insert 0..9
  		elif [[ ${field[$chosen_cell]} = "$cross" ]] || [[ ${field[$chosen_cell]} = "$zero" ]]; then 
  			echo Cell ocupied, repeat trial
 		else
 			break
  		fi  		
  	done
	
	echo inputed cell was ${field[$chosen_cell]}
	

  	((turns_count=turns_count+1))
  	
  	field[$chosen_cell]=$current_turn
  	
  	
  	chosen_cell=-1
}


while $game_in_process
	do
		make_turn
		check_all_variants
		print_field
		determine_winner_if_game_is_over
		
		if [[ $current_turn == $cross ]]; then
    		current_turn=$zero
  		else
    		current_turn=$cross
  		fi
	done
