class TimeMap {
    class Pair {
        String value;
        int timestamp;
        public Pair(String value, int timestamp) {
            this.value = value;
            this.timestamp = timestamp;
        }
    }

    Map<String, List<Pair>> keyValue = new HashMap<>();

    String binarySearch(List<Pair> valueList, int timestamp) {
        String value = new String("");
        int lo = 0, hi = valueList.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(valueList.get(mid).timestamp <= timestamp) {
                value = valueList.get(mid).value;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return value;
    }

    public TimeMap() {

    }

    public void set(String key, String value, int timestamp) {
        List<Pair> valueList = keyValue.get(key);
        if (valueList == null) {
            valueList = new ArrayList<>();
        }
        valueList.add(new Pair(value, timestamp));
        keyValue.put(key, valueList);
    }

    public String get(String key, int timestamp) {
        List<Pair> valueList = keyValue.get(key);
        if (valueList == null) {
            return new String("");
        }
        return binarySearch(valueList, timestamp);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
