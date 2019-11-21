/*
0. dp[i] = i번째까지 집을 털었을 때 가장 많은 금액
1. dp[i] = max(dp[i-2]+money[i], dp[i-1])
2. 하지만 1번의 식만으로는 money[0]를 털었을 때 money[n-1]을 털 수 없는 것을 커버할 수 없다.
3. money[] = {0,0,100,0,0,100}의 경우 money[2]와 money[5]가 선택되어야 하는데 이 둘 사이의 인덱스 차이는 2이다. 그리고 money[2]를 선택할 때는 money[0]를 선택하지 않고 money[5]가 선택되어야 한다.
4. 이 문제에서 크리티컬한 것은 첫 번째 집을 터는지에 대한 문제이므로, 첫 집을 터는 dp, 안터는 dp로 나눠서 진행한다.
5. 첫 집을 터는 경우 dp[0] = dp[1] = money[0]; i = [2...n-1)
6. 첫 집을 안터는 경우 dp[0] = 0; dp[1] = money[1]; i=[2...n)
*/
#include <string>
#include <vector>
#define MAX(a,b) (a) > (b) ? (a) : (b)
using namespace std;

int solution(vector<int> money) {
    int size = money.size();
    vector<int> dp(size,0);    
    vector<int> dp2(size,0);
    dp[0] = dp[1] = money[0];
    for(int i=2; i<size-1; i++){
        dp[i] = MAX(dp[i-2] + money[i], dp[i-1]);
    }
    dp2[0] = 0; dp2[1] = money[1];
    for(int i=2; i<size; i++){
        dp2[i] = MAX(dp2[i-2]+money[i], dp2[i-1]);
    }
    return MAX(dp[size-2], dp2[size-1]);
}