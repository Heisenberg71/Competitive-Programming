class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));
        Map<String, Integer> wordSequence = new HashMap<String, Integer>();
        int longestChainLength = 0;
        for(int i = 0; i < words.length; i++) {
            if(wordSequence.containsKey(words[i]) == false) wordSequence.put(words[i], 1);
            for(int ch = 0; ch < words[i].length(); ch++) {
                String firstPart = words[i].substring(0, ch);
                String lastPart = words[i].substring(ch + 1);

                if(wordSequence.containsKey(firstPart + lastPart) && wordSequence.get(words[i]) < 1 + wordSequence.get(firstPart + lastPart)) {
                    wordSequence.put(words[i], 1 + wordSequence.get(firstPart + lastPart));
                }
            }
            longestChainLength = Math.max(longestChainLength, wordSequence.get(words[i]));
        }
        return longestChainLength;
    }
}
