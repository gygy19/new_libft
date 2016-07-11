# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2016/05/30 23:10:37 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-20-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		= -O3 -ggdb

SRCDIR		=	

OBJDIR		=	.objs/

INCDIR		=	includes/

LIBFTDIR	=	libftprintf/

INCDIRLIBFT	=	$(LIBFTDIR)/includes/

SRCBASE		=	\
				test_printf.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	$(MAKE) -j $(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(LIBFTDIR) -lftprintf
	echo "MAKE   [$(NAMEBASE)]"
	#echo "\r\033[38;5;40mMAKE    [\033[0m$(NAMEBASE)\033[38;5;40m]\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR) -I $(INCDIRLIBFT)
	printf "\r\033[38;5;117m%s%*.*s\033[0m\033[K"							\
	"MAKE   "$(NAMEBASE)" plz wait ..."										\
		$(MAX_COLS) $(MAX_COLS) "($(@)))"

clean:
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;101mCLEAN  "									\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K";							\
	else																	\
		printf "\r";														\
	fi
	make -C $(LIBFTDIR) fclean

fclean:		clean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124mFCLEAN "									\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K";							\
	else																	\
		printf "\r";														\
	fi
	make -C $(LIBFTDIR) clean

libre:
	make -C $(LIBFTDIR) re

re:			fclean libre all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
