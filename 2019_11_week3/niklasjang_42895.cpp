/*
이 문제가 왜 동적계획법인지 모르겠다. 작은 문제로 바꿔서 풀면서 중복되는 작은 문제의 답을 미리 구해놓은 것을 활용해야하는데
방법을 모르겠다.
최대 깊이가 8인 것을 사용해서 완전탐색을 하는 것으로 방향을 바꿨다.
가장 문제가 되는 부분이 연속적인 숫자를 쓸 수 있는 것이다. 모르겠어서 찾아보고 재구성해서 통과했다.
아래 코드에서 vector에 저장하는 숫자 temp를 활용하는 v[i]를 보면 기가막힌다.
*/
#include <cmath>
#include <vector>
using namespace std;
vector<int> v;
int num = 0;
int answer = 987654321;
void foo(int curr, int depth){
    if(depth >= 9) return ;
    if(curr == num){
        answer = answer > depth ? depth : answer;
        return;
    }
    for(int i = 0; i <v.size(); i++){
        foo(curr*v[i], depth+i+1);
        foo(curr/v[i], depth+i+1);
        foo(curr-v[i], depth+i+1);
        foo(curr+v[i], depth+i+1);
    }
}
int solution(int N, int number) {
    int temp = 0;
    num = number;
    for(int i=0; i<8; i++){
        temp += pow(10,i)*N;
        v.push_back(temp);
    }
    foo(0, 0);
    return answer <= 8 ? answer : -1;
}
