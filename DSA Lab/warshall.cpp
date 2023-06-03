#include <iostream>
using namespace std;

class graph
{
    int **adjacency;
    int n;

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
                for(int j=0; j<n; j++)
                {
                    cout<<"Enter cost of edge between "<<i<<" and "<<j<<": ";
                    cin>>adjacency[i][j];
                }
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

        void warshall()
        {
            for(int k=0; k<n; k++)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(adjacency[i][k]+adjacency[k][j]<adjacency[i][j])
                            adjacency[i][j]=adjacency[i][k]+adjacency[k][j];
                    }
                }
            }
        }

};

int main()
{
    graph g;
    g.display("Entered Matrix:");
    g.warshall();
    g.display("Final Matrix:");
}
