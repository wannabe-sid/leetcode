class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        if (n >= 1000LL) commas += (n - 1000LL + 1);
        if (n >= 1000000LL) commas += (n - 1000000LL + 1);
        if (n >= 1000000000LL) commas += (n - 1000000000LL + 1);
        if (n >= 1000000000000LL) commas += (n - 1000000000000LL + 1);
        if (n >= 1000000000000000LL) commas += (n - 1000000000000000LL + 1);
        return commas;
    }
};