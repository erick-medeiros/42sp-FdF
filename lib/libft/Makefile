NAME 			= libft.a

INC_PATH	= include/
SRC_PATH	= src/
OBJ_PATH	= obj/
OBJ_DIRS	= obj/ obj/ft_printf/

FILES			= ft_grp_is.c
FILES			+= ft_grp_to.c
FILES			+= ft_strlen.c
FILES			+= ft_memset.c
FILES			+= ft_memcpy.c
FILES			+= ft_memmove.c
FILES			+= ft_strchr.c
FILES			+= ft_strrchr.c
FILES			+= ft_strncmp.c
FILES			+= ft_memchr.c
FILES			+= ft_memcmp.c
FILES			+= ft_strnstr.c
FILES			+= ft_strdup.c
FILES			+= ft_strlcpy.c
FILES			+= ft_strlcat.c
FILES			+= ft_atoi.c
FILES			+= ft_calloc.c
FILES			+= ft_substr.c
FILES			+= ft_strjoin.c
FILES			+= ft_split.c
FILES			+= ft_itoa.c
FILES			+= ft_ulltoa_base.c
FILES			+= ft_uitoa_base.c
FILES			+= get_next_line.c
FILES			+= ft_strupd.c
FILES			+= ft_atoi_base.c

FILES			+= ft_printf/ft_printf.c
FILES			+= ft_printf/ft_initialize.c
FILES			+= ft_printf/ft_placeholder.c
FILES			+= ft_printf/ft_specifier_c.c
FILES			+= ft_printf/ft_specifier_s.c
FILES			+= ft_printf/ft_specifier_p.c
FILES			+= ft_printf/ft_specifier_d_i.c
FILES			+= ft_printf/ft_specifier_ui.c
FILES			+= ft_printf/ft_specifier_pct.c
FILES			+= ft_printf/ft_subspecs.c
FILES			+= ft_printf/ft_sprintf.c

SRC				= $(addprefix $(SRC_PATH), $(FILES))
OBJ				= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

CFLAGS 		= -Wall -Wextra -Werror
CFLAGS		+= -g -I $(INC_PATH)
CC 				= cc
LIB 			= ar -rcs
RM				= rm -fr

C_W				= \e[00m
C_G				= \e[32m
C_R				= \e[91m

all: $(NAME)

$(OBJ_DIRS):
	@echo "$(C_G)Create dir$(C_W) $@"
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -n "$(C_G)obj: $(C_W)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(OBJ)
	@echo "$(C_G)Compiling $(C_W)$(NAME:.a=)"
	$(LIB) $(NAME) $(OBJ)
	@echo "$(C_G)Compiled $(C_W)~ $(NAME)"

clean:
	@echo "$(C_R)Removing $(C_W)all objects"
	${RM} $(OBJ)

fclean: clean
	@echo "$(C_R)Removing $(C_W)$(NAME)"
	${RM} $(NAME)

re: fclean all

norm:
	@clear
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

.PHONY: all clean fclean re norm