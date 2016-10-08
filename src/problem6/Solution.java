public class Solution {
    public String convert(String s, int numRows) {
        int len = s.length();
        if (numRows == 1) {
            return s;
        }
        int period = 2 * numRows - 2;
        int periodNums = len/period + (len%period == 0 ? 0 : 1);
        String result = "";
        for (int i = 0; i <= period / 2; i++) {
            for (int j = 0; j < periodNums; j++) {
                if (i == 0 || i == period / 2) {
                    if (j*period+i >= len) break;
                    result = result + s.charAt(j*period + i);
                } else {
                    if (j*period+i >= len)
                        break;
                    else if (j*period+period-i >= len)
                        result = result + s.charAt(j*period + i);
                    else
                        result = result + s.charAt(j*period + i) + s.charAt(j*period + (period - i));
                }
            }
        }
        return result;
    }
}
