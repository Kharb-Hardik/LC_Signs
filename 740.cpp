#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoint(int index, vector<int>& unique, unordered_map<int, int>& freq,
                 vector<int>& dp) {
        if (index >= unique.size())
            return 0;
        if (dp[index])
            return dp[index];
        int num = unique[index];

        int take = num * freq[num];
        if (index + 1 < unique.size() && unique[index + 1] == num + 1) {
            take += maxPoint(index + 2, unique, freq, dp);
        } else {
            take += maxPoint(index + 1, unique, freq, dp);
        }

        int skip = maxPoint(index + 1, unique, freq, dp);

        return dp[index] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& arr) {
        unordered_map<int, int> freq;
        set<int> uniqueSet;
        vector<int> dp(arr.size() + 1, 0);
        for (int num : arr) {
            freq[num]++;
            uniqueSet.insert(num);
        }

        vector<int> unique(uniqueSet.begin(), uniqueSet.end());

        return maxPoint(0, unique, freq, dp);
    }
};
