#include <iostream>
#include <fstream>
#include <math.h> 

#define N 9
#define UNASSIGNED 0

using namespace std;

class Board
{
    private:
    
    //three different boards
    int board[N][N]; //original board that the user chooses
    int solution[N][N]; //solution the program computes
    int guess[N][N]; //the users attempt at solving the puzzle
    
    //difficulty that user chooses
    int difficulty;
    
    //score of the round
    int score = 0;
    
    //defined file names
    const string EASYNAME = "easyfile.txt";
    const string MEDNAME = "medfile.txt";
    const string HARDNAME = "hardfile.txt";
    
    //method to assign the original board
    void setBoard(int difficulty)
    {
        string fileName;
        
        int d = difficulty;
        
        //changes file name depending on the difficulty
        switch(d)
        {
            case 0:
                fileName = EASYNAME;
                break;
                
            case 1:
                fileName = MEDNAME;
                break;
                
            case 2:
                fileName = HARDNAME;
                break;
                
            default:
                //happens if they choose a difficulty that does not exist
                cout << "Invalid difficuly level.";
                exit(0);
        }
        
        //fills the board with numbers
        fillBoard(board, fileName);
        //fills solution board with board numbers to start out with
        fillBoard(solution, fileName);
    }
    
    //fills the board with the given numbers in said file
    void fillBoard(int b[N][N], string fileName)
    {
        ifstream inFile;
        inFile.open(fileName);
        
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                inFile >> b[r][c];
            }
        }
        
        inFile.close();
    }
    
    //displays a certain board to the user
    void displayBoard(int b[N][N])
    {
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cout << b[r][c] << " ";
            }
            
            cout << endl;
        }
    }
    
    //determines if there are any unassigned locations
    bool findUnassignedLocation(int& row, int& col)
    {
        for(row = 0; row < N; row++)
        {
            for(col = 0; col < N; col++)
            {
                if(solution[row][col] == UNASSIGNED)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    //checks if said number is in the row given
    bool usedInRow(int r, int num)
    {
        
        for(int col = 0; col < N; col++)
        {
            if(solution[r][col] == num)
            {
                return true;
            }
        }
        
        return false;
    }
    
    //checks if said number is in the column given
    bool usedInCol(int c, int num)
    {
        for(int row = 0; row < N; row++)
        {
            if(solution[row][c] == num)
            {
                return true;
            }
        }
        
        return false;
    }
    
    //checks if said number is in the box of the puzzle
    bool usedInBox(int boxStartRow, int boxStartCol, int num)
    {
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                if(solution[row+boxStartRow][col+boxStartCol] == num)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    //checks if the number is valid in that row and column and box
    bool isSafe(int r, int c, int num)
    {
        return !usedInRow(r, num) &&
               !usedInCol(c, num) &&
               !usedInBox(r - r%3, c - c%3, num);
    }
    
    //compares the solution the program came up with and the 
    bool compareResults()
    {
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                if(solution[r][c] == guess[r][c])
                {
                    score++;
                }
            }
        }
        
        return score == N*N;
    }
    
    //recursive function to find the solution of the board
    bool solve()
    {
        
        int row, col;
        
        //if all there 
        if(!findUnassignedLocation(row, col))
        {
            return true;
        }
        
        //trys different numbers in the cell until it makes sense
        for(int num = 1; num <= N; num++)
        {
            if(isSafe(row, col, num))
            {
                solution[row][col] = num;
                
                if(solve())
                {
                    return true;
                }
                
                solution[row][col] = UNASSIGNED;
            }
        }
        
        return false;
    }
    
    public:
    
    //constructor that sets the default values for the program
    Board()
    {
        string fN;
        
        cout << "Enter a difficulty:\n\t{0} Easy\n\t{1} Medium\n\t{2} Hard" << endl;
        cin >> difficulty;
        setBoard(difficulty);
        
        cout << endl << "Board: " << endl;
        displayBoard(board);
        
        cout << endl << "Enter file name of your solution: ";
        cin >> fN;
        cout << endl;
        fillBoard(guess, fN);
    }

    //executes the game
    void Play()
    {
        //checks if solved
        if(solve())
        {
            //compares the solution board with the guess board
            if(compareResults())
            {
                cout << "Correct!" << endl;
                displayBoard(guess);
                cout << endl << "Your score is: " << score << endl;
            }
            else
            {
                cout << "Incorrect!" << endl;
                cout << "Correct answer is:" << endl;
                displayBoard(solution);
                cout << endl << "Your score is: " << score << endl;
            }
        }
        else
        {
            cout << "The solution for this board does not exist.";
        }
    }
};

int main()
{
    int play = 0;
    cout << "Do you want to play?\n\t{0} no\n\t{1} yes\n";
    cin >> play;
    
    //continues playing as long as the user wants to
    while(play == 1)
    {
        Board b;
        b.Play();
        
        cout << "Do you want to play again?\n\t{0} no\n\t{1} yes\n";
        cin >> play;
    }
    
    return 0;
}
