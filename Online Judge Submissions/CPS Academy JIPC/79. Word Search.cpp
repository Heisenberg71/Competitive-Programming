class Solution {
private:
    constexpr static int adjacent_row[4] = {-1, 1, 0, 0};
    constexpr static int adjacent_col[4] = {0, 0, -1, 1};

    map<pair<int, int>, bool> isVisitedCell;

    bool isMatched(char currentLetter, int row, int col, vector<vector<char>>& board) {
        int rowSize = board.size(), colSize = board[0].size();
        if(row < 0 || rowSize <= row || col < 0 || colSize <= col || currentLetter != board[row][col]) {
            return false;
        }
        return true;
    }

    bool backtrack(int currentPosition, int row, int col, vector<vector<char>>& board, string word) {
        if(!isMatched(word[currentPosition], row, col, board)) return false;
        if(currentPosition+ 1 == word.size()) return true;

        bool isWordMatched = false;
        for(int i = 0; i < 4; i++) {
            int newRow = row + adjacent_row[i];
            int newCol = col + adjacent_col[i];
            if(isVisitedCell[ {newRow, newCol} ]) {
                continue;
            }
            isVisitedCell[ {newRow, newCol} ] = true;
            isWordMatched |= backtrack(currentPosition + 1, newRow, newCol, board, word);
            isVisitedCell[ {newRow, newCol} ] = false;
        }
        return isWordMatched;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool isWordFound = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                isVisitedCell[ {i, j} ] = true;
                isWordFound |= backtrack(0, i, j, board, word);
                isVisitedCell[ {i, j} ] = false;
            }
        }

        return isWordFound;
    }
};
