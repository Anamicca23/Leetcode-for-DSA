class Solution {
public:
    string decodeCiphertext(string encoded, int rows) {
        int n = encoded.length();
        int cols = n / rows;

        string original;
        original.reserve(n);

        int last_chr = -1;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (i + j == cols) {
                    original.resize(last_chr + 1); 
                    return original;
                }
                int idx = j * cols + i + j;
                if (encoded[idx] != ' ') last_chr = original.length();
                original.push_back(encoded[idx]);
            }
        }
        original.resize(last_chr + 1);
        return original;
    }
};