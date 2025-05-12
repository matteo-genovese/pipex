# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 17:07:02 by mgenoves          #+#    #+#              #
#    Updated: 2024/11/12 10:40:16 by mgenoves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

# Definiamo i file sorgenti mantenendo i percorsi originali
SRCS = 	src/main.c src/check_cmd.c src/utils_stack.c src/pipex.c \
		libft/ft_bzero.c libft/ft_calloc.c libft/ft_memset.c libft/ft_split.c \
		libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_strdup.c \
		libft/ft_strjoin.c libft/ft_putstr_fd.c \

SRCS_BONUS = 	bonus/main_bonus.c bonus/check_cmd_bonus.c bonus/utils_stack_bonus.c bonus/pipex_bonus.c \
				libft/ft_bzero.c libft/ft_calloc.c libft/ft_memset.c libft/ft_split.c \
				libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_strdup.c \
				libft/ft_strjoin.c libft/ft_putstr_fd.c \

# Cartella per gli oggetti
OBJ_DIR = obj

# Variabile OBJS per i file oggetto dentro obj (file .o saranno tutti in obj/)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS_BONUS)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Obiettivo principale: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
# Obiettivo bonus: $(NAME_BONUS)	
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)
	
# Creazione della cartella obj se non esiste
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regola generica per compilare ogni file sorgente, indipendentemente dalla directory di origine
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: bonus/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per trovare i file .c originali nelle sottocartelle
vpath %.c $(sort $(dir $(SRCS)))

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

git:
	make fclean
	git add .
	git commit -m "update"
	git push

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re git bonus
