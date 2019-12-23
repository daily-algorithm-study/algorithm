#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[2000][2000];

int recur(int l, int r, vector<int> &left, vector<int> &right)
{
    int ret = 0;
    
    if(dp[l][r] != -1) return dp[l][r];
    
    if(l < left.size() - 1) ret = max(ret, recur(l+1,r,left,right));
    if(l < left.size() - 1 && r < right.size()) ret = max(ret, recur(l+1,r+1,left,right));
    if(r < right.size() && left[l] > right[r]) ret = max(ret, recur(l,r+1,left,right) + right[r]);
    
    return dp[l][r] = ret;
}

int solution(vector<int> left, vector<int> right) {
    memset(dp,-1,sizeof(dp));
    
    return recur(0,0,left,right);
}
