class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){
            int index=i%n;
            while(!s.empty() && nums[s.top()]<nums[index] ){
                ans[s.top()]=nums[index];
                s.pop();

            }
            if(i<n)
            s.push(i);
        }
        return ans;
    }
};