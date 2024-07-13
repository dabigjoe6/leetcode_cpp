// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // We would go a single pass
        // our loop will be the length of the longer string
        // at each iteration we will check if we've not passed the length of the string
        // at each iteration if we haven't passed the length of word1 we will add to our result
        // at each iteration, after adding the character in word1 if we haven't passed the length of word2
        // we will add to our result.

        string result;
        string::const_iterator word1It = word1.begin();
        string::const_iterator word2It = word2.begin();

        string::const_iterator word1End = word1.end();
        string::const_iterator word2End = word2.end();

        while (word1It != word1End || word2It != word2End) {
            if (word1It != word1End) {
                result.push_back(*word1It);
                ++word1It;
            }
            if (word2It != word2End) {
                result.push_back(*word2It);
                ++word2It;
            }
        }

        return result;
    }
};
