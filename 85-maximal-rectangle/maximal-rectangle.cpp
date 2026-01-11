class Solution {
public:

    vector<int> nextSmaller(vector<int> nums){
        stack<int> s;
        s.push(-1);
        int n = nums.size();
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){

            while(s.top() != -1 && nums[s.top()] >= nums[i]){
                s.pop();
            }
                
            ans[i]= s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int> nums){
        stack<int> s;
        s.push(-1);
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){

            while(s.top() != -1 && nums[s.top()] >= nums[i]){
                s.pop();
            }
                
            ans[i]= s.top();
            s.push(i);
        }
        return ans;        
    }

    int maxiHisto(vector<int> arr){
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevsmaller(arr);

        int maxi = INT_MIN;
        for( int i = 0; i< arr.size(); i++){
            int length = arr[i];
            if(next[i] == -1){
                next[i] = arr.size();
            }

            int breadth = next[i] - prev[i] - 1;

            maxi = max(maxi, length * breadth);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int maxi = INT_MIN;

        vector<int> v(matrix[0].size(), 0);

        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j]++;
                }


            }

            maxi = max(maxiHisto(v) , maxi);
        }    
        return maxi;
    }
};