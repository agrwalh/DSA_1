//IMPORTANT


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevsmaller(vector<int> &in){
    stack<int>s;
    vector<int> ans(in.size());
    s.push(-1);
     for(int i=0;i<in.size();i++){
        int curr=in[i];
    
    while(s.top()>=curr){
        s.pop();
    }
    ans[i]=s.top();
    s.push(curr);

    }
    return ans;

}
vector<int> nextsmaller(vector<int> &in){
stack<int>s;
    vector<int> ans(in.size());
    s.push(-1);
    for(int i=in.size()-1;i>=0;i--){
        int curr=in[i];
    
    while(s.top()>=curr){
        s.pop();
    }
    ans[i]=s.top();
    s.push(curr);

    }
    return ans;
}

int main(){
    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(4);
    in.push_back(3);

    vector<int> ans=nextsmaller(in); 
    cout<<"printing ans1"<<endl;

    for(int i=0;i<in.size();i++){
        cout<<ans[i]<<" ";

    }   cout<<endl;

    vector<int> ans2=prevsmaller(in);
     cout<<"printing ans2"<<endl;

    for(int i=0;i<in.size();i++){
        cout<<ans2[i]<<" ";

    }   cout<<endl;





    return 0;
}