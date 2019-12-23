#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(long long t, vector<int> &times, int n)
{
    long long cnt = 0;
    int i;
    
    for(i=0;i<times.size();i++)
    {
        cnt += t / times[i];
    }
    
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s, e, mid;
    
    s = 0;
    e = 1000000000LL * 1000000000LL;
    while(s <= e)
    {
        mid = (s + e) / 2;
        
        if(check(mid, times, n))
        {
            answer = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    
    return answer;
}
