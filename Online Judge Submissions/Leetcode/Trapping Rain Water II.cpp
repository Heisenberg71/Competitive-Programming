class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }

        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) {
            return 0;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    heap.push({heightMap[i][j], {i, j}});
                    heightMap[i][j] = -1;
                }
            }
        }

        int level = 0, res = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!heap.empty()) {
            auto [height, pos] = heap.top();
            heap.pop();
            int x = pos.first, y = pos.second;
            level = max(level, height);

            for (auto& dir : directions) {
                int i = x + dir.first, j = y + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && heightMap[i][j] != -1) {
                    heap.push({heightMap[i][j], {i, j}});

                    if (heightMap[i][j] < level) {
                        res += level - heightMap[i][j];
                    }

                    heightMap[i][j] = -1;
                }
            }
        }

        return res;
    }
};
