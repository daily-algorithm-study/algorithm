// 다른 풀이보고 했는데 이분탐색으로 푼 것 같아요
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int l = 1, r = 100000000;
    
    while(l <= r) {
        int mid = l + r >> 1, cnt = 0; // 시프트 연산자 -> (l+r)/2 랑 똑같음. 2로 나누면 시간초과
        vector<int> v;
        
        for(int i = 0;i < cores.size(); ++i) {
            cnt += mid / cores[i] + 1;
            if(mid % cores[i] == 0) {
                v.push_back(i);
                cnt -= 1;
            }
        }
        if(cnt >= n)
            r = mid - 1;
        else if(cnt + v.size() < n)
            l = mid + 1;
        else
            return v[n - cnt - 1] + 1;
    }
}
