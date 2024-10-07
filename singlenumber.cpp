class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int val:nums){

            ans=ans^val;
        }
        return ans;
        
    }
};


// ------>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int ,int> mp;
        for(auto i: nums)
        {
        mp[i]++;
        }  

        for(auto i:mp){
            if(i.second==1){
                return i.first;
            }
        }
        return -1;
    }
};