class Solution {
public:
    int func(int ops,int l,vector<int>& nums, vector<int>& multipliers,vector<vector<int>>&dp)
    {
        if(ops==multipliers.size()){
            return 0;
        }
        if(dp[l][ops]!=INT_MIN ){
            return dp[l][ops];
        }
        
        int left=nums[l]*multipliers[ops]+func(ops+1,l+1,nums,multipliers,dp);
        int right=nums[nums.size()-1-(ops-l)]*multipliers[ops]+func(ops+1,l,nums,multipliers,dp);
        return dp[l][ops]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(multipliers.size()+1,INT_MIN));
        return func(0,0,nums,multipliers,dp);
    }
};