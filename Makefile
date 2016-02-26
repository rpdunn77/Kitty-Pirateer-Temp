CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm -lSOIL `sdl-config --cflags --libs`  -lSDL_mixer 
OBJ = Game.cpp \
      Player.cpp \
      ImageLoader.cpp \
      Jukebox.cpp \
		Obstacle.cpp \
		Items.cpp \
		ItemHandler.cpp\
		Weapon.cpp
      
All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o game
