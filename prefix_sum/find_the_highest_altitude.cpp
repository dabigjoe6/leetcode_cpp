// https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       vector<int> net_gain = {0};

       vector<int>::size_type k = gain.size();

       int max_altitude = 1e-9;

        for (int i = 0; i < k; ++i) {
            int curr_net_gain = net_gain[i] + gain[i];
            max_altitude = max(max_altitude, curr_net_gain);
            net_gain.push_back(curr_net_gain);
        }

        return max_altitude;
    }
};
