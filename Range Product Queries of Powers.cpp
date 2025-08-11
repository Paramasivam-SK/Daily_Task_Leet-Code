// ✅ Problem: 2438. Range Product Queries of Powers
// 🔗 Link: https://leetcode.com/problems/range-product-queries-of-powers/?envType=daily-question&envId=2025-08-11



class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<long long> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < (int)powers.size(); i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }
        auto modPow = [&](long long base, long long exp) {
            long long res = 1;
            while (exp > 0) {
                if (exp & 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp >>= 1;
            }
            return res;
        };
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product = prefix[r + 1] * modPow(prefix[l], MOD - 2) % MOD;
            ans.push_back((int)product);
        }

        return ans;
    }
};
