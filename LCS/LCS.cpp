#include<bits/stdc++.h>

using namespace std;

int main()
{
    char array_1[] = "ABCBEM";
    char array_2[] = "BEMAC";

    int first = strlen(array_1);
    int second = strlen(array_2);

    int length[first+1][second+1];

    for(int i = 0; i <= first; i++)
    {
        for(int j = 0; j <= second; j++)
        {
            if(i == 0 || j == 0)
                length[i][j] = 0;
            else if(array_1[i-1] == array_2[j-1])
            {
                length[i][j] = length[i-1][j-1] + 1;
            }
            else
                length[i][j] = max(length[i][j-1],length[i-1][j]);

        }

    }

    cout << length[first][second] << endl ;

    int index = length[first][second];
    char res[index+1];
    res[index] = '\0';

    int i = first;
    int j = second;

    while(i > 0 && j > 0)
    {
        if(array_1[i-1] == array_2[j-1])
        {
            cout << array_1[i-1];
            res[index-1] = array_1[i-1];
            index--;
            i--;
            j--;
        }

        else if(length[i-1][j] > length[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }

    }

    cout << " =======> "  << res << endl;

}
