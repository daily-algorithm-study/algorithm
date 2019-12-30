#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int idx = 0;
    int i;
    vector<int> answer;
    int cnt;
    
    while(idx < progresses.size()){
        cnt = 0;
        while(idx < progresses.size() && progresses[idx] >= 100){
            cnt++;
            idx++;
        }
        
        if(cnt) answer.push_back(cnt);
        
        for(i=idx;i<progresses.size();i++) progresses[i] += speeds[i];
    }
    return answer;
}
