class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int j=0;j<nums.size();j++)
        {   
            if(map.find(target-nums[j])!=map.end())
             return {map[target-nums[j]],j};
            map[nums[j]]=j;

        }
       assert(false); 
    }
};