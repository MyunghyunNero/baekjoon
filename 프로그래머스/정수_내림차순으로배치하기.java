import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        List<Integer> list = new ArrayList<Integer>();
        while(n>0) {
            Integer num = (int)(n%10);
            list.add(num);
            n/=10;
        }
        list.sort(Collections.reverseOrder());
        String str = "";
        for(int i : list) {
            str+=i;
        }
        return Long.parseLong(str);
    }
}