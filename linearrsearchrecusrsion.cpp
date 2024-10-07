#include<iostream>
using namespace std;
int linearsearch(int arr[],int size,int key){
    if(size==0){
        return false;
    }
   if(arr[0]==key){
        return true;
    }
    else{
        int rempart=linearsearch(arr+1,size-1,key);
        return rempart;
    }

}
int main(){
    int arr[5]={3,2,1,6,5};
    int size=5;
    int k=10;
    int ans=linearsearch(arr,size,k);
    if(ans){
         cout<<"Element is present "<<endl;
    }
    else{
        cout<<"Element Not Found "<<endl;
    }
   
}