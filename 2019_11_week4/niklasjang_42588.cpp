#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    int size = heights.size();
    for(int pi = size-1; pi>=0; pi--){
        int curr = heights[pi];
        bool check = false;
        for(int comp = pi-1; comp>=0; comp--){
            if(heights[comp] > curr){
                s.push(comp+1);
                check = true;
                break;
            }
        }
        if(!check) s.push(0);
    }
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}