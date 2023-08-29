// LetterCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



int main()
{
    char letterCounter[5][6] = {
            {'D', 'E', 'Y', 'H', 'A','D'},
            {'C', 'B', 'Z', 'Y', 'J', 'K'},
            {'D', 'B', 'C', 'A', 'M', 'N'},
            {'F', 'G', 'G', 'R', 'S', 'R'},
            {'V', 'X', 'H', 'A', 'S', 'S'}
    };
    
        cout << "Hello World!\n";
        letterCounter(letterCounter, 'D');
}

int letterCounter(char *grid, char fletter)
{
    cout << "This: " << grid[1] << " " << fletter << endl;

    return 0;
}
