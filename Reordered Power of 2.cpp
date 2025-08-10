// ✅ Problem: 869. Reordered Power of 2
// 🔗 Link: https://leetcode.com/problems/reordered-power-of-2/description/?envType=daily-question&envId=2025-08-10


class Solution {
public:
    string sortDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        unordered_set<string> powerSignatures;
        for (int i = 0; i < 31; i++) {
            powerSignatures.insert(sortDigits(1 << i));
        }
        return powerSignatures.count(sortDigits(n)) > 0;
    }
};
