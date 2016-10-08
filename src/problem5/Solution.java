public class Solution {
    public String longestPalindrome(String s) {
         if (s == null) {
            return null;
        } else if (s.length() <= 1) {
            return s;
        }

        String max = s.substring(0, 1);

        for (int i = 0; i < s.length(); i++) {
            int start = i, stop = i;
            while (start >=0 && stop < s.length() && s.charAt(start) == s.charAt(stop)) {
                start--;
                stop++;
            }
            String tmp1 = s.substring(start+1, stop);
            start = i;
            stop = i+1;
            while (start >=0 && stop < s.length() && s.charAt(start) == s.charAt(stop)) {
                start--;
                stop++;
            }
            String tmp2 = s.substring(start+1, stop);
            if (tmp1.length() > max.length() && tmp1.length() > tmp2.length()) {
                max = tmp1;
            } else if (tmp2.length() > max.length() && tmp2.length() > tmp1.length()) {
                max = tmp2;
            }
        }
        return max;
    }
}
