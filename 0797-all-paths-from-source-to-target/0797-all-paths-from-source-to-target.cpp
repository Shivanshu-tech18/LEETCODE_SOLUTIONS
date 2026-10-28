class Solution {
    private: void dfs(int node,vector<vector<int>>&graph,vector<vector<int>>&res,vector<int>&path)
    {
        if(node==graph.size()-1)
        {
            res.push_back(path);
            return;
        }
        for(int i:graph[node])
        {
            path.push_back(i);
            dfs(i,graph,res,path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>path;
        path.push_back(0);
        dfs(0,graph,res,path);
        return res;
    }
};