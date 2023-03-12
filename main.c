#include <stdio.h>

int main() {
    unsigned long N;
    unsigned long M;
    int res = 1;
    scanf ("%lu %lu", &N, &M);
    //N won't affect the result. Let's assume that N is much larger than M.
    //(M+k)th square's colour must be same as kth square's colour to satisfy the condition.

    //We have to paint even number of squares so answer is 2^(M-1). Answer should be C(M, 0) + C(M, 2) + .... + C(M, k) + .....
    //This is equal to 2^(M-1) because k is odd and k < M -> M!/((M-k)!*k!) + M!/((M-k-1)!*(k+1)!) = (M+1)!/((k+1)!*(M-k)!)
    M--;
    //Since 2^52-1 is multiple of 53 and 2^18-1 is multiple of 19, 2^468-1 is multiple of 1007 because 2^468-1 can divisible by 2^52-1 and 2^ 18-1.
    //So remainder of 2^M (mod 1007) can only have 468 different answers.(2^0 (mod 1007) is equal to 2^468 (mod 1007))
    M = M % 468;
    for(; M > 0; M--){
        // Since answer would be 2^M (mod 1007), res must be multiplied by 2 for M times.(Congruence product theorem)
        res *= 2;
        // If it exceeds 1007 just subtract 1007 from itself
        if(res > 1007){
            res -= 1007;
        }
    }
    printf("%d", res);
}