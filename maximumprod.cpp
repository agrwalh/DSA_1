class Solution {
  public:
    long long maxProduct(vector<int> &arr) {
        long long maxProd = arr[0], minProd = arr[0], result = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                
                swap(maxProd, minProd);
            }
            
            maxProd = max((long long)arr[i], maxProd * arr[i]);
            minProd = min((long long)arr[i], minProd * arr[i]);

            
            result = max(result, maxProd);
        }

        return result;
    }
};