public class Solution1 {
	public String intToRoman(int num) {
		// number inputed ranges from 1 to 3999
		if (num < 1 || num > 3999) {
			return "Number inputed is out of range";
		}

		int[] n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		String[] rn = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		String RomanNum = "";

		for (int i = 0; i < n.length; i++) {
			int coef = num / n[i];
			num = num % n[i];
			for (int j = 0; j < coef; j++) {
				RomanNum = RomanNum + rn[i];
			}
		}
		return RomanNum;
	}
}