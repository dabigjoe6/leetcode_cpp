// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:

    std::vector<string> split(const string& s, const char& character) {
        std::vector<string> result;

        string::const_iterator it = s.begin();
        string::const_iterator end = s.end();

        while (it != end) {
            if (*it != character) {
                string::const_iterator wordStart = it;
                string::const_iterator wordEnd = it;

                while (wordEnd != end && *wordEnd != character) {
                    ++wordEnd;
                }

                string newString(wordStart, wordEnd);

                result.push_back(newString);

                if (wordEnd != end) {
                    it = wordEnd + 1;
                } else {
                    break;
                }

            } else {
                ++it;
            }
        }

        return result;
    }

    string reverseWords(string s) {
        // one way to do this (brute force approach)
        // seperate the words into a vector of strings
        // such that ["the", "sky", "is", "blue"]
        // itereate through the vector in reverse
        // such that ["blue", "is", "sky", "the"]

        // another way to do this is to swap the words in place
        // the sky is blue five
        // becomes -> five blue is sky the
        // at each iteration, we would have 4 pointers and an iterator
        // first two pointers, will represent the beginning and end of the word1 to swap
        // last two pointers, will represent the beginning and end of the word2 to swap
        //
        // a better way to do this overall is to not create a new vector, just store the indices
        // of the words

        //brute force approach
        //split words by spaces
        std::vector<string> words = split(s, ' ');

        std::vector<string>::iterator it = words.begin();

        std::vector<string>::iterator end = words.end();
        std::vector<string>::iterator rit = std::prev(end);


        while (it < rit) {
            std::swap(*it, *rit);

            ++it;
            --rit;
        }

        it = words.begin();

        string result;

        while (it != end) {
            result.append(*it);
            ++it;

            if (it != end) {
                result.append(" ");
            }
        }

        return result;

    }
};
