// class Solution {
// public:
//     int bagOfTokensScore(vector<int>& tokens, int power) {
//       int n= tokens.size();
//       int mxscore = 0;
//       sort(tokens.begin(),tokens.end());
//       int i=0,j=n-1;
//       int score = 0;
//       while(i<=j){
//         if(power>=tokens[i]){
//             power-=tokens[i];
//             score+=1;
//             i++;
//             mxscore = max(mxscore,score);
//         }else if(score>=1){
//             power+=tokens[j];
//             score-=1;
//             j--;
//         }else{
//             return mxscore;
//         }
//       }  
//       return mxscore;
//     }
// };
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int max_score = 0;
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score += 1;
                left += 1;
                max_score = max(max_score, score);
            } else if (score > 0) {
                power += tokens[right];
                score -= 1;
                right -= 1;
            } else {
                break;
            }
        }
        
        return max_score;
    }
};