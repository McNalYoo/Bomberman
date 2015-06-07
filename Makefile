##                                                                                                                                                                                                                                             
## Makefile for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                                    
##                                                                                                                                                                                                                                             
## Made by Kevin Huo Yung Kai                                                                                                                                                                                                                  
## Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
##                                                                                                                                                                                                                                             
## Started on  Mon Jun  1 09:39:00 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
## Last update Sat Jun  6 22:57:32 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
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

all     : $(NAME)

$(NAME) : $(OBJ)
        $(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean   :
        $(RM) $(OBJ)

fclean  : clean
        $(RM) $(NAME)

re      : fclean all
