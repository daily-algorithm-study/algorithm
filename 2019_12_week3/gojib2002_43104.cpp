#include <string>
#include <vector>

using namespace std;

long long dp[100];

long long solution(int N) {
    if(N==1) return 4;
    else if(N==2) return 6;
    
    int i;
    dp[0] = 1;
    dp[1] = 1;
    for(i=2;i<=N;i++) dp[i] = dp[i-1] + dp[i-2];
    return 2*(dp[N] + dp[N-1]);
}
