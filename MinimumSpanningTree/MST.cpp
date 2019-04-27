#include <iostream>

using namespace std;

int root[100];
int edge;
int vertex;

struct node
{
	int src;
	int des;
	int weight;
};

struct node tree[100];

int FindRoot(int x)
{
	if(root[x] == x)
		return x;
	else
		return FindRoot(root[x]);
}

void Union(int x,int y)
{
	int rootX = FindRoot(x);
	int rootY = FindRoot(y);

	root[rootX] = rootY;
}

void CreateTree()
{
	cin >> vertex ;
    cin >> edge ;

    for(int i = 0; i < edge; i++)
    {
        cin >> tree[i].src ;
        cin >> tree[i].des ;
        cin >> tree[i].weight ;
    }
	//SORTING TREE
    cout << endl ;
	for(int i = 0;i < edge;i++)
	{
		for(int j = 0;j < edge - i;j++)
		{
			if(tree[j].weight > tree[j+1].weight)
			{
				swap(tree[j],tree[j+1]);
			}
		}
	}

}

void Krushkal()
{
    int x,y,cost;
    int totalWeight = 0,j = 0;

	CreateTree();

	for(int i = 0;i < 100;i++)
	{
		root[i] = i;
	}

	for(int i = 0;i < edge || j < vertex - 1;i++)
	{
		x = tree[i].src ;
		y = tree[i].des ;
		cost = tree[i].weight;

		if(FindRoot(x) != FindRoot(y))
		{
		    totalWeight = totalWeight + cost;
			Union(x,y);
			j++;
			cout << x << " " ;
			cout << y << " " ;
			cout << cost << " " ;
			cout << endl ;
		}
	}

	cout << endl ;
    cout << "Minimum Cost for the Given Graph is: " << totalWeight << endl;
}

int main(void)
{
	Krushkal();
	return 0;
}

/*

7 9
1 2 100
1 3 40
1 4 100
2 3 50
3 4 70
1 5 1000
1 6 10
1 7 60
6 7 80

*/
