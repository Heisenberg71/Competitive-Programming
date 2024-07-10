class Solution {
private:
    int STARTING = 1;
    int ENDING = 2;
    int EMPTY_CELL = 0;
    int OBSTACLE = -1;

    int dir[5] = {0, 1, 0, -1, 0};

    vector<vector<bool>> isVisited;
    int uniquePaths, totalVisitedCell;
    int totalCells, totalVisitableCells, totalCellWithObstacles;

    bool isInside(int row, int col, vector<vector<int>>& grid){
        int height = grid.size(), weidth = grid[0].size();
        return (0 <= row && row < height && 0 <= col && col < weidth);
    }

    void backtrack(int row, int col, vector<vector<int>>& grid) {
        if(!isInside(row, col, grid)) return;
        if(isVisited[row][col] == true) return;
        if(grid[row][col] == OBSTACLE) return;

        isVisited[row][col] = true;
        totalVisitedCell++;

        if(grid[row][col] == ENDING){
            if(totalVisitableCells == totalVisitedCell){
                uniquePaths++;
            }
            isVisited[row][col] = false;
            totalVisitedCell--;
            return;
        }
        
        for(int i = 1; i < 5; i++){
            backtrack(row + dir[i - 1], col + dir[i], grid);
        }

        isVisited[row][col] = false;
        totalVisitedCell--;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int height = grid.size(), weidth = grid[0].size();
        isVisited.assign(height, vector<bool>(weidth, false));

        int startRow, startCol;
        for(int row = 0; row < height; row++){
            for(int col = 0; col < weidth; col++){
                if(grid[row][col] == STARTING){
                    startRow = row;
                    startCol = col;
                }
                if(grid[row][col] == OBSTACLE){
                    totalCellWithObstacles++;
                }
            }
        }

        totalCells = height*weidth;
        totalVisitableCells = totalCells - totalCellWithObstacles;

        backtrack(startRow, startCol, grid);
        return uniquePaths;
    }
};
