public class Solution {
	public String intToRoman(int num) {
		// the input is ranged from 1 to 3999
		if (num < 1 || num > 3999) {
			return "Number inputed is out of range";
		}

		int[] coef = new int[4];
		int[] n = {1000, 100, 10, 1};
		String[] rn1 = {"M", "C", "X", "I"};
		String[] rn2 = {"", "D", "L", "V"};
		String RomanNum = "";
		for (int i = 0; i < 4; i++) {
			coef[i] = num / n[i];
			num = num % n[i];
			if (coef[i] == 9) 
				RomanNum = RomanNum + rn1[i] + rn1[i - 1];
			else if (coef[i] >= 5) {
				RomanNum = RomanNum + rn2[i];
				for (int j = coef[i] - 5; j > 0; j--) {
					RomanNum = RomanNum + rn1[i];
				}
			}
			else if (coef[i] == 4)
				RomanNum = RomanNum + rn1[i] + rn2[i];
			else {
				for (int j = 0; j < coef[i]; j++) {
					RomanNum = RomanNum + rn1[i];
				}
			}
		}
		return RomanNum;
	}
}