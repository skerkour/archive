# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@42.fr>                    +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 14:57:38 by skerkour          #+#    #+#              #
#    Updated: 2016/11/11 13:30:27 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all test grace sully colleen
.DEFAULT: all

all: colleen grace sully

colleen: 00/Colleen.c
	clang -Wall -Wextra -Werror 00/Colleen.c -o 00/Colleen

grace: 01/Grace.c
	clang -Wall -Wextra -Werror 01/Grace.c -o 01/Grace

sully: 02/Sully.c
	clang -Wall -Wextra -Werror 02/Sully.c -o 02/Sully

clean:
	rm -rf 00/tmp_Colleen 01/Grace_kid.c 02/test bonus00/tmp_Colleen bonus01/Grace_kid.js bonus02/test

fclean: clean
	rm -rf 00/Colleen 01/Grace 02/Sully

re: fclean all

test: re
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Colleen ******************************************************************** #"
	@echo "# **************************************************************************** #"
	./00/Colleen > 00/tmp_Colleen
	diff 00/Colleen.c 00/tmp_Colleen
	
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Grace ********************************************************************** #"
	@echo "# **************************************************************************** #"
	@cd 01 ; \
	./Grace
	diff 01/Grace.c 01/Grace_kid.c
	
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Sully ********************************************************************** #"
	@echo "# **************************************************************************** #"
	@cd 02 ; \
	mkdir test ; \
	cd test ; \
	cp ../Sully .
	@cd 02/test; ./Sully
	cd 02/test; ls -al | grep Sully | wc -l
	-cd 02/test; diff ../Sully.c Sully_0.c
	-cd 02/test; diff Sully_3.c Sully_2.c

bonuses: fclean
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Colleen ******************************************************************** #"
	@echo "# **************************************************************************** #"
	node bonus00/Colleen > bonus00/tmp_Colleen
	diff bonus00/Colleen.js bonus00/tmp_Colleen
	
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Grace ********************************************************************** #"
	@echo "# **************************************************************************** #"
	cd bonus01; node Grace.js
	diff bonus01/Grace.js bonus01/Grace_kid.js
	
	@echo "\n"
	@echo "# **************************************************************************** #"
	@echo "# Sully ********************************************************************** #"
	@echo "# **************************************************************************** #"
	@cd bonus02 ; \
	mkdir test ; \
	cd test ; \
	cp ../Sully.js .
	cd bonus02/test; node Sully.js
	cd bonus02/test; ls -al | grep -v 'drwx'
	-cd bonus02/test; diff ../Sully.js Sully_0.js
	-cd bonus02/test; diff Sully_3.js Sully_2.js
