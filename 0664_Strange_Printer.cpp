// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int strangePrinter(string s) {
        int n= s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        function<int(int , int)> solver = [&](int l, int r){
            if(l==r){
                return 1;
            }
            if(l>r){
                return 0;
            }
            int i=l+1;
            while(i<=r && s[i]==s[l]){
                i++;
            }
            if(i>=r+1){
                return 1;
            }
            if(dp[l][r]!=-1){
                return dp[l][r];
            }
            int first= 1+solver(i,r);
            int second = INT_MAX;
            for(int j=i; j<=r; j++){
                if(s[j]==s[l]){
                    int ans = solver(i, j-1) + solver(j, r);
                    second = min(second, ans);
                }
            }
            return dp[l][r]= min(first, second);
        };
        return solver(0,n-1);
    }
};
int kuchbhi() {
    std::string line;
    std::vector<std::string> test_cases;
    
    // Read all input lines
    while (std::getline(std::cin, line)) {
        test_cases.push_back(line);
    }
    
    Solution solution;
    std::vector<int> results;
    
    // Process each test case
    for (const std::string& test_case : test_cases) {
        // Convert JSON string to std::string (assumes input is valid)
        std::string s = test_case.substr(1, test_case.length() - 2);  // remove quotes
        results.push_back(solution.strangePrinter(s));
    }
    
    // Write results to output file
    std::ofstream outfile("user.out");
    for (int result : results) {
        outfile << result << std::endl;
    }
    
    return 0;
}
