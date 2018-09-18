# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 19:52:44 by vbrazas           #+#    #+#              #
#    Updated: 2018/09/18 23:10:25 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		fdf

SRC_PATH :=	src/
INC_PATH :=	includes/
LIB_PATH :=	ft_printf/
MLX_PATH :=	mlx/
OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-g #-Wall -Werror -Wextra
IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH) -I $(MLX_PATH)
LFLAGS :=	-L $(LIB_PATH) -L $(MLX_PATH)
LFLAGS +=	-framework OpenGL -framework AppKit
LFLAGS +=	-lm -lmlx -lftprintf 

HDRS :=		$(INC_PATH)fdf.h $(MLX_PATH)mlx.h
FILES :=	fdf
LIB :=		$(LIB_PATH)libftprintf.a $(MLX_PATH)libmlx.a

SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
$(LIB): 
	make -C $(MLX_PATH)
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
