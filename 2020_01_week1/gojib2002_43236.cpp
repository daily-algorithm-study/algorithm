#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check(int mid, vector<int> &rocks, int n){
    stack<int> s;
    int i;
    
    s.push(0);
    for(i=0;i<rocks.size();i++){
        if(!s.empty() && rocks[i] - s.top() < mid) continue;
        
        s.push(rocks[i]);
    }
    
    return s.size() >= rocks.size() - n + 1;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int s, e, mid;
    
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    s = 0;
    e = 1000000000;
    while(s<=e){
        mid = (s+e)/2;
        
        if(check(mid, rocks, n)){
            answer = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    
    return answer;
}
