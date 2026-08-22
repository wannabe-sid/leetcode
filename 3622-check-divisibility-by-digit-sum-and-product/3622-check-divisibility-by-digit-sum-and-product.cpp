class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digSum = 0;
        int digProd = 1;
        while(temp > 0){
            int ld = temp % 10;
            temp = temp / 10;
            digSum += ld;
            digProd *= ld;
        }
        int sum = digSum + digProd;
        if(n % sum == 0) return true;
        return false;
    }
};