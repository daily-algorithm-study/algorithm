// 조합을 사용해 갯수 찾기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;
    vector<int> v;
    
    for(int i=0; i<n; i++) {
        v.push_back(1);  // 왼쪽 괄호
        v.push_back(-1); // 오른쪽 괄호
    }
    
    do{
        sum = 0;
        answer++;
        for(int i=0; i<n*2; i++) {
            sum += v[i];
            if(sum < 0) { // 한번이라도 왼쪽 < 오른쪽 이면 틀린 괄호
                answer--;
                break;
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
