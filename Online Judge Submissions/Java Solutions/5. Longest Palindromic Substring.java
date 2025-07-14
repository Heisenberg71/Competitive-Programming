class Solution {
    public String longestPalindrome(String s) {
        int maxPalindromeLength = 0;
        int startingPoint = -1;
        int length = s.length();
        for(int i = 0; i < length; i++) {
            for(int j = i, k = i; j >= 0 && k < length; j--, k++) {
                if(s.charAt(j) != s.charAt(k)) {
                    break;
                }
                if(maxPalindromeLength < k - j + 1) {
                    maxPalindromeLength = k - j + 1;
                    startingPoint = j;
                }
            }
            for(int j = i, k = i + 1; j >= 0 && k < length; j--, k++) {
                if(s.charAt(j) != s.charAt(k)) {
                    break;
                }
                if(maxPalindromeLength < k - j + 1) {
                    maxPalindromeLength = k - j + 1;
                    startingPoint = j;
                }
            }
        }
        return s.substring(startingPoint, startingPoint + maxPalindromeLength);
    }
}
