// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> start = { entrance[0], entrance[1], 0 };
        queue<vector<int>> q;

        q.push(start);

        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            // cout << curr[0] << " " << curr[1] << " " << curr[2] << "\n";

            if ((curr[0] == 0 || curr[1] == 0 || curr[0] >= maze.size() - 1 || curr[1] >= maze[0].size() - 1) && (curr[0] != entrance[0] || curr[1] != entrance[1])) {
                return curr[2];
            }

            int nCol;
            int nRow;
            for (int i = 0; i < directions.size(); ++i) {
                nRow = directions[i][0] + curr[0];
                nCol = directions[i][1] + curr[1];

                if ((nRow >= 0 && nRow < maze.size()) && (nCol >= 0 && nCol < maze[0].size()) && (maze[nRow][nCol] != '+')) {
                    int nStep = curr[2] + 1;
                    vector<int> nQ = { nRow, nCol, nStep };
                    maze[nRow][nCol] = '+';
                    q.push(nQ);
                }
            }
        }

        return -1;
    }
};
