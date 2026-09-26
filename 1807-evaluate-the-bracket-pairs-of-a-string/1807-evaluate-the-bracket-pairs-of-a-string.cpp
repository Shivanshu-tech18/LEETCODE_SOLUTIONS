class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, int> mp;
        int n = knowledge.size();
        for (int i = 0; i < n; i++) {
            mp[knowledge[i][0]] = i + 1;
        }
        string ans = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                int j = i + 1;
                string temp = "";
                while (s[j] != ')') {
                    temp += s[j];
                    j++;
                }
                if (mp[temp] > 0) {
                    ans += knowledge[mp[temp] - 1][1];
                } else {
                    ans += '?';
                }
                i = j + 1;
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};