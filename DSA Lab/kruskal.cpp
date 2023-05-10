#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30

class graph
{
    pair<int, pair<int, int>> G[MAX];
    int edges;
    int id[MAX];

    public:
        
        graph()
        {
            cout<<"Enter number of edges: ";
            cin>>edges;
            int x, y, weight;
            cout<<"Enter values for x, y and weight of each edge:\n";
            for(int i=0; i<edges; i++)
            {
                cin>>x>>y>>weight;
                G[i]=make_pair(weight, make_pair(x,y));
            }

            for (int i=0; i<MAX; i++)
                id[i]=i;
        }

        void kruskal()
        {
            sort(G, G+edges);

            int cost=0;
            int x, y, weight;

            for(int i=0; i<edges; i++)
            {
                x=G[i].second.first;
                y=G[i].second.second;
                weight=G[i].first;
                if(root(x)!=root(y))
                {
                    cost+=weight;
                    cout<<x<<" --> "<<y<<": "<<weight<<endl;
                    make_union(x, y);
                }
            }
            cout<<"Minimum Cost: "<<cost;
        }

        int root(int x)
        {
            while(id[x]!=x)
            {
                id[x]=id[id[x]];
                x=id[x];
            }
            return x;
        }

        void make_union(int x, int y)
        {
            id[root(x)]=id[root(y)];
        }
};

int main()
{
	graph g;
    g.kruskal();
}