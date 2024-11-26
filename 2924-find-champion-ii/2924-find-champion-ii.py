class Solution:
    def findChampion(self, n, edges):
        freq = [0] * n

        # Count incoming edges for each node
        for edge in edges:
            e = edge[1]
            freq[e] += 1

        champ = -1
        count = 0

        # Find the node with zero incoming edges
        for i in range(n):
            if freq[i] == 0:
                champ = i
                count += 1
                if count > 1:
                    return -1  # More than one node with zero incoming edges

        return champ  # Return the champion or -1 if no unique champion exists
