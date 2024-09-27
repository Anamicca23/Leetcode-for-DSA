import java.util.ArrayList;
import java.util.List;

class MyCalendarTwo {
    private List<int[]> cal;
    private List<int[]> overlap;

    public MyCalendarTwo() {
        cal = new ArrayList<>();
        overlap = new ArrayList<>();
    }

    private boolean overlapped(int start1, int end1, int start2, int end2) {
        return Math.max(start1, start2) < Math.min(end1, end2);
    }

    private int[] overlappedInterval(int start1, int end1, int start2, int end2) {
        return new int[]{Math.max(start1, start2), Math.min(end1, end2)};
    }

    public boolean book(int start, int end) {
        for (int[] book : overlap) {
            if (overlapped(book[0], book[1], start, end)) {
                return false;  
            }
        }
        for (int[] book : cal) {
            if (overlapped(book[0], book[1], start, end)) {
                overlap.add(overlappedInterval(book[0], book[1], start, end));
            }
        }

        cal.add(new int[]{start, end});
        return true; 
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start, end);
 */
