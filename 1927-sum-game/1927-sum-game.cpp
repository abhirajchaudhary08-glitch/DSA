// class Solution {
//  public:
//   bool sumGame(string num) {
//     const int n = num.length();
//     double ans = 0.0;

//     for (int i = 0; i < n / 2; ++i)
//       ans += getExpectation(num[i]);

//     for (int i = n / 2; i < n; ++i)
//       ans -= getExpectation(num[i]);

//     return ans != 0.0;
//   }

//  private:
//   double getExpectation(char c) {
//     return c == '?' ? 4.5 : c - '0';
//   }
// };
class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int cnt = 0;
        for ( char ch : num ){
            if( ch == '?' )  cnt++;
        }
        
        if( cnt % 2 == 1 ){
            return true;
        }

        int fHalf = 0;
        int sHalf = 0;

        int fQ = 0;
        int sQ = 0;

        int mid = n / 2;

        for ( int i = 0; i < n; i++ ){
            if(num[i] == '?'){
                if(i < mid)
                    fQ++;
                else
                    sQ++;
            }
            else{
                if(i < mid)
                    fHalf += num[i] - '0';
                else
                    sHalf += num[i] - '0';
            }
        }

        if( fQ == sQ ){
            return sHalf != fHalf; 
        }

        int diff = (fQ - sQ);
        int halfDiff = (fHalf - sHalf);

        if(diff % 2 != 0)   return true;

        return halfDiff != -9 * (diff / 2);


    }
};