#include <iostream>
#include <fstream>
using namespace std;

class employee
{
    int empid;
    string name;
    int salary;

    public:
        void get_data()
        {
            cout<<"Enter new employee id: ";
            cin>>empid;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter salary: ";
            cin>>salary;
        }

        void show()
        {
            cout<<empid<<"\t"<<name<<"\t"<<salary<<"\n";
        }
    friend class index;
};

class index
{
    employee e;
    fstream f;

    public:
        void insert()
        {
            f.open("employee.DAT", ios::out | ios::app | ios::binary);

            if(!f)
            {
                cout<<"Error opening file";
                return;
            }
            e.get_data();
            f.write((char*)&e, sizeof(e));
            f.close();
        }

        void display()
        {
            f.open("employee.dat", ios::in | ios::binary);
            if(!f)
            {
                cout<<"Error opening file";
                return;
            }
            
            cout<<"ID\tName\tSalary"<<endl;
            while(f.read((char*)&e, sizeof(e)))
            {
                e.show();
            }
            f.close();
        }

        void search()
        {
            int id;
            int found=0;
            cout<<"Enter employee id to search for: ";
            cin>>id;

            f.open("employee.dat", ios::in);
            if(!f)
            {
                cout<<"Error opening file";
                return;
            }

            while(f.read((char*)&e, sizeof(e)))
            {
                if(e.empid==id)
                {
                    cout<<"Employee found"<<endl;
                    cout<<"ID\tName\tSalary"<<endl;
                    e.show();
                    found=1;
                }
            }
            f.close();
            if(!found)
                cout<<"Employee not found"<<endl;
        }

        void delete_info()
        {
            int id;
            int found=0;
            cout<<"Enter employee id to delete: ";
            cin>>id;

            f.open("employee.dat", ios::out | ios::in | ios::binary);
            if(!f)
            {
                cout<<"Error opening file";
                return;
            }

            fstream f1;
            f1.open("temp.dat", ios::out | ios::binary);
            if(!f1)
            {
                cout<<"Error opening file";
                return;
            }

            f.seekg(0, ios::beg);    //set reading pointer at beginning
            while(f.read((char*)&e, sizeof(e)))
            {
                if(e.empid!=id)
                   f1.write((char*)&e, sizeof(e));
                else
                    found=1;
            }

            f.close();
            f1.close();

            remove("employee.dat");
            rename("temp.dat", "employee.dat");

            if(!found)
                cout<<"Employee not found"<<endl;
            else
                cout<<"Deletion was successful"<<endl;
        }
};

int main()
{
    index i;
    int choice;

    while(1)
    {
        cout<<"\nOperations on Hash Table"<<endl;
        cout<<"1. Add employee"<<endl;
        cout<<"2. Display employee information"<<endl;
        cout<<"3. Search for employee"<<endl;
        cout<<"4. Delete employee information"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: i.insert();
                    break;
            case 2: i.display();
                    break;
            case 3: i.search();
                    break;
            case 4: i.delete_info();
                    break;
            case 5: exit(1);

            default: cout<<"\nEnter correct option\n";
        }
    }
    return 0;
}