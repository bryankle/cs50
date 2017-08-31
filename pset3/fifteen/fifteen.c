/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();
    printf("WELCOME TO GAME OF dsadasdas\n");
    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    int total = ( d * d ) - 1;
    while(total > 0)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = total--;
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != 0)
            {
                printf("%2i", board[i][j]);
            }
            else
            {
                printf("%2s", "_");
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // TODO
    // Find location of 0 and return coordinates i and j
    int empty[2]; // Initialize array to record location of empty space
    int tileLoc[2]; // Initialize array to record location of requested tile
    // Loop over every value inside the board to assign location of empty space and selected tile
    // i travels down
    // j travels across
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                empty[0] = i;
                empty[1] = j;
            }
            if (board[i][j] == tile)
            {
                tileLoc[0] = i;
                tileLoc[1] = j;
            }
        }
    }
    // Prints current coordinates of empty
    // printf("%d\n", empty[0]);
    // printf("%d\n", empty[1]);
    // Check user selected tile up, down, left, right for empty slot, if true, the proceed, otherwise, request new tile from user
    // printf("%s%d\n", "tile: ", tile);
    // printf("%s%d\n", "tile i: ", tileLoc[0]);
    // printf("%s%d\n", "tile j: ", tileLoc[1]);
    // // Checks the board value up, left, down, right of user selected value if empty space is found
    if (
        // Right
        (tileLoc[0] == empty[0] &&
        tileLoc[1] + 1 == empty[1]) ||
        // Down
        (tileLoc[0] + 1 == empty[0] &&
        tileLoc[1] == empty[1]) ||
        // Up
        (tileLoc[0] - 1 == empty[0] &&
        tileLoc[1] == empty[1]) ||
        // Left
        (tileLoc[0] == empty[0] &&
        tileLoc[1] - 1 == empty[1])
        )
    {
        // printf("%s\n", "Empty space nearby");
        // Initialize temporary placeholder array to perform switching
        // int temp[2];
        // temp[0] = tileLoc[0];
        // temp[1] = tileLoc[1];
        // Switch empty value into selected value
        board[empty[0]][empty[1]] = tile;
        board[tileLoc[0]][tileLoc[1]] = 0;
        return true;

    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // Quantity of non-zero numbers
    int total = 0;
    // Loop through array to check order
    // Loop down column
    while (total < ( d * d ) - 1)
    {
        bool matched = true;
        // Loop down column
        for (int i = 0; i < d; i++)
        {
            // Loop through row
            for (int j = 0; j < d; j++)
            {
                // If value is in correct order, proceed to next
                if (board[i][j] == total) {
                    total++;
                }
                // If value does not match expected correct value, return false
                else
                {
                    matched = false;
                }
            }
        }
        return matched;
    }
    // If entire board is successfully traversed, then return true
    return false;
}
