#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	bool flag = true,err=false;
	int size;
	cout<<"Enter the number of data to send: ";
	cin>>size;
	int data[size];
	cout<<"Enter the data: \n";
	for(int j=0;j<size;j++)
	{
		cin>>data[j];
	}
	int ack = 1,x=0;
	int frame[2];
	int i=0;
	while(i<=size)
	{
		if(flag)
		{			
			if(i!=size)
			{
				cout<<"\n-----------------------\n";
		    	cout<<"Sender's side\n";
			    cout<<"-----------------------\n";
			    if(err)
			    {
				   cout<<"Timer out!!\nAcknowldegement not received\n";
				   err=false;
			    }
			    else
			    {
			    	if(i!=0)
			    	{
			    		cout<<"Acknoledgement received: ACK"<<ack<<endl;
					}
				}
				frame[0]=data[i++];
			    frame[1]=ack;
			    cout<<"Frame send by sender: "<<frame[0];
				cout<<endl<<"with sequence number: "<<frame[1]<<endl;
			    x=rand()%(7);
			    flag = false;
			}
		}
		else
		{
			cout<<"\n-----------------------\n";
			cout<<"Receiver's side\n";
			cout<<"-----------------------\n";
			switch(x)
				{
					case 1: cout<<"Frame received by receiver....\n";
					        cout<<"Frame received is damaged...\n\n";
					        err=true;
					        i--;
					        break;
					case 2: cout<<"No frame Received...\n\n";
					        err=true;
					        i--;
					        break;
					case 3: cout<<"Data received by Receiver: "<<frame[0]<<endl;
					        int temp;
					        if(ack == 1)
					           temp = 0;
					        else
					          temp = 1;
					        cout<<"Acknowledgement send to Sender... ACK: "<<temp<<endl;
					        err=true;
					        i--;
					        break;
					default: cout<<"Data received by Receiver:"<<frame[0]<<endl;
					        if(ack == 1)
					           ack = 0;
					        else
					           ack = 1;
					        cout<<"Acknowledgement send to Sender... ACK"<<ack<<endl<<endl;
					        break;
		        }
		        flag = true;
		}
		
	}
	cout<<"\n-----------------------\n";
	cout<<"Sender's side\n";
    cout<<"-----------------------\n";
    cout<<"Acknowledgement received: ACK"<<ack<<endl;
    cout<<"No Frames to send...\n";	
}