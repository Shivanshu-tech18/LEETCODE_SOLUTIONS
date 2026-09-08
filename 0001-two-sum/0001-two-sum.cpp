class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            
            int rem=target-nums[i];
            // if(nums[i]<0) rem=target-
            if((mp[rem]>0) &&  (mp[rem] !=i) ){
                // cout<<nums[i]<<" "<<target-nums[i]<<" "<<mp[target-nums[i]]<<endl;
                return {i,mp[rem]};
            }
        }
        return {-1,-1};
    }
};