public class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        char[] input = s.toCharArray();
        int head = -1;
        int tail = -1;
        int back = 0;
        int countOnes = 0;
        for (int front = 0; front < input.length; ++front) {
            countOnes += input[front] - '0';
            if (countOnes < k) {
                continue;
            }
            while (back < front && input[back] == '0') {
                countOnes -= input[back] - '0';
                ++back;
            }
            if (head == -1 || head - tail + 1 > front - back + 1) {
                head = front;
                tail = back;
            } else if (head - tail + 1 == front - back + 1
                    && s.substring(tail, head + 1).compareTo(s.substring(back, front + 1)) > 0) {
                head = front;
                tail = back;
            }
            while (back < front && countOnes == k) {
                countOnes -= input[back] - '0';
                ++back;
            }
        }
        return head != -1 ? s.substring(tail, head + 1) : "";
    }
}