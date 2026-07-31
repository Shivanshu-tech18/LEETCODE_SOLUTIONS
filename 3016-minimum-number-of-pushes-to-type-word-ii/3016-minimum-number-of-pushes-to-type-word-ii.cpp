class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (char i : word)
            mp[i]++;
        vector<int> freq;
        for (auto i : mp) {
            freq.push_back(i.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0, index = 1, sum = 0;
        for (int i = 0; i < freq.size(); i++) {
            sum += freq[i];
            if ((i + 1) % 8 == 0) {
                ans += sum * index;
                index++;
                sum = 0;
            }
        }
        if(sum!=0){
            ans+=sum*index;
        }
        return ans;
    }
};