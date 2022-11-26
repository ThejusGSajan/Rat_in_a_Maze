#include <stdio.h>
#include <stdlib.h>

//static variable to store the ULDR solution to a character string
static int k = 0;

void display(int** Soln, int n, char* string)
{
    int i,j;
    //prints solution matrix which contains the path
    printf("\n---Maze Path---\n");
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < n; j++)
        {
            printf("%d\t", Soln[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");

    /*prints the solution in UDLR
    where   u - Up
            L - Left
            D - Down
            R - Right*/
    printf("---Maze Solution---\n");
    for(i = (n * n - 1); i >= 0; i--)
    {
        //if char is an empty character, skip it
        if(string[i] == '\0')
            continue;
        else
            printf("%c ", string[i]);
    }
    printf("\n");
}

int findRoute(int r, int c, int**maze, int** soln, int n, char* string)
{
    if((r == n - 1) && (c == n - 1))
    {
        soln[r][c] = 1;
        return 1;
    }
    
    if(r >= 0 && c >= 0 && r < n && c < n && soln[r][c] == 0 && maze[r][c] == 1)
    {
        //if cell not visited and safe to traverse, visit it
        soln[r][c] = 1;

        //going down
        if(findRoute(r + 1, c, maze, soln, n, string))
        {
            string[k++] = 'D';
            return 1;
        }

        //going right
        if(findRoute(r, c + 1, maze, soln, n, string))
        {
            string[k++] = 'R';
            return 1;
        }

        //going up
        if(findRoute(r - 1, c, maze, soln, n, string))
        {
            string[k++] = 'U';
            return 1;
        }

        //going left
        if(findRoute(r, c - 1, maze, soln, n, string))
        {
            string[k++] = 'L';
            return 1;
        }

        //if none of the conditions are satisfied, backtrack
        soln[r][c] = 0;
        return 0;
    }
    return 0;

}

int main()
{
    
    int i, j, n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    printf("---Generated %d x %d Matrix---\n", n, n);

    int** Maze = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        Maze[i] = (int*)malloc(n * sizeof(int));
    
    int** Soln = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        Soln[i] = (int*)malloc(n * sizeof(int));

    char* string = (char*)malloc(n * n * sizeof(int));
    
    printf("Enter the maze matrix row-wise:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &Maze[i][j]);
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Soln[i][j] = 0;          //initialising solution matrix to 0
        }
    }
    if (findRoute(0, 0, Maze, Soln, n, string))
        display(Soln, n, string);
    else
        printf("No solution\n");
    return 0;
}