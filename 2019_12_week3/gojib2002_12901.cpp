#include <string>
#include <vector>

using namespace std;

string ans[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
int day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int sum[13];

string solution(int a, int b) {
    int i;
    for(i=0;i<12;i++) sum[i] = sum[i-1] + day[i];
    return ans[(sum[a-1]+b)%7];
}
