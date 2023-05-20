#include <iostream>
using namespace std;

class node
{
    node *left;
    node *right;
    int data;
    bool lthread;
    bool rthread;

    public:
        node()
        {
            left=NULL;
            right=NULL;
            cout<<"Enter data: ";
            cin>>data;
            lthread=false;
            rthread=false;
        }

        node(int data)
        {
            left=NULL;
            right=NULL;
            this->data=data;
            lthread=false;
            rthread=false;
        }
        friend class tbt;
};

class tbt
{
    node *root;

    public:
        tbt()
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

        void display_btree()
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
                cout<<a->data<<"\t";
                inorder(a->right);
            }
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

        node * inorder_successor(node *a)
        {
            a=a->right;
            while(a->left!=NULL)
                a=a->left;
            return a;
        }

        node * inorder_predecessor(node *a)
        {
            a=a->left;
            while(a->right!=NULL)
                a=a->right;
            return a;
        }

        void thread_tree()
        {
            node *head=new node('\0');
            head->left=root;
            head->lthread=false;
            head->right=head;
            head->rthread=true;

           node *A[20];
           int n=0;
           queue_inorder(A, root, n);

           for(int i=0; i<n; i++)
           {
                if(A[i]->left==NULL)
                {
                    if(i==0)
                        A[i]->left=head;
                    else
                        A[i]->left=A[i-1];
                    A[i]->lthread=true;
                }
                if(A[i]->right==NULL)
                {
                    if(i==n-1)
                        A[i]->right=head;
                    else
                        A[i]->right=A[i+1];
                    A[i]->rthread=true;
                }
           }
        }
 

        void queue_inorder(node *A[], node *a, int & n)
        {
            if(a!=NULL)
            {
                queue_inorder(A, a->left, n);
                A[n]=a;
                n++;
                queue_inorder(A, a->right, n);
            }
        }

        void display_ttree()
        {
            node *temp=leftMost(root);
            while(temp->data!='\0')
            {
                cout<<temp->data<<"\t";
                if(temp->rthread)
                    temp=temp->right;
                else
                    temp=leftMost(temp->right);
            }

        }

        node * leftMost(node *temp)
        {
            while(!temp->lthread)
                temp=temp->left;
            return temp;
        }
};

int main()
{
    tbt t;
    int x;

    while(1)
    {
        cout<<"\nEnter your choice:";
        cout<<"\n1.Insert element in BST";
        cout<<"\n2.Display BST (inorder)";
        cout<<"\n3.Thread BST";
        cout<<"\n4.Display TBT";
        cout<<"\n5.Exit"<<endl;;
        cin>>x;
        switch(x)
        {
            case 1: t.insert();
                    break;
            case 2: t.display_btree();
                    break;
            case 3: t.thread_tree();
                    break;
            case 4: t.display_ttree();
                    break;
            case 5: exit(0);
        }
    }
}
