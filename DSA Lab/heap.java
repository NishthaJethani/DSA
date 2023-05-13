public class heap<T extends Comparable<T>>
{
    T data[];
    int length;

    public heap(T[] data)
    { 
        this.data=data;
        this.length=data.length;
    }
    
    public void heapsort()
    {
        bulid_max_heap();
        T temp;
        for(int i=length-1; i>=0; i--)
        {
            temp=data[0];
            data[0]=data[i];
            data[i]=temp;
            max_heapify(0, i);
        }
    }

    public void bulid_max_heap()
    {
        for (int k=length/2-1; k>=0; k--)
        {
            max_heapify(k, length);
        }
    }

    public void max_heapify(int i, int n)
    {
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        if(l<n &&  data[l].compareTo(data[largest])>0)
            largest=l;
        if(r<n && data[r].compareTo(data[largest])>0)
            largest=r;
        T temp;
        if(largest!=i)
        {
            temp=data[i];
            data[i]=data[largest];
            data[largest]=temp;
            max_heapify(largest, n);
        }
    }

    public void display()
    {
        for(int i=0; i<length; i++)
        {
            System.out.print(data[i]+"\t");
        }
    }

    public static void main(String []args)
    {
        Integer[] data1 = {7, 3, 2, 5, 6, 10, 9, 8, 1};
        heap h1 = new heap<Integer>(data1);
        System.out.println("\nGiven Integer Data:");
        h1.display();
        h1.heapsort();
        System.out.println("\nSorted:");
        h1.display();

        String[] data2 = {"lalu", "vivek", "kia", "priya", "jui"};
        heap h2 = new heap<String>(data2);
        System.out.println("\nGiven String Data:");
        h2.display();
        h2.heapsort();
        System.out.println("\nSorted:");
        h2.display();

        Character[] data3 = {'b', 'a', 'z', 'v', 'T'};
        heap h3 = new heap<Character>(data3);
        System.out.println("\nGiven Character Data:");
        h3.display();
        h3.heapsort();
        System.out.println("\nSorted:");
        h3.display();

        Double[] data4 = {1.2, 4.3, 6.7, 7.1, 3.9};
        heap h4 = new heap<Double>(data4);
        System.out.println("\nGiven Double Data:");
        h4.display();
        h4.heapsort();
        System.out.println("\nSorted:");
        h4.display(); 
    }
}