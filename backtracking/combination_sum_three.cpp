// https://leetcode.com/problems/combination-sum-iii/?envType=study-plan-v2&envId=leetcode-75


class Solution {
public:
    void _combinationSum(int currVal, vector<int>& currComb, vector<vector<int>>& result, int currDepth, int& cummSum, int& k, int& n) {
        // currVal -> 2,
        //            3,
        //
        // currComb -> [2, 3]
        // currDepth -> 1, 2
        // cummSum -> 0, 2, 5
        // result -> [[1, 2, 6], [1, 3, 5]]

        while (currVal < 10) {
            cummSum += currVal;
            currComb.push_back(currVal);

            int remainder = n - cummSum;
            if (remainder > 0 && currDepth < k) {
                _combinationSum(currVal + 1, currComb, result, currDepth + 1, cummSum, k, n);
            } else if (remainder == 0 && currDepth == k) {
                vector<int> combination(currComb);
                result.push_back(combination);

                cummSum -= currVal;
                currComb.pop_back();
                break;
            }

            cummSum -= currVal;
            currComb.pop_back();
            ++currVal;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> firstComb = { };
        vector<vector<int>> result = { };

        int depth = 1;
        int cummSum = 0;

        int initVal = 1;
        _combinationSum(initVal, firstComb, result, depth, cummSum, k, n);

        return result;
    }
};
