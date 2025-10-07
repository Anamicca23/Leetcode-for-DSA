class Solution {
    public int[] avoidFlood(int[] rains) {
        int n= rains.length;
        int[] ans= new int[n];
        Map<Integer, Integer> last_rain= new HashMap<>();
        int def= 5;
        TreeSet<Integer> dry_days= new TreeSet<>();
        for(int i=0; i<n; i++){
            int lake= rains[i];
            if(lake==0){
                dry_days.add(i);
                ans[i]= def;
            }else{
                ans[i]= -1;
                if(last_rain.containsKey(lake)){
                    Integer day= dry_days.higher(last_rain.get(lake));
                    //next dry day of last_rain.get(lake)
                    //[2 , 3, 4, 5, 9, 10]
                    //6
                    if(day==null) return new int[0];
                    ans[day]= lake;
                    dry_days.remove(day);
                }
                last_rain.put(lake, i);
            }
        }
        return ans;
    }
}