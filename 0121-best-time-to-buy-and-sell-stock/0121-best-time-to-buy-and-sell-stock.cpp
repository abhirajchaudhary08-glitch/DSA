class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprof = 0;
        for(int price :prices){
            if(price<minprice){
                minprice = price;
            }
            else{
                maxprof = max(maxprof,price-minprice);
            }
        }
        return maxprof;
    }
};