import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] result = new int[commands.length];
        
        for (int i = 0; i < commands.length; i++) {
            // array cutting
            int[] arr = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
            // sorting
            Arrays.sort(arr);
            // element add
            result[i] = arr[commands[i][2]-1];
        }
        
        return result;
    }
}
