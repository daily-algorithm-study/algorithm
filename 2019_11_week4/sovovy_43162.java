class Solution {
    boolean[] visit = new boolean[200];

    public void dfs(int start, int[][] computers, int n) {
        visit[start] = true;
        for (int i = 0; i < n; i++) {
            if (!visit[i] && computers[start][i] > 0) {
                dfs(i, computers, n);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]){
                answer++;
                dfs(i, computers, n);
            }
        }
        return answer;
    }
}
