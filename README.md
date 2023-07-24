# Project Name: So Long - Peter Griffin VS Ernie the Giant Chicken - Unfinished

![simplescreenrecorder-peter-vs-ernie](https://user-images.githubusercontent.com/81270660/255337939-4fd93f3b-e2e3-4960-b303-a48aead948b5.png)

![simplescreenrecorder-game-play](https://user-images.githubusercontent.com/81270660/255337185-03cbcf88-f751-4345-848d-af5c3c3383fe.gif)

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

## Description:
This project is a small 2D game developed as part of the curriculum at 42 code school. The objective of the project is to work with textures, sprites, and basic gameplay elements. The game is built using the MiniLibX graphical library and requires the implementation of various features such as window management, event handling, map rendering, and character movement.

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

### Animations in the Game

Animations in the game are implemented using sprite sheets and changing the displayed image at regular intervals. The `game_loop` function is responsible for handling animations and rendering the frames on the screen. Here's a breakdown of how the animations work:

1. `game->anim_index`: This variable keeps track of the current frame of the animation. The `game_loop` function increments this index at a regular interval (controlled by `SP_ANIM_DELAY`), causing the animation to play continuously.

2. `render_animation`: This function is called inside the `game_loop` function to render the animated frames. It loops through the map grid, looking for collectibles, enemies, and the player character. When it finds a collectible or an enemy, it changes the image displayed on the screen to the corresponding frame of the animation. The specific frame is determined by the `game->anim_index`.

3. `put_tile`: This function is used to display the tiles on the screen. It uses the `mlx_put_image_to_window` function from the MiniLibX library to render the images at their respective positions.

4. Player Animation: The player character also has a separate animation. The `game->player.i_anim` variable keeps track of the current frame for the player animation. It is incremented inside the `render_animation` function, and different frames are displayed for walking animations.

### Eric_Trump Mode (Enemies Following the Player)

The "eric_trump" mode is an extension of the game where enemies actively pursue the player character. Here's how it works:

1. `eric_trump`: This function is called in the `game_loop` function when the game is in "eric_trump" mode (controlled by `TRUMP_MODE`). It is responsible for making the enemies follow the player.

2. `init_path_grid`: This function initializes a 2D array (`path_grid`) to store the shortest paths from each tile on the map to the player character. It sets all values to `INT_MAX` initially.

3. `best_path_grid`: This function recursively calculates the shortest path from the player's current position to all reachable tiles on the map. It updates the `path_grid` with the number of steps required to reach each tile.

4. `best_direction`: This function determines the best direction for each enemy to move towards the player. It considers the neighboring tiles around each enemy and chooses the direction that leads to a tile with the lowest number of steps in the `path_grid`.

5. `joe_biden`: This function resets the "eric_trump" mode after a certain number of steps (`TRUMP_STEPS`). It turns off the "trump" mode for all enemies, making them return to their normal behavior.

In summary, the "eric_trump" mode adds intelligence to the enemies, making them follow the player character using the shortest paths calculated in the `path_grid`. The enemies switch to "trump" mode at a random interval, and after a certain number of steps, they return to their normal behavior.
