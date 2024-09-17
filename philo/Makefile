# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 22:45:06 by marvin            #+#    #+#              #
#    Updated: 2024/08/19 22:45:06 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#--------------FLAGS----------------------------#
CFLAGS = -Wall -Werror -Wextra -g3 -pthread
#--------------PATHS----------------------------#

OBJFOLDER = objs/

#--------------FILES----------------------------#
SRC = 0_main.c \
 1_validate.c \
 2_init.c \
 3_philo_actions.c \
 7_free.c\
 8_utils.c \
 9_delete.c \
#--------------RULES----------------------------#

OBJFILES = $(patsubst %.c, $(OBJFOLDER)%.o, $(SRC))

all: $(OBJFOLDER) $(NAME)

$(OBJFOLDER):
	@mkdir -p $(OBJFOLDER)

$(NAME): $(OBJFILES)
	@if [ ! -f $(NAME) ]; then \
		$(MAKE) ascii_art; \
	fi
	$(CC) $(OBJFILES) $(CFLAGS) -o $(NAME) -g 

ascii_art:
	@echo "\033[0;32m"
	@echo "         _      _  _        "
	@echo "        | |    (_)| |       "
	@echo "  _ __  | |__   _ | |  ___  "
	@echo " | '_ \ | '_ \ | || | / _ \ "
	@echo " | |_) || | | || || || (_) |"
	@echo " | .__/ |_| |_||_||_| \___/ "
	@echo " | |                        "
	@echo " |_|                        "
	@echo "\033[0m"


$(OBJFOLDER)%.o : $(SOURCES)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g 

#----------------CLEAN--------------------------#

clean:
	rm -f $(OBJFILES) -r $(OBJFOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
