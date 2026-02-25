class Solution {
public:
    int noOfOnes(int n){
        int cnt = 0;
        while(n){
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
    
    void print(vector<int> &arr){
        for(int i = 0; i < arr.size(); i++){
            cout<< arr[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ones(arr.size(), 0);
        for(int i =0; i < arr.size();i++){
            ones[i] = noOfOnes(arr[i]);
        }

        print(ones);

        int temp = 0;
        for(int i =0; i < arr.size(); i++){
            for(int j = 0; j<arr.size()-i-1;j++){
                if(ones[j] > ones[j+1]){
                    temp = ones[j];
                    ones[j] = ones[j+1];
                    ones[j+1]= temp;

                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                else if(ones[j] == ones[j+1]){
                    // no of ones are same but sort them by value
                    if(arr[j]> arr[j+1]){
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
        }

        return arr;
    }
};