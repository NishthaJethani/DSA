#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    int **adjacency;
    int n;
    bool *visited;

    public:
        graph()
        {
            cout<<"Enter number of nodes: ";
            cin>>n;
            adjacency=new int*[n];
            for(int i=0; i<n; i++)
                adjacency[i]=new int[n];

            for(int i=0; i<n; i++)
            {
                for(int j=i; j<n; j++)
                {
                    cout<<"Enter cost of edge between "<<i<<" and "<<j<<": ";
                    cin>>adjacency[i][j];
                    adjacency[j][i]=adjacency[i][j];
                }
            }

            visited=new bool[n];
            for(int i=0; i<n; i++)
            {
                visited[i]=false;
            }
        }

        void display(string prompt)
        {
            cout<<prompt<<endl;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    cout<<adjacency[i][j]<<" ";
                cout<<endl;
            }
        }

        void prims()
        {
            int edges=0;
            int min;
            int x, y;
            int cost=0;
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
                            if(!visited[j] && adjacency[i][j])
                            {
                                if(adjacency[i][j]<min)
                                {
                                    x=i;
                                    y=j;
                                    min=adjacency[i][j];
                                }
                            }
                        }
                    }
                }
                cout<<x<<"--->"<<y<<": "<<min<<endl;
                cost+=min;
                visited[y]=true;
                edges++;
            }
            cout<<"Minimum Cost: "<<cost;
        }

};

int main()
{
    graph g;
    g.display("Entered Matrix:");
    g.prims();
}
