class Solution {
    private int[][] nextCharPosition;
    public int numMatchingSubseq(String s, String[] words) {
        int length = s.length();
        int ALPHABET_SIZE = 26;
        nextCharPosition = new int[length + 1][ALPHABET_SIZE];

        for(int i = s.length() - 1; i >= 0; i--) {
            for(int ch = 0; ch < ALPHABET_SIZE; ch++) {
                nextCharPosition[i][ch] = nextCharPosition[i + 1][ch];
            }
            nextCharPosition[i][ s.charAt(i) - 'a' ] = i + 1;
        }

        int matchCount = 0;
        for(String word: words) {
            if(isSubsequence(word)) matchCount++;
        }

        return matchCount;
    }

    private boolean isSubsequence(String word) {
        int mainStringIndex = 0;
        for(int i = 0; i < word.length(); i++) {
            if(nextCharPosition[mainStringIndex][ word.charAt(i) - 'a' ] == 0) return false;
            mainStringIndex = nextCharPosition[mainStringIndex][ word.charAt(i) - 'a' ];
        }
        return true;
    }
}
