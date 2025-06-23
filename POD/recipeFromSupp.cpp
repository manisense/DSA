#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    // Create graph and count incoming dependencies
    unordered_map<string, vector<string>> adj;  // item -> list of recipes that can be made once this item is available
    unordered_map<string, int> inDegree;        // recipe -> count of unavailable ingredients
    unordered_set<string> recipeSet(recipes.begin(), recipes.end());
    unordered_set<string> availableItems(supplies.begin(), supplies.end());
    
    // Initialize in-degree for all recipes
    for (int i = 0; i < recipes.size(); i++) {
        inDegree[recipes[i]] = 0;
    }
    
    // Build graph
    for (int i = 0; i < recipes.size(); i++) {
        for (const string& ingredient : ingredients[i]) {
            if (!availableItems.count(ingredient)) {
                if (recipeSet.count(ingredient)) {
                    // This ingredient is another recipe
                    adj[ingredient].push_back(recipes[i]);
                    inDegree[recipes[i]]++;
                } else {
                    // This ingredient is not available and not another recipe
                    inDegree[recipes[i]]++;
                }
            }
        }
    }
    
    // Start BFS with recipes that have all ingredients available
    queue<string> q;
    for (const string& recipe : recipes) {
        if (inDegree[recipe] == 0) {
            q.push(recipe);
        }
    }
    
    vector<string> result;
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        result.push_back(current);
        availableItems.insert(current);
        
        // Update dependencies
        for (const string& dependent : adj[current]) {
            inDegree[dependent]--;
            if (inDegree[dependent] == 0) {
                q.push(dependent);
            }
        }
    }
    
    return result;
}

int main() {
    vector<string> recipes = {"xevvq","izcad","p","we","bxgnm","vpio","i","hjvu","igi","anp","tokfq","z","kwdmb","g","qb","q","b","hthy"};

    vector<vector<string>> ingredients = {{"wbjr"},{"otr","fzr","g"},{"fzr","wi","otr","xgp","wbjr","igi","b"},{"fzr","xgp","wi","otr","tokfq","izcad","igi","xevvq","i","anp"},{"wi","xgp","wbjr"},{"wbjr","bxgnm","i","b","hjvu","izcad","igi","z","g"},{"xgp","otr","wbjr"},{"wbjr","otr"},{"wbjr","otr","fzr","wi","xgp","hjvu","tokfq","z","kwdmb"},{"xgp","wi","wbjr","bxgnm","izcad","p","xevvq"},{"bxgnm"},{"wi","fzr","otr","wbjr"},{"wbjr","wi","fzr","xgp","otr","g","b","p"},{"otr","fzr","xgp","wbjr"},{"xgp","wbjr","q","vpio","tokfq","we"},{"wbjr","wi","xgp","we"},{"wbjr"},{"wi"}};
    
    vector<string> supplies = {"wi","otr","wbjr","fzr","xgp"};

    vector<string> result = findAllRecipes(recipes, ingredients, supplies);

    cout << "Total recipes we can make: " << result.size() << endl;
    cout << "Recipes: ";
    for(const auto& recipe : result) {
        cout << recipe << " ";
    }
    cout << endl;
    
    return 0;
}