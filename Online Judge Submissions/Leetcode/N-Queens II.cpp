class Solution {
private:
    vector<vector<string>> uniqueValidQueenPlacements;
    vector<vector<int>> placedQueenTillNow;

    void placeQueensOnChessboard(int n) {
        string chessboardRow(n, '.');
        vector<string> chessBoard = vector<string>(n, chessboardRow);
        for(int i = 0; i < placedQueenTillNow.size(); i++){
            chessBoard[ placedQueenTillNow[i][0] ][ placedQueenTillNow[i][1] ] = 'Q';
        }
        uniqueValidQueenPlacements.push_back(chessBoard);
    }

    bool isAValidKeyPosition(int row, int col) {
        for(int i = 0; i < placedQueenTillNow.size(); i++){
            int oldQueenRow = placedQueenTillNow[i][0], oldQueenCol = placedQueenTillNow[i][1];
            if(oldQueenRow == row || oldQueenCol == col || 
                abs(oldQueenRow - row) == abs(oldQueenCol - col)) return false;
        }
        return true;
    }

    void backtrack(int queenPlaced, int currentRow, int n) {
        if(currentRow == n && queenPlaced == n) {
            placeQueensOnChessboard(n);
            return;
        }
        if(currentRow == n) return;

        for(int col = 0; col < n; col++) {
            if(isAValidKeyPosition(currentRow, col)) {
                placedQueenTillNow.push_back({currentRow, col});
                backtrack(queenPlaced + 1, currentRow + 1, n);
                placedQueenTillNow.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        
        backtrack(0, 0, n);
        return uniqueValidQueenPlacements;
    }
};
