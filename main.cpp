#include <iostream>
#include <vector>
//#include <stdio.h>
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
            input 9 -> 1,0
            input 10 -> 1,1


    2. check  if solved
    
    4. check  n-th  blank spot
        paint
    5. repeat 4.
    5,5. at the end of the board jump to 2.
    6. return
*/

int board[9][9];
int missings[9][9][9];
int row[9], square[9];
int ofset = 0;
std::string input;
unsigned char flags,sum = 0; //flagi: bit 0 = wygrana




void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

void checkcell(int board[9][9], char x, char y){
    sum = 0;
    for (char i = 0; i < 9; i++)
    {
        row[i] = board[x][i];
    }
    int n = sizeof(row)/sizeof(row[0]);

    quickSort(row,0,n);  //sort

    //missings w rzędzie
    for (char i = 0; i < 8; i++)
    {
        //jeżeli row[i] != row[i] -1
        if (row[i] != row[i+1]-1)
        {   
            missings[x][y][i] = row[i]+1;
            sum++;
        }
        
    }
    
    //sprawdź czy element z missingów jest możliwy:
    for (int i = 0; i < sum; i++)
    {

        //w kolumnie i ustawia na 0
        for (int j = 0; j < 9; j++)
        {
            if (missings[x][y][i] == board[x][j])
            {
                missings[x][y][i] = 0;
            }
            
        }

        
        
    }
    

    //printf("&d", row);
    std::cout << "here";
    
}

int main()    
{
    std::cout << "wpisz nierozwiązane sudoku do terminala: ";
    std::cin >> input;
    std::cout << std::endl;

    parse(input);
    
    while(true){  //(flags & 10000000)
        checkiswon(board);
        //printf("test");
        for (char i = 0; i < 9; i++)
        {
            //std::cout << "here";
            for (char j = 0; j < 9; j++)
            {
                checkcell(board,i,j);
            }
            
        }
        
        

    } 
    


    return 0;

}