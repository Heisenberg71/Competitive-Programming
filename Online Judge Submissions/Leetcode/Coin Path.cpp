/*
  Problem Link: https://leetcode.com/problems/coin-path/
*/

class Solution {

private:
    int INVALID = -1;
    int MAX_VALUE = 100005;
    vector<int> cost, parent;

    void calculateCheapestPath(int maxJump, vector<int>& coins){
        int n = cost.size();
        cost[n - 1] = coins.back();
        for (int i = n - 2; i >= 0; i--) {
            if (coins[i] == INVALID)
                continue;

            for (int j = i + 1; j < min(i + maxJump + 1, n); j++) {
                if (coins[j] == INVALID)
                    continue;

                if (cost[j] + coins[i] < cost[i]) {
                    cost[i] = cost[j] + coins[i];
                    parent[i] = j;
                }
            }
        }
    }

    void findCheapestPath(vector<int>& path){
        if (cost[0] == MAX_VALUE) return;

        int pathIndex = 0;
        while (pathIndex != INVALID) {
            path.push_back(pathIndex + 1);
            pathIndex = parent[pathIndex];
        }
    }

public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        cost.assign(n, MAX_VALUE);
        parent.assign(n, INVALID);

        calculateCheapestPath(maxJump, coins);
        vector<int> path;
        findCheapestPath(path);

        return path;
    }
};
