class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String,String> map = new HashMap<>();
        for(List<String> list : knowledge) {
            map.put(list.get(0),list.get(1));
        }

        StringBuilder key = new StringBuilder();
        StringBuilder res = new StringBuilder();
        boolean flag = false;

        for(char ch : s.toCharArray()) {
            if(ch == '(') {
                flag = true;
            }
            else if(ch == ')') {
                if(map.containsKey(key.toString())) {
                    res.append(map.get(key.toString()));
                }
                else {
                    res.append("?");
                }
                flag = false;
                key.setLength(0);
            }
            else if(flag) {
                key.append(ch);
            }
            else {
                res.append(ch);
            }
        }
        return res.toString();
    }
}