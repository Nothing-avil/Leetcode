class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        unordered_map<char, int> hash_table;
        int max_length = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (hash_table.find(s[j]) != hash_table.end() && hash_table[s[j]] >= i) {
                i = hash_table[s[j]] + 1;
            }
            hash_table[s[j]] = j;
            max_length = max(max_length, j - i + 1);
        }
        return max_length;
    }
};
