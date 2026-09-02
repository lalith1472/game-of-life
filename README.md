# game of life

# Game of Life

A simple implementation of Conway's Game of Life made using C++ and raylib.

I made this project to experiment with cellular automata and get more comfortable with C++ and raylib.

## How it works

The simulation uses a 100 x 100 grid. Each cell can either be alive or dead.

For every generation, each cell checks its 8 neighbouring cells and follows the normal Game of Life rules:

- A live cell with 2 or 3 neighbours survives.
- A live cell with fewer than 2 neighbours dies.
- A live cell with more than 3 neighbours dies.
- A dead cell with exactly 3 neighbours becomes alive.

The grid wraps around at the edges, so cells on one side of the screen can interact with cells on the opposite side.

## Features

- 100 x 100 grid
- Interactive cell placement
- Start and pause the simulation
- Reset the grid
- Automatic generation updates
- Neon green cells on a black background
- Wrapping edges

## Controls

| Input | Action |
|---|---|
| Left Mouse Button | Toggle cells |
| Space | Start / Pause |
| R | Reset |

## Implementation

The project uses a 2D `vector` to store the grid.

Instead of creating a second grid for every generation, I use temporary cell states while updating:

- `0` = dead
- `1` = alive
- `2` = newly born
- `3` = surviving cell

This allows the grid to be updated in place while still keeping track of the original states when counting neighbours.

## Built With

- C++
- raylib

## Future Improvements

- Add a generation counter
- Add adjustable simulation speed
- Add random grid generation
- Add preset patterns
- Add more cellular automata rules
- Improve the cell drawing and UI