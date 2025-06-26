class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<String, List<String>>();

        for(String str: strs) {
            String sortedStr = bucketSort(str);
            List<String> anagramList = anagramMap.containsKey(sortedStr) == true ? anagramMap.get(sortedStr) : new ArrayList<String>();
            anagramList.add(str);
            anagramMap.put(sortedStr, anagramList);
        }

        List<List<String>> anagrams = new ArrayList<>();
        for(List<String> anagramList: anagramMap.values()) {
            anagrams.add(anagramList);
        }

        return anagrams;
    }

    private String bucketSort(String str) {
        int[] charCount = new int[26];
        for(int i = 0; i < str.length(); i++) {
            charCount[ str.charAt(i) - 'a' ]++;
        }

        StringBuffer sf = new StringBuffer();
        for(int i = 0; i < 26; i++) {
            sf.append(String.valueOf('a' + i).repeat(charCount[i]));
        }
        
        return sf.toString();
    }
}
