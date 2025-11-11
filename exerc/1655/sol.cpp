// #pragma GCC target("popcnt")  // if solution involves bitset
#include <bits/stdc++.h>
using namespace std;

#ifdef croquete  // BEGIN TEMPLATE ----------------------|
#include "dbg.h"
#define fio freopen("in.txt", "r", stdin)
#else
#define dbg(...)
#define fio cin.tie(0)->sync_with_stdio(0)
#endif
#define ll           long long
#define vll          vector<ll>
#define vvll         vector<vll>
#define pll          pair<ll, ll>
#define vpll         vector<pll>
#define all(xs)      xs.begin(), xs.end()
#define rep(i, a, b) for (ll i = (a); i  < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (ll)(b); --i)
#define eb           emplace_back
#define cinj         cin.iword(0)  = 1, cin
#define coutj        cout.iword(0) = 1, cout
template <typename T>  // read vector
istream& operator>>(istream& is, vector<T>& xs) {
    assert(!xs.empty());
    rep(i, is.iword(0), xs.size()) is >> xs[i];
    return is.iword(0) = 0, is;
} template <typename T>  // print vector
ostream& operator<<(ostream& os, vector<T>& xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << ' ';
    return os.iword(0) = 0, os;
} void solve();
signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) solve();
}  // END TEMPLATE --------------------------------------|

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> counts;
        for (auto const& [key, val] : freq) {
            counts.push_back(val);
        }

        sort(quantity.rbegin(), quantity.rend());

        return backtrack(counts, quantity, 0);
    }
private:
    bool backtrack(vector<int>& counts, vector<int>& quantity, int index) {
        if (index == quantity.size()) {
            return true;
        }

        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] >= quantity[index]) {
                counts[i] -= quantity[index];

                if (backtrack(counts, quantity, index + 1)) {
                    return true;
                }

                counts[i] += quantity[index];
            }
        }

        return false;
    }
};

void solve() {
    Solution sol;

    // ll n;
    // cin >> n;
    // vector<int> nums(n);
    // cin >> nums;

    // ll m;
    // cin >> m;
    // vector<int> quantity(m);
    //
    vector<int> nums = {1,2,3,4};
    vector<int> quantity = {2};

    cout << sol.canDistribute(nums, quantity) << '\n';
}
