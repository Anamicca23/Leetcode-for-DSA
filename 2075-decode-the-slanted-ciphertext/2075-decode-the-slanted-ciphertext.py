class Solution(object):
    def decodeCiphertext(self, encodedText, rows):
        if rows == 1:
            return encodedText  
        n = len(encodedText)
        cols = n // rows 
        res = []
        for start_col in range(cols):
            r, c = 0, start_col
            while r < rows and c < cols:
                res.append(encodedText[r * cols + c])
                r += 1
                c += 1
        return "".join(res).rstrip()