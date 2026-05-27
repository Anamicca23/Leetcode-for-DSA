class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        last_lower = {}
        first_upper = {}
        invalid = set()
        for i, ch in enumerate(word):
            letter = ch.lower()
            if ch.islower():
                last_lower[letter] = i
                if letter in first_upper:
                    invalid.add(letter)
            else:
                if letter not in first_upper:
                    first_upper[letter] = i
        special_count = 0
        for letter in last_lower:
            if letter in first_upper and letter not in invalid:
                special_count += 1
        return special_count