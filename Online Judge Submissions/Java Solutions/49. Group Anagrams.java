class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<String, List<String>>();

        for(String str: strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sortedStr = new String(chars);

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
}
