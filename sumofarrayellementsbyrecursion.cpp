#include<iostream>
using namespace std;
int sumofarrayellementsbyrecursion(int arr[],int size){
    if(size==0){
        return 0;
    }
    else if(size==1){
        return arr[0];
    }
    else{
        int rempart=sumofarrayellementsbyrecursion(arr+1,size-1);
        int sum=arr[0]+rempart;
        return sum;
    }

}
int main(){
    int arr[5]={3,2,1,6,5};
    int size=5;
    int ans=sumofarrayellementsbyrecursion(arr,size);
    cout<<"The sum of array elemnts is: "<<ans<<endl;
}