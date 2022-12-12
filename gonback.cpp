#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	int n,ws,ca;
	srand(time(0)); 
	cout<<"Enter the sender window size: ";
	cin>>ws;
	cout<<"Enter the number of data to send: ";
	cin>>n;
	int x=3;
	bool flag = true,ackflag=false,error=false;
	int i = 1,sq=0,ack,lack=0,cer=0,ld=1;
	int counter=1;
	int frame[2];
	while(i<=n||!flag)
	{
		if(flag)
		{
			cout<<"\n\n------------------";
			cout<<"\nSender's side...\n";
			cout<<"------------------\n";
			if(cer!=2)
			{
			frame[0] = i;
			frame[1] = sq;
			if(ackflag)
			{
				cout<<"ack "<<ack<<" received\n";
				lack=ack;
				ld=i;
				ackflag = false;
			}
			cout<<"Frame "<<i<<" sent\nsequence no. "<<sq<<endl;
			i++;
			if(sq<ws)
			{
				sq++;
			}
			else
			{
				sq=0;
			}
		    }
		    else
		    {
		    	cout<<"Timer out!! ack "<<lack+1<<" not received"<<endl;
		    	cout<<"Resending Frames from sequnce number "<<lack<<endl;
		    	frame[0] = i=ld;
			    frame[1] = sq=lack;
		    	cout<<"Frame "<<i<<" sent\nsequence no. "<<sq<<endl;
			    i++;
			    if(sq<ws)
			   {
				sq++;
			   }
			   else
			   {
				sq=0;
			   }
			   error = false;
			   cer=0;		    	
			}
			ca=rand()%(7);
			flag = false;
		}
		else
		{
			cout<<"\n\n\t\t\t------------------";
			cout<<"\n\t\t\tReceiver's side...\n";
			cout<<"\t\t\t------------------\n";
			if(!error)
			{				
			switch(ca)
			{
				case 1: cout<<"\t\t\tFrame "<<frame[0]<<" received with sequence no. "<<frame[1]<<endl;
				        cout<<"\t\t\tData frame received is damaged...\n\n";
				            if(i==n)
		   	                {
			                 cer=2;
			                 i--;		   		
			                }
					        error = true;
					        break;
				case 2: cout<<"\t\t\tData frame not received...\n\n";
				            if(i==n)
		   	                {
			                 cer=2;
			                 i--;		   		
			                }
					        error = true;
					        break;
				case 3: cout<<"\t\t\tFrame "<<frame[0]<<" received with sequence no. "<<frame[1]<<endl;
					      ack = frame[1]+1;
				          cout<<"\t\t\tack "<<ack<<" sent\n";
				          cer++;
				          counter = 0;
				          x=2+rand()%(ws-1);
					      break;
				default: cout<<"\t\t\tFrame "<<frame[0]<<" received with sequence no. "<<frame[1]<<endl;
				         if(counter++==x||i==n+1)
		             	{
				          ack = frame[1]+1;
				          cout<<"\t\t\tack "<<ack<<" sent\n";
				          counter = 0;
				          x=2+rand()%(ws-1);
				          ackflag= true;
			            }
					    break;
		        }
		        flag = true;
		   }
		   else
		   {
		   	cout<<"\t\t\tFrame "<<frame[0]<<" received with sequence no. "<<frame[1]<<endl;
		   	cout<<"\t\t\tFrame"<<frame[0]<<" discarded "<<endl;
		   	cer++;
		   	if(i=n)
		   	{
			   cer=2;
			   i--;		   		
			}
		   	flag = true;
		   }	 
		   }
		}
		cout<<"\n\n------------------";
		cout<<"\nSender's side...\n";
		cout<<"------------------\n";
		cout<<"ack "<<ack<<" received\n";
		cout<<"No more frames to send\n";
		cout<<"\n\nFrame transfering executed successfully...";		
	}
