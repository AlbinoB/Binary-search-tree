//circular linklist
#include<iostream>
using namespace std;

	class node
	{
	    public:int data;
	    node *left;
	    node *right;
	};

    node* search1(node *,int);
    node* insert1(node *,node *);
	void display(node *);

int main()
{
    node *root=NULL;
	int n,c;
	do
	{       cout<<"\n*********************************\n";

		cout<<"\n\n\n enter your choice \n 1:insert a number. \n 2.display \n 3.search for a number. \n  0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
			    node *a;
                a=new(node);
                cout<<"\n enter the value:";
                cin>>a->data;
                a->left=NULL;
                a->right=NULL;
                if(root==NULL)
                {
                    root=a;//if its the first node make root point to a
                }else
                {
                    insert1(root,a);//else pass the root and the new node pointer
                }

				break;
				}
            case 2:{
				display(root);
                break;
				}
			case 3:{
			    if(root==NULL)
                {
                    cout<<"\n no number inserted!!!!";
                }
                else
                {
                    int val;
                    node *t;
                    cout<<"enter the number to be searched:";
                    cin>>val;
                    t=search1(root,val);
                    if(t)
                    {
                        cout<<"\n returned:"<<t->data;
                    }
                    else
                    {
                        cout<<"\n"<<val<<" is not present!!!";
                    }
                }
				break;
				}
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<5 && c>0);
	return 0;
}

    void display(node *root){
            if( root->right==NULL && root->left==NULL)
            {
                cout<<" "<<root->data;
            }else
            {
                if( root->left!=NULL)
                {
                    display(root->left);
                }
                cout<<" "<<root->data;
                if( root->right!=NULL)
                {
                    display(root->right);
                }
            }

    }




	node* insert1(node *root,node *a)
	{
            if(a->data<root->data && root->left==NULL)//if its less than the root value and if the roots left is null .
			{
                root->left=a;//make the roots left point to the new node
			}
			else
            {
                if(a->data>root->data && root->right==NULL)//if its greater than the root value and if the roots right is null .
                {
                    root->right=a;//make the roots right point to the new node
                }
                else
                {
                    if(a->data<root->data)
                    {
                        root=root->left;
                        insert1(root,a);
                    }
                    else
                    {
                        root=root->right;
                        insert1(root,a);
                    }
                }

            }
            return root;
	}

    node* search1(node *root,int val){
        if(root!=NULL)
        {
                if(root->data==val)
            {
                cout<<"\n value found:";
            }
            else
            {
                if(val<root->data)
                {
                    root=search1(root->left,val);
                }
                else
                {
                    if(val>root->data)
                    {
                        root=search1(root->right,val);
                    }
                }

            }
        }
        return root;

    }
