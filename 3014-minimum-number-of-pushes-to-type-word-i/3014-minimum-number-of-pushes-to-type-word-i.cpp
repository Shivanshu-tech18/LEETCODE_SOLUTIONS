class Solution {
public:
    void solve(int len,int &sum,int i){
        if(len<=8)
        {
            sum+=len*i;
            return;
        }
        sum+=8*i;
        solve(len-8,sum,i+1);
        
    }
    int minimumPushes(string word) {
       int len=word.length();
       int sum=0;
       solve(len,sum,1);
        return sum;
    }
};