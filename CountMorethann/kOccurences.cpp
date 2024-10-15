class Solution {
public:
    int countOccurence(int arr[], int n, int k) {
        int count = 0;
        int threshold = n / k;
        std::sort(arr, arr + n);
        int current_count = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                current_count++;
            } else {
                if (current_count > threshold) {
                    count++;
                }
                current_count = 1;
            }
        }

        if (current_count > threshold) {
            count++;
        }

        return count;
    }
};