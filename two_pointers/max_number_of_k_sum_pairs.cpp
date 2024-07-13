// https://leetcode.com/problems/max-number-of-k-sum-pairs/?envType=study-plan-v2&envId=leetcode-75

#include <map>

class Solution {
public:
    int _maxOperations(vector<int>& nums, int& k, int maxNumberOfOperations, map<int, int>& isTaken) {
        vector<int>::const_iterator it = nums.begin();
        vector<int>::const_iterator end = nums.end();

        while (it != end) {
            if (isTaken[*it] != 0) {
                isTaken[*it] = isTaken[*it] - 1;
                if ((isTaken.find(k - (*it)) != isTaken.end()) && isTaken[k - (*it)] != 0) {
                    isTaken[k - (*it)] = isTaken[k - (*it)] - 1;
                    maxNumberOfOperations += 1;
                } else {
                    isTaken[*it] += 1;
                }
            }

            ++it;
        }

        return maxNumberOfOperations;
    }

    int maxOperations(vector<int>& nums, int k) {
        // First approach that comes to mind is to have a recursion, that does a
        // pass on the array - When it finds a sum of 2 integers equals k, it increments a variable
        // that tracks the number of operations.
        // To find if a sum of 2 integers in the array equals k, we will keep a hashtable of the
        // integers in the array, and point them to a value that represents if they are taken.
        // Such that if k - nums[i] == <integer in the hash table that is not taken>, we increment
        // the number of operators, and set it as taken

        // Ended up with a single loop O(n) solution. The recursive solution had a lot of memory overhead
        // for some of the test cases

        // Better solution is to just sort and have two pointers at the beginning and end
        // Move both pointers forward/backward when they add up to k
        // move the end pointer backward if front + back > k
        // else move the start pointer forward if front + back < k
        // This solution is O(n)

        map<int, int> isTaken;

        vector<int>::const_iterator it = nums.begin();
        vector<int>::const_iterator end = nums.end();

        while (it != end) {
            if (isTaken.find(*it) != isTaken.end()) {
                isTaken[*it] += 1;
            } else {
                isTaken[*it] = 1;
            }
            ++it;
        }

        return _maxOperations(nums, k, 0, isTaken);
    }
};
