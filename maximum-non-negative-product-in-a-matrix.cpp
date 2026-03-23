//Time : O(m * n)
//Space: O(m * n)


class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long long MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> mx(m, vector<long long>(n, 0));
        vector<vector<long long>> mn(m, vector<long long>(n, 0));

        mx[0][0] = mn[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                long long cur = grid[i][j];
                vector<long long> candidates;

                if (i > 0) {
                    candidates.push_back(mx[i - 1][j] * cur);
                    candidates.push_back(mn[i - 1][j] * cur);
                }

                if (j > 0) {
                    candidates.push_back(mx[i][j - 1] * cur);
                    candidates.push_back(mn[i][j - 1] * cur);
                }

                mx[i][j] = *max_element(candidates.begin(), candidates.end());
                mn[i][j] = *min_element(candidates.begin(), candidates.end());
            }
        }

        long long ans = mx[m - 1][n - 1];
        if (ans < 0) return -1;
        return ans % MOD;
    }
};
