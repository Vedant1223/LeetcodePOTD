class Solution {
public:
    int Count(long curr, long next, int n) {
        int countNum = 0; 
        while (curr <= n) {

            // har ek node se 10 new node nikal rahi h 
            // so new nodes ka formula 
            
            // also hat 10 nodees m 10 aur nodes hongi 
            countNum += min(next, long(n + 1)) - curr;
            curr *= 10;
            next *= 10;
        }

        // ye find kar ke de tha curr and next ke biich uss range m kitne nodes h and then 
        // hum usse hata rahe h 
        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; // since we start from 1, we need k - 1 more steps

        while (k > 0) {
            int count = Count(curr, curr + 1, n);
            if (count <= k) {
                curr++; // move to the next lexicographical number
                k -= count;
            } else {
                curr *= 10; // dive deeper into the current prefix subtree
                k -= 1; // account for moving to the next number
            }
        }

        return curr;
    }
};