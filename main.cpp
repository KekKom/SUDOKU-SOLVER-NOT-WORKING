#include <iostream>
#include <vector>
#include <regex>

/*
https://leetcode.com/problems/sudoku-solver/
TODO: 
    1. parse input                  DONE
        1. get string input
        2. check for corectness 
        3. split
            
            input[0] -> 0,0
            input 1 -> 0,1
            ...
            intpu 9 -> 1,0
            input 10 -> 1,1


    2. check  if solved
    
    4. check  first  blank spot
        paint
    5. jump to 2.
    6. return
*/

int board[9][9];
int ofset = 0;
std::string input;
unsigned char flags = 0; //flagi: bit 0 = wygrana

void parse(std::string input){
   for (int x = 0; x < 9; x++)
    {
        //std::cout << "not crashed first loop\n";
        for (int y = 0; y < 9; y++)
        {
            board[x][y] = input[(9 * x) + y] - '0';
            //std::cout << x << "   " << y << ": " << input[(9*x)+y] << std::endl;
        }
    }
}


void checkiswon(int sudoku[9][9]){
    flags  = flags | 128;
    for (char x = 0; x < 9; x++)
    {
        for (char y = 0; y < 9; y++)
        {
            if(sudoku[x][y]==0){
                flags -= 128;
            }
        }
    }
}

void checkcell(int cell){
    
}

int main()    
{
    std::cout << "wpisz nierozwiązane sudoku do terminala: ";
    std::cin >> input;
    std::cout << std::endl;

    parse(input);
    
    while((flags & 128)==128){  //(flags & 10000000)
        checkiswon(board);
        for (char i = 0; i < 9; i++)
        {
            for (char j = 0; j < 9; j++)
            {
                checkcell(board[i][j]);
            }
            
        }
        
        

    } 
    


    return 0;

}