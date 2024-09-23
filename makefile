
all: build

build:
	g++ -ID:\demo\src\include -LD:\demo\src\lib sorting.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -o sorting.exe

run: build
	./sorting.exe


clean:
	del *.o sorting.exe


# Build the Project: mingw32-make
# Run the Executable: mingw32-make run
# Clean the Project: mingw32-make clean