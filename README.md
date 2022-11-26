# Rat in a Maze Problem

## Requirements
---
This code is written in C which means any C compiler is required to compile the code.
## Description
---
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find a possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.


This classic problem is solved here using C and a use of a [backtracking algorithm](https://en.wikipedia.org/wiki/Backtracking) - function *findRoute()*. The function accepts the row, column, maze matrix, solution matrix, the order of the matrices and a string to store the solution of the maze, and is called recursively while checking if a path in the matrix has been traversed through or not. If the selected path does not reach [N-1][N-1], it backtracks to the last working location of the current path and tries another path, if available. If unable to reach [N-1][N-1] at all, it returns that there is no solution for the maze.

## Execution
---
For example, if using gcc, go into the directory containing the file and
```bash
gcc maze.c -o maze
./maze
```

## Example
<img src="https://cdn.discordapp.com/attachments/888438523047329812/1046111475640582317/Screenshot_2022-11-26-10-40-50_1920x1080.png">