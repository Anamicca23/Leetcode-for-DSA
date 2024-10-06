from collections import deque

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        deque1 = deque(sentence1.split())
        deque2 = deque(sentence2.split())

        # Always compare the smaller sentence with the larger one
        if len(deque1) > len(deque2):
            deque1, deque2 = deque2, deque1

        # Compare from the front and back
        while deque1:
            if deque1[0] == deque2[0]:
                deque1.popleft()
                deque2.popleft()
            elif deque1[-1] == deque2[-1]:
                deque1.pop()
                deque2.pop()
            else:
                break

        # If deque1 is empty, it means sentence1 can be transformed into sentence2
        return not deque1
