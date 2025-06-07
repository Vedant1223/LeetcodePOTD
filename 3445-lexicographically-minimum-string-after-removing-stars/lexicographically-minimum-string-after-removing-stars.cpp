#define pci pair<char, int>


struct Compare {
    bool operator()(pci a, pci b) {
        if (a.first != b.first)
            return a.first > b.first; 
        return a.second < b.second;   
    }
};

class Solution {
public:
    string clearStars(string s) {
        
        priority_queue<pci, vector<pci>, Compare> pq;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
               
                if (!pq.empty()) {
                    pci ch = pq.top();
                    pq.pop();
                    s[ch.second] = '*'; 
                }
            } else {
                pq.push({s[i], i});
            }
        }

        string res = "";
        for (char c : s) {
            if (c != '*') {
                res += c;
            }
        }
        return res;
    }
};