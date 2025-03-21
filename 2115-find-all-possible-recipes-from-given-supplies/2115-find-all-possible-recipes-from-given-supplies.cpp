class Solution {
   public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients,
								  vector<string>& supplies) {
		unordered_set<string> suppliesSet;
		for (const auto& ingredient : supplies) {
			suppliesSet.insert(ingredient);
		}

		unordered_map<string, const vector<string>*> recipeMap;

		for (size_t i = 0; i < recipes.size(); ++i) {
			recipeMap[recipes[i]] = &ingredients[i];
		}

		for (const auto& recipe : recipes) {
			search(recipe, recipeMap, suppliesSet);
		}

		vector<string> result;
		for (const auto& recipe : recipes) {
			if (suppliesSet.contains(recipe)) result.push_back(recipe);
		}

		return result;
	}

   private:
	void search(const string& recipe, unordered_map<string, const vector<string>*>& recipeMap,
				unordered_set<string>& supplies) {
		if (supplies.contains(recipe)) return;

		auto it = recipeMap.find(recipe);
		if (it == recipeMap.end()) return;

		const vector<string>* ingredientList = it->second;

		recipeMap.erase(it);

		bool canMake = true;
		for (const auto& ingredient : *ingredientList) {
			if (supplies.contains(ingredient)) continue;
			search(ingredient, recipeMap, supplies);

			if (!supplies.contains(ingredient)) {
				canMake = false;
				break;
			}
		}

		recipeMap[recipe] = ingredientList;

		if (canMake) supplies.insert(recipe);
	}
};