#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

void print(int ar[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

int bintodec(int ar[],int size)
{
	int temp[size];
	for(int i=0;i<size;i++)
	{
		temp[i]=ar[size-1-i];
	}
	int bin=0;
	for(int i=0;i<size;i++)
	{
		bin = bin+(temp[i]*pow(2,i));
	}
	return bin;
}

void dectobin(int ar[],int size,int dec)
{
	for(int i=0;i<size;i++)
	{
		ar[i]=0;
	}
	
	for(int j=size;j>0 && dec!=0;j--)
	{
		ar[j-1]=dec%2;
		dec=dec/2;
	}
	return;
}

int main()
{
	int m;
	cout<<"Enter the size of Data Word: ";
	cin>>m;
	int data[m];
	cout<<"Enter the Data Word: ";
	for(int i=0;i<m;i++)
	{
		cin>>data[i];
	}
	int r=0;
	for(;r>=0;r++)
	{
		if(pow(2,r)>=(m+r+1))
		   break;
	}
	int ar[m+r][r];
	for(int i=0;i<m+r;i++)
	{
		for(int j=0;j<r;j++)
		{
			ar[i][j]=0;
		}
	}
	int temp[r];	
	for(int i=1;i<=m+r;i++)
	{
		dectobin(temp,r,i);
		for(int j=0;j<r;j++)
		{
			ar[i-1][j]=temp[j];
		}
	}
    int codeword[m+r];
	for(int i=m+r,k=m,a=0;i>0;i--)
	{
		if( pow(2,a)==(m+r-i+1))
		{
			codeword[i-1]=0;
			a++;
		}
		else
		    codeword[i-1]=data[--k];
	}
	int rbit[r];
	for(int i=0;i<r;i++)
	{
		rbit[i]=0;
	}	
	for(int i=r-1;i>=0;i--)
	{
		for(int j=0;j<m+r;j++)
		{
			if(ar[j][i]==1)
			{
				rbit[i]=rbit[i]+codeword[(m+r)-j-1];
			}
		}
	}
	for(int i=0;i<r;i++)
	{
		if(rbit[r-1-i]%2==0)
		{
			codeword[m+r-int(pow(2,i))]=0;
		}
		else
		{
			codeword[m+r-int(pow(2,i))]=1;
		}
		
	}
	cout<<"Code word genertaed by the Sender is: \n";
	print(codeword,m+r);	
	cout<<"\n\nSending code word to receiver: \n";
	int x=rand()%(m+r+10);
	if(x<m+r)
	{
		if (codeword[x] == 1)
		{
			codeword[x] = 0;
		}
		else
		{
			codeword[x] = 1;
		}
	}
	cout<<"\nCodeword received by receiver: \n";
	print(codeword,m+r);
	cout<<"\nChecking Codeword...\n";
	for(int i=0;i<r;i++)
	{
		rbit[i]=0;
	}	
	for(int i=r-1;i>=0;i--)
	{
		for(int j=0;j<m+r;j++)
		{
			if(ar[j][i]==1)
			{
				rbit[i]=rbit[i]+codeword[(m+r)-j-1];
			}
		}
	}
	for(int i=0;i<r;i++)
	{
		rbit[i]=rbit[i]%2;
	}
	int y = bintodec(rbit,r);
	if(y!=0)
	{
		cout<<"Error detected in code word...\nImplemeting correction technique..\n";
		cout<<"\nError dtected at position: "<<y<<endl;
		if(codeword[m+r-y]==1)
		{
			codeword[m+r-y]=0;
		}
		else
		{
			codeword[m+r-y]=1;
		}
		cout<<"code word after correction..\n";
		print(codeword,m+r);
		
	}
	else
	{
		cout<<"No error in received codeword..";
	}
	
}