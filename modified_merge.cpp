#include <iostream>

using namespace std;

template<typename type>
void merge(type* data , int begin , int mid , int end){
 for(int i=begin;i<=mid;i++){
      if(data[i]>data[mid+1]){
           type temp = data[i];
           data[i]=data[mid+1];
           int j = mid+2;
	    while(j<=end && temp>data[j]){
		      data[j-1]=data[j];
	         j++;
       }
	     data[j-1]=temp; 		
     }
  }
}
template <typename type>
type* modif_ms(type *data,int begin , int end)
{
  int mid = begin + (end-begin)/2;
  if(begin<end){
	     modif_ms(data,begin,mid);
  	   modif_ms(data,mid+1,end);
 	     merge(data,begin,mid,end);		 
  }
 return data;
}

int main(){ 
 int size,*start;
 cin>>size;
 int data[size]; 
 for(int i=0;i<size;i++)
	 cin>>data[i];
 start = modif_ms(data,0,size-1);
 for(int i=0;i<size;i++)
   cout<<start[i]<<" ";
 return 0; 
}
