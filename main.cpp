#include "class.h"
 
 
int main()
{
    vector<process>pr ;        //vector which collect the object data types
    int i = 0;
    int n = 1;
    while(n != 0)
    {
        process p ;      //object created at an instant
        pr.push_back(p);
        cout<<"Enter the priority scheduling data:\n ";
        cin>>pr[i];
        cout<<pr[i]<<endl;
        cout<<"Enter any number to continue and 0 to stop: ";
        cin>>n;
        i++;
    }
    
    return 0;
}
