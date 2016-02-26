CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm -lSOIL `sdl-config --cflags --libs`  -lSDL_mixer 
OBJ = ./src/Game.cpp \
      ./src/Player.cpp \
      ./src/ImageLoader.cpp \
      ./src/Jukebox.cpp \
		./src/Obstacle.cpp \
		./src/Items.cpp \
		./src/ItemHandler.cpp\
		./src/Weapon.cpp
      
All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o game
