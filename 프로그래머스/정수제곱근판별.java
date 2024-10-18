class Solution {
    public long solution(long n) {
        long answer = -1;
        for(long i=0; i*i<=n;i++){
            if(i*i == n) answer = i;
        }
        if(answer == -1) return -1;
        return (answer+1)*(answer+1);
    }
}