class Solution {
public:
    void solve(int curr, int &n, vector<int> &res) {  // Pass res by reference
        if(curr > n) {
            return;
        }

        res.push_back(curr);

        // Append loop with recursive call
        int newNo;
        for(int i = 0; i <= 9; i++) {
            newNo = (curr * 10) + i;
            if(newNo > n) {
                return;
            }
            solve(newNo, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i <= 9; i++) {  // Start from 1 instead of 0
            solve(i, n, res);
        }
        return res;
    }
};