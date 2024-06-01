# so_long

so_long is a simple 2D game developed as part of the 42 École curriculum. The objective of the game is to navigate through a map, collect all items, and reach the exit. The game is built using the MiniLibX library.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Implementation Details](#implementation-details)
- [Contact](#contact)

## Features

- 2D game map rendering using MiniLibX.
- Player movement and collision detection.
- Item collection and exit mechanics.

## Installation

To build and run the so_long project, follow these steps:

1. **Clone the repository**
   ```
   git clone https://github.com/your_username/so_long.git
   cd so_long

    Install MiniLibX
    Follow the instructions to install the MiniLibX library on your system.

    Build the project

    make

Usage

To start the game, simply run the compiled executable with a map file:

```
./so_long maps/map.ber
```
Map File Format

The map file should be a .ber file with a specific format, where:

    1 represents walls
    0 represents empty space
    P represents the player starting position
    C represents collectible items
    E represents the exit

Example of a map file (map.ber):
```
1111111
1P0C0E1
1000001
1111111
```
Controls

    W / UP: Move up
    A / LEFT: Move left
    S / DOWN: Move down
    D / RIGHT: Move right
    ESC: Exit the game

Implementation Details

    Rendering: The game map and sprites are rendered using the MiniLibX library.
    Movement: Player movement and collision detection are implemented to ensure smooth gameplay.
    Items and Exit: The player must collect all items (C) before reaching the exit (E) to win the game.

Erik Grigoryan - ergrigor@student.42yerevan.am
