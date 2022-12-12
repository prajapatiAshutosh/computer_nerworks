#include<iostream>
using namespace std;

class node
{
	int length;
	int pred;
	
	public:
	node(int l=-1,int p=-1)
	{
		int length=l;
		int pred=p;
	}
	friend int main(); 
};

int main()
{
	int n,c;
	cout<<"Enter the numbers of router: ";
	cin>>n;
	node** ar=new node*[n];
	for(int i=0;i<n;i++)
	{
		ar[i]=new node[n];
	}
	cout<<"Your routers are named as: ";
	for(int i=0;i<n;i++)
	{
		cout<<i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ar[i][j].pred=ar[i][j].length=-1;
			if(i==j)
			{
				ar[i][j].length=0;
				ar[i][j].pred=i;
			}	
		}
	}
	cout<<endl<<"Enter the number of connections in the network: ";
	cin>>c;
	cout<<"Enter the nodes connected and length between them: \n";
	for(int i=0;i<c;i++)
	{
		int n1,n2;
		cin>>n1>>n2;
		cin>>ar[n1][n2].length;
		ar[n1][n2].pred=n1;	
		ar[n2][n1].length=ar[n1][n2].length;
		ar[n2][n1].pred=n2;			
	}
	cout<<"\t ";
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t";
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j].length<<"\t";
		}
		cout<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		int nextnode,l;
		for(int j=0,nextnode=j,l=ar[i][j].length;j<n;j++)
		{
			if(l<ar[i][j].length&&ar[i][j].length!=-1)
			{
				nextnode=j;
				l=ar[i][j].length;
			}
		}
		
	}
	
}