#include <string>
#include <vector>

using namespace std;

#define MOD 1234567

int dp[100001];

int solution(int n) {
    int i;
    
    dp[1] = 1;
    for(i=2;i<=n;i++) dp[i] = (dp[i-1] + dp[i-2])%MOD;
    
    return dp[n];
}
