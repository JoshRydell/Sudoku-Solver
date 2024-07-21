#include <iostream>
#include <string.h>
using namespace std;

void printGrid(int grid[9][9]);

bool checkLegalEntry(int grid[9][9],  int x, int y, int entry);
void recursion(int grid[9][9], int *location);

int main()
{
    int grid[9][9];                 //INITIALISE GRID
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }


    string code;
    cout << "Enter xye\n";
    cin >> code;
    while (code != "e")
    {
        
        
        grid[(int)(code[0]-'0')][(int)(code[1]-'0')] = (int)(code[2]-'0');
        cout << "Enter xye\n";
        cin >> code;
    }  
    

    printGrid(grid);
    int loc = 0;




    recursion(grid, &loc);
    printGrid(grid);
    //delete location; 
}

void printGrid(int grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
        {
            for(int j = 0; j < 25; j++)
            {
                cout << "-";
            }
            cout << endl;
        }
        for(int j = 0; j < 9; j++)
        {
            if(j % 3 == 0) cout << "| ";
            cout << grid[j][i] << " ";
        }
        cout << "|" << endl;

    }
    for(int j = 0; j < 25; j++)
    {
        cout << "-";
    }
    cout << endl;
    cout << endl;

}

bool checkLegalEntry(int grid[9][9], int x, int y, int entry)
{   
    if(entry < 1 || entry > 9) return false;

    for(int i = 0; i < 9; i++)
    {
        if(grid[i][y] == entry|| grid[x][i] == entry)
        {
            return false;
        }

    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[x - (x % 3) + i][y - (y % 3) + j] == entry)
            {
                return false;
            }
        }
    }

    return true;


}

void recursion(int grid[9][9], int *location)
{   
    if(*location == 81) return;
    int x =*location % 9;
    int y = *location / 9;

    //printGrid(grid);
    if(grid[x][y] == 0)
    {
        for(int i = 1; i <= 9; i++)
        {

            if(checkLegalEntry(grid, x ,y ,i))
            {
                grid[x][y] = i;
                (*location)++;
                recursion(grid, location);
                if(*location == 81) return;
            }
        }

        grid[x][y] = 0;
        
    }
    else
    {
        (*location)++;
        recursion(grid, location);
        if(*location == 81) return;
    }
    (*location)--;

}