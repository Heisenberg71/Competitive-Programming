class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<List<Integer>, List<String>> shiftedGroup_string_map = new HashMap<>(); 
        for(String s: strings) {
            List<Integer> differenceList = new ArrayList<>();
            for(int i = 0; i < s.length(); i++) {
                int charDifference = s.charAt(0) - s.charAt(i);
                if(charDifference < 0) charDifference += 26;
                differenceList.add(charDifference);
            }
            if(!shiftedGroup_string_map.containsKey(differenceList)) {
                shiftedGroup_string_map.put(differenceList, new ArrayList<String>());
            }
            List<String> currentListString = shiftedGroup_string_map.get(differenceList);
            currentListString.add(s);
            shiftedGroup_string_map.put(differenceList, currentListString);
        }

        return new ArrayList<>(shiftedGroup_string_map.values());
    }
}
