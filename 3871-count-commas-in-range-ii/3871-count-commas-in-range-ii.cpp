class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        if (n >= 1000) commas += (n - 1000 + 1);
        if (n >= 1000000) commas += (n - 1000000 + 1);
        if (n >= 1000000000) commas += (n - 1000000000 + 1);
        if (n >= 1000000000000) commas += (n - 1000000000000 + 1);
        if (n >= 1000000000000000) commas += (n - 1000000000000000 + 1);
        return commas;
    }
};