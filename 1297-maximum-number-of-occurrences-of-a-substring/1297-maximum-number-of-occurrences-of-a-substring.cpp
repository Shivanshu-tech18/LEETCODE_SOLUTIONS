class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        unordered_map<char,int> freq;
        unordered_map<string,int> mp;

        int l = 0;

        for(int r = 0; r < s.size(); r++) {

            freq[s[r]]++;

            if(r - l + 1 == minSize) {

                if(freq.size() <= maxLetters) {
                    string t = s.substr(l, minSize);
                    mp[t]++;
                }

                freq[s[l]]--;
                if(freq[s[l]] == 0)
                    freq.erase(s[l]);
                l++;
            }
        }

        int occ = 0;
        for(auto &i : mp)
            occ = max(occ, i.second);

        return occ;
    }
};