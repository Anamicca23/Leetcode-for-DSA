import java.util.*;

public class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        Deque<String> deque1 = new LinkedList<>();
        Deque<String> deque2 = new LinkedList<>();

        // Split sentence1 into deque1
        for (String word : sentence1.split(" ")) {
            deque1.addLast(word);
        }

        // Split sentence2 into deque2
        for (String word : sentence2.split(" ")) {
            deque2.addLast(word);
        }

        // Always compare the smaller sentence with the larger one
        if (deque1.size() > deque2.size()) {
            Deque<String> temp = deque1;
            deque1 = deque2;
            deque2 = temp;
        }

        // Compare from the front and back
        while (!deque1.isEmpty()) {
            if (deque1.peekFirst().equals(deque2.peekFirst())) {
                deque1.pollFirst();
                deque2.pollFirst();
            } else if (deque1.peekLast().equals(deque2.peekLast())) {
                deque1.pollLast();
                deque2.pollLast();
            } else {
                break;
            }
        }

        // If deque1 is empty, it means sentence1 can be transformed into sentence2
        return deque1.isEmpty();
    }
}
