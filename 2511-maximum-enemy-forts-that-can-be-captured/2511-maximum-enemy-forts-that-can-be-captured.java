class Solution {
	public int captureForts(int[] forts) {
		int ans = 0; 
		for (int i = 0, ii = 0; i < forts.length; ++i) 
			if (forts[i] != 0) {
				if (forts[ii] == -forts[i]) ans = Math.max(ans, i-ii-1); 
				ii = i; 
			}
		return ans; 
	}
}