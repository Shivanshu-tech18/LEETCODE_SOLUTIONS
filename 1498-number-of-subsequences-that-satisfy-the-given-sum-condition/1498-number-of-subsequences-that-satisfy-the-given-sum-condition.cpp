class Solution {
public:
    const long long M = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        int l=0,n=nums.size();
        int r=n-1;
        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % M;
        }
        while(l<=r){
            if((nums[l]+nums[r])>target) r--;
            else {
                sum=(sum+pow2[r-l])%M;
                l++;
            }
        }
    return int(sum); 
    }
};