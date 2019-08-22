# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ction <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 18:06:10 by ction             #+#    #+#              #
#    Updated: 2019/04/13 13:00:10 by ction            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_atoi.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
	ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c \
	ft_strlen.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_isprint.c ft_tolower.c ft_toupper.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
	ft_strnew.c ft_strdel.c ft_memalloc.c ft_memdel.c \
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strndup.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c ft_expmem.c \
	ft_str_is_printable.c ft_strcasecmp.c ft_abs.c \
	ft_strnchr.c ft_strbs.c ft_strfs.c ft_pushfront.c
CFLAGS = -g -Wall -Wextra -Werror
OBJ_DIR = ./objs
SRC_DIR = ./srcs
INCLUDES = -I ./includes
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	
$(NAME): $(OBJ_DIR) $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all
