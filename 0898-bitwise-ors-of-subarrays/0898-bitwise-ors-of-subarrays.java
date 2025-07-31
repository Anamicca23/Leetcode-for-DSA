import java.util.*;
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> result=new HashSet<>();
        for(int i=0;i<arr.length;i++){
            result.add(arr[i]);
            for(int j=i-1;j>=0;j--){
                if(arr[j]==(arr[j] | arr[i])) break;
                arr[j]|=arr[i];
                result.add(arr[j]);
            }
        }
        return result.size();
    }
}