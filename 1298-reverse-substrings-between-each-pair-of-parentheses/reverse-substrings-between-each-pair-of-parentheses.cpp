class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        // help in reversal

        int n = s.size();
        for( int i = 0; i < n; i++){
            if(s[i]== '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int start = st.top() + 1;
                int end = i;
                //      it solves the most innermost bracket
                reverse(s.begin() + start, s.begin()+end);
                st.pop();
                //    ' ( '  ko pop kar rha h 
            }
        }
        // original string is manipulated and solved now a copy will be created without brackets.

        string ans ="";
        for( int i = 0; i< n; i++){
            if(s[i] == '(' || s[i]==')'){
                continue;
                // ignore bracket
            }
            else{
                ans.push_back(s[i]);
                // pushing the solved string
            }
            
        }
        return ans;
    }
};