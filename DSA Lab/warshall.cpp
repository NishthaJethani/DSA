#include <iostream>
using namespace std;

class graph
{
    int adjacency[4][4];
    public:
        graph()
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    cout<<"Enter cost of edge between "<<i<<" and "<<j<<".\n";
                    cin>>adjacency[i][j];
                }
            }
        }

        void warshall()
        {
            for(int k=0; k<4; k++)
            {
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(adjacency[i][k]+adjacency[k][j]<adjacency[i][j])
                            adjacency[i][j]=adjacency[i][k]+adjacency[k][j];
                    }
                }
            }
        }

        void display(string prompt)
        {
            cout<<prompt;
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    cout<<adjacency[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    graph g;
    g.display("Matrix Entered:\n");
    g.warshall();
    g.display("Final Matrix:\n");
}