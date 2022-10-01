#include<iostream>

using namespace std;

class details
{
public:
    string text ;
    float real_value;
    int int_value;
    details operator <= (details const &obj)
     {
       details result;
         result.real_value =obj.real_value;
         result.int_value =  obj.int_value;
         result.text=text;
         return result;
    }
    void getDetails()
    {
        cout<<"enter the text details: ";
        cin>>this->text;
        cout<<"Enter the real value: ";
        cin>>this->real_value;
        cout<<"Enter the int value: ";
        cin>>this->int_value;

    }
    void display()
    {
        cout<<"Text is: "<<this->text<<endl;
        cout<<"Real value is: "<<this->real_value<<endl;
        cout<<"Int value is: "<<this->int_value<<endl;
    }
    
//    details(/* args */);
    ~details();
};




details::~details()
{
}
int main()
{
       details d[5];
       bool created = false;
       
       
    int choice, num, Choice;
    while(1)
    {
        cout<<"\n 1. Enter details (create details object).";
        cout<<"\n 2. Assign detail values (calls for overloading ‘<=’ operator).";
        cout<<"\n 3. Check substring or not.";
        cout<<"\n 4. Display all the objects.";
        cout<<"\n 5.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                  for(int i = 0;i<5;i++)
                  d[i].getDetails();
                 created = true;
                 
                }
                               
                break;
               
                case 2:
                {
                   try{
                       if(!created)
                       throw created;
                       int x, y;
                       cout<<"Enter the numbers objects to perform assigning: ";
                       cin>>x>>y;
                       if(x == y || x<=0 || x>5 || y<=0 || y>5)
                       {
                           cout<<"Points are invalid"<<endl;
                       }
                       else{
                           switch(x)
                           {
                               case 1: switch(y)
                               {
                                   case 2: d[0]<=d[1];
                                   break;
                                   case 3: d[0]<=d[2];
                                   break;

                                   case 4: d[0]<=d[3];
                                   break;

                                   case 5: d[0]<=d[4];
                                   break;
                                   default: break;

                               }
                               break;
                               case 2:switch(y)
                               {
                                   case 1: d[1]<=d[0];
                                   break;

                                   case 2: d[1]<=d[2];
                                   break;

                                   case 3: d[1]<=d[3];
                                   break;

                                   case 4: d[1]<=d[4];
                                   break; 
                               }
                               case 3:switch(y)
                               {
                                   case 1: d[2]<=d[0];
                                   break;

                                   case 2: d[2]<=d[1];
                                   break;

                                   case 3: d[2]<=d[3];
                                   break;

                                   case 4: d[2]<=d[4];
                                   break; 
                               }
                               case 4:switch(y)
                               {
                                   case 1: d[3]<=d[0];
                                   break;

                                   case 2: d[3]<=d[1];
                                   break;

                                   case 3: d[3]<=d[2];
                                   break;

                                   case 4: d[3]<=d[4];
                                   break; 
                               }
                               case 5:switch(y)
                               {
                                   case 1: d[4]<=d[0];
                                   break;

                                   case 2: d[4]<=d[1];
                                   break;

                                   case 3: d[4]<=d[2];
                                   break;

                                   case 4: d[4]<=d[3];
                                   break; 
                               }
                               
                           }
                       }
                   }
                   catch(bool val)
                   {
                       cout<<"details are not created yet"<<endl;
                   }
                }
                break;
                case 3:
                {
                  try{
                       if(!created)
                       throw created;

                   }
                   catch(bool val)
                   {
                       cout<<"details are not created yet"<<endl;
                   } 
                }
                break;
                case 4:
                {
                   try{
                       if(!created)
                       throw created;
                        for(int i = 0;i<5;i++)
                        d[i].display();
                   }
                   catch(bool val)
                   {
                       cout<<"details are not created yet"<<endl;
                       
                   }
                }
                break;
                case 5:
                exit(1);
                default:
                cout<<"\nWrong choice, try again!\n";
        }
    }

    
    
 return(0);
}

