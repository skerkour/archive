# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_all.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 16:16:36 by skerkour          #+#    #+#              #
#    Updated: 2017/09/27 17:32:48 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "\033[33mChecking the author file...\033[0m";
./auteur.sh

echo "\033[33mChecking the norme...\033[0m";
./norminette.sh

echo "\033[33mChecking the Makefile...\033[0m";
./test_makefile.sh

echo "\033[33mChecking the lib...\033[0m";
./test_lib.sh
