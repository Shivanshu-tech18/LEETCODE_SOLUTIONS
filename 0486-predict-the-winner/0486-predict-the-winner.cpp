class Solution {
public:
    int solve(vector<int>&nums,int i,int j){
        if(i>j) return 0;
        if(i==j) return nums[i];

        int take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int take_j=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int p1=solve(nums,0,nums.size()-1);
        int p2=sum-p1;
        return p1>=p2;
    }
};