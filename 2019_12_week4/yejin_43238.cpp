#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0, right = 100000000000000;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;  // mid라는 시간동안 통과할 수 있는 사람수
        
        for(int i=0; i<times.size(); i++) {
            sum += mid / times[i];
        }
        
        if(sum >= n) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
