define compiling
	@echo -n "$(shell tput bold)$(shell tput setaf 3)Compiling$1 $(shell tput sgr0)"
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $1 > /dev/null -c $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define finishing
	@echo -n "$(shell tput bold)$(shell tput setaf 2)Creating executable$1 $(shell tput sgr0)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $1
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define cleaning
	@echo -n "$(shell tput bold)$(shell tput setaf 8)Cleaning $1 $(shell tput sgr0)"
	@rm -rf $1 $2> /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define fcleaning
	@echo -n "$(shell tput bold)$(shell tput setaf 8)Fcleaning $1 $(shell tput sgr0)"
	@rm -f $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

SRC_DIR = ./src/
OBJ_DIR = ./bin/
INC_DIR = ./includes/

SRCS = bin_manip.c\
		free.c\
		lst_ops.c\
		main.c\
		parsing_2.c\
		parsing.c\
		ranking.c\
		sorting.c\
		sorting_ops.c\
		sort_s_set.c\
		ft_split.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

PUSH_SWAP = push_swap

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g3

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address
endif

CPPFLAGS = -I$(INC_DIR)

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJS)
	$(call finishing, $(PUSH_SWAP))

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(call compiling, $@, $<)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(call compiling, $@, $<)

clean:
	$(call cleaning, $(OBJ_DIR), $(OBJ_DIR))

fclean: clean
	$(call fcleaning, $(PUSH_SWAP))

re: fclean all

.PHONY: all clean fclean re
