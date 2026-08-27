class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1
        for ch in target:
            cnt[ord(ch) - ord('a')] -= 1
        bad = 0
        mask = 0
        for c in range(26):
            if cnt[c] < 0:
                bad += 1
            elif cnt[c]:
                mask |= 1 << c
        for i in range(len(target) - 1, -1, -1):
            cur = ord(target[i]) - ord('a')
            cnt[cur] += 1
            if cnt[cur] == 0:
                bad -= 1
            elif cnt[cur] == 1:
                mask |= 1 << cur
            if bad:
                continue
            up = mask >> (cur + 1)
            if not up:
                continue
            nxt = cur + 1 + (up & -up).bit_length() - 1
            cnt[nxt] -= 1
            ans = list(target[:i])
            ans.append(chr(nxt + ord('a')))
            for c in range(26):
                ans.extend(chr(c + ord('a')) * cnt[c])
            return ''.join(ans)
        return ""