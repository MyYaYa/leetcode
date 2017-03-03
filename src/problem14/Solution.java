public class Solution {
	public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        int i = 0;
        char c = ' ';
        boolean b = true;
        StringBuilder result = new StringBuilder();

        while (true) {
            if (i == strs[0].length()) {
                b = false;
            } else {
                c = strs[0].charAt(i);
                for (String s :
                        strs) {
                    if (i == s.length()) {
                        b = false;
                        break;
                    }
                    if (s.charAt(i) != c) {
                        b = false;
                        break;
                    }
                }
            }
            if (b == false) {
                return result.toString();
            } else {
                i++;
                result.append(c);
            }
        }
    }
}