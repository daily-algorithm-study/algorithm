#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0;  // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();
    
    sort(jobs.begin(), jobs.end(), compare); // 소요시간을 우선으로 배열
    
    while(!jobs.empty()) {
        for(int i=0; i<jobs.size(); i++) {
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            if(i == jobs.size()-1) start++;
        }
    }
    
    return time / size;  // 걸린 시간의 평균
}
