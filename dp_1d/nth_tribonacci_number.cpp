https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75

#include <map>

class Solution {
public:
    int _tribonacci(int j, std::map<int, int>& memo) {
        if (memo.find(j) != memo.end()) {
            return memo[j];
        }

        if (j == 0) {
            return 0;
        }

        if (j == 1) {
            return 1;
        }

        if (j == 2) {
            return 1;
        }

        int n = j - 3;

        int result = _tribonacci(n, memo) + _tribonacci(n + 1, memo) + _tribonacci(n + 2, memo);
        memo[j] = result;

        return result;
    }

    int tribonacci(int n) {
        std::map<int, int> memo;
        return _tribonacci(n, memo);
    }
};
