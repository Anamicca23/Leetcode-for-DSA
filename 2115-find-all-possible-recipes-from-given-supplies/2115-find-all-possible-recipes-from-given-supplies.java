import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Set<String> supplySet = new HashSet<>(Arrays.asList(supplies));
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> inDegree = new HashMap<>();

        for (int i = 0; i < recipes.length; i++) {
            for (String ing : ingredients.get(i)) {
                if (!supplySet.contains(ing)) {
                    graph.computeIfAbsent(ing, k -> new ArrayList<>()).add(recipes[i]);
                    inDegree.merge(recipes[i], 1, Integer::sum);
                }
            }
        }

        Queue<String> q = new ArrayDeque<>();
        for (String r : recipes) if (inDegree.getOrDefault(r, 0) == 0) q.offer(r);
        
        List<String> result = new ArrayList<>();
        while (!q.isEmpty()) {
            String curr = q.poll();
            result.add(curr);
            for (String nxt : graph.getOrDefault(curr, Collections.emptyList())) {
                if (inDegree.merge(nxt, -1, Integer::sum) == 0) q.offer(nxt);
            }
        }
        return result;
    }
}
