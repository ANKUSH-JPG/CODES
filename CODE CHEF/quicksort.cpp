#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

int partition(int *arr,int low ,int high){
int p;
p=arr[high];
int i,j;
i=low-1;
for(j=low;j<=high-1;j++){
if(arr[j]<p){
i++;
swap(&arr[i],&arr[j]);
}
}
swap(&arr[i+1],&arr[high]);
return (i+1);
}

void quicksort(int *arr,int low ,int high){
if(low<high){
int s;
s=partition(arr,low,high);
quicksort(arr,low,s-1);
quicksort(arr,s+1,high);
}
}

void displayarray(int *arr,int n){
cout<<"Sorted Array is:"<<endl;
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}

void inputarray(int *arr,int n){
for(int i=0;i<n;i++){
cin>>arr[i];
}
}

int main(){
int *arr,n;
cin>>n;
arr= new int[n];
inputarray(arr,n);
auto start = high_resolution_clock::now();
quicksort(arr,0,n-1);
auto stop= high_resolution_clock::now();
displayarray(arr,n);
cout<<"Duration of the code is: ";
auto duration= duration_cast<microseconds>(stop-start);
cout<<(duration.count())<<endl;
return 0;
}

