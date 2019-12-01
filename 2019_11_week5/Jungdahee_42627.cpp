#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair <int, int> &a, const pair <int, int> &b){ //디스크 컨트롤러 - success
  if(a.second == b.second) return a.first < b.first;
  else return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; 
    int time = 0;
    vector<pair<int, int>> job;
    
    for (int i = 0; i < jobs.size(); i++) job.push_back(make_pair(jobs[i][0], jobs[i][1]));
    
    sort(job.begin(), job.end(), cmp);
    
    while (!job.empty()) {
        for (int i = 0; i < job.size(); i++) {
            if (job[i].first <= start) {
                start += job[i].second;
                time += start - job[i].first;
                job.erase(job.begin() + i);
                break;
            } 
            if (i == job.size() - 1) start++;
        }
    }
    answer = time / jobs.size();
    return answer;
}
