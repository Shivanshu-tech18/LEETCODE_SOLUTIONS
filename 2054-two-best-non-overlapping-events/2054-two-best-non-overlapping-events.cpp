class Solution {
public:
int n;
int dp[100001][3];
    int binary_search(vector<vector<int>>&events,int endTime){
        int l=0,r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>endTime){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&events,int i,int count){
        if(count>=2 || i>=n) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int nextValidIndex=binary_search(events,events[i][1]);
        int take=events[i][2]+solve(events,nextValidIndex,count+1);
        int not_take=solve(events,i+1,count);
        return dp[i][count]=max(take,not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
        n=events.size();
        return solve(events,0,0);
    }
};