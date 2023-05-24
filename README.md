# COHRINT Track The Crocotta Project

This project has two versions:

- lightweight command line version
- openGL version (which I think is more fun :D)

### Compiling leightweight verion

Make sure you are in the command_line directory and the g++ compiler installed
```
g++ main.cpp game.cpp -o TTCCommandLine.exe
```

### Compiling OpenGL version

GLFW must be installed on your system. To install it on linux, use
```
sudo apt-get install libglfw3-dev
```
We will also need cmake:
```
sudo apt-get install cmake
```
Go into the OpenGL/build directory and type `make`.

### Running the game

For OpenGL, `./SDLTest.exe` in the build folder, for command_line, `./TTCCommandLine.exe`.
