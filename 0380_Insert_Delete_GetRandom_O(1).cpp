#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class RandomizedSet {
public:
    vector<int>res;
    unordered_map<int, int>mp;
    RandomizedSet() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        res.push_back(val);
        mp[val]=res.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        // swap(res[mp[val]], res.back());
        // mp[res.back()] = mp[val];
        int idx       = mp[val];
        int temp      = res.back();
        res.back()    = val;
        res[idx]      = temp;
        mp[temp]      = idx;
        res.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n= res.size();
        return res[rand()%n];
    }
};
