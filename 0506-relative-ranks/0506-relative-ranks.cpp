class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        int n=score.size();
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string>ans(n,"");
        for(int rank=1;rank<=n;rank++){
            auto athlete=pq.top();
            pq.pop();
            if(rank==1){
                ans[athlete.second]="Gold Medal";
            }
            else if(rank==2){
                ans[athlete.second]="Silver Medal";
            }
            else if(rank==3){
                ans[athlete.second]="Bronze Medal";
            }
            else{
                ans[athlete.second]=to_string(rank);
            }
        }
        return ans;
    }
};