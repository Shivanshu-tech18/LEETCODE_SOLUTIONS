class Solution {
public:
    int solve(int idx,vector<int>&nums,int prev,vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int nottake=solve(idx+1,nums,prev,dp);
        int take=0;
        if( prev==-1  || nums[idx]>nums[prev]){
            take=1+solve(idx+1,nums,idx,dp);
            
        }
        return dp[idx][prev+1] =max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {         
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0,nums,-1,dp);
    }
};