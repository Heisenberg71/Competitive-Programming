class Solution {
    public String decodeString(String s) {
        Deque<Pair<Integer, StringBuilder>> stack = new ArrayDeque<>();
        stack.push(new Pair<>(1, new StringBuilder()));
        
        int value = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                value = value * 10 + (ch - '0');
            } else if (Character.isLowerCase(ch)) {
                stack.peek().getValue().append(ch);
            } else if (ch == ']') {
                Pair<Integer, StringBuilder> top = stack.pop();
                StringBuilder repeated = new StringBuilder();
                for (int i = 0; i < top.getKey(); i++) {
                    repeated.append(top.getValue());
                }
                stack.peek().getValue().append(repeated);
            } else if (ch == '[') {
                stack.push(new Pair<>(value, new StringBuilder()));
                value = 0;
            }
        }

        return stack.peek().getValue().toString();
    }

    static class Pair<K, V> {
        private final K key;
        private final V value;
        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
        public K getKey() { return key; }
        public V getValue() { return value; }
    }
}
