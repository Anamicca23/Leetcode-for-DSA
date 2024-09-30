import java.util.ArrayList;

class CustomStack {
    private ArrayList<Integer> incremental;
    private ArrayList<Integer> container;
    private int cap;

    // Constructor to initialize the stack with maxSize
    public CustomStack(int maxSize) {
        this.cap = maxSize;
        this.container = new ArrayList<>();
        this.incremental = new ArrayList<>();
    }

    // Push operation
    public void push(int x) {
        if (container.size() == cap) return;
        container.add(x);  // Add element to container
        incremental.add(0);  // Add corresponding zero to incremental
    }

    // Pop operation
    public int pop() {
        if (container.isEmpty()) return -1;
        int index = container.size() - 1;
        int result = container.get(index) + incremental.get(index); // Top element + incremental effect
        container.remove(index);
        if (incremental.size() > 1) {
            incremental.set(incremental.size() - 2, incremental.get(incremental.size() - 2) + incremental.get(index));
        }
        incremental.remove(index);
        return result;
    }

    // Increment operation
    public void increment(int k, int val) {
        if (container.isEmpty()) return;
        k = Math.min(k - 1, container.size() - 1);  // Adjust the index based on k and container size
        incremental.set(k, incremental.get(k) + val);
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k, val);
 */
