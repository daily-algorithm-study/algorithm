#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) { //탑 - success
    vector<int> answer(heights.size());
    
    for(int i = heights.size() - 1; i > 0; i--){
        for(int j = i - 1; j >= 0; j--){
            if(heights[i] < heights[j]){ //높은 탑을 찾은 경우
                answer[i] = j + 1;
                break;
            }
        }
    }
    return answer;
}
