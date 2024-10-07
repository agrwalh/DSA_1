#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs<0){
        return 0;
    }
    else if(nStairs==0){
        return 1;
    }
    else{
         return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    }
}