public class Solution {
    public int reverse(int x) {
        int inter = x;
        int rest = 0;
        long result = 0;
        while(inter != 0) {
            rest = inter%10;
            inter = inter/10;
            result = result * 10 + rest;
            if (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) {
                result = 0;
                break;
            }
        }
        return (int) result;
    }
}
