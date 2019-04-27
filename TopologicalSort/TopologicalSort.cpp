#include<iostream>
#include<stack>

using namespace std;

int edge;
int vertex;
int adjMat[50][50];

stack <int> st;

struct Node
{
    bool visit;
    string item;
};
Node graph[100];

void DFS(int n)
{
    graph[n].visit = true;
    for(int i = 0;i < vertex;i++ )
    {
        if(adjMat[n][i] == 1 && graph[i].visit == false)
        {
            DFS(i);
        }
    }

    st.push(n);
}

void DfS_Util()
{
    for(int i = 0;i < vertex;i++ )
    {
       if(graph[i].visit == false)
        {
            DFS(i);
        }
    }
}


int main(void)
{
    int n1;
    int n2;

    cout << "Enter the Number of Edges: ";
    cin >> edge;
    cout << "Enter the Number of Vertex: ";
    cin >> vertex;

    cout << "Enter the Edges: "<< endl;
    for(int i = 0;i < edge;i++ )
    {
       cin >> n1 >> n2;
       adjMat[n1][n2] = 1;
    }

    DfS_Util();

    cout <<"\nGraph:\n" ;
    while(!st.empty())
    {
        cout << st.top() << " " ;
        st.pop();
    }

}







