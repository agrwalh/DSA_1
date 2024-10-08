void merge(vector < int > & arr,int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    int minarr=s;
    for(int i=0;i<len1;i++)
    {

        first[i]=arr[minarr++];
    }
    minarr=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[minarr++];
    }
    int i1=0;
    int i2=0;
    minarr=s;

    while(i1<len1&&i2<len2){
        if(first[i1]<second[i2]){
            arr[minarr++]=first[i1++];
        }
        else{
             arr[minarr++]=second[i2++];
        }
    }
    while(i1<len1){
        arr[minarr++]=first[i1++];
    }
    while(i2<len2){
        arr[minarr++]=second[i2++];
    }

}



void solve(vector < int > & arr,int s,int e){
    if(s>=e){
    return;
    }
    int mid=(s+e)/2;

    solve(arr,s,mid);
    solve(arr,mid+1,e);
    merge(arr,s,e);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr,0,n-1);
}