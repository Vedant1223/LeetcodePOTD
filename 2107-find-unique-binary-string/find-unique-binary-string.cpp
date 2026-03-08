class Solution {
public:
    int toNum(string s){
        int n = 0;
        for(int i = 0;i < s.size(); i++){
            if(s[i]=='1'){
                n += pow(2, i);
            }
        }
        return n;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> numbers;
        for(auto s : nums){
            numbers.insert(stoi(s, 0, 2));
        }

        string result = "";
    int n = nums.size();
        for(int i = 0; i <= nums.size(); i++){
            
            if(numbers.find(i) == numbers.end()){
                result = bitset<16>(i).to_string();
                return result.substr(16-n, n);
            }
        }
        return "";
    }
};