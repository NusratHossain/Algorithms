#include<bits/stdc++.h>
#define MAX 1000243

using namespace std;

typedef pair <int,int> PI;

int vertex;
int edge;
int parent[100];
int dis[100];

vector < PI > graph[100];

void InputGraph()
{
    for(int i = 0; i < 100; i++)
    {
        parent[i] = i;
        dis[i] = MAX;
    }
    cin >> vertex >> edge ;
    for(int i = 0; i < edge; i++)
    {
        int u;
        int v;
        int w;

        cin >> u >> v >> w ;

        graph[u].push_back(make_pair(w,v));
        graph[v].push_back(make_pair(w,u));
    }

}
bool Relax(int u,int v,int w)
{
    if(dis[u] + w  < dis[v])
    {
        dis[v] = dis[u] + w;
        return true;
    }
    else
        return false;
}


void Dijkstra()
{
    InputGraph();
    priority_queue <PI,  vector <PI>, greater <PI> > Q;
    PI P;
    int minCost = 0;
    dis[0] = 0;
    Q.push(make_pair(0,0));

    for(int i = 0; i < vertex; i++)
    {
        P = Q.top();
        Q.pop();

        int u = P.second;

        for(int i = 0; i < graph[u].size(); i++)
        {
            int w = graph[u][i].first;
            int v = graph[u][i].second;

            if(Relax(u,v,w))
            {
                parent[v] = u;
                Q.push(make_pair(w, v));
            }
        }

    }

    cout << endl << "Parent of each vertex :" << endl ;
    for(int i = 0; i < vertex; i++)
    {
        cout << i << " --> " << parent[i] << endl;
    }

}

int main()
{
    Dijkstra();
    return 0;
}


/*

8 15
0 1 2
0 2 5
0 5 20
1 4 22
1 3 8
2 6 4
5 2 9
5 7 1
4 7 4
3 4 3
3 2 6
6 5 4
6 7 12
7 3 11
7 4 5

*/
