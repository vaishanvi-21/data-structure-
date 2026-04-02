#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};









template <class T>
class DoublyCL
{
    public:
        struct node <T>* head;
        struct node<T> *tail;
        int iCount;



       DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};
       template<class T>
        DoublyCL<T>::DoublyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

         template<class T>
        void DoublyCL<T>:: InsertFirst(T no)
        {
            struct node<T>* newn=NULL;
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
                head->prev=newn;
                head=newn;
            }
            tail->next=head;
            head->prev=tail;
            iCount++;
        }
        template<class T>
        void DoublyCL<T>::InsertLast(T no)
        {
           struct node<T>*newn=NULL;
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
               newn->prev=tail;

               tail=newn;

            }
            tail->next=head;
            head->prev=tail;
            iCount++;

        }
        template<class T>
        void DoublyCL<T>:: InsertAtPos(T no, int ipos) 
        {
            struct node<T>* newn=NULL;
           struct node<T>* temp=NULL;

            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;

           if((ipos<1)||(ipos>iCount+1))
           {
              cout<<"invalid linked list\n";
              return;
           }
           if(ipos==1)
           {
            InsertFirst(no);
           }
           else if(ipos==iCount+1)
           {
            InsertLast(no);
           }
           else
           {
            temp=head;
            int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp->next;
            }
            newn->next=temp->next;
            temp->next->prev=newn;

           }
           temp->next=newn;
           newn->prev=temp;

           iCount++;
        }
        template<class T>
        void  DoublyCL<T>::DeleteFirst()
        {
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
                head=head->next;
                delete(tail->next);



            }
            tail->next=head;
            head->prev=tail;

            iCount--;
        }
        template<class T>
        void DoublyCL<T>:: DeleteLast()
        {
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

              tail=tail->prev;
              delete(tail->next);
              tail->next=NULL;



            }
            tail->next=head;
            head->prev=tail;

            iCount--;
        }
        template<class T>
        void DoublyCL<T>:: DeleteAtPos(int ipos)
        {
            struct node<T>* target=NULL;
           struct node<T>* temp=NULL;

           if((ipos<1)||(ipos>iCount))
           {
              cout<<"invalid linked list\n";
              return;
           }
           if(ipos==1)
           {
            DeleteFirst();
           }
           else if(ipos==iCount)
           {
            DeleteLast();
           }
           else
           {
            temp=head;
            int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp->next;

            }
             temp->next=temp->next->next;
             delete(temp->next->prev);

              temp->next->prev=temp;





           }
           iCount--;

        }
        template<class T>
        void  DoublyCL<T>::Display()
        {
               if(head==NULL&& tail==NULL)
            {
                cout<<"linked list invaild\n";
                return ;

            }
            cout<<"element of linkedlist\n";

            do
           {
              cout<<"|"<< head->data<<"|=>";
              head=head->next;
           }while(head!=tail->next);

           cout<<"\n";

        }
        template<class T>
        int DoublyCL<T>:: Count()
        {





            return iCount;
        }



int main()
{
    DoublyCL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";











    return 0;
}
Next[10:14 AM]#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template <class T>
class DoublyLL
{
    public:
        struct node <T>* head;
        struct node<T>*temp;

        int iCount;



       DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};
       template<class T>
       DoublyLL<T>::DoublyLL()
        {
            head = NULL;

            iCount = 0;
        }

         template<class T>
        void DoublyLL<T>:: InsertFirst(T no)
        {
            struct node<T>* newn=NULL;
            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;
            if(head==NULL)
            {
                head=newn;

            }
            else
            {
                newn->next=head;
                head->prev=newn;
                head=newn;
            }

            iCount++;
        }
        template<class T>
        void DoublyLL<T>::InsertLast(T no)
        {
           struct node<T>*newn=NULL;
            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;
            if(head==NULL)
            {
                head=newn;

            }
            else
            {
              struct node<T>*temp=NULL;
              temp=head;

              while(temp->next!=NULL)
              {
                temp=temp->next;
              }
              temp->next=newn;
              newn->prev=temp;

            }

            iCount++;

        }
        template<class T>
        void DoublyLL<T>:: InsertAtPos(T no, int ipos) 
        {
            struct node<T>* newn=NULL;
           struct node<T>* temp=NULL;

            newn = new node<T>;  
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;

           if((ipos<1)||(ipos>iCount+1))
           {
              cout<<"invalid linked list\n";
              return;
           }
           if(ipos==1)
           {
            InsertFirst(no);
           }
           else if(ipos==iCount+1)
           {
            InsertLast(no);
           }
           else
           {
             temp=head;
             int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp->next;
            }





              newn->next = temp->next;    
             temp->next->prev = newn;    
              temp->next = newn;          
             newn->prev = temp;  
           }
           iCount++;
        }
        template<class T>
        void  DoublyLL<T>::DeleteFirst()
        {
            if(head==NULL)
            {
                return;
            }
            else if(head->next=NULL)
            {
                head=NULL;

            }
            else
            {
                head=head->next;
                delete(head->prev);
                head->prev=NULL;



            }



            iCount--;
        }
        template<class T>
        void DoublyLL<T>:: DeleteLast()
        {
               if(head==NULL)
            {
                return;
            }
            else if(head->next==NULL)
            {
                head=NULL;

            }
            else
            {

              temp = head;

              while(temp->next->next != NULL)
             {
                temp = temp -> next;
             }

             delete(temp->next);
             temp->next = NULL;



            }



            iCount--;
        }
        template<class T>
        void DoublyLL<T>:: DeleteAtPos(int ipos)
        {
            struct node<T>* target=NULL;
           struct node<T>* temp=NULL;

           if((ipos<1)||(ipos>iCount))
           {
              cout<<"invalid linked list\n";
              return;
           }
           if(ipos==1)
           {
            DeleteFirst();
           }
           else if(ipos==iCount)
           {
            DeleteLast();
           }
           else
           {
            temp=head;
            int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp->next;

            }
               target = temp->next;

           temp->next = target -> next;   
            temp->next->prev = temp;        
            delete(target);                     
           }   

             iCount--;  

           }





        template<class T>
        void  DoublyLL<T>::Display()
        {
            cout<<"Elements of the LinkedList are : \n"  ;

         cout<<"NULL <=> ";
        while(head != NULL)
       {
       cout<<"| %d | <=> "<<head->data;
        head = head->next;  
        }

        }
        template<class T>
        int DoublyLL<T>:: Count()
        {





            return iCount;
        }



int main()
{
    DoublyLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";


    return 0;
}