#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a<b) answer = (b - a + 1)*(long long)(b+a)/2;
    else if(a>b) answer = (a - b + 1)*(long long)(a+b)/2;
    else answer = a;
    
    return answer;
}
