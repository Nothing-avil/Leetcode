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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> avil(supplies.begin(), supplies.end());
        queue<int> qu;
        for(int i=0; i<recipes.size(); i++){
            qu.push(i);
        }
        vector<string> createdRecipes;
        int lastSize = -1;
        while (static_cast<int>(available.size()) > lastSize) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();
            while (queueSize-- > 0) {
                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();
                bool canCreate = true;
                for (string& ingredient : ingredients[recipeIdx]) {
                    if (!available.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }
                if (!canCreate) {
                    recipeQueue.push(recipeIdx);
                } else {
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                }
            }
        }
        return createdRecipes;
    }
};
