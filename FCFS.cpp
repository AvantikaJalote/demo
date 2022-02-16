#include <iostream>
 
using namespace std;

struct data
{
    int p_id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
}d[10];

int main()
{
    float avg_TAT=0; //to store avg TAT
    float avg_WT=0; //to store avg WT

    int n; // stores the number of proccess are to be executed
    cout<<"\nEnter the number of processes: ";
    cin>>n;

    //stores values for AT and BT
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter process id: ";
        cin>>d[i].p_id;
        cout<<"Enter the arrival time: ";
        cin>>d[i].AT;
        cout<<"Enter the burst time: ";
        cin>>d[i].BT;
    }


    //to sort AT in ascending order of arrival
    data temp;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n-i-1; j++) 
        {
            if(d[j].AT>d[j+1].AT) 
            {
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }

    //calculation of completion time
    d[0].CT=d[0].AT+d[0].BT;
    for(int i=1; i<n; i++)
    {
        d[i].CT=d[i-1].CT+d[i].BT;
    }
    
    //calculation of TAT
    for(int i=0; i<n; i++)
    {
        d[i].TAT= d[i].CT-d[i].AT;
    }

    //calculation of WT
    for(int i=0; i<n; i++)
    {
         d[i].WT= d[i].TAT- d[i].BT;
    }

    //display
    cout<<"\nFIRST COME FIRST SERVE: "<<endl;
    cout<<"\nPId\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<d[i].p_id<<"\t";
        cout<<d[i].AT<<"\t";
        cout<<d[i].BT<<"\t";
        cout<<d[i].CT<<"\t";
        cout<<d[i].TAT<<"\t";
        cout<<d[i].WT<<"\t";
        cout<<endl;
    }
    
    //calculation of average waiting time and turn around time
    for(int i=0;i<n;i++)
    {
        avg_TAT+=d[i].TAT;
        avg_WT+=d[i].WT;
    }

    avg_TAT/=n;
    avg_WT/=n;

    cout<<"\nAverage turn around time is: "<<avg_TAT;
    cout<<"\nAverage waiting time is: "<<avg_WT;

    return 0;
}