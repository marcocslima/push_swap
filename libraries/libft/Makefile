# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:00:15 by mcesar-d          #+#    #+#              #
#    Updated: 2022/08/08 02:59:56 by mcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_recursive_power.c ft_isdigit.c ft_strlen.c ft_atoi.c \
					ft_putstr_fd.c ft_stcknewone.c ft_stcklast.c ft_stckadd_back.c \
					ft_sckadd_front.c ft_lstadd_front.c ft_lstlast.c
OBJS			=	$(SRCS:.c=.o)
BONUS			=	
BONUS_O			=	$(BONUS:.c=.o)
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)
			make bonus

%.o:		%.c	libft.h
			$(CC) $(CFLAGS) -I . -c $< -o $@

bonus:		$(BONUS_O)
			make OBJS="$(OBJS) $(BONUS_O)" all

clean:
			rm -rf $(OBJS) $(BONUS_O)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re bonus