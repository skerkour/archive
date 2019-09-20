# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auteur.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 15:29:26 by skerkour          #+#    #+#              #
#    Updated: 2017/09/26 16:22:44 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

content=$(cat -e ../auteur)
if [ $content == 'skerkour$' ]; then
	echo "\033[32mauteur file is good\033[0m";
	echo $content;
else
	echo "\033[31mauther file is bad\033[0m";
	echo $content;
fi;
