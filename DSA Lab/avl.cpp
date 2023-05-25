#include <iostream>
using namespace std;

class node
{
    string word, meaning;
    int height;
    node *left;
    node *right;

    public:
        node()
        {
            left=right=NULL;
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

        void add_word()
        {
            node *temp=new node();

            cout<<"Enter word to add: ";
            cin>>temp->word;
            cout<<"Enter it's meaning: ";
            cin>>temp->meaning;

            root = place_word(root, temp);
        }

        node * place_word(node *r, node *temp)
        {
            if(r==NULL)
                r=temp;
            else  if(r->word>temp->word)
            {
                r->left=place_word(r->left, temp);
                if(balance(r)==2)
                {
                    if(temp->word>r->left->word)
                        r=LR(r);
                    else
                        r=LL(r);
                }
            }
            else if (r->word<temp->word)
            {
                r->right=place_word(r->right, temp);
                if(balance(r)==-2)
                {
                    if(temp->word>r->right->word)
                        r=RR(r);
                    else
                        r=RL(r);
                }
            }
            r->height=height(r);
            return r;
        }

        int balance(node *temp)
        {
            int lh, rh;

            if(temp==NULL)
                return 0;
            
            if(temp->left==NULL)
                lh=0;
            else
                lh=(temp->left->height)+1;
            
            if(temp->right==NULL)
                rh=0;
            else
                rh=(temp->right->height)+1;

            return (lh-rh);
        }

        int height(node *temp)
        {
            int rh, lh;

            if (temp==NULL)
                return 0;

            if(temp->left==NULL)
                lh=0;
            else
                lh=(temp->left->height)+1;
            
            if(temp->right==NULL)
                rh=0;
            else
                rh=(temp->right->height)+1;
            
            if(lh>rh)
                return lh;
            else
                return rh;
        }

        node * LL(node *temp)
        {
            temp=rotateright(temp);
            return temp;
        }

        node * RR(node *temp)
        {
            temp=rotateleft(temp);
            return temp;
        }

        node * LR(node *temp)
        {
            temp->left = rotateleft(temp->left);
            temp=rotateright(temp);
            return temp;
        }

        node * RL(node *temp)
        {
            temp->right = rotateright(temp->right);
            temp=rotateleft(temp);
            return temp;
        }

        node *rotateleft(node *temp)
        {
            node * x=temp->right;
            temp->right=x->left;
            x->left=temp;

            temp->height=height(temp);
            x->height=height(x);

            return x;
        }

        node * rotateright(node *temp)
        {
            node * x=temp->left;
            temp->left=x->right;
            x->right=temp;

            temp->height=height(temp);
            x->height=height(x);

            return x;
        }

        void display()
        {
            cout<<"Word\tMeaning\n";
            inorder(root);
        }

        void inorder(node *temp)
        {
            if(temp!=NULL)
            {
                inorder(temp->left);
                cout<<temp->word<<"\t"<<temp->meaning<<"\n";
                inorder(temp->right);
            }
        }

        void search()
        {
            string key;
            cout<<"Enter word to search for: ";
            cin>>key;

            node *temp;
            temp=search_word(root, key);

            if(temp==NULL)
                cout<<"\nWord is not present in dictionary.\n";
            else
                cout<<"\nWord: "<<temp->word<<"\nMeaning: "<<temp->meaning<<"\n";
        }

        node * search_word(node *r, string key)
        {
            if (r==NULL)
                return NULL;
            if(key>r->word)
                return search_word(r->right, key);
            else if (key<r->word)
                return search_word(r->left, key);
            else
                return r;
        }

        void update()
        {
            string key;
            cout<<"Enter word to update meaning: ";
            cin>>key;

            node *temp;
            temp=search_word(root, key);

            if(temp==NULL)
                cout<<"\nWord is not present in dictionary.\n";
            else
            {
                cout<<"\nWord: "<<temp->word<<"\nMeaning: "<<temp->meaning<<"\n";
                cout<<"Enter new meaning: ";
                cin>>temp->meaning;
                cout<<"Meaning updated.\n";
            }
        }

        void remove()
        {
            string key;
            cout<<"Enter word to delete: ";
            cin>>key;

            node *temp;
            temp=search_word(root, key);

            if(temp==NULL)
                cout<<"\nWord is not present in dictionary.\n";
            else
            {
                root=delete_word(root, key);
                cout<<"Word deleted.\n";
            }
        }

        node * delete_word(node *r, string key)
        {
            if(r==NULL)
                return r;
            if(key>r->word)
                r->right=delete_word(r->right, key);
            else if(key<r->word)
                r->left=delete_word(r->left, key);
            else
            {
                if((r->left==NULL) || (r->right==NULL))
                {
                    node *temp;
                    if(r->right)
                        temp=r->right;
                    else
                        temp=r->left;

                    if(temp==NULL)
                    {
                        temp=r;
                        r=NULL;
                    }
                    else
                        *r=*temp;
                    delete temp;
                }
                else
                {
                    node *temp=minvalue(r->right);
                    r->word=temp->word;
                    r->meaning=temp->meaning;
                    r->right=delete_word(r->right, temp->word);
                }
            }

            if(r==NULL)
                return r;
            
            r->height=height(r);
            int balanceFactor=balance(r);

            if(balanceFactor>1 && balance(r->left)>=0)
                return LL(r);
            if(balanceFactor>1 && balance(r->left)<0)
                return LR(r);
            if(balanceFactor<-1 && balance(r->right)<=0)
                return RR(r);
            if(balanceFactor<-1 && balance(r->right)>0)
                return RL(r);

            return r;
        }

        node * minvalue(node *temp)
        {
            while(temp->left!=NULL)
                temp=temp->left;
            return temp;
        }

};

int main()
{
    dictionary d;
    int choice;

    while (1)
    {
        cout<<"\nAVL Tree Dictionary"<<endl;
        cout<<"1. Add word to dictionary"<<endl;
        cout<<"2. Display dictionary"<<endl;
        cout<<"3. Search word in dictionary"<<endl;
        cout<<"4. Update meaning of a word"<<endl;
        cout<<"5. Delete word from dictionary"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: d.add_word();
                    break;
            case 2: d.display();
                    break;
            case 3: d.search();
                    break;
            case 4: d.update();
                    break;
            case 5: d.remove();
                    break;
            case 6: exit(0);
        }
    }
    
}