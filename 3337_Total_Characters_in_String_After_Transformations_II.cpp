// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    const int MOD = 1e9 + 7;
    const int ALPHABET_SIZE = 26;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        std::vector<std::vector<long long>> M(ALPHABET_SIZE, std::vector<long long>(ALPHABET_SIZE, 0));
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            int transforms = nums[i];
            for (int j = 0; j < transforms; ++j) {
                M[i][(i + j + 1) % ALPHABET_SIZE]++;
            }
        }
        std::vector<long long> count(ALPHABET_SIZE, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        auto multiply = [&](const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
            std::vector<std::vector<long long>> result(ALPHABET_SIZE, std::vector<long long>(ALPHABET_SIZE, 0));
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                for (int j = 0; j < ALPHABET_SIZE; ++j) {
                    for (int k = 0; k < ALPHABET_SIZE; ++k) {
                        result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return result;
        };
        auto power = [&](std::vector<std::vector<long long>> matrix, int exp) {
            std::vector<std::vector<long long>> result(ALPHABET_SIZE, std::vector<long long>(ALPHABET_SIZE, 0));
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                result[i][i] = 1;
            }
            while (exp) {
                if (exp % 2) {
                    result = multiply(result, matrix);
                }
                matrix = multiply(matrix, matrix);
                exp /= 2;
            }
            return result;
        };
        std::vector<std::vector<long long>> M_t = power(M, t);
        std::vector<long long> final_count(ALPHABET_SIZE, 0);
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                final_count[j] = (final_count[j] + M_t[i][j] * count[i]) % MOD;
            }
        }
        long long total_length = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            total_length = (total_length + final_count[i]) % MOD;
        }
        return total_length;
    }
};
