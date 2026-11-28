class Solution {
    record Item(int price, int factor) implements Comparable<Item> {
        public int compareTo(Item other) {
            return Integer.compare(price, other.price);
        }
    }

    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int cheapest = Arrays.stream(items).mapToInt(item -> item[1]).min().getAsInt();
        int[] have = new int[n + 1], deals = new int[n + 1];  // have[f]: items with factor f
        for (int[] item : items) have[item[0]]++;
        Arrays.fill(deals, -1);  // counted when an item is reached

        List<Item> worth = Arrays.stream(items).filter(item -> item[1] < 2 * cheapest)
                .map(item -> new Item(item[1], item[0])).toList();
        PriorityQueue<Item> heap = new PriorityQueue<>(worth);  // built in O(n)
        int copies = 0;
        while (!heap.isEmpty() && heap.peek().price <= budget) {  // the cheapest deal left is affordable
            Item item = heap.poll();
            if (deals[item.factor] < 0)  // from -1: the item itself is not a deal
                for (int multiple = item.factor; multiple <= n; multiple += item.factor)
                    deals[item.factor] += have[multiple];
            int pairs = Math.min(deals[item.factor], budget / item.price);
            copies += 2 * pairs;
            budget -= pairs * item.price;
        }
        return copies + budget / cheapest;
    }
}