class Solution {
public:
    // int f(int x){
    //     string s = to_string(x);
    //     int wav = 0;
    //     for(size_t i=1;i<s.size()-1;i++){
    //         bool isPeek = s[i]<s[i+1] and s[i+1]>s[i+2];
    //         bool isValley = s[i]>s[i+1] and s[i+2]>s[i+1];
    //         if(isPeek || isValley){
    //             wav++;
    //         }
    //     }
    //     return wav;
    // }
    // int totalWaviness(int n1, int n2){
    // int total = 0;
    // for(int i=n1;i<=n2;i++){
    //     total+=f(i);
    // }
    // return total;

    //}
    int totalWaviness(int num1, int num2) {
        auto getWaviness = [](int x) -> int {
            string s = to_string(x);
            int waviness = 0;

            for (size_t i = 1; i < s.size() - 1; ++i) {
                bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
                bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
                if (isPeak || isValley) {
                    ++waviness;
                }
            }

            return waviness;
        };

        int total = 0;
        for (int i = num1; i <= num2; ++i) {
            total += getWaviness(i);
        }

        return total;
    }
};