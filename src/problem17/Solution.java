public class Solution {
    public List<String> letterCombinations(String digits) {
        String[] phoneNum = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> list = new ArrayList<>();
        List<String> listTemp = new ArrayList<>();

        for (int i = 0; i < digits.length(); i++) {
            char c = digits.charAt(i);
            int num = Character.getNumericValue(c);
            if (list.size() == 0) {
                for (int j = 0; j < phoneNum[num].length(); j++) {
                    list.add(String.valueOf(phoneNum[num].charAt(j)));
                }
            } else {
                for (String s:
                     list) {
                    for (int j = 0; j < phoneNum[num].length(); j++) {
                        listTemp.add(s+phoneNum[num].charAt(j));
                    }
                }
                list.clear();
                list.addAll(listTemp);
                listTemp.clear();
            }
        }
        return list;
    }
}