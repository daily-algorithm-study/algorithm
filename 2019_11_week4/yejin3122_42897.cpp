// DP
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp(money.size(), 0);
    vector<int> dp2(money.size(), 0);
    
    // 첫번째 집부터 훔친 경우 -> 맨 마지막 집은 못훔침
    dp[0] = money[0];
    dp[1] = money[0];
    for(int i=2; i<money.size() - 1; i++) {
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }

    // 두번째 집부터 훔친 경우 -> 맨 마지막 집 훔칠 수 있음
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2; i<money.size(); i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    return max(dp[money.size()-2]), dp2.back());
}
