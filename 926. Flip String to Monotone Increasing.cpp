#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> dp;
        int n;
        int f(string& s, int idx, int prev) {
            if (idx >= n)
                return 0;
            if (dp[idx][prev] != -1)
                return dp[idx][prev];
            int flip = INT_MAX, nflip = INT_MAX;
            if (s[idx] == '0') {
                if (prev == 0) {
                    flip = 1 + f(s, idx + 1, 1);
                    nflip = f(s, idx + 1, 0);
                } else {
                    flip = 1 + f(s, idx + 1, 1);
                }
            } else { // curr=1
                if (prev == 0) {
                    flip = 1 + f(s, idx + 1, 0);
                    nflip = f(s, idx + 1, 1);
                } else {
                    nflip = f(s, idx + 1, 1);
                }
            }
            return dp[idx][prev] = min(flip, nflip);
        }
        int minFlipsMonoIncr(string s) {
            n = s.length();
            dp.resize(n, vector<int>(2, -1));
            return f(s, 0, 0);
        }
    };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}