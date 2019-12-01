#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n) { //올바른 괄호의 갯수 - success
    int answer = 0;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        v.push_back(1); // ( 괄호 의미하는 숫자
        v.push_back(-1); // ) 괄호 의미하는 숫자
    }
    
    do{
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            if(sum < 0) { //닫는 괄호가 더 많아지는 경우에 올바른 괄호가 아니므로 카운팅 감소 + break;
                answer--;
                break;
            }
        }
        answer++;
        
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
