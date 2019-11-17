#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;

void calc(int N, int number, int count, int num){ //N으로 표현하기 - success
    //8개 이상이 넘어가는 경우 -1 반환(종료 조건)
    if(count > 8) return;
    
    //같은 경우 개수가 적은 걸로 갱신
    if(num == number){
        if (count < answer || answer == -1) answer = count;
		return;
    }
    
    int nn = 0;
    for(int i = 0; i < 8; i++){
        nn = nn * 10 + N;
        //모든 사칙 연산 다 계산
        calc(N, number, count + 1 + i, num * nn);
        calc(N, number, count + 1 + i, num / nn);
        calc(N, number, count + 1 + i, num + nn);
        calc(N, number, count + 1 + i, num - nn);
    }
}

int solution(int N, int number) {
    calc(N, number, 0, 0);
    return answer;
}
