#include <iostream>
using namespace std;

/*
### Description:

The `Draw` function prints a Tic-Tac-Toe board to the console.
It takes a 2D array `board[3][3]` containing the board's state (either 'X', 'O', or a space).

- **Horizontal Lines:** For even rows (i = 0, 2, 4, 6), it prints a line of dashes (`-`).
- **Board Rows:** For odd rows (i = 1, 3, 5), 
it prints the game grid with vertical separators (`|`) and the corresponding values from `board`.

### Output:
The function outputs the Tic-Tac-Toe board with alternating grid lines and symbols.
*/
void Draw(char board[3][3])
{
    for (int i = 0; i < 7; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << " - ";
            }
        }

        else
        {
            for (int j = 0; j <= 15; j++)
            {
                if (j % 5 == 0)
                {
                    cout << "| ";
                    if (i / 2 < 3 && j / 5 < 3)
                        cout << " " << board[i / 2][j / 5] << " ";
                }

                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

/*
### Description:

The `Check` function updates the Tic-Tac-Toe board based on the user's move. It takes the following parameters:
- `board[3][3]`: The Tic-Tac-Toe board.
- `x`, `y`: The coordinates of the cell where the player wants to place their mark.
- `X`: A boolean that determines whether the current player is 'X' (`true`) or 'O' (`false`).

The function performs the following steps:
- **Check if the cell is empty:** If the cell at `board[x][y]` is empty (' '), it places 'X' or 'O' in the cell based on the value of `X`.
- **Handle occupied cells:** If the cell is already occupied, it prints a message prompting the user to choose a different cell.
*/
void Check(char board[3][3], int x, int y, bool X)
{

    if (board[x][y] == ' ')
    {
        if (X)
            board[x][y] = 'X';
        else
            board[x][y] = 'O';
    }

    else
    {
        cout << "Cell already occupied. Please enter again." << endl;
    }
}

/*
### Description:

The `Win` function checks if a player has won the Tic-Tac-Toe game. It evaluates the current state of the board and returns `true` if a player has won, and `false` otherwise. The function performs the following checks:

1. **Diagonal Wins:**
   - It checks the main diagonal (from top-left to bottom-right) and the anti-diagonal (from top-right to bottom-left). If all three cells in a diagonal contain the same non-empty symbol ('X' or 'O'), that player is declared the winner.

2. **Row Wins:**
   - It checks each of the three rows. If all cells in a row contain the same non-empty symbol, the player is declared the winner.

3. **Column Wins:**
   - It checks each of the three columns. If all cells in a column contain the same non-empty symbol, the player is declared the winner.

If a player wins, a message is printed announcing the winner, and the function returns `true`. If no winner is found, the function returns `false`.
*/
bool Win(char board[3][3])
{

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        cout << "Player " << board[0][0] << " wins." << endl;
        return true;
    }

    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
    {
        cout << "Player " << board[1][1] << " wins." << endl;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            cout << "Player " << board[i][1] << " wins." << endl;
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            cout << "Player " << board[1][i] << " wins." << endl;
            return true;
        }
    }

    return false;
}

/*
### Description:

The `main` function runs a Tic-Tac-Toe game. It initializes a 3x3 board, alternates turns between players ('X' and 'O'), and checks for a winner or a draw.

- The board is initialized with empty spaces.
- Players input row and column indices for their moves, which are validated.
- The `Check` function places the player's mark, and the `Draw` function updates the board display.
- The `Win` function checks for a winner after each move.
- The game ends when a player wins or all cells are filled (draw).
*/
int main()
{

    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }

    Draw(board);

    int iter = 0;
    bool X = true;

    while (iter < 9)
    {
        int x, y;
        cout << "Enter the row index: ";
        cin >> x;
        cout << "Enter the Column index: ";
        cin >> y;

        if ((x < 0 || x > 2) || (y < 0 || y > 2))
        {
            cout << "Invalid input, Please enter in range(0,2)." << endl;
            continue;
        }

        Check(board, x, y, X);
        Draw(board);

        X = !X;
        iter++;

        if (Win(board))
            return 0;
    }

    cout << "The match ended in a draw." << endl;
    return 0;
}

// Test the Tic-Tac-Toe game