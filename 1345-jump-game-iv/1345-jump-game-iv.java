class Solution {
    public int minJumps(int[] arr) {
        HashMap<Integer, HashSet<Integer>> numIndexMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            numIndexMap.computeIfAbsent(arr[i], k -> new HashSet<>()).add(i);
        }
        boolean[] visited = new boolean[arr.length];
        boolean[] added = new boolean[arr.length];
        int[] jumps = new int[arr.length];
        int size = arr.length;
        Arrays.fill(jumps, Integer.MAX_VALUE);
        jumps[0] = 0;
        ArrayList<Integer> jumpList = new ArrayList<>();
        jumpList.add(0);
        added[0] = true;
        for (int i = 0; i < jumpList.size(); i++) {
            int currIndex = jumpList.get(i);
            if(visited[currIndex]) {
                continue;
            }
            visited[currIndex] = true;
            if (currIndex - 1 > 0 && !added[currIndex - 1] && !visited[currIndex - 1]) {
                jumpList.add(currIndex - 1);
                if(jumps[currIndex - 1] > jumps[currIndex] + 1) {
                    jumps[currIndex - 1] = jumps[currIndex] + 1;
                    added[currIndex - 1] = true;
                }
            }
            if (currIndex + 1 < size && !added[currIndex + 1] && !visited[currIndex + 1]) {
                jumpList.add(currIndex + 1);
                if(jumps[currIndex + 1]> jumps[currIndex] + 1) {
                    jumps[currIndex + 1] = jumps[currIndex] + 1;
                    added[currIndex + 1] = true;
                }
                if(currIndex + 1 == size - 1) {
                    break;
                }
            }
            HashSet<Integer> numIndexSet;
            if (numIndexMap.containsKey(arr[currIndex])) {
                numIndexSet = numIndexMap.get(arr[currIndex]);
                for(Integer index : numIndexSet) {
                    if (!added[index] && !visited[index]) {
                        jumpList.add(index);
                        if(jumps[index] > jumps[index] + 1) {
                            jumps[index] = jumps[currIndex] + 1;
                        }
                        if(index == size - 1) {
                            break;
                        }
                    }
                }
                numIndexMap.remove(arr[currIndex]);
            }
        }
        return jumps[size - 1];
    }
}