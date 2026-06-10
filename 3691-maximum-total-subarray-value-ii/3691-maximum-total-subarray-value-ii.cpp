struct SparseTable {
	int n, K;
	vector<vector<int>> mn, mx;
	vector<int> lg;

	SparseTable(const vector<int>& arr) {
		n = arr.size();
		K = log2(n) + 1;

		mn.assign(K, vector<int>(n));
		mx.assign(K, vector<int>(n));
		lg.assign(n + 1, 0);

		for (int i = 2; i <= n; i++)
			lg[i] = lg[i / 2] + 1;

		for (int i = 0; i < n; i++) {
			mn[0][i] = arr[i];
			mx[0][i] = arr[i];
		}

		for (int k = 1; k < K; k++) {
			for (int i = 0; i + (1 << k) <= n; i++) {
				mn[k][i] = min(mn[k - 1][i],
					mn[k - 1][i + (1 << (k - 1))]);

				mx[k][i] = max(mx[k - 1][i],
					mx[k - 1][i + (1 << (k - 1))]);
			}
		}
	}

	int getMin(int L, int R) {
		int k = lg[R - L + 1];
		return min(mn[k][L], mn[k][R - (1 << k) + 1]);
	}

	int getMax(int L, int R) {
		int k = lg[R - L + 1];
		return max(mx[k][L], mx[k][R - (1 << k) + 1]);
	}
};

class Solution {
	typedef long long ll;
	struct Item {
		int beg;
		int end;
		int diff;
	};
public:
	long long maxTotalValue(vector<int>& nums, int k) {
		if (nums.size() < 3) {
			if (nums.size() < 2) {
				return 0;
			}
			return std::max(nums[0], nums[1]) - std::min(nums[0], nums[1]);
		}

		vector<pair<int, int>> minMax(nums.size(), { nums.back(), nums.back() });
		for (int i = (int)nums.size() - 2; i >= 0; i--) {
			if (nums[i] < minMax[i + 1].first) {
				minMax[i].first = nums[i];
			}
			else {
				minMax[i].first = minMax[i + 1].first;
			}
			if (nums[i] > minMax[i + 1].second) {
				minMax[i].second = nums[i];
			}
			else {
				minMax[i].second = minMax[i + 1].second;
			}
		}

		ll diff = minMax.front().second - minMax.front().first;
		if (diff == 0) {
			return 0;
		}
		ll totCount = 0;
		int mnid = -1;
		int mxid = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == minMax.front().first) {
				mnid = i;
			}
			if (nums[i] == minMax.front().second) {
				mxid = i;
			}
			if (mnid != -1 && mxid != -1) {
				totCount += min(mnid, mxid) + 1;
			}
		}
		if (totCount >= k) {
			return diff * (ll)k;
		}
		SparseTable st(nums);
		
		int beg = 0;
		int end = nums.size() - 1;
		vector<Item> heap;
		auto hs = [](const Item& it1, const Item& it2)
			{ return it1.diff < it2.diff; };
		while (beg <= end) {
			int mx = st.getMax(beg, end);
			int mn = st.getMin(beg, end);
			heap.push_back({beg, end, mx - mn});
			std::push_heap(heap.begin(), heap.end(), hs);
			beg++;
		}
		totCount = 0;
		while (k > 0) {
			auto item = heap.front();
			std::pop_heap(heap.begin(), heap.end(), hs);
			heap.pop_back();
			totCount += item.diff;
			k--;
			if ((item.beg < item.end) && (k > 0)) {
				int mx = st.getMax(item.beg, item.end - 1);
				int mn = st.getMin(item.beg, item.end - 1);
				heap.push_back({ item.beg, item.end - 1, mx - mn });
				std::push_heap(heap.begin(), heap.end(), hs);
			}
		}

		return totCount;
	}
};