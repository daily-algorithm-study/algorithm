#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int ss =s.size();
    if(ss % 2 == 0){
        answer = s.substr(ss/2 - 1,2);
    }else{
        answer = s[ss/2];
    }
    return answer;
}