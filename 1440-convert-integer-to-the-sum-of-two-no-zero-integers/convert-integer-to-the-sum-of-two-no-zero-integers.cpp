class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int take;
        int unit = 1;

        // we are splitting the n in 2 numbers and we will solve 
        //ones then tens then hunderds then   thousands

        while( n > 1){
            take = 1;
            if(n%10 == 1){
                take = 2;
            }
            a = a - take*unit;
            b = b + take*unit;

            n = (n-take)/10;

            unit = unit * 10;
        }

        return {a,b};
    }
};