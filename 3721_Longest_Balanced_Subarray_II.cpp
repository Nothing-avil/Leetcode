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
};
class Node {
public:
    int l = 0, r = 0;
    int mn = 0, mx = 0;
    int lazy = 0;
};

class SegmentTree {
public:
    SegmentTree(int n) {
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 0, n);
    }
    void modify(int u, int l, int r, int v) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            apply(u, v);
            return;
        }
        pushdown(u);
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
    int query(int u, int target) {
        if (tr[u]->l == tr[u]->r) {
            return tr[u]->l;
        }
        pushdown(u);
        int lc = u << 1, rc = u << 1 | 1;
        if (tr[lc]->mn <= target && target <= tr[lc]->mx) {
            return query(lc, target);
        }
        return query(rc, target);
    }

private:
    vector<Node*> tr;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        tr[u]->mn = tr[u]->mx = 0;
        tr[u]->lazy = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void apply(int u, int v) {
        tr[u]->mn += v;
        tr[u]->mx += v;
        tr[u]->lazy += v;
    }

    void pushup(int u) {
        tr[u]->mn = min(tr[u << 1]->mn, tr[u << 1 | 1]->mn);
        tr[u]->mx = max(tr[u << 1]->mx, tr[u << 1 | 1]->mx);
    }

    void pushdown(int u) {
        if (tr[u]->lazy != 0) {
            apply(u << 1, tr[u]->lazy);
            apply(u << 1 | 1, tr[u]->lazy);
            tr[u]->lazy = 0;
        }
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);
        unordered_map<int, int> last;
        int now = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            int det = (x & 1) ? 1 : -1;
            if (last.count(x)) {
                st.modify(1, last[x], n, -det);
                now -= det;
            }
            last[x] = i;
            st.modify(1, i, n, det);
            now += det;
            int pos = st.query(1, now);
            ans = max(ans, i - pos);
        }
        return ans;
    }
};
