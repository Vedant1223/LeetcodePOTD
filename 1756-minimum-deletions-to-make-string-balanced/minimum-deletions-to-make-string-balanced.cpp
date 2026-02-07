class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        st.push('a');
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(st.top() == 'b' && s[i]=='a'){
                st.pop();
                count++;
            }
            else{
                st.push(s[i]);
            }
        }

        return count;
    }
};