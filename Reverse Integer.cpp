// ✅ Problem: Reverse Integer
// 🔗 Link: https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
         long long rev = 0;
        while (x != 0) {
            int digit = x % 10; 
            rev = rev * 10 + digit;
            x /= 10;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0;
            }
        }
        return static_cast<int>(rev);
    }
};
