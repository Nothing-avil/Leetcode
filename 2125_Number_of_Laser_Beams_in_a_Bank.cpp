#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = bank.size();
        int prevDeviceCount = 0;
        int result = 0;
        for(int i = 0; i<n; i++) {
            int currDeviceCount = 0;
            for(char &ch : bank[i]) {
                if(ch == '1') {
                    currDeviceCount++;
                }
            }
            result += (prevDeviceCount * currDeviceCount);
            prevDeviceCount = currDeviceCount == 0 ? prevDeviceCount : currDeviceCount;   
        }
        return result;
    }
};
