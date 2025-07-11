class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> exist = new HashSet<>();
        int left = 0, maxLength = 0;
        for(int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            while(exist.contains(rightChar)) {
                char leftChar = s.charAt(left);
                exist.remove(leftChar);
                left++;
            }
            exist.add(rightChar);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        return maxLength;
    }
}
