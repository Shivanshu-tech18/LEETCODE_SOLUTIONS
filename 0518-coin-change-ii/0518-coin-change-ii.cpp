class Solution1 {
public:
    int solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int not_take=solve(coins,amount,index-1,dp);
        int take=0;
        if(coins[index]<=amount){
            take=solve(coins,amount-coins[index],index,dp);
        }
        return dp[index][amount]= take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(coins,amount,coins.size()-1,dp);
    }
};
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0){
                    if(j%coins[0]==0){
                        dp[i][j]=1;
                    }
                    else dp[i][j]=0;
                continue;
                }
                long long not_take=dp[i-1][j];
                long long take=0;
                if(coins[i]<=j){
                    take=dp[i][j-coins[i]];
                }
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};