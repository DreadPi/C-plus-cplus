#include <iostream>
using namespace std;

class Node
{ public:
	Node *next;
  	int data;

	Node(int x,Node *n=0)
    {
      data=x;
      next=n;
    }
 	void  addtoHead(int x);
    friend ostream& operator<<(ostream &ostr,Node &J);
    friend istream& operator>>(istream &str,Node &J);

};
   
class SLL
{
	Node *head;
    Node *tail;
    public:
    SLL()
    {
      head=NULL;
      tail=NULL;
    }
	void addtoHead(int x);
	void addtoTail(int x);
	void display();
	int  count();
	void addtoPos(int x);
};



    void SLL::addtoHead(int x)
    {
		Node *p=new Node(x);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
		{
		  
          p->next=head;
          head=p;
		}
	}
    void SLL::addtoTail(int x)
    {
        Node *p=new Node(x);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
		{
		tail->next=p;
		tail=p;
          
        }
    }
    void SLL::display()
	{
      	Node *temp=head;
      	while(temp!=0)
      	{
      		cout<<temp->data<<"\t";
      		temp=temp->next;
      	
		}
  		cout<<endl;
	}
	int SLL::count()
    {
      	int x;
      	if(head==0)
		  {
		  	x=0;
		  }
		Node *temp=head;
		  
		while(temp!=0)
		{
		 	temp=temp->next;
		 	x++;
		} 
		  return x;
	}
	void SLL:addtoPos(int x)
	{  Node *point
		int temp=0;
		while(temp!=x)
		{
			temp=
		}
		
		
		
		
	}
	  
    istream& operator>>(istream &str,Node &J)
    {
      	cout<<"enter data for the elements in linked list";
    	int d;
    	str>>d;
      	return str;

    }
    ostream& operator<<(ostream &ostr,Node &J)
    {
      ostr<<"data =" <<J.data<<"\n address of next elements = "<<J.next<<endl;
      return ostr;

    }


int main()
{
	SLL S;
 	int n;
 	do
 	{
 		cout<<"Linked List Version 2.0 Copyright under 23Act\n 1.Add to head \n 2.Add to tail \n 3.Count number of elements \n 4.Display the elements \n 5.Exit"<<endl;
 		cin>>n;
 		switch(n)
 		{
 		
 			case 1:
 				{
				cout<<"Enter the element value to be added"<<endl;
 				int x;
 				cin>>x;
 				S.addtoHead(x);
 				break;
			 	}
 		
 			case 2:
 				{
 				cout<<"Enter the element value to be added"<<endl;
 				int x;
 				cin>>x;
 				S.addtoTail(x);
 				break;
			    }
			case 3:
 				{
 				int x=S.count();
 				cout<<"Number of elements are :"<<x<<endl;
 				break;
			    }
			 
		    case 4:
 			{
 				S.display();
 				break;
			}	 
 			case 5:
 			{
			 
				n=0;
 				break;
			}
 		
 	    }
 		
 		
 		
	}
	 while(n!=0);
	 


	return 0;
}
