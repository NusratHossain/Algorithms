#include <bits/stdc++.h>
#define MAX 1000909

using namespace std;

struct node
{
    int u;
    int v;
    int w;
};

struct node ver[100] ;

int dis[100];
int vertex;
int edge;
int parent[100];
bool display = true;

void CreateGraph()
{
    for(int i = 0; i < 100; i++)
    {
        parent[i] = i;
        dis[i] = MAX;
    }

    cin >> vertex >> edge ;

    for( int i = 0; i < edge; i++)
    {
        int src;
        int des;
        int weight;

        cin >> src >> des >> weight ;

        ver[i].u = src;
        ver[i].v = des;
        ver[i].w = weight;

    }

}

bool Relax(int u,int v,int w)
{
    if(dis[u] + w < dis[v])
    {
        dis[v] = dis[u] + w;
        return true;
    }
    else
        return false;
}

void BellmanFord(int src)
{
    CreateGraph();

    dis[src] = 0;
    for(int i = 0; i < vertex - 1; i++)
    {
        for(int j = 0; j < edge; j++)
        {
            if(Relax(ver[i].u,ver[i].v,ver[i].w))
            {
                int v = ver[i].v;
                int u = ver[i].u;
                parent[v] = u;
            }
        }
    }
    for(int i = 0; i < edge; i++)
    {
        if(Relax(ver[i].u,ver[i].v,ver[i].w))
        {
            cout << endl << "Shortest path cannot be calculated due to having a negative cycle!" << endl ;
            display = false;
            return ;

        }

    }
    if(display)
    {
        int sum = 0;
        cout << endl << "Parent of each vertex :" << endl ;
        for(int i = 0; i < 4; i++)
        {
            sum = sum + dis[i];
            cout << i << " --> " << parent[i] << endl;
        }
        cout << endl << "Path distance : " << sum << endl ;
    }
}

int main()
{
    BellmanFord(0);
    return 0;
}
/*
4 5
0 1 10
1 2 20
2 3 30
3 0 70
1 3 60
*/
