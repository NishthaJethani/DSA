#include <iostream>
using namespace std;
#define n 6

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
	string que[10];
	public:

		queue()
		{
			f=r=-1;
		}
		
		bool qFull()
		{
			if(r==10-1)
				return true;
			else
				return false;
		}
		
		bool qEmpty()
		{
			if(f==-1 && r==-1)
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
				que[r++]=city;
			}
		}
		
		string deleteQ()
		{
			string city;
			if(qEmpty())
				cout<<"Queue is empty";
			else if (f==r)
			{
				city=que[f];
				r=f=-1;
			}
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
	city *network[n];
	queue q;
	string visited[n];
	int count=0;

	public:
		graph()
		{
			for(int i=0; i<n; i++)
				network[i]=NULL;
			createNetwork();
		}
		
		void createNetwork()
		{
			int total_flights, time;
			string city1, city2;
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
			q.insertQ(source);
			
			city *head;
			string visited_city;

			while(!q.qEmpty())
			{
				visited_city=q.deleteQ();
				cout<<visited_city<<"\t";
				visited[count]=visited_city;
				count++;

				int index=getindex(visited_city);
				head=network[index];

				while(head->next!=NULL)
				{
					head=head->next;
					if((!q.inQueue(head->name)) && (!isVisited(head->name)))
						q.insertQ(head->name);
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
	int choice;

	graph g;
	g.display();
	cout<<"BFS: ";
	g.bfs("a");
	
}
