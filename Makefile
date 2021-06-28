NAME =	Enn

SRC		=	src/main.cpp \
			src/Core.cpp \
			src/Scene.cpp \
			src/Button.cpp \
			src/Player.cpp \
			src/Scene/Menu.cpp \
			src/Scene/Tuto.cpp \
			src/Scene/Game.cpp \

OBJS	=	$(SRC:.cpp=.o)

all:	$(OBJS)
		g++ -o $(NAME) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

run:
	Enn.exe