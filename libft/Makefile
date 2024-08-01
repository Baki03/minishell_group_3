#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johassin <johassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 10:32:22 by johassin          #+#    #+#              #
#    Updated: 2024/07/31 14:33:05 by johassin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC =  -I ./

SRCS =  ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strndup.c\
		list/ft_lstadd_back.c\
		list/ft_lstadd_front.c\
		list/ft_lstclear.c\
		list/ft_lstdelone.c\
		list/ft_lstiter.c\
		list/ft_lstlast.c\
		list/ft_lstfirst.c\
		list/ft_lstmap.c\
		list/ft_lstnew.c\
		list/ft_lstsize.c

OBJS = ${SRCS:.c=.o}
	
all:${NAME}
	
.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@ar -rs ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}
	
fclean:	clean
	@rm -f ${NAME}
	
re:	fclean all
	
.PHONY:	all clean fclean re