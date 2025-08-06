class Solution {
    int[] segTree ;
    //construct the segment tree using baskets array
    void constructTree(int[] basket,int st,int end,int n){
        if(st == end){
            segTree[n] = basket[st];
            return;
        }
        int mid = (st+end)/2;
        constructTree(basket,st,mid,2*n);
        constructTree(basket,mid+1,end,2*n+1);
        segTree[n] = Math.max(segTree[2*n],segTree[2*n+1]);
    }
    //search and update the leaf to root nodes 
    int search(int n, int st, int end, int k) {
        if (segTree[n] < k) return -1;
        if (st == end) {
            segTree[n] = -1;
            return st;
        }
        int mid = (st + end) / 2;
        int pos = -1;
        //(we need to find minimum index )
        //first check the left tree if it is possible go left 
        //else go right 
        if (segTree[2 * n] >= k) {
            pos = search(2 * n, st, mid, k);
        } else {
            pos = search(2 * n+ 1, mid + 1, end, k);
        }
        segTree[n] = Math.max(segTree[2 * n], segTree[2 * n + 1]);
        //returns the minimum index where fruit[i] can be placed
        return pos;
    }

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        segTree = new int[4*n];
        constructTree(baskets,0,n-1,1);
        int ans= 0;
        //for each fruit find the left most basket from tree
        for (int i = 0; i < n; i++) {
            int pos = search(1, 0, n - 1, fruits[i]);
            //no basket is empty where the fruit[i] can be taken
            if (pos == -1) 
                ans++;
        }
        return ans;

    }
}