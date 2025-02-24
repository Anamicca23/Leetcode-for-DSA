class Solution
{
    public int mostProfitablePath(int[][] edges, int bob, int[] amount)
    {
        int n = amount.length;
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) tree[i] = new ArrayList<>();

        // Step 1: Build the adjacency list representation of the tree
        for (int[] e : edges)
        {
            tree[e[0]].add(e[1]);
            tree[e[1]].add(e[0]);
        }

        int[] bobTime = new int[n];
        Arrays.fill(bobTime, -1);

        // Step 2: Track Bob’s path and record when he reaches each node
        findBobPath(bob, 0, tree, bobTime, 0);

        // Step 3: Use DFS for Alice to find the most profitable path
        return dfs(0, -1, tree, amount, 0, bobTime);
    }

    private boolean findBobPath(int node, int time, List<Integer>[] tree, int[] bobTime, int bob)
    {
        bobTime[node] = time;
        if (node == 0) return true;

        for (int neighbor : tree[node])
        {
            if (bobTime[neighbor] == -1 && findBobPath(neighbor, time + 1, tree, bobTime, bob))
            {
                return true;
            }
        }
        bobTime[node] = -1;
        return false;
    }

    private int dfs(int node, int parent, List<Integer>[] tree, int[] amount, int time, int[] bobTime)
    {
        int income = amount[node];

        // Step 4: Adjust Alice’s income based on Bob’s arrival time
        if (bobTime[node] != -1)
        {
            if (bobTime[node] > time)
            {
            }
            else if (bobTime[node] == time)
            {
                income /= 2;
            }
            else
            {
                income = 0;
            }
        }

        int maxProfit = Integer.MIN_VALUE;
        boolean isLeaf = true;

        for (int neighbor : tree[node])
        {
            if (neighbor != parent)
            {
                isLeaf = false;
                maxProfit = Math.max(maxProfit, dfs(neighbor, node, tree, amount, time + 1, bobTime));
            }
        }

        // Step 5: If leaf node, return income, else return maxProfit + income
        return income + (isLeaf ? 0 : maxProfit);
    }
}