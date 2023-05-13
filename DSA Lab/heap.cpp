#include <iostream>
using namespace std;

class heap
{
    int *a;

    public:

        void accept(int n)
        {
            
            a = new int[n];
            cout<<"Enter the marks of students:\n";
            for(int i=0; i<n; i++)
            {
                cin>>a[i];
            }
        }

        void heapsort(int n)
        {
            bulid_max_heap(n);
            int temp;
            for(int i=n-1; i>=0; i--)
            {
                temp=a[0];
                a[0]=a[i];
                a[i]=temp;
                max_heapify(0, i);
            }
        }

        void bulid_max_heap(int n)
        {
            for (int k=n/2-1; k>=0; k--)
            {
                max_heapify(k, n);
            }
        }

        void max_heapify(int i, int n)
        {
            int l=2*i+1;
            int r=2*i+2;
            int largest=i;
            if(l<n &&  a[l]>a[largest])
                largest=l;
            if(r<n && a[r]>a[largest])
                largest=r;
            int temp;
            if(largest!=i)
            {
                temp=a[i];
                a[i]=a[largest];
                a[largest]=temp;
                max_heapify(largest, n);
            }
        }

        void display(int n)
        {
            cout<<"Sorted Marks:\n";
            for(int i=0; i<n; i++)
            {
                cout<<a[i]<<"\t";
            }
        }
};

int main()
{
    heap h;
    int n;
    cout<<"Enter number of students:\n";
    cin>>n;
    h.accept(n);
    h.heapsort(n);
    h.display(n);
}