class Solution {
    public int minMeetingRooms(int[][] intervals) {
        Map<Integer, Integer> timeline = new TreeMap<>();
        for(var interval: intervals) {
            int L = interval[0];
            int R = interval[1];
            timeline.put(L, (timeline.containsKey(L) ? timeline.get(L) + 1: 1));
            timeline.put(R + 1, (timeline.containsKey(R + 1) ? timeline.get(R + 1) - 1 : -1));
        }

        int maxConcurrentMeetings = 0;
        int currentConcurrentMeetings = 0;
        for(Integer value: timeline.values()) {
            currentConcurrentMeetings += value;
            maxConcurrentMeetings = Math.max(maxConcurrentMeetings, currentConcurrentMeetings);
        }

        return maxConcurrentMeetings;
    }
}
