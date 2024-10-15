class Solution {
    
    private:
    bool issafe(int x, int y, vector<vector<int>>& visited, vector<vector<int>>& mat) {
        int n = mat.size();
       
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (mat[x][y] == 1)) {
            return true; 
        } else {
            return false; 
        }
    }

    void solve(vector<vector<int>>& mat, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        int n = mat.size();
       
        // Base case: Reached destination (n-1, n-1)
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        
        // Move Down
        int newx = x + 1;
        int newy = y;
        if (issafe(newx, newy, visited, mat)) {
            path.push_back('D');
            solve(mat, ans, newx, newy, visited, path);
            path.pop_back();  // Backtrack
        }

        // Move Left
        newx = x;
        newy = y - 1;
        if (issafe(newx, newy, visited, mat)) {
            path.push_back('L');
            solve(mat, ans, newx, newy, visited, path);
            path.pop_back();  // Backtrack
        }

        // Move Up
        newx = x - 1;
        newy = y;
        if (issafe(newx, newy, visited, mat)) {
            path.push_back('U');
            solve(mat, ans, newx, newy, visited, path);
            path.pop_back();  // Backtrack
        }

        // Move Right
        newx = x;
        newy = y + 1;
        if (issafe(newx, newy, visited, mat)) {
            path.push_back('R');
            solve(mat, ans, newx, newy, visited, path);
            path.pop_back();  // Backtrack
        }
        
        visited[x][y] = 0;  // Unmark this cell (Backtrack)
    }

    public:
    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;
        
        // Edge case: if start or end point is blocked
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return ans;
        }
         
        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        
        solve(mat, ans, srcx, srcy, visited, path);
        
        sort(ans.begin(), ans.end());  // Sort the paths lexicographically
        
        return ans;
    }
};
