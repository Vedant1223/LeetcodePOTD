class Solution {
public:
    
    int maxFreqSum(string s) {
        vector<int> f(26, 0);
        for( char c : s){
            f[c-'a']++;
        }
        for(auto i : f){
            cout<< i << " ";
        }cout<<endl;
        int v = 0;
        int c = 0;
        for(int i = 0; i < 26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                v = max(v, f[i]);
            }
            else{
                c = max(c, f[i]);
            }
        }
        cout<< v<<" "<< c;
        return c+v;    
    }
};