#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    struct Compare {
        unordered_map<string, int>* ratingMap;
        Compare(unordered_map<string, int>* rm) : ratingMap(rm) {}
        bool operator()(const string& a, const string& b) const {
            int r1 = ratingMap->at(a);
            int r2 = ratingMap->at(b);
            if (r1 != r2) return r1 > r2;  // higher rating first
            return a < b;                  // lexicographically smaller first
        }
    };

    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<string, function<bool(const string&, const string&)>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }

        for (int i = 0; i < foods.size(); i++) {
            string cuisine = cuisines[i];
            if (!cuisineFoods.count(cuisine)) {
                cuisineFoods[cuisine] = set<string, function<bool(const string&, const string&)>>(
                    [&](const string& a, const string& b) {
                        int r1 = foodToRating[a];
                        int r2 = foodToRating[b];
                        if (r1 != r2) return r1 > r2;
                        return a < b;
                    }
                );
            }
            cuisineFoods[cuisine].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& s = cuisineFoods[cuisine];

        s.erase(food);
        foodToRating[food] = newRating;
        s.insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineFoods[cuisine].begin();
    }
};