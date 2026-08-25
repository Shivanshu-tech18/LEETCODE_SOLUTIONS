class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_map<int,bool>mp;
       for(int i:nums) mp[i]=true;
       for(int i=1;i<=nums.size()*2;i++){
        if(!mp[i*k]) return i*k;
       } 
       return k;
    }
};