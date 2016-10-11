public class ManacherSolution {
    public String preProcess(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append('#');
        for (int i = 0; i < s. length(); i++) {
            sb.append(s.charAt(i));
            sb.append('#');
        }
        return String.valueOf(sb);
    }

    public String longestPalindrome(String s) {
        String newStr = preProcess(s);
        int[] rad = new int[newStr.length()];
        int pos = 0;
        int maxRight = 0;
        int maxLen = 0;
        int mid = 0;
        for (int i = 0; i < newStr.length(); i++) {
            if (i < maxRight)
                rad[i] = Integer.min(rad[pos*2 - i], maxRight - i);
            else
                rad[i] = 1;
            while (i-rad[i] >= 0 && i+rad[i] < newStr.length() && newStr.charAt(i-rad[i]) == newStr.charAt(i+rad[i]))
                rad[i]++;
            /* update pos and maxRight */
            if (i + rad[i] - 1 > maxRight) {
                maxRight = i + rad[i] - 1;
                pos = i;
            }
            if (rad[i] - 1 > maxLen) {
                maxLen = rad[i] - 1;
                mid = i;
            }
        }
        return s.substring((mid-maxLen)/2, (mid+maxLen)/2);
    }
}
