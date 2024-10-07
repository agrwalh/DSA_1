class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int bb=prices[0];
        for (int i=0;i<prices.size();i++){
            if(prices[i]>bb){
                mp=max(mp,prices[i]-bb);
            }
                 bb=min(bb,prices[i]);


        }
        return mp;
   
        
    }
};