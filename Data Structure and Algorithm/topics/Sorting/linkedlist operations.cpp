#include<iostream>
#include <stdlib.h>
using namespace std;
class LinkedList
{
private:
      struct node   //listnode
          {
            int data;
            node*next;
          }*head;
public:
        LinkedList() //constructor
         {
           head=NULL;
         }
       void createList();
       void insertInList();
       void delnodeFromList();
       void displayList();
       void searchList();
       void reverseList();
      
};

void LinkedList::createList()
{
   head=new node;
   cout<<"Enter value of the node:";
   cin>>head->data;
   head->next=NULL;
}
void LinkedList::insertInList()
{
   int n;
   char p;
   node*list,*prev,*temp;
   list=head;
   cout<<"Insert node at front/middle/last? f/m/l:"<<endl;
   cin>>p;
   if(p=='f')
   {
       temp=new node;
       cout<<"Enter the value for the node:";
       cin>>temp->data;
       temp->next=head;
       head=temp;
   }
   if(p=='m')
   {
       cout<<"Enter the value for the new node before:"<<endl;
       cin>>n;
       while(list->data!=n)
       {
           prev=list;
           list=list->next;
       }
   temp=new node;
   cout<<"Enter the value for the node:";
   cin>>temp->data;
   prev->next=temp;
   temp->next=list;
   }
   if(p=='l')
   {
   while(list->next!=NULL)
   list=list->next;
   temp=new node;
   cout<<"Enter the data for the node:";
   cin>>temp->data;
   temp->next=NULL;
   list->next=temp;
   }
}
void LinkedList::delnodeFromList()
{
   int n,p=0;
   node *list,*prev,*temp;
   list=head;
   cout<<"Enter the data for the node to be deleted:";
   cin>>n;
   if(head->data==n)
   {
       head=head->next;
       p=1;
   }
   else
   {
      while((list->next!=NULL)&&(list->data!=n))
        {
       prev=list;
       list=list->next;
        }
       if((list->next!=NULL)&&(list->data==n))
       {
       temp=list;
       prev->next=NULL;
       p=1;
       }
       else if(list->data==n)
       {
       temp=list;
       prev->next=list->next;
       p=1;
       }
      delete(temp);
   }
   if(p==0)
   {
   cout<<"Node is not present";
   }
}
void LinkedList::displayList()
{
   node*list;
   list=head;
   if(list==NULL)
   cout<<"List is empty";
   else
   {
   cout<<"List is: ";
   while(list!=NULL)
   {
   cout<<list->data<<"<==>";
   list=list->next;
   }
   cout<<"NULL";
   }

}

void LinkedList::searchList()
{
  
    int value, pos = 0;
    bool flag = false;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node *s;
    s = head;
    while (s != NULL)
    {
        pos++;
        if (s->data == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;
}
void LinkedList::reverseList()
{
   struct node *ptr1, *ptr2, *ptr3;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (head->next == NULL)
    {
        return;
    }
    ptr1 = head;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;       
    }
    head = ptr2;
}

int main()
{
int option;
LinkedList s;
   while(option!=5)
   {
   cout<<"1.CreateList()"<<endl;
   cout<<"2.InsertInList()"<<endl;
   cout<<"3.DeleteFromList()"<<endl;
   cout<<"4.DisplayList()"<<endl;
   cout<<"5.SearchList()"<<endl;
   cout<<"6.reverseList()"<<endl;
   cout<<"7.Exit()"<<endl;
   cout<<"Enter your option:";
   cin>>option;
   switch(option)
   {
       case 1:
       s.createList();
       break;
       case 2:
       s.insertInList();
       break;
       case 3:
       s.delnodeFromList();
       break;
       case 4:
       s.displayList();
       break;
       case 5:
       s.searchList();
       break;
       case 6:
       s.reverseList();
       break;
       case 7:
       break;
   }
   }
   return 0;
}