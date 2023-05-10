#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 9

class graph
{
    int G[n][n]={
	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 1, 6},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0},
	};

    int visited[n];

    public:
        
        graph()
        {
            for (int i=0; i<n; i++)
            {
                visited[i]=false;
            }
        }

        void prims()
        {
            int min, x, y;
            int edges=0, cost=0;
            visited[0]=true;
            while(edges<n-1)
            {
                min=INT_MAX;
                for(int i=0; i<n; i++)
                {
                    if(visited[i])
                    {
                        for(int j=0; j<n; j++)
                        {
                            if(!visited[j] && G[i][j])
                            {
                                if(min>G[i][j])
                                {
                                    min=G[i][j];
                                    x=i;
                                    y=j;
                                }
                            }
                        }
                    }
                }
                cout<<x<<" --> "<<y<<": "<<G[x][y]<<endl;
                cost+=G[x][y];
                visited[y]=true;
                edges++;
            }
            cout<<"Minimum Cost: "<<cost;
        }
};

int main()
{
	graph g;
    g.prims();
}