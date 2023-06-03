#include<iostream>
using namespace std;

class city
{
	string name;
	int cost;
	city * next;

	public:
	
		city()
		{
			name="";
			cost=0;
			next=NULL;
		}

		city(string name, int cost)
		{
			this->name=name;
			this->cost=cost;
			next=NULL;
		}

		friend class graph;
};


class queue
{
	int f, r;
	string *que;
    int n;


	public:
	
        queue()
        {

        }

		queue(int num)
		{
            this->n=num;
            que=new string[n];
			f=r=-1;
		}
	
		bool qFull()
		{
			if(r==n-1)
				return true;
			else
				return false;
		}
	
		bool qEmpty()
		{
			if(f==-1 || f>r)
				return true;
			else
				return false;
		}
	
		void insertQ(string city)
		{
			if(qFull())
				cout<<"Queue is full";
			else if (f==-1 && r==-1)
			{
				f=r=0;
				que[r]=city;
			}
			else
			{
				r++;
				que[r]=city;
			}
		}
	
		string deleteQ()
		{
			string city;
			if(qEmpty())
				return "Queue is empty";		
			else
			{
				city=que[f];
				f++;
			}
			return city;
		}
	
		bool inQueue(string city)
		{
			if(qEmpty())
				return 0;
			else
			{
				for(int i=0; i<n; i++)
				{
					if(que[i]==city)
						return 1;
				}
				return 0;
			}
		}			
	
	friend class graph;
};

class graph
{
    city **network;
    queue que;
    string *visited;
    int count=0;
    int n;

    public:
        graph()
        {
            cout<<"Enter number of cities: ";
            cin>>n;
            network=new city*[n];
            que=queue(n);
            visited=new string[n];

            for(int i=0; i<n; i++)
                network[i]=NULL;

            createnetwork();
        }
        
        void createnetwork()
        {
            string city1, city2;
            int total_flights, time;
            cout<<"Enter cities to connect:\n";
			for(int i=0; i<n; i++)
			{
				network[i]= new city();
				cout<<"Enter name of city "<<i+1<<": ";
				cin>>network[i]->name;
			}

            cout<<"Enter total number of flights in network: ";
			cin>>total_flights;
			for(int i=0; i<total_flights; i++)
			{
				cout<<"Enter Source: ";
				cin>>city1;
				cout<<"Enter Destination: ";
				cin>>city2;
				cout<<"Enter time of flight: ";
				cin>>time;
				insert(city1, city2, time);
				insert(city2, city1, time);
			}
        }

        void insert(string city1, string city2, int time)
        {
            city *dest = new city(city2, time);

			int index=getindex(city1);
			city *source=network[index];
			
			while(source->next!=NULL)
				source=source->next;
			source->next=dest;
        }

        int getindex(string city)
		{
			for(int i=0; i<n; i++)
			{
				if(network[i]->name==city)
					return i;
			}
			return -1;
		}

        void display()
		{
			for(int i=0; i<n; i++)
			{
				city *temp=network[i];
				while(temp!=NULL)
				{
					cout<<temp->name<<" ("<<temp->cost<<") -> ";
					temp=temp->next;
				}
				cout<<"NULL"<<endl;
			}
        }

        void bfs(string source)
		{
			que.insertQ(source);	
			city *head;
			string visited_city;

			while(!que.qEmpty())
			{
				visited_city=que.deleteQ();
				cout<<visited_city<<"\t";
				visited[count]=visited_city;
				count++;

				int index=getindex(visited_city);
				head=network[index];
				while(head->next!=NULL)
				{
					head=head->next;
					if((!que.inQueue(head->name)) && (!isVisited(head->name)))
						que.insertQ(head->name);
				}
			}
		}

		bool isVisited(string city)
		{
			for(int i=0; i<count; i++)
			{
				if(visited[i]==city)
					return true;
			}
			return false;
		}
};

int main()
{
	graph g;
	g.display();
	cout<<"BFS: ";
	g.bfs("a");	
}
