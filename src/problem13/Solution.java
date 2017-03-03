public class Solution {

	public int getVal(char s) {
        switch(s) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    public int romanToInt(String s) {
        // number inputed ranges from 1 to 3999
        int result = 0;
        int max = getVal('I');
        for (int i = s.length() - 1; i >= 0; i--) {
            int num = getVal(s.charAt(i));
            if (num >= max) {
                max = num;
                result = result + num;
            } else {
                result = result - num;
            }
        }
        return result;
    }
}