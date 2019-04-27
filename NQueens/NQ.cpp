#include <bits/stdc++.h>

using namespace std;

int totalQueen;
int Array[100];

void Initialization()
{
    cout << "Number of Queens : " << endl;
    cin >> totalQueen;
    cout << endl << endl ;
}

bool Safe(int position)
{
    for(int i = 1; i < position; i++)
    {
        if(Array[i] == Array[position] || fabs(Array[i] - Array[position]) == fabs(i-position))
            return false;
    }

    return true;
}

void Print()
{
    for(int i = 1; i <= totalQueen; i++)
    {
        for(int j = 1; j <=totalQueen; j++)
        {
            if(Array[i] == j)
                cout << "Q\t";
            else cout << "*\t";
        }

        cout << endl;
    }
}

void PlaceQueens()
{
    int currentQueen = 1;
    Array[currentQueen] = 0;

    while(currentQueen != 0)
    {
        do
        {
            Array[currentQueen]++;
        }
        while(Array[currentQueen] <= totalQueen && !Safe(currentQueen));

        if(Array[currentQueen] <= totalQueen)
        {
            if(currentQueen == totalQueen)
            {
                Print();
                return;

            }
            else
            {
                currentQueen++;
                Array[currentQueen] = 0;
            }
        }

        else
        {
            currentQueen--;
        }
    }
}


int main()
{
    Initialization();
    PlaceQueens();

}

