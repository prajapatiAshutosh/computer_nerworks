#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;
class crc
{
	private:
		int gsize,msize,*g,*m,x,*temp;
	public:
		crc()		//Taking generating polynomial and size of message bits  
		{
			cout<<"\n Enter the Generating polynomial size :- ";
			cin>>gsize;
			g=new int[gsize+1];
			cout<<"\n Enter the Generating polynomial :- ";
			for(int i=0;i<gsize+1;i++)
			cin>>g[i];
			if(g[0]==0)
			{
				cout<<"\n Error in generating polynomial !! ";
				exit(-1);
			}
			cout<<"\n Enter the message bits size :- ";
			cin>>msize;
			m=new int[msize+gsize];
		}
		
	void enter()
		{
			cout<<"\n Enter the message :- ";		// Taking message bits     
			for(int i=0;i<msize;i++)
				cin>>m[i];
			for(int i=msize;i<msize+gsize;i++)
				m[i]=0;
		}
		
	void calculate()			//calculating crc code 
		{
			int mi=0;
			int *temp=new int[gsize+1];//dekhio generator size ka array
			for(int i=0;i<gsize+1;i++)//till gsize
				temp[i]=m[mi++];
				
			while(mi<msize+gsize)
			{
				for(int i=0;i<gsize+1;i++)	// Dividing with generating polynomial
				{
					if(temp[i]==g[i])
						temp[i]=0;
					else
						temp[i]=1;
				}
				if(temp[0]==0)	// Shifting the bits when first bit of rem. is 0
				{
					for(int i=0;i<gsize+1;i++)
					{
						temp[i]=temp[i+1];
					}
					temp[gsize]=m[mi++];
				}
			}	
			for(int i=0;i<gsize;i++)		//y	// To get actual crc code
			{
				temp[i]=temp[i+1];
			}
			temp[gsize]=m[mi++];
				int flag=0;
			for(int i=msize;i<gsize+msize;i++)
				m[i]=temp[flag++];
		}

	void random() 					//To cause an error 
		{ 
			//srand(time(0));//wht??
			x=rand()%(gsize+msize+10);
			if(x<gsize+msize)//othbit pe error q ni aa skta
			{
				if(m[x-1]==0)
					m[x-1]=1;
				else
					m[x-1]=0;
			}
		}
		
	void check()	//To check whether the message is right or corrupted one
		{	
			int mi=0,flag=0;
			int *temp=new int[gsize+1];
			for(int i=0;i<gsize+1;i++)
				temp[i]=m[mi++];	
			while(mi<msize+gsize)
			{
				for(int i=0;i<gsize+1;i++)
				{
					if(temp[i]==g[i])
						temp[i]=0;
					else
						temp[i]=1;
				}
				if(temp[0]==0)
				{
					for(int i=0;i<gsize+1;i++)
					{
							temp[i]=temp[i+1];
					}
					temp[gsize]=m[mi++];
				}
			}
			for(int i=0;i<gsize;i++)
			{
				temp[i]=temp[i+1];
			}
			temp[gsize]=m[mi++];

			for(int i=0;i<gsize;i++)			//Checking whether the remainder is 0 or not 
			{
				if(temp[i]!=0)
				{
					flag=1;
					break;
				}
			}

			if(flag==0)					
			{
				cout<<"\n Data reciever :- ";
				show();
			}
			else
				{
					cout<<"\n Your data is corrupted /n";
					//cout<<"\n Error is in  "<<x<<" bit \n";
				}
		}
	void show()
	{
		cout<<"\n";
		for(int i=0;i<msize+gsize;i++)
			cout<<m[i]<<" ";
	}
};


void reciever(crc b)
{
	b.check();
}
void sender()
{
	crc a;
	a.enter();
	a.calculate();
	cout<<"\n******* MAIN MENU *********";
	cout<<"\n 1) NOISY CHANNEL \n";
	cout<<"\n 2) NOISELESS CHANNEL \n";
	int choice;
	cout<<"\nEnter your choice  ";
	cin>>choice;
	if(choice==1){
		a.random();
	reciever(a);
	}
	else
	reciever(a);
}


int main()
{
	sender();
	return 0;
}