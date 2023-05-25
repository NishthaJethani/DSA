#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int rollno;
    string name;
    char div;
    string address;

    public:
        void get_data()
        {
            cout<<"Enter student roll no.: ";
            cin>>rollno;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter divison: ";
            cin>>div;
            cout<<"Enter address: ";
            cin>>address;
        }

        void show()
        {
            cout<<rollno<<"\t"<<name<<"\t"<<div<<"\t"<<address<<"\n";
        }
    friend class index;
};

class index
{
    student s;

    public:
        void insert()
        {
            ofstream f;
            f.open("student.dat", ios::out| ios::app | ios::binary);

            if(!f)
            {
                cout<<"Error opening file";
                return;
            }
            s.get_data();
            f.write((char*)&s, sizeof(s))<<flush;
            f.close();
        }

        void display()
        {
            ifstream f;
            f.open("student.dat", ios::in | ios::binary);
            if(!f)
            {
                cout<<"Error opening file";
                return;
            }

            cout<<"Roll No\tName\tDivison\tAddress"<<endl;
            while(f.read((char*)&s, sizeof(s)))
            {
                s.show();
            }
            f.close();
        }

        void search()
        {
            int roll;
            int found=0;
            cout<<"Enter student roll no. to search for: ";
            cin>>roll;
            ifstream f;
            f.open("student.dat", ios::in|ios::binary);
            if(!f)
            {
                cout<<"Error opening file";
                return;
            }
            f.seekg(0, ios::beg);
            while(f.read((char*)&s, sizeof(s)))
            {
                if(s.rollno==roll)
                {
                    cout<<"Student found"<<endl;
                    cout<<"Roll No\tName\tDivison\tAddress"<<endl;
                    s.show();
                    found=1;
                }
            }
            f.close();
            if(!found)
                cout<<"Student not found"<<endl;
        }

        void delete_info()
        {
            int roll;
            int found=0;
            cout<<"Enter student roll no. to delete: ";
            cin>>roll;
            fstream f;
            f.open("student.dat", ios::out | ios::in | ios::binary);
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
            while(f.read((char*)&s, sizeof(s)))
            {
                if(s.rollno!=roll)
                   f1.write((char*)&s, sizeof(s));
                else
                    found=1;
            }

            f.close();
            f1.close();

            remove("student.dat");
            rename("temp.dat", "student.dat");

            if(!found)
                cout<<"Student not found"<<endl;
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
        cout<<"1. Add student"<<endl;
        cout<<"2. Display student information"<<endl;
        cout<<"3. Search for student"<<endl;
        cout<<"4. Delete student information"<<endl;
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