# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_makefile.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 16:16:54 by skerkour          #+#    #+#              #
#    Updated: 2017/09/26 16:22:43 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# checking if Makefile has got rules "all" "clean" "fclean" and "re"

path=".."

make -C $path all
let "ret = $?"
make -C $path re
let "ret = $ret + $?"
make -C $path clean
let "ret = $ret + $?"
make -C $path fclean
let "ret = $ret + $?"
if [ $ret -eq 0 ];
then
	echo "\033[32mMakefile is good\033[0m";
else
	echo "\033[31mMakefile is bad\033[0m";
fi
