class Solution {
public:
int dp[502][502];
    int solve(vector<int>&piles,int i,int j){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=piles[i]+min(solve(piles,i+2,j),solve(piles,i+1,j-1));
        int take_j=piles[j]+min(solve(piles,i+1,j-1),solve(piles,i,j-2));

        return dp[i][j]= max(take_i,take_j);

    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int ts=accumulate(begin(piles),end(piles),0);
        int alice=solve(piles,0,n-1);
        int bob=ts-alice;
        return alice>bob;
    }
};