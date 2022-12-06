// implementation of function overloading
// cs20b1085 gugulothu ravindar

#include<iostream>
using namespace std;

class list
{
 private:
         int data;
         list * next;
         list * head1;
         list * head2;
         int number;
         list * head3;
         list *head;
 public:
        void getData()
        {
         int num1;
         cout<<"Enter the number of nodes in linked list 1"<<endl;
         cin>>num1;
         
         printlist(num1);
        }
 
        void printlist(int num1)
        {
         list *temp,*newnode;
         
         head1 = (list*)malloc(sizeof(list));
         
         if(head1 == NULL)
         {
          cout<<"Unable to allocate memory"<<endl;
         }
         else
         {
          cout<<"Enter data of node 1 : ";
          cin>>data;
          
          head1->data = data;
          head1->next = NULL;
          
          temp = head1;
          
          for(int i=2 ; i<=num1 ; i++)
          {
           newnode = (list*)malloc(sizeof(list));
           
           if(newnode == NULL)
           {
            cout<<"Unable to allocate memory"<<endl;
           }
           else
           {
            cout<<"Enter the data node "<<i<<" : ";
            cin>>data;
           }
            newnode->data = data;
            newnode->next = NULL;
            
            temp->next = newnode;
            temp = temp->next;
          }
         }
        }
        
        void setData()
        {
         float num2;
         cout<<"Enter the number of nodes in linked list 2"<<endl;
         cin>>num2;
         
         printlist(num2);
        }
 
        void printlist(float num2)
        {
         list *temp,*newnode;
         
         head2 = (list*)malloc(sizeof(list));
         
         if(head2 == NULL)
         {
          cout<<"Unable to allocate memory"<<endl;
         }
         else
         {
          cout<<"Enter data of node 1 : ";
          cin>>data;
          
          head2->data = data;
          head2->next = NULL;
          
          temp = head2;
          
          for(int i=2 ; i<=num2 ; i++)
          {
           newnode = (list*)malloc(sizeof(list));
           
           if(newnode == NULL)
           {
            cout<<"Unable to allocate memory"<<endl;
           }
           else
           {
            cout<<"Enter the data node "<<i<<" : ";
            cin>>data;
           }
            newnode->data = data;
            newnode->next = NULL;
            
            temp->next = newnode;
            temp = temp->next;
          }
         }
        }
   void display1()
    {
            list *temp = head1;
           while(temp != NULL)
         {
        cout<<" "<<temp->data<<"->"; 
        temp = temp->next;
        
         }
    }
    void display2()
    {
            list *temp = head2;
           while(temp != NULL)
         {
        cout<<" "<<temp->data<<"->"; 
        temp = temp->next;
        
         }
    }
    list operator + (list const &head3)
    {
      if (head == NULL)
    {
      head = head3.head;
      //cout << "\033[1;34mMERGED SUCCESSFULLY\033[0m" << endl;
      return head3;
    }
    else
    {
      list *travel = head;
      while (travel->next != NULL)
        travel = travel->next;
      travel->next = head3.head;
      //this->sort();
      //cout << "\033[1;34mMERGED SUCCESSFULLY\033[0m" << endl;
      return head3;
    }
    }
      void print()
      {
        cout<<head1<<" + "<<head2<<endl;
      }
 };
int main()
{
       class list l1;
       class list l2;
       class list l3;
    int choice, num, Choice;
    while(1)
    {
        cout<<"\n 1. insertSort\n 2. mergeSort(operator overload)\n 3.display \n 4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                  l1.getData();
                  l2.setData();  
                }                   
                break;
               
                case 2:
                {
                   l3 = l1 + l2;
                   l3.print();
                }
                break;
                case 3:
                {
                  l1.display1();
                  l2.display2();
                }
                break;
            case 4:
                exit(1);
            default:
                cout<<"\nWrong choice, try again!\n";
        }
    }

    
    
 return(0);
}