#include <vector>
using namespace std;

class Solution {
public:
    bool check(int k, vector<int> nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            prefix[left] -= val;
            if (right + 1 < n) {
                prefix[right + 1] += val;
            }
        }

        int dec = 0;
        for (int i = 0; i < n; i++) {
            dec += prefix[i];
            if (nums[i] + dec > 0) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int start = 0, end = queries.size(), ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(mid, nums, queries)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
