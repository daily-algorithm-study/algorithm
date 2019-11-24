#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) { //도둑질 - success
    vector<int> dp1(money.size() - 1);
    vector<int> dp2(money.size());
        
    dp1[0] = money[0];
    dp1[1] = money[0]; 
                                 
    dp2[0] = 0;
    dp2[1] = money[1];

    //첫 번째 집을 훔치는 경우                      
    for(int i = 2;i < money.size() - 1; i++) dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    //첫 번째 집을 훔치지 않는 경우
    for(int i = 2; i < money.size(); i++) dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    
    return max(dp1[money.size() - 2], dp2[money.size() -1]);
}
