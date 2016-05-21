# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2016/03/30 10:16:32 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-20-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3 -ggdb

SRCDIR		=	srcs/

OBJDIR		=	.objs/

INCDIR		=	includes/

SRCBASE		=	\
				part1/ft_atoi.c								\
				part1/ft_bzero.c							\
				part1/ft_isalnum.c							\
				part1/ft_isalpha.c							\
				part1/ft_isascii.c							\
				part1/ft_isdigit.c							\
				part1/ft_isprint.c							\
				part1/ft_memccpy.c							\
				part1/ft_memchr.c							\
				part1/ft_memcmp.c							\
				part1/ft_memcpy.c							\
				part1/ft_memmove.c							\
				part1/ft_memset.c							\
				part1/ft_strcat.c							\
				part1/ft_strchr.c							\
				part1/ft_strcmp.c							\
				part1/ft_strcpy.c							\
				part1/ft_strdup.c							\
				part1/ft_strlcat.c							\
				part1/ft_strlen.c							\
				part1/ft_strncat.c							\
				part1/ft_strncmp.c							\
				part1/ft_strncpy.c							\
				part1/ft_strnstr.c							\
				part1/ft_strrchr.c							\
				part1/ft_strstr.c							\
				part1/ft_tolower.c							\
				part1/ft_toupper.c							\
				part2/ft_itoa.c								\
				part2/ft_memalloc.c							\
				part2/ft_memdel.c							\
				part2/ft_putchar.c							\
				part2/ft_putchar_fd.c						\
				part2/ft_putendl.c							\
				part2/ft_putendl_fd.c						\
				part2/ft_putnbr.c							\
				part2/ft_putnbr_fd.c						\
				part2/ft_putstr.c							\
				part2/ft_putstr_fd.c						\
				part2/ft_strclr.c							\
				part2/ft_strdel.c							\
				part2/ft_strequ.c							\
				part2/ft_striter.c							\
				part2/ft_striteri.c							\
				part2/ft_strjoin.c							\
				part2/ft_strmap.c							\
				part2/ft_strmapi.c							\
				part2/ft_strnequ.c							\
				part2/ft_strnew.c							\
				part2/ft_strsplit.c							\
				part2/ft_strsub.c							\
				part2/ft_strtrim.c							\
				bonus/ft_lstadd.c							\
				bonus/ft_lstdel.c							\
				bonus/ft_lstdelone.c						\
				bonus/ft_lstiter.c							\
				bonus/ft_lstmap.c							\
				bonus/ft_lstnew.c							\
				list/ft_lstaddend.c							\
				list/ft_lstsplit.c							\
				list/ft_putlst.c							\
				int/ft_add_end_int.c						\
				int/ft_itoabase.c							\
				int/ft_putnbr_back.c						\
				string/ft_count_char.c						\
				string/ft_lenbychar.c						\
				string/ft_strnchr.c							\
				string/ft_strndup.c							\
				string/ft_strtrim_n.c						\
				string/ft_strtrim_string.c					\

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	$(MAKE) -j $(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "\r\033[38;5;40mMAKE    [\033[0m$(NAMEBASE)\033[38;5;40m]\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR)
	printf "\r\033[38;5;117m%s%*.*s\033[0m\033[K"							\
	"MAKE   "$(NAMEBASE)" plz wait ..."										\
		$(MAX_COLS) $(MAX_COLS) "($(@))"

clean:
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;101mCLEAN  "									\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K";							\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124mFCLEAN "									\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K";							\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
