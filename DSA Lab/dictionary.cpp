#include <iostream>
using namespace std;

class node
{
    node *left;
    node *right;
    string word, meaning;

    public:
        node()
        {
            left=NULL;
            right=NULL;
            cout<<"Enter word: ";
            cin>>word;
            cout<<"Enter meaning: ";
            cin>>meaning;
        }

        node(string word, string meaning)
        {
            left=NULL;
            right=NULL;
            this->word=word;
            this->meaning=meaning;
        }
        friend class dictionary;
};

class dictionary
{
    node *root;

    public:
        dictionary()
        {
            root=NULL;
        }

        void insert()
        {
            node *temp=new node();
            if(root==NULL)
                root=temp;
            else
            {
                node *t=root;
                node *s;
                while(t!=NULL)
                {
                    s=t;
                    if(s->word<temp->word)
                        t=t->right;
                    else
                        t=t->left;
                }
                if(s->word<temp->word)
                    s->right=temp;
                else
                    s->left=temp;
            }
        }

        void display_ascending()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
                inorder(root);
        }

        void inorder(node *a)
        {
            if(a!=NULL)
            {
                inorder(a->left);
                cout<<a->word<<" : "<<a->meaning<<"\n";
                inorder(a->right);
            }
        }

        void display_descending()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
                descending(root);
        }

        void descending(node *a)
        {
            if(a!=NULL)
            {
                descending(a->right);
                cout<<a->word<<" : "<<a->meaning<<"\n";
                descending(a->left);

            }
        }

        void search()
        {
            string key;
            bool flag=false;
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                cout<<"Enter data to be searched: ";
                cin>>key;

                if(root->word==key)
                {
                    cout<<"Data Found in Tree."<<endl;
                    flag=true;
                }
                else
                {
                    node *temp=root;
                    while(temp!=NULL)
                    {
                        if(key==temp->word)
                        {
                            cout<<"Data Found in Tree."<<endl;
                            flag=true;
                            break;
                        }
                        else if(key>temp->word)
                            temp=temp->right;
                        else
                            temp=temp->left;
                    }
                }
                if(!flag)
                    cout<<"Data not found in tree."<<endl;
            }
        }

        void deletion()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                string key;
                cout<<"Enter data to be deleted: ";
                cin>>key;
                root=delete_node(root, key);
            }
        }
        node * delete_node(node *a, string key)
        {
            if(a->word>key)
                a->left=delete_node(a->left, key);
            else if(a->word<key)
                a->right=delete_node(a->right,key);
            else
            {
                if(a->left==NULL && a->right==NULL)
                {
                    delete a;
                    return NULL;
                }
                else if(a->left==NULL)
                {
                    node *temp=a->right;
                    delete a;
                    return temp;
                }
                else if(a->right==NULL)
                {
                    node *temp=a->left;
                    delete a;
                    return temp;
                }
                else if(a->right!=NULL && a->left!=NULL)
                {
                    node * successor=inorder_successor(a);
                    a->word=successor->word;
                    a->right=delete_node(a->right, successor->word);
                }
            }
            return a;
        }

        node * inorder_successor(node *a)
        {
            a=a->right;
            while(a->left!=NULL)
                a=a->left;
            return a;
        }
};

int main()
{
    dictionary d;
    int x;

    while(1)
    {
        cout<<"\nEnter your choice:";
        cout<<"\n1.Insert word in Dictionary.";
        cout<<"\n2.Display Dictionary in ascending order.";
        cout<<"\n3.Display Dictionary in descending order.";
        cout<<"\n4.Search for a word.";
        cout<<"\n5.Delete word from Dictionary.";
        cout<<"\n6.Exit"<<endl;;
        cin>>x;
        switch(x)
        {
            case 1: d.insert();
                    break;
            case 2: d.display_ascending();
                    break;
            case 3: d.display_descending();
                    break;
            case 4: d.search();
                    break;
            case 5: d.deletion();
                    break;
            case 6: exit(0);
        }
    }
}
