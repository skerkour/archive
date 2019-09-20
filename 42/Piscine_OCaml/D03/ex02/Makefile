# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/16 14:00:32 by skerkour          #+#    #+#              #
#    Updated: 2016/06/17 20:09:54 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests

SOURCES = uncipher.ml cipher.ml

CAMLC = ocamlc
CAMLOPT = ocamlopt
CAMLDEP = ocamldep


LIBS = 

all: depend $(NAME)

$(NAME): opt byt
	ln -sf $(NAME).byt $(NAME)


opt: $(NAME).opt
byt: $(NAME).byt

OBJS = $(SOURCES:.ml=.cmo)
OPTOBJS = $(SOURCES:.ml=.cmx)


$(NAME).byt: $(OBJS)
	$(CAMLC) -o $(NAME).byt $(LIBS) $(OBJS)

$(NAME).opt: $(OPTOBJS)
	$(CAMLOPT) -o $(NAME).opt $(LIBS:.cma=.cmxa) $(OPTOBJS)

.SUFFIXES:
.SUFFIXES: .ml .mli .cmo .cmi .cmx

.ml.cmo:
	$(CAMLC) -c $<

.mli.cmi:
	$(CAMLC) -c $<

.ml.cmx:
	$(CAMLOPT) -c $<

clean:
	rm -f *.cm[iox]
	rm -f $(SOURCES:.ml=.o)

fclean: clean
	rm -rf $(NAME) $(NAME).opt $(NAME).byt .depend

depend:
	$(CAMLDEP) $(SOURCES) > .depend

re: fclean all
