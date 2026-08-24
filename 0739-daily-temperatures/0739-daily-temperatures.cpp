class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n=temperatures.size();
        s.push(0);
        vector<int> ans(n,0);
        for (int i = 1; i < n; i++) {

            if (temperatures[s.top()] > temperatures[i]) {
                s.push(i);
            } 
            else {
                while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                    ans[s.top()]=(i - s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
};