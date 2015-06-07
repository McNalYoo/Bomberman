##
## Makefile for  in /home/hodali_g/Bomberman
##
## Made by gabriel hodali
## Login   <hodali_g@epitech.net>
##
## Started on  Sun Jun  7 15:37:54 2015 gabriel hodali
## Last update Sun Jun  7 15:38:39 2015 gabriel hodali
##


CC      = g++

RM      = rm -f

NAME    = bomberman

SRC     = main.cpp \
        AObject.cpp \
        Cube.cpp \
        GameEngine.cpp

LDFLAGS += -L./LibBomberman_linux_x64/includes/ -L./LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

OBJ     = $(SRC:.cpp=.o)

CXXFLAGS = -I ./LibBomberman_linux_x64/includes/

all     :$(NAME)

$(NAME) :$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean   :
	$(RM) $(OBJ)

fclean  :clean
	$(RM) $(NAME)

re      : fclean all
