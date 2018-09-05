#include <iostream>
using namespace std;
class dllNode
{
friend class dll;
  dllNode *next;
  dllNode *previous;
   int data;
  public:
    dllNode(int d,dllNode *p=0,dllNode *n=0)
    {
      data=d;
      previous=p;
      next=n;
    }

};
class dll
{
  dllNode *head;
  dllNode *tail;
public:
  dll()
  {
    head=tail=NULL;

  }
  void addToHead(int);
  void addToTail(int);
  void display();
  void deleteFromHead();
  int  deleteFromTail();
  void deleteNode(int );

};
void dll::addToHead(int x)
{
  dllNode *p=new dllNode(x);
  if(head==NULL)
  {
    head=tail=p;
  }
  else
  {
    head->previous=p;
    p->next=head;
    head=p;
  }
}
void dll::addToTail(int x)
{
  dllNode *p=new dllNode(x,tail,0);
  if(tail==NULL)
  {
    head=tail=p;
  }
  else
  {
    tail->next=p;
    p->previous=tail;
    tail=p;
  }
}
void dll::display()
{
  dllNode *trav=head;
  if(head==NULL)
  {
    cout<<"list is empty"<<endl;
  }
  else
  { while(trav!=0)
    { cout<<trav->data<<"\t";
      trav=trav->next;
    }
    cout<<"\n";
  }
}
  void dll::deleteFromHead()
  {
    dllNode *temp=head;
     if(head==NULL)
    {
      throw "list is empty";
    }
    else if(head==tail)
    {
      head=tail=0;
    }
    else
    {
      head=head->next;
      delete temp;
      head->previous=0;
    }
  }
  int dll::deleteFromTail()
  {
    dllNode *temp=tail;
    int t;
    if(head==NULL)
    {
      throw "list is empty";
    }
    else if(head==tail)
    {
      t=head->data;
      head=tail=0;


    }
    else
    { t=tail->data;
      tail=tail->previous;
      tail->next=0;


    }
    delete temp;
    return t;
  }
   void dll::deleteNode(int x )
   {
     if(head==tail)
     {
       this->deleteFromHead();
     }
     else
     {

       dllNode *temp=head;
     while(temp!=0&&temp->data!=x)
     {
       temp=temp->next;
     }
     if(temp==0)
     {
       cout<<"element not found "<<endl;
     }
     else if(temp==head)
     {
       this->deleteFromHead();

     }
     else if(temp==tail)
     {
       this->deleteFromTail();
     }

     else
     {
       dllNode *temp1=temp->previous;
      dllNode *temp2=temp->next;
      temp1->next=temp->next;
      temp2->previous=temp1;
      delete temp;
     }
   }
 }













  int  main()
  {
    dll d;
    int n;
   cout<<"enter option number to execute opertion specified"<<endl;
    do
    {   cout<<"Doubly Link List @hackathon\n 1.Add to head \n 2.Add To Tail \n 3.Display \n 4.Delete from Head \n 5.Delete from Tail \n 6.delete a particular value in list \n 7.Exit "<<endl;

        cin>>n;
        switch(n)
        {
          case 1:
          {

            cout<<"enter the value to enter in the node "<<endl;
            int temp;
            cin>>temp;
            d.addToHead(temp);
            break;


            }
          case 2:
          {
            cout<<"enter the value to enter in the node "<<endl;
            int temp;
            cin>>temp;
            d.addToTail(temp);
            break;


            }
            case 3:
            {
              cout<<"elements are "<<endl;
             d.display();
              break;


              }
              case 4:
              {
                d.deleteFromHead();
                break;
                }
                case 5:
                {
                  d.deleteFromTail();
                  break;
                }
          case 6:
          {
            cout<<"enter the value to be deleted from the list "<<endl;
            int temp;
            cin>>temp;
            d.deleteNode(temp);
            break;
          }
          default:
          {
            cout<<"enter a valid option "<<endl;
            break;
          }

        }

    }
 while(n!=0);

    return 0;
  }
