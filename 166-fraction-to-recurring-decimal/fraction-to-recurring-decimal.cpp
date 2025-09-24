class Solution {
public:
    void putBrackets(int ind, string &s) {
        // ind = position where the remainder first repeated
        // put ( at that position and ) at the end
        s.insert(ind, "(");
        s.push_back(')');
    }

    string DenominatorBuilder(long long r, long long d) {
        unordered_map<long long, int> mp; 
        string s ="";
        // first int for the rem  which  will be the key
        // second int for the index or distance after decimal symbol

        while(true){
            if(r == 0){
                return s; // no loop, end of fraction
            }

            if(mp.find(r) != mp.end()){
                // element found loop mil gya
                int ind = mp[r];
                putBrackets(ind, s);
                return s;
            }

            // store remainder with current length of s
            mp[r] = s.size();

            r *= 10; // now safe in long long
            int q = r / d;
            s += to_string(q);
            r = r % d;
        }
        return s;
    }

    string fractionToDecimal(int numerator, int denominator) {                 
        if(numerator == 0) return "0";

        string ans = "";
        // handle negative numbers
        if((numerator < 0) ^ (denominator < 0)) ans += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // quotient part before decimal
        long long quotient = (n / d);
        ans += to_string(quotient);

        long long remainder = n % d;
        if(remainder != 0){
            ans +=".";
            string str = DenominatorBuilder(remainder, d);
            ans = ans + str;
        }
        return ans;
    }
};
