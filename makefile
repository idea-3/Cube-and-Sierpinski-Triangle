all :
	g++ Disable.cpp Draw.cpp Enable.cpp main.cpp -o HelloTriangle -lopengl32 -lwinmm -lgdi32

sierpinski :
	g++ sierpinski.cpp -o sierpinski -Wall -mwindows -m32 glut32.lib -lopengl32 -lglu32