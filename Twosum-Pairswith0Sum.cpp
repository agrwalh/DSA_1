class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        set<pair<int, int>> uniquePairs;

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                uniquePairs.insert({arr[left], arr[right]});
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }

        vector<vector<int>> result;
        for (auto pair : uniquePairs) {
            result.push_back({pair.first, pair.second});
        }

        return result;
    }
};