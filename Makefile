NAME	= 	numerology

SRCS	=	numerology.cpp

OBJS	=	$(SRCS:%.c=obj/%.o)

CC		=	c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

#supprimer les objets
clean:
	@rm -rf objs
	@echo "remove objs directory"

#supprimer les objets et les programmes
fclean: clean
	@rm -rf $(NAME)
	@echo "remove pgm"

re: fclean all

# Compilation du programme
$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

# Compilation des fichiers objets
obj/%.o : %.cpp | obj
	$(CC) -c $< -o $@

# Créer le dossier objs s'il n'existe pas
obj:
	mkdir -p obj

.PHONY: clean fclean re all
