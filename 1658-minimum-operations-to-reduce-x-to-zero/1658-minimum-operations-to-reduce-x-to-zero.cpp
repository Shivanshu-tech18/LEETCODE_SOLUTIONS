class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int ps=accumulate(begin(nums),end(nums),0);
        ps-=x;
        if(ps==0 ) return n;
        if(ps<0) return -1;
        int i=0,ans=-1,sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>ps){
                sum=sum-nums[i];
                i++;
            }
            if(sum==ps) ans=max(ans,j-i+1);
        }
        return ans==-1? -1:n-ans;
    }
};