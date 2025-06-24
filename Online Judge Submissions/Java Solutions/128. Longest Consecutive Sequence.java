class Solution {
    Map<Integer, Integer> valueSequenceMap = new HashMap<>();

    private int findPrevSequence(int num) {
        if(valueSequenceMap.containsKey(num) == false) return 0;
        if(valueSequenceMap.get(num) != 0) return valueSequenceMap.get(num);

        valueSequenceMap.put(num, findPrevSequence(num - 1) + 1);
        return valueSequenceMap.get(num);
    }
    
    public int longestConsecutive(int[] nums) {
        for(int num: nums) {
            valueSequenceMap.put(num, 0);
        }

        int longestSequenceLength = 0;
        for(int num: nums) {
            if(valueSequenceMap.get(num) > 0) continue;

            findPrevSequence(num);
            longestSequenceLength = Math.max(longestSequenceLength, findPrevSequence(num));
        }

        return longestSequenceLength;
    }
}
