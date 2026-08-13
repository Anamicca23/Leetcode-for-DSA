class Solution {
    private static class SegmentTree {
        private final int n;
        private final int[] pre;
        private final int[] suf;
        private final int[] best;
        private final char[] cs;

        public SegmentTree(String s) {
            n = s.length();
            pre = new int[n << 2];
            suf = new int[n << 2];
            best = new int[n << 2];
            cs = s.toCharArray();

            build(1, 0, n - 1);
        }

        private void build(int node, int l, int r) {
            if (l == r) {
                pre[node] = suf[node] = best[node] = 1;
                return;
            }
            int mid = (l + r) >>> 1;
            build(node << 1, l, mid);
            build(node << 1 | 1, mid + 1, r);
            pushUp(node, l, r);
        }

        private void pushUp(int node, int l, int r) {
            int left = node << 1;
            int right = node << 1 | 1;
            int mid = (l + r) >>> 1;
            int lenL = mid - l + 1;
            int lenR = r - mid;

            pre[node] = pre[left];
            suf[node] = suf[right];
            best[node] = Math.max(best[left], best[right]);
            if (cs[mid] == cs[mid + 1]) {
                if (pre[left] == lenL) {
                    pre[node] = lenL + pre[right];
                }
                if (suf[right] == lenR) {
                    suf[node] = lenR + suf[left];
                }
                best[node] = Math.max(best[node], suf[left] + pre[right]);
            }
        }

        public void update(int i) {
            update(1, 0, n - 1, i);
        }

        private void update(int node, int l, int r, int i) {
            if (l == r) {
                return;
            }
            int mid = (l + r) >>> 1;
            if (i <= mid) {
                update(node << 1, l, mid, i);
            } else {
                update(node << 1 | 1, mid + 1, r, i);
            }
            pushUp(node, l, r);
        }

        public void updateChar(char c, int i) {
            cs[i] = c;
        }
    }

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int k = queryIndices.length;
        SegmentTree tree = new SegmentTree(s);
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            int index = queryIndices[i];
            tree.updateChar(queryCharacters.charAt(i), index);
            tree.update(index);
            ans[i] = tree.best[1];
        }
        return ans;
    }
}