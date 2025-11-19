class Solution {
    public boolean isAnagram(String s, String t) {
        // If lengths differ, cannot be anagrams
        int n = s.length();
        int m = t.length();
        if(n != m) return false;

        short[] count = new short[26];

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;   // increment for s
            count[t.charAt(i) - 'a']--;   // decrement for t
        }

        // If all counts == 0, then anagrams
        for (short c : count) {
            if (c != 0) return false;
        }

        return true;
    }
}

