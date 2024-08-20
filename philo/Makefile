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
CFLAGS = -Wall -Werror -Wextra -g3
#--------------PATHS----------------------------#

OBJFOLDER = objs/
SOURCES = ./sources/

#--------------FILES----------------------------#
SRC = $(SOURCES)main.c \
#--------------RULES----------------------------#

OBJFILES = $(subst $(SOURCES),$(OBJFOLDER),$(SRC:.c=.o))

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