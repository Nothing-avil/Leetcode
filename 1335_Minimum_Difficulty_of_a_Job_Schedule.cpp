#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        return minDifficulty_v2(jobDifficulty, d);
    }

    int minDifficulty_v2(const vector<int>& jobDifficulty, int d) {
        const int n = static_cast<int>(jobDifficulty.size());
        if (n < d) {
            return -1;
        } else if (n == d) {
            int res = 0;
            for (int v: jobDifficulty)
                res += v;
            return res;
        }
        std::vector<int> dp(n);
        dp[0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = std::max(jobDifficulty[i], dp[i-1]);
        }
        std::vector<int> dpPrev(n);
        std::vector<int> stkIdx;
        stkIdx.reserve(n);
        int lastIdx;
        for (int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            stkIdx.clear();
            for (int j = i; j < n; ++j) {
                dp[j] = jobDifficulty[j] + dpPrev[j - 1];
                while (!stkIdx.empty() && jobDifficulty[stkIdx.back()] <= jobDifficulty[j]) {
                    lastIdx = stkIdx.back();
                    stkIdx.pop_back();
                    dp[j] = std::min(dp[j], dp[lastIdx] + jobDifficulty[j] - jobDifficulty[lastIdx]);
                }
                if (!stkIdx.empty()) {
                    lastIdx = stkIdx.back();
                    dp[j] = std::min(dp[j], dp[lastIdx]);
                }
                stkIdx.emplace_back(j);
            }
        }
        return dp.back();
    }

    int minDifficulty_v1(const vector<int>& jobDifficulty, int d) {
        const int n = static_cast<int>(jobDifficulty.size());
        if (n < d) {
            return -1;
        } else if (n == d) {
            int res = 0;
            for (int v: jobDifficulty)
                res += v;
            return res;
        }

        std::vector<int> dp(n);
        dp[0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = std::max(jobDifficulty[i], dp[i-1]);
        }
        std::vector<int> dpPrev(n);
        for (int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            for (int j = i; j < n; ++j) {
                int lastDayDifficulty = jobDifficulty[j];
                int tmpMin = lastDayDifficulty + dpPrev[j - 1];
                for (int t = j - 1; i - 1 < t; --t) {
                    lastDayDifficulty = std::max(lastDayDifficulty, jobDifficulty[t]);
                    tmpMin = std::min(tmpMin, lastDayDifficulty + dpPrev[t - 1]);
                }
                dp[j] = tmpMin;
            }
        }
        return dp.back();
    }

};
