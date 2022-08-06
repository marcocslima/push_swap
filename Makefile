# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 22:47:14 by mcesar-d          #+#    #+#              #
#    Updated: 2022/08/06 16:38:09 by mcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH			=	./libraries/libft
LIBFT				=	$(LIBFT_PATH)/libft.a

SOURCES_FILES		=	push_swap.c error.c checks.c init.c sort_litle.c sort_big.c
SOURCES_DIR			=	./src
SOURCES				=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

HEADER_SRCS			=	push_swap.h
HEADER_DIR			=	./includes/
HEADER				=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

OBJS				=	$(SOURCES:.c=.o)

NAME				=	push_swap

CC					=	gcc
RM					=	rm -f

CFLAGS				=	-Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS) $(HEADER)
					$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

.c.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all
					make clean

debug:
					$(CC) -g $(CFLAGS) $(SOURCES_BONUS) $(LIBFT) -o $(NAME)
					gdb --tui --args ./push_swap 5 3 9 100 2

.PHONY:				all clean fclean re libft