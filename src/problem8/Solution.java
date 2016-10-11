public class Solution {
    public int myAtoi(String str) {
        if (str == null) {
            return 0;
        }
        str = str.trim();
        if (str.length() == 0) {
            return 0;
        }
        int index = 0;
        boolean isNeg = false;
        if (str.charAt(index) == '-' || str.charAt(index) == '+') {
            if (str.charAt(index) == '-') {
                isNeg = true;
            }
            index++;
        }
        long result = 0;
        while (index < str.length() && str.charAt(index) > '0' && str.charAt(index) < '9') {
            result = result * 10 + (int) str.charAt(index) - 48;
            if (result > Integer.MAX_VALUE) {
                if (isNeg) {
                    return Integer.MIN_VALUE;
                } else {
                    return Integer.MAX_VALUE;
                }
            }
            index++;
        }
        return isNeg ? (int) -result : (int) result;
    }
}
