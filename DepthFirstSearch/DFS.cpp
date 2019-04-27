#include<iostream>
#include<stack>

using namespace std;

int edge;
int node;
int path;
int adjMat[50][50];

stack <int> st;

struct nodeProperty
{
    int starting;
    int ending;
    bool visit = false;
};

nodeProperty graph[100];

void DFS(int c)
{
    graph[c].visit = true;
    graph[c].starting = path++;

    for(int i = 0;i < node;i++ )
    {
        if(adjMat[c][i] == 1 && graph[i].visit == false)
        {
            DFS(i);
        }
    }
    graph[c].ending = path++;
    st.push(c);

}

int main(void)
{
    int n1;
    int n2;

    cout << "Enter the Number of Edges: ";
    cin >> edge;
    cout << "Enter the Number of Vertex: ";
    cin >> node;

    cout << "Enter the Edges: "<< endl;
    for(int i = 0;i < edge;i++ )
    {
       cin >> n1 >> n2;
       adjMat[n1][n2] = 1;
       adjMat[n2][n1] = 1;
    }

    DFS(0);
    cout << "\nGraph:\n";
    while(!st.empty())
    {
        cout << st.top() << "\t";
        st.pop();
    }
}














