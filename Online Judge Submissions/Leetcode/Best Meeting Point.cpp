/*
  Problem Link: https://leetcode.com/problems/best-meeting-point/
*/

class Solution {
private:
int minDistanceHorizontally(int distance, int friendCount, vector<vector<int>>& grid){
    int height = grid.size(), weidth = grid[0].size();
    int minDistance = distance, onLeftCount = 0;
    for(int col = 0; col < weidth; col++){
        for(int row = 0; row < height; row++){
            if(grid[row][col]) onLeftCount++;
        }
        distance += onLeftCount;
        distance -= (friendCount - onLeftCount);
        minDistance = min(minDistance, distance);
    }

    return minDistance;
}

int minDistanceVertically(int distance, int friendCount, vector<vector<int>>& grid){
    int height = grid.size(), weidth = grid[0].size();
    int minDistance = distance, onAboveCount = 0;
    for(int row = 0; row < height; row++){
        for(int col = 0; col < weidth; col++){
            if(grid[row][col]) onAboveCount++;
        }
        distance += onAboveCount;
        distance -= (friendCount - onAboveCount);
        minDistance = min(minDistance, distance);
    }

    return minDistance;
}
public:
    int minTotalDistance(vector<vector<int>>& grid) {

    int height = grid.size(), weidth = grid[0].size();
    int horizontalDistance = 0, verticalDistance = 0, friendCount = 0;
    for(int row = 0; row < height; row++){
        for(int col = 0; col < weidth; col++){
            if(grid[row][col]){
                 horizontalDistance += col;
                 verticalDistance += row;
                 friendCount++;
            }
        }
    }

    return minDistanceHorizontally(horizontalDistance, friendCount, grid) 
        + minDistanceVertically(verticalDistance, friendCount, grid);
    }
};
