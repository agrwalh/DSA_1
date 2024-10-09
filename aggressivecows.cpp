bool canweplace(vector<int> &stalls,int dist,int cows)
{
    int cnt=1,last=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            cnt++;
            last=stalls[i];
        }
        if(cnt==cows){
            return true;
        }

    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int l=1,h=stalls[n-1]-stalls[0];
    while(l<=h){
        int mid=(l+h)/2;
        if(canweplace(stalls, mid,k)){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return h;

}