class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=0;
        int currSum=0;
        vector<int>minLenIdx(n,INT_MAX);
        int result=INT_MAX,bestMin=INT_MAX;
        while(r<n){
            currSum+=arr[r];
            while(l<r && currSum>target){ 
                currSum-=arr[l++];
            }
            if(currSum==target){
                int len=r-l+1;
                if(l>0 && minLenIdx[l-1]!=INT_MAX){
                    result=min(result,len+minLenIdx[l-1]);
                }
                bestMin=min(bestMin,len);
            }
            minLenIdx[r]=bestMin;
            r++;
        }
        return result==INT_MAX?-1:result;
    }
};