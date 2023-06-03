#include <iostream>
using namespace std;

class heap
{
    int *a;
    int n;

    public:
        heap()
        {
            cout<<"Enter number of stduents: ";
            cin>>n;
            a=new int[n];
            cout<<"Enter students marks: ";
            for (int i=0; i<n; i++)
            {
                cin>>a[i];
            }
        }

        void heap_sort()
        {
            build_max_heap();

            int temp;
            for(int i=n-1; i>=0; i--)
            {
                temp=a[i];
                a[i]=a[0];
                a[0]=temp;
                max_heapify(0, i);
            }
        }

        void build_max_heap()
        {
            for(int k=n/2-1; k>=0; k--)
                max_heapify(k, n);
        }

        void max_heapify(int i, int size)
        {
            int l=2*i+1;
            int r=2*i+2;

            int largest=i;

            if(l<size && a[l]>a[largest])
                largest=l;
            if(r<size && a[r]>a[largest])
                largest=r;

            int temp;
            if(largest!=i)
            {
                temp=a[largest];
                a[largest]=a[i];
                a[i]=temp;
                max_heapify(largest, size);
            }
        }

        void display()
        {
            for(int i=0; i<n; i++)
                cout<<a[i]<<"\t";
        }
};

int main()
{
    heap h;
    h.heap_sort();
    h.display();
}
