# Project Name: So Long - Unfinished

![simplescreenrecorder-2023-04-17_15 04 52](https://user-images.githubusercontent.com/81270660/254154047-a27208df-2939-4143-9161-4e95af85c03c.gif)

## Installation
To play the game, you need to follow these steps:

1. Clone the repository.
2. Navigate to the project directory.

## Usage
To compile and run the game, you have the following options:

### Make
- Run `make` to compile the game. This step is mandatory.
- Run `make bonus` to compile the game with bonus features (if available).
- Run `make run` to play the game. You will be prompted to choose a map (Just a number, it ill give you the options)
- Run `make runall` to play all the remaining maps starting from a selected map (Just a number)

![simplescreenrecorder-make runall](https://user-images.githubusercontent.com/81270660/254307718-32df4169-5ee4-499d-84dc-c643aa0445c8.png)


### Cleaning
- Run `make clean` to remove object files.
- Run `make fclean` to remove object files and executables.


## Description:
This project is a small 2D game developed as part of the curriculum at 42 code school. The objective of the project is to work with textures, sprites, and basic gameplay elements. The game is built using the MiniLibX graphical library and requires the implementation of various features such as window management, event handling, map rendering, and character movement.

## Version:
2.3

## Objectives:
The main objectives of this project are:
- Gain experience in computer graphics programming.
- Improve C programming skills and understanding of basic algorithms.
- Learn to work with textures, sprites, and graphical elements.
- Familiarize oneself with window management, event handling, and color manipulation.

## Contents:
The project includes the following files and directories:
- Makefile: A Makefile to compile the project's source files.
- *.h: Header files containing function prototypes and definitions.
- *.c: Source code files implementing the game logic and graphics.
- maps: Directory containing map description files in the *.ber format.
- textures: Directory containing textures, sprites, and other graphical assets.

## Instructions:
1. The project must be written in C programming language.
2. The Norm: The code must adhere to the Norm, which is the coding standard used at 42 code school.
3. Error Handling: The program should handle errors gracefully and avoid unexpected crashes or memory leaks.
4. Makefile: The provided Makefile should compile the source files with the necessary flags and rules.
5. External Functions: The allowed external functions include open, close, read, write, malloc, free, perror, strerror, exit, math library functions, MiniLibX functions, and a custom implementation of ft_printf or equivalent.
6. Libft: The project allows the use of the libft library. If used, the libft sources and its associated Makefile should be copied into a "libft" folder.
7. Mandatory Part: The mandatory requirements for the project include game mechanics such as collecting items, avoiding walls, displaying movement count, and creating a valid map.
8. Graphic Management: The program should display graphics using the MiniLibX library, handle window management, and provide a smooth user experience.
9. Map: The map should consist of walls, collectibles, and free spaces represented by specific characters. The map file must be in the .ber format and meet certain criteria such as having a valid path and being surrounded by walls.
10. Bonus Part: Optional additional features can be implemented to earn extra points. Suggestions include enemy patrols, sprite animations, and on-screen display of movement count.

**Note:** This README provides a summary of the project requirements and guidelines. For more detailed instructions, refer to the original project document or subject materials provided by 42 code school.

