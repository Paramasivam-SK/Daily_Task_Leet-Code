// ✅ Problem: 2787. Ways to Express an Integer as Sum of Powers
// 🔗 Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/?envType=daily-question&envId=2025-08-12

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1;; i++) {
            long long p = pow(i, x);
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<vector<int>> dp(powers.size() + 1, vector<int>(n + 1, -1));

        function<int(int,int)> dfs = [&](int idx, int remaining) -> int {
            if (remaining == 0) return 1;  
            if (idx >= powers.size() || remaining < 0) return 0;  

            int &res = dp[idx][remaining];
            if (res != -1) return res;

            long long skip = dfs(idx + 1, remaining) % MOD;
            long long take = dfs(idx + 1, remaining - powers[idx]) % MOD;

            return res = (skip + take) % MOD;
        };

        return dfs(0, n);
    }
};
