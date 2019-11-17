#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) { // 3 * n 타일링 - success
    vector<long long> number(n + 1, 0);
    number[0] = 1; 
    number[2] = 3;
    
    for(int i = 4; i <= n; i += 2){
        //이전 값에 *3 수행 시 이전 타일을 그대로 사용했을 시 경우의 수 계산 가능
        number[i] += (number[i - 2] * 3) % 1000000007;
        for(int j = 0; j <= i - 4; j += 2) number[i] += (number[j] * 2) % 1000000007;
    }
    
    return number[n] % 1000000007;
} 
