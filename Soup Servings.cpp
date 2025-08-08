// ✅ Problem: 808. Soup Servings
// 🔗 Link: Link: https://leetcode.com/problems/soup-servings/description/?envType=daily-question&envId=2025-08-08

class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;  // Optimization: answer approaches 1 as n increases
        int scaledN = ceil((double)n / 25.0);
        return dp(scaledN, scaledN);
    }

private:
    unordered_map<int, unordered_map<int, double>> memo;

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;  // Both empty
        if (a <= 0) return 1.0;            // A empty first
        if (b <= 0) return 0.0;            // B empty first

        if (memo[a].count(b)) return memo[a][b];

        // Calculate expected value from 4 options
        double result = 0.25 * (
            dp(a - 4, b) +         // (100, 0)
            dp(a - 3, b - 1) +     // (75, 25)
            dp(a - 2, b - 2) +     // (50, 50)
            dp(a - 1, b - 3)       // (25, 75)
        );

        memo[a][b] = result;
        return result;
    }
};
