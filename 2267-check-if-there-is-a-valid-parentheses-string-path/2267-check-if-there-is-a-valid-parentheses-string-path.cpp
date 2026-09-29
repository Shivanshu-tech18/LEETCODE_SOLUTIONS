class Solution {
public:
    bool dfs(int r, int c, int bal, vector<vector<char>>& grid,
             vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (r >= m || c >= n)
            return false;
        if (grid[r][c] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
            return false;
        if (r == m - 1 && c == n - 1)
            return bal == 0;

        // Already calculated
        if (dp[r][c][bal] != -1)
            return dp[r][c][bal];

        // Try down and right
        bool down = dfs(r + 1, c, bal, grid, dp);
        bool right = dfs(r, c + 1, bal, grid, dp);

        return dp[r][c][bal] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0)
            return false;
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );
        return dfs(0, 0, 0, grid, dp);
    }
};