# Maze_Runner
Maze Runner is a 3D maze game that utilizes raycasting for 3D rendering and is built with the SDL2 library.
The project demonstrates basic principles of 3D graphics, including raycasting algorithms and efficient rendering using SDL2.

## Features
* 3D maze generation using raycasting
* Real-time rendering with SDL2
* Smooth player movement and collision detection
* Clean, modular code with functions limited to 40 lines for readability

## Installation
To run this project, you will need to install SDL2. If you're using Windows Subsystem for Linux (WSL), additional steps are required for proper rendering. The following instructions guide you through the setup process.
#Installing SDL2
1. Install SDL2 using your package manager:
```bash
    sudo apt-get install libsdl2-dev
```
2. If you encounter issues with rendering on WSL, you will need an X server to display the SDL2 output. I used a program called Xlunch to enable this functionality.
## X Server Setup:
1. Install Xlunch or another X server program.
2. Run the X server and set the display environment variable:
```bash
export DISPLAY=:0
```
After completing these steps, you should be able to render the game correctly on WSL.

# Code Structure
The project is divided into several small, modular functions, each no longer than 40 lines. This structure keeps the code clean and maintainable.

* Raycasting Algorithm: I spent significant time learning and implementing the raycasting algorithm, which is the core of the rendering logic.
Understanding how to calculate ray positions and distances was a challenging but rewarding process.

* Pointers: One of the most challenging parts of the project was managing variables between files using pointers. This allowed me to manipulate variables declared in the main file from other source files.

# Challenges
* SDL2 Installation: Installing SDL2 on WSL was more complex than expected. Initially, I couldn't render the game until I used the Xlunch program as an X server.

* Code Cleanliness: I aimed to keep each function under 40 lines to ensure clean and modular code. This took considerable time, as I needed to refactor and optimize sections of the program frequently.

* Raycasting Algorithm: Understanding the raycasting algorithm was a major learning curve. I gained a deeper understanding of how to work with pointers, especially when handling variables across multiple files.

# Conclusion
Maze Runner was a challenging and educational project. It helped me improve my understanding of raycasting, pointer manipulation, and clean coding practices. Despite the hurdles, especially with setting up SDL2 on WSL and managing pointers, the project came together successfully.


