#include <string>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size();
    stack<char> s1;
    stack<char> s2;
    for(int i=0; i<len; i++){
        //k는 몇 개의 숫자를 지울 수 있는지를 나타냄
        while(!s1.empty() && s1.top() < number[i] && k){
            s1.pop();
            k--;
        }
        s1.push(number[i]);
    }
    while(k--) s1.pop();
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        answer += s2.top();
        s2.pop();
    }
    return answer;
}