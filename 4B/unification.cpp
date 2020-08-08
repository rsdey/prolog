#include<iostream>
#include<string.h>
using namespace std;

int np;
int na[10];
int i,j;
string predicate[10];
string argument[10][10];


void unify();
void display();
void checking();


   int main()
   {
   char ch;
   do{
   

 
            cout<<"**********PROGRAM FOR UNIFICATION*********\n";
            cout<<"\nEnter number of predicates : ";
            cin>>np;
			

            for(i=0;i<np;i++)
            {
               
            cout<<"\nEnter Predicate "<<i+1<<":";
            cin>>predicate[i];
            cout<<"\nEnter number of arguments for the predicate "<<predicate[i]<<":";
            cin>>na[i];
                        for(j=0;j<na[i];j++)
                        {
                         
                         cout<<"\nEnter argument"<<j+1<<":";
                         cin>>argument[i][j];
                        }
            }

            display();
            cout<<"\n\n**********UNIFICATION RESULT**********";
            checking();
            
            
            cout<<"\nDo you want to continue(y/n):";
            cin>>ch;
       }while(ch == 'y');
       return 0;
   }



   void display()
   {
       cout<<"\n ********** THE PREDICATES ARE **********";
            for(i=0;i<np;i++)
            {
             cout<<"\n"<<predicate[i]<<"(";
                        for(j=0;j<na[i];j++)
                        {
                        cout<<argument[i][j];
                        if(j!=na[i]-1)
                                    cout<<",";
                        }
             cout<<")";
            }
   }

   void checking()
   {
   int pf=0;
   int af=0;

 
            for(i=0;i<np-1;i++)
            {
                        if(predicate[i]!=predicate[i+1])
                        {
                        cout<<"\nThe predicates not same.";
                        cout<<"\nUnification cannot be done";
                        pf=1;
                        break;
                        }
            }

     if(pf!=1)
     {
            for(i=0;i<na[i]-1;i++)
            {
                        if(na[i]!=na[i+1])
                        {
                        cout<<"\nArguments are not unifiable.";
                        af=1;
                        break;
                        }
            }
     }
            if(af==0 && pf==0)
                        unify();

   }

   void unify()
   {
            int flag=0;
            for(i=0;i<np-1;i++)
            {
                 for(j=0;j<na[i];j++)
                 {
                        if(argument[i][j]!=argument[i+1][j])
                        {
                          if(flag==0)
                          cout<<"\n\n SUBSTITUITION : ";
                        cout<<"\n"<<argument[i+1][j]<<" = "<<argument[i][j];
                         flag++;
                        }
                }
            }
            if(flag==0)
            {          cout<<"\nArguments are Identical.";
                        cout<<"\nNo Substitution is Possible.\n";
            }
   }




