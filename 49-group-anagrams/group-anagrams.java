class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            int[] count = new int[26];
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
            }

            // Convert to key string like "1#0#0#2#..."
            StringBuilder key = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                key.append(count[i]).append('#');
            }

            map.computeIfAbsent(key.toString(), k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
