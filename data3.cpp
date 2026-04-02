#include<iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class SinglyCL
{
    public:
        struct node <T>* head;
        struct node<T> *tail;
        int iCount;

       SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};
template <class T>
SinglyCL<T>::SinglyCL()
{
    head = NULL;
    tail=NULL;
    iCount = 0;
}
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{

            struct node <T>* newn=NULL;
            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;

            if((head==NULL)&&(tail==NULL))
            {
                head=newn;
                tail=newn;
            }
            else
            {
                newn->next=head;
                head=newn;
            }
            tail->next=head;
            iCount++;
}
template <class T>
void SinglyCL<T>::InsertLast(T no)
{
          struct node<T> * newn=NULL;
            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;



            if((head==NULL)&&(tail==NULL))
            {
                head=newn;
                tail=newn;
            }
            else
            {

               tail->next=newn;
               tail=newn;

            }
            tail->next=head;
            iCount++;
}
template <class T>
void SinglyCL<T>::InsertAtPos(T no , int ipos)
{
    int i = 0;
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {

        newn = new node<T>;  

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;

        for(i = 1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
       iCount++;
    }

template <class T>
void SinglyCL<T>::DeleteFirst()
{
      struct node<T> * temp=NULL;

            if((head==NULL)&&(tail==NULL))
            {
                return;
            }
            else if(head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                temp=head;

                 head=head->next;
                 delete(temp);
                 tail->next=head;



            }
            iCount--;
}
  template <class T>
  void SinglyCL<T>::DeleteLast()
{
       struct node<T> *temp=NULL;

            if((head==NULL)&&(tail==NULL))
            {
                return;
            }
            else if(head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
               temp=head;
               while(temp->next!=tail)
               {
                temp=temp->next;
               }
               delete(temp->next);
               tail=temp;
               tail->next=head;







            }
            iCount--;

}
template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
        int iCount = 0;
        int  i = 0;

        struct node<T> * temp = NULL;





       if((ipos < 1) || (ipos > iCount))
        {
        printf("Invalid position\n");
        return;
       }

      if(ipos == 1)
       {
        DeleteFirst();
      }
      else if(ipos == iCount)
      {
        DeleteLast();
       }
      else
      {
        temp = head;

        for(i = 1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
       }
        iCount--;

}
template <class T>
void SinglyCL<T>::Display()
{
      if(head==NULL&& tail==NULL)
            {
                cout<<"linked list invaild\n";
                return ;

            }
            cout<<"element of linkedlist\n";

            do
           {
              cout<<"| |=>"<<head->data;
              head=head->next;
           }while(head!=tail->next);

           cout<<"\n";





}
template <class T>
int SinglyCL<T>::Count()
{



      return iCount;

}

int main()
{
    SinglyCL <int>sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.InsertAtPos(75,4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(4);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}