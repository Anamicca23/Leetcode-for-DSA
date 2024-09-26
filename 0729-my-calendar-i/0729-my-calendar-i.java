class MyCalendar {
    private static class Node implements Comparable<Node> {
        int start, end;

        Node(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Node other) {
            if (this.end <= other.start) {
                return -1;
            } else if (this.start >= other.end) {
                return 1;
            } else {
                return 0;  
            }
        }
    }

    private TreeSet<Node> bookings;

    public MyCalendar() {
        bookings = new TreeSet<>();
    }

    public boolean book(int start, int end) {
        Node newNode = new Node(start, end);
        Node floor = bookings.floor(newNode);
        Node ceiling = bookings.ceiling(newNode);

        if ((floor != null && floor.compareTo(newNode) == 0) || 
            (ceiling != null && ceiling.compareTo(newNode) == 0)) {
            return false;  
        }

        bookings.add(newNode);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */