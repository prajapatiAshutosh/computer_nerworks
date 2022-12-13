#include<iostream>
using namespace std;


void addcarry(int temp[],int n,int carry){
        if(carry==0){
            return ;
        }
        int *temp2=new int[n];
        for(int i=0;i<n-1;i++){
            temp2[i]=0;
        }
        temp2[n-1]=carry;
        
        int incarry=0;
        for(int i=n-1;i>=0;i--){
           if(temp[i]+temp2[i]+incarry==0){
                temp[i]=0;
                incarry=0;
            }
            else if(temp2[i]+temp[i]+incarry==1){
                temp[i]=1;
                incarry=0;
            }
            else if(temp2[i]+temp[i]+incarry==2){
                temp[i]=0;
                incarry=1;
            }
            else{
                temp[i]=1;
                incarry=1;

            }
        
        }
       
        addcarry(temp,n,incarry);
}


void add(int arr[],int i,int n,int temp[]){
    // here the size of both the arrays is n and we need to add the corresponding elements into it using binary operation 
    // also to add the carry if required
    int carry=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]+temp[i]+carry==0){
            temp[i]=0;
            carry=0;
        }
        else if(arr[i]+temp[i]+carry==1){
            temp[i]=1;
            carry=0;
        }
        else if(arr[i]+temp[i]+carry==2){
            temp[i]=0;
            carry=1;
        }
        else{
            temp[i]=1;
            carry=1;

        }
        
    }
    //  cout<<"Intermediate result is "<<endl;
    //     for(int i=0;i<n;i++){
    //         cout<<temp[i]<<" ";
    //     }
    //     cout<<endl;
    if(carry==1){
            addcarry(temp,n,carry);

     }

}




int main(){
   cout<<"Enter the length of the dataword"<<endl;
   int size;
   cin>>size;
   int *arr;
   
   cout<<"Enter the length of the checksum"<<endl;
   int  n;
   cin>>n;
   int ext=0;
   if(size%n==0){
      arr=new int[size];
      cout<<"Enter the datawaord"<<endl;
      for(int i=0;i<size;i++){
        cin>>arr[i];
      }
      
   }
   
   else{
       ext=n-size%n;
      arr=new int[size+ext];
      for(int i=0;i<ext;i++){
        arr[i]=0;
      }
      cout<<"Enter the dataword"<<endl;
      for(int i=ext;i<size+ext;i++){
        cin>>arr[i];
      }
      
   }
   
   size+=ext;
   cout<<size<<endl;
   for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;

   int number=size/n;
   cout<<number<<endl;
   
   int **temp;
   temp=new int*[number];
   int cnt=0;
   for(int i=0;i<number;i++){
    temp[i]=new int[n];
    for(int j=0;j<n;j++){
       temp[i][j]=arr[cnt];
       cnt++;
    }
   }
   // now the 2-d array has the data into it
   for(int i=0;i<number;i++){
    for(int j=0;j<n;j++){
        cout<<temp[i][j]<<" ";
    }
    cout<<endl;
   }
   
   int *temp2=new int[n];
   for(int i=0;i<n;i++){
    temp2[i]=0;
   }
//    for(int i=0;i<n;i++){
//      cout<<temp2[i]<<" ";
//    }
   cout<<endl;
   for(int i=0;i<number;i++){
        int *temp1=new int[n];
        for(int j=0;j<n;j++){
            temp1[j]=temp[i][j];
        }
        cout<<"adding "<<endl;
        for(int j=0;j<n;j++){
            cout<<temp1[j]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){

         cout<<temp2[i]<<" ";
        }
        cout<<"upto"<<endl;
        
        add(temp1,i,n,temp2);

        cout<<"and result is"<<endl;
        for(int i=0;i<n;i++){

         cout<<temp2[i]<<" ";
        }
        
        
   }
//    for(int i=0;i<n;i++){
//      cout<<temp2[i]<<" ";
//    }

   // now step is to flip the bit in the temp 2 and then add it to the dataword
   for(int i=0;i<n;i++){
     if(temp2[i]==0){
        temp2[i]=1;
     }
     else{
        temp2[i]=0;
     }
   }
   cout<<endl;

   // now we need to create another 2-D array which represents the code word
   int **codeword;
   codeword=new int*[number+1];
   cnt=0;
   for(int i=0;i<number;i++){
       codeword[i]=new int[n];
       for(int j=0;j<n;j++){
        codeword[i][j]=arr[cnt];
        cnt++;
       }
   }
   codeword[number]=new int[n];
   for(int i=0;i<n;i++){
    codeword[number][i]=temp2[i];
   }


   cout<<"The data in the codeword is "<<endl;
   for(int i=0;i<=number;i++){
    for(int j=0;j<n;j++){
        cout<<codeword[i][j]<<" ";
    }
    cout<<endl;
   }


   // again adding these numbers 
   
   
   for(int i=0;i<n;i++){
    temp2[i]=0;
   }
   cout<<endl;
   for(int i=0;i<=number;i++){
        int *temp1=new int[n];
        for(int j=0;j<n;j++){
            temp1[j]=codeword[i][j];
        }
        cout<<"adding "<<endl;
        for(int j=0;j<n;j++){
            cout<<temp1[j]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){

         cout<<temp2[i]<<" ";
        }
        cout<<"upto"<<endl;
        
        add(temp1,i,n,temp2);

        cout<<"and result is"<<endl;
        for(int i=0;i<n;i++){

         cout<<temp2[i]<<" ";
        }
        
        
   }
//    for(int i=0;i<n;i++){
//     cout<<temp2[i]<<" ";
//    }
//    cout<<endl;
  bool flag=false;
   for(int i=0;i<n;i++){
    if(temp2[i]==0){
        flag=true;
        break;
    }
   }
   if(flag){
    cout<<"Error"<<endl;
   }
   else{
    cout<<"No error"<<endl;
   }
   
}