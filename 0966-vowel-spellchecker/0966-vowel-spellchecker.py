class Solution:
    def spellchecker(self, wordlist, queries):
        exact_match_set = set(wordlist)
        case_insensitive_map = {}
        vowel_insensitive_map = {}

        def normalize_vowels(word: str) -> str:
            vowels = set("aeiou")
            return "".join("*" if c in vowels else c for c in word)

        # Build maps
        for word in wordlist:
            lower_word = word.lower()
            case_insensitive_map.setdefault(lower_word, word)
            vowel_insensitive_map.setdefault(normalize_vowels(lower_word), word)

        results = []
        for query in queries:
            if query in exact_match_set:
                results.append(query)
                continue

            lower_query = query.lower()
            if lower_query in case_insensitive_map:
                results.append(case_insensitive_map[lower_query])
                continue

            vowel_normalized = normalize_vowels(lower_query)
            if vowel_normalized in vowel_insensitive_map:
                results.append(vowel_insensitive_map[vowel_normalized])
                continue

            results.append("")  # No match found

        return results