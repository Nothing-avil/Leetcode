#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int first = 0, last = 0;
        int i = 1;
        vector<int> ans(2, INT_MAX);
        while (curr->next) {
            if (curr->val < min(prev->val, curr->next->val) || curr->val > max(prev->val, curr->next->val)) {
                if (last == 0)
                    first = i;
                else {
                    ans[0] = min(ans[0], i - last);
                    ans[1] = i - first;
                }
                last = i;
            }
            ++i;
            prev = curr;
            curr = curr->next;
        }
        if (first == last) return {-1, -1};
        return ans;
    }
};
