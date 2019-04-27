#include <bits/stdc++.h>

using namespace std;

struct Task
{
    int start;
    int finish;
};

Task task[100];

int main()
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> task[i].start >> task[i].finish;
    }

    for(int i = 0; i < num; i++)
    {
        for(int j = i+1; j < num; j++)
        {
            if(task[i].finish > task[j].finish)
            {
                swap(task[i],task[j]);
            }
        }
    }

    int countt = 1;
    int current = 0;
    Task temp[100];

    cout << endl << endl;
//    cout << task[0].start << " " << task[0].finish << endl;

    for(int i = 1; i < num; i++)
    {
        if(task[i].start >= task[current].finish)
        {
            countt++;
            current = i;
        }

    }
    cout << countt;
    cout << endl << task[0].start << " " << task[0].finish << endl;
    current = 0;

    for(int i = 1; i < num; i++)
    {
        if(task[i].start >= task[current].finish)
        {
          cout << task[i].start << " " << task[i].finish << endl;
          current = i;
        }
    }
}
