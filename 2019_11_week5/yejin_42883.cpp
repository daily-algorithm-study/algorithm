/*
 * 각 자리 숫자를 뽑을때마다 그때그때의 최대값 선택
 * 숫자 비교할때 최대 숫자는 적어도 +k번째 숫자 전에 나와야함
 */
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    char max;
    int idx = 0;
    
    for(int i=0; i<number.size()-k; i++) {
        max = '0';
        for(int j=idx; j<=k+i; j++) {
            if(max < number[j]) {
                max = number[j];
                idx = j+1;
            }
        }
        answer += max;
    }
    
    return answer;
}
