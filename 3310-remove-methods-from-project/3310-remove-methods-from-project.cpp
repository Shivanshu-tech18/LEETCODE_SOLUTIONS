class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<bool>suspicious(n,false);
        for(auto &i:invocations)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }   
        queue<int>q;
        q.push(k);
        suspicious[k]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int &nbh:adj[curr]){
                indegree[nbh]--;
                if(!suspicious[nbh]){
                    q.push(nbh);
                    suspicious[nbh]=true;
                }
            }
        }
        vector<int>result;
        bool groupnot=false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && indegree[i]>0){
                groupnot=true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(groupnot){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec; 
        }
        return result;
        
    }
};