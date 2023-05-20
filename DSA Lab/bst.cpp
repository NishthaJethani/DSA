
#include <iostream>
using namespace std;

class node
{
    node *left;
    node *right;
    int data;

    public:
        node()
        {
            left=NULL;
            right=NULL;
            cout<<"Enter data: ";
            cin>>data;
        }

        node(int data)
        {
            left=NULL;
            right=NULL;
            this->data=data;
        }
        friend class bst;
};

class bst
{
    node *root;

    public:
        bst()
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
                    if(s->data<temp->data)
                        t=t->right;
                    else
                        t=t->left;
                }
                if(s->data<temp->data)
                    s->right=temp;
                else
                    s->left=temp;
            }
        }

        void display()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
                preorder(root);
        }

        void preorder(node *a)
        {
            if(a!=NULL)
            {
                cout<<a->data<<"\t";
                preorder(a->left);
                preorder(a->right);
            }
        }

        void find_height()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
                cout<<"Height of tree is "<<height(root);
        }

        int height(node* a)
        {
            if(a==NULL)
                return 0;
            else
            {
                int lefth=height(a->left);
                int righth=height(a->right);

                if(lefth>righth)
                    return lefth+1;
                else
                    return righth+1;
            }
        }

        void min_max()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                node *temp=root;

                while(temp->right!=NULL)
                    temp=temp->right;
                cout<<"Maximum element in tree is "<<temp->data<<endl;

                temp=root;
                while(temp->left!=NULL)
                    temp=temp->left;
                cout<<"Minimum element in tree is "<<temp->data<<endl;
            }
        }

        void search()
        {
            int key;
            bool flag=false;
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                cout<<"Enter data to be searched: ";
                cin>>key;

                if(root->data==key)
                {
                    cout<<"Data Found in Tree."<<endl;
                    flag=true;
                }
                else
                {
                    node *temp=root;
                    while(temp!=NULL)
                    {
                        if(key==temp->data)
                        {
                            cout<<"Data Found in Tree."<<endl;
                            flag=true;
                            break;
                        }
                        else if(key>temp->data)
                            temp=temp->right;
                        else
                            temp=temp->left;
                    }
                }
                if(!flag)
                    cout<<"Data not found in tree.";
            }
        }

        void swap_tree()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                swap(root);
            }
        }

        void swap(node *a)
        {
            if(a->left!=NULL)
                swap(a->left);
            if(a->right!=NULL)
                swap(a->right);

            node *temp;
            temp=a->left;
            a->left=a->right;
            a->right=temp;
        }

        void deletion()
        {
            if(root==NULL)
                cout<<"Tree does not exist.";
            else
            {
                int key;
                cout<<"Enter data to be deleted: ";
                cin>>key;
                root=delete_node(root, key);
            }
        }
        node * delete_node(node *a, int key)
        {
            if(a->data>key)
                a->left=delete_node(a->left, key);
            else if(a->data<key)
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
                    a->data=successor->data;
                    a->right=delete_node(a->right, successor->data);
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
    bst b;
    int x;

    while(1)
    {
        cout<<"\nEnter your choice:";
        cout<<"\n1.Insert element";
        cout<<"\n2.Display Tree (preorder)";
        cout<<"\n3.Search for an element";
        cout<<"\n4.Swap Left and Right";
        cout<<"\n5.Height of Tree";
        cout<<"\n6.Delete element";
        cout<<"\n7.Find Minimum Maximum Element";
        cout<<"\n8.Exit"<<endl;;
        cin>>x;
        switch(x)
        {
            case 1: b.insert();
                    break;
            case 2: b.display();
                    break;
            case 4: b.swap_tree();
                    break;
            case 3: b.search();
                    break;
            case 5: b.find_height();
                    break;
            case 6: b.deletion();
                    break;
            case 7: b.min_max();
                    break;
            case 8: exit(0);
        }
    }
}
