class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If the array size is 1, we're already at the end
        if (n == 1)
            return 0;
        
        // If the first element is 0, we cannot move forward
        if (arr[0] == 0)
            return -1;
        
        // Initialize variables
        int jumps = 0;       // Number of jumps made
        int farthest = 0;    // The farthest index we can currently reach
        int end = 0;         // The current jump limit
        
        for (int i = 0; i < n; i++) {
            // Update the farthest index we can reach from the current index
            farthest = max(farthest, i + arr[i]);
            
            // If we reach or exceed the end of the array
            if (farthest >= n - 1)
                return jumps + 1;
            
            // If we have reached the end of the current jump range
            if (i == end) {
                jumps++;
                end = farthest;
                
                // If we are stuck (can't move forward), return -1
                if (end == i)
                    return -1;
            }
        }
        
        // If we exit the loop without reaching the end, return -1
        return -1;
    }
};
