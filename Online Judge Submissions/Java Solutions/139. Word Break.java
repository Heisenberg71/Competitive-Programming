class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        s = '#' + s;
        int length = s.length();
        boolean[] isMakeable = new boolean[length];
        isMakeable[0] = true;
        for(int i = 0; i < length; i++) {
            if(isMakeable[i] == false) {
                continue;
            }
            for(String word: wordDict) {
                int wordLength = word.length();
                if(i + wordLength < length && s.substring(i + 1, i + wordLength + 1).equals(word)) {
                    isMakeable[i + wordLength] = true;
                }
            }
        }
        for(int i = 0; i < length; i++) {
            System.out.println(isMakeable[i] + " ");
        }
        return isMakeable[length - 1];
    }
}
