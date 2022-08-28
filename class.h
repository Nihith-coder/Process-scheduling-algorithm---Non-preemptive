#include "data.h"
 
class process
{
    Node p[1000];
    //vector<Node> p_v;
    int n;
    public:
    process()
    {
        n = 10;
        for(int i = 0 ; i < n ; i++)
        {
            p[i].at = i +1;
            p[i].bt = 10- i;
            p[i].pri =1;
        }
    }
    ~process(){}
    
    friend istream& operator>>(istream& inp , process& pr);
    friend ostream& operator<<(ostream& out , process & pr);
    void sort();
    void findwt(Node p[], int n );
    void findtat(Node p[], int n );
    void findst(Node p[], int n);
};
 
istream& operator>>(istream& inp ,process & pr)
{
    cout<<"Enter the number of processes: ";
        inp>>pr.n;
        for(int i = 0; i < pr.n; i++)
        {
            
            cout<<"Enter the process "<<i+1<<" details:\n ";
            pr.p[0].pid = 0;
            
            if(i)
                pr.p[i].pid = 1 + pr.p[i-1].pid;
                
            /*cout<<"Arrival Time :";
            inp>>pr.p[i].at;
            cout<<"Burst Time :";
            inp>>pr.p[i].bt;*/
            cout<<"Priority :";
            inp>>pr.p[i].pri;
            pr.p[i].at = rand()%6;
            pr.p[i].bt = rand()%6;
        }
                
        return inp;
}
 
ostream& operator<<(ostream& out , process & pr)
{
        int total_wt = 0;
        int total_tat = 0;
        pr.sort();
        pr.findwt(pr.p , pr.n);
        pr.findtat(pr.p , pr.n);
        pr.findst(pr.p,pr.n);
        
        cout << "\nProcesses  "<<" Arrival time "<<"  Priority  "<<" Completion time "<< " Burst time  " << " Waiting time  " << " Turn around time\n"; 
  
    for (int  i=0; i<pr.n; i++) 
    { 
        total_wt = total_wt + pr.p[i].wt; 
        total_tat = total_tat + pr.p[i].tat; 
        cout << "   " << pr.p[i].pid << "\t\t"<<pr.p[i].at<<"\t\t"<<pr.p[i].pri<<"\t\t"<<pr.p[i].ct<<"\t\t"<< pr.p[i].bt << "\t\t" << pr.p[i].wt << "\t\t  " << pr.p[i].tat <<endl; 
    } 
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)pr.n; 
    cout << "\nAverage turn around time = " << (float)total_tat / (float)pr.n; 
        return out;
}
void process::sort() 
{ 
    int temp;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n-1 ;j++)
        {
            
            if(p[j].pri < p[j+1].pri && p[j].at == p[j+1].at )
            {
                temp = p[j].pri;
                p[j].pri = p[j+1].pri;
                p[j+1].pri = temp;
                
                temp = p[j].bt;
                p[j].bt = p[j+1].bt;
                p[j+1].bt = temp;
                    
                temp = p[j].pid;
                p[j].pid = p[j+1].pid;
                p[j+1].pid = temp;
            }
            else if( p[j].at > p[j+1].at )
            {
                temp = p[j].pri;
                p[j].pri = p[j+1].pri;
                p[j+1].pri = temp;
                
                temp = p[j].bt;
                p[j].bt = p[j+1].bt;
                p[j+1].bt = temp;
                    
                temp = p[j].pid;
                p[j].pid = p[j+1].pid;
                p[j+1].pid = temp;
                
                temp = p[j].at;
                p[j].at = p[j+1].at;
                p[j+1].at = temp;
            }
        }
    }
}
    
void process::findwt(Node p[], int n )
{
    int service[100];
    service[0] = p[0].at; 
    p[0].wt=0; 
  
    for(int i=1;i< n ;i++) 
    { 
        service[i]=p[i-1].bt+service[i-1];        
  
        p[i].wt=service[i] - p[i].at;
        
        if(p[i].wt<0) 
        { 
            p[i].wt=0; 
        } 
       
    } 
}
 
void process::findtat(Node p[], int n )
{ 
    for (int  i = 0; i < n ; i++ ) 
        p[i].tat =  p[i].bt + p[i].wt;          
}

void process::findst(Node p[] , int n)
{
    p[0].st = p[0].at;                     
    p[0].ct=p[0].st + p[0].tat;          
  
for(int i=1;i<n;i++) 
    { 
        p[i].st=p[i-1].ct; 
        p[i].ct = p[i].st+p[i].tat - p[i].wt; 
    } 
}
