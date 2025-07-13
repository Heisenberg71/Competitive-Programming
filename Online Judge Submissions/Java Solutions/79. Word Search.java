class Solution {
    boolean[][] isVisited;
    int[] direction = { 0, 1, 0, -1, 0 };

    boolean isInside(int row, int col, char[][] board) {
        return (0 <= row && row < board.length && 0 <= col && col < board[0].length);
    }

    boolean traverse(int index, int row, int col, char[][] board, String word) {
        if(index == word.length()) {
            return true;
        }
        boolean isExist = false;
        for(int dir = 1; dir < 5; dir++) {
            int newRow = row + direction[dir - 1];
            int newCol = col + direction[dir];
            if(isInside(newRow, newCol, board) && !isVisited[newRow][newCol] && board[newRow][newCol] == word.charAt(index)) {
                isVisited[newRow][newCol] = true;
                isExist |= traverse(index + 1, newRow, newCol, board, word);
                isVisited[newRow][newCol] = false;
            }
        }
        return isExist;
    }

    public boolean exist(char[][] board, String word) {
        int height = board.length;
        int width = board[0].length;
        isVisited = new boolean[height][width];

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(!word.isBlank() && board[i][j] == word.charAt(0)) {
                    isVisited[i][j] = true;
                    boolean isExist = traverse(1, i, j, board, word);
                    if(isExist) {
                        return true;
                    }
                    isVisited[i][j] = false;
                }
            }
        }

        return false;
    }
}
