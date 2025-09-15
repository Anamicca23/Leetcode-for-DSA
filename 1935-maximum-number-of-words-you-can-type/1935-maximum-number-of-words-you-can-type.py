class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        brokenKeyMap = [0] * 26
        asciiA = ord('a')

        # Mark broken keys
        for c in brokenLetters:
            brokenKeyMap[ord(c) - asciiA] = 1

        word_count = 1
        broken_word_count = 0
        word_has_broken_key = False

        for c in text:
            if c == " ":
                if word_has_broken_key:
                    broken_word_count += 1
                word_has_broken_key = False
                word_count += 1
            elif not word_has_broken_key and brokenKeyMap[ord(c) - asciiA] > 0:
                word_has_broken_key = True

        # Check last word
        if word_has_broken_key:
            broken_word_count += 1

        return word_count - broken_word_count