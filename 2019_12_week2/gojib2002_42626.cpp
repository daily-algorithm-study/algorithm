#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int i;
    int a, b;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(pq.size() >= 2 && pq.top() < K){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        
        pq.push(a + 2*b);
        
        answer++;
    }
    
    if(pq.top() < K) return -1;
    
    return answer;
}
