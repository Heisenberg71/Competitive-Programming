class Solution {
    public String longestCommonPrefix(String[] strs) {
        int matchedPrefixLength = strs[0].length();
        for(int i = 1; i < strs.length; i++) {
            int maxPrefixLength = 0;
            for(int j = 0; j < strs[i].length(); j++) {
                if(j < strs[0].length() && strs[i].charAt(j) != strs[0].charAt(j)) {
                    break;
                }
                maxPrefixLength++;
            }
            matchedPrefixLength = Math.min(matchedPrefixLength, maxPrefixLength);
        }
        return strs[0].substring(0, matchedPrefixLength);
    }
}
