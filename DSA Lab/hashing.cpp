#include <iostream>
using namespace std;
#define size 20

class hashentry
{
    int id, phone;
    string name;
    public:
        hashentry(int id, int phone, string name)
        {
            this->id=id;
            this->phone=phone;
            this->name=name;
        }
        friend class hashmap;
};

class hashmap
{
    hashentry **table;
    public:
        hashmap()
        {
            table = new hashentry *[size];
            for (int i=0; i<size; i++)
            {
                table[i]=NULL;
            }
        }

        int hashfunc(int id)
        {
            return id%size;
        }

        void insert()
        {
            string name;
            int id, phone;
            cout<<"Enter client id: ";
            cin>>id;
            cout<<"Enter name of client: ";
            cin>>name;
            cout<<"Enter phone number: ";
            cin>>phone;

            int hash=hashfunc(id);
            bool exists=false;

            while(table[hash]!=NULL)
            {
                if(table[hash]->id==id)
                {
                    cout<<"Customer with same ID already exists."<<endl;
                    exists=true;
                    break;
                }
                else
                    hash=hashfunc(hash+1);
            }            
            if(exists==false)
                table[hash]=new hashentry(id, phone, name);
        }

        void display()
        {
            cout<<"ID\tName\tPhone Number\n";
            for(int i=0; i<size; i++)
            {
                if(table[i]!=NULL)
                    cout<<table[i]->id<<"\t"<<table[i]->name<<"\t"<<table[i]->phone<<"\n";
            }
        }

        void search()
        {
            int id;
            cout<<"Enter client id to look up phone number: ";
            cin>>id;

            int hash=hashfunc(id);

            while(table[hash]!=NULL && table[hash]->id!=id)
            {
                hash=hashfunc(hash+1);
            }

            if(table[hash]==NULL)
                cout<<"Client not found.\n";
            else
            {
                cout<<"CLient found.\n";
                cout<<"ID\tName\tPhone Number\n";
                cout<<table[hash]->id<<"\t"<<table[hash]->name<<"\t"<<table[hash]->phone<<"\n";
            }
        }

        void remove()
        {
            int id;
            cout<<"Enter client id to delete: ";
            cin>>id;

            int hash=hashfunc(id);

            while(table[hash]!=NULL && table[hash]->id!=id)
            {
                hash=hashfunc(hash+1);
            }

            if(table[hash]==NULL)
                cout<<"Client not found.\n";
            else
            {
                delete table[hash];
                table[hash]=NULL;
                cout<<"Client information deleted.\n";
            }
        }
};

int main()
{
    hashmap h;
    int choice;

    while (1)
    {
        cout<<"\nOperations on Hash Table"<<endl;
        cout<<"1. Add client information"<<endl;
        cout<<"2. Display client information"<<endl;
        cout<<"3. Search client phone number"<<endl;
        cout<<"4. Delete client information"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: h.insert();
                    break;
            case 2: h.display();
                    break;
            case 3: h.search();
                    break;
            case 4: h.remove();
                    break;
            case 5: exit(1);

            default: cout<<"\nEnter correct option\n";
        }
    }
    return 0;
}