#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) { //가운데 글자 가져오기 - success
    string answer = "";
    int size = s.length();   
    
    if(size % 2 != 0){ //홀수인 경우 가운데 글자만 추출
        answer = s[size / 2];
    }
    else { //짝수인 경우 가운데 두 글자 추출
        answer = s[size / 2 - 1];
        answer += s[size / 2];
    }
    
    return answer;
}
