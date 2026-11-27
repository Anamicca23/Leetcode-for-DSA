class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        auto factors =
            items | views::transform([](auto& item) { return item[0]; });
        auto prices =
            items | views::transform([](auto& item) { return item[1]; });
        int top = ranges::max(factors);
        vector<int> have(top + 1),
            gains(top + 1); // have[f]: items with factor f
        for (int factor : factors)
            have[factor]++;
        for (int factor = 1; factor <= top;
             factor++) // every factor-th cell is a multiple
            gains[factor] = ranges::fold_left(
                have | views::drop(factor) | views::stride(factor), 0, plus{});

        int cheapest = ranges::min(prices);
        vector<int> best(
            budget +
            1); // no first copies yet: everything goes to the cheapest item
        for (int money = 0; money <= budget; money++)
            best[money] = money / cheapest;
        for (auto& item : items) {
            int factor = item[0], price = item[1];
            if (int gain = gains[factor];
                gain > price / cheapest) // else the same money buys as many
                                         // copies of the cheapest item
                for (int money = budget; money >= price;
                     money--) // backwards: one first copy per item
                    best[money] = max(best[money], best[money - price] + gain);
        }
        return best[budget];
    }
};