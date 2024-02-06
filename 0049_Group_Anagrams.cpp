#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<string>> output;
        unordered_map<string, vector<string>> outputMap;
        for (const auto& s : strs){
            string sCopy {s};
            ranges::sort(sCopy);
            outputMap[sCopy].push_back(s);
        }
        for (auto& [_, x] : outputMap)
            output.push_back(move(x));

        return output;
    }
};
