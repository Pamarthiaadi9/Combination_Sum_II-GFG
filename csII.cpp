class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(), arr.end());
        solve(arr, curr, 0, 0, k, ans);
        return ans;
    }
    
    void solve(vector<int> &A, vector<int> &curr, int sum, int id, int T, vector<vector<int>> &ans) {
        if (sum == T) {
            ans.push_back(curr);
            return;
        }
        if (sum > T || id == A.size()) return;
        for (int i = id; i < A.size(); i++) {
            if (i > id && A[i] == A[i - 1]) continue;
            curr.push_back(A[i]);
            solve(A, curr, sum + A[i], i + 1, T, ans);
            curr.pop_back();
        }
    }
};
