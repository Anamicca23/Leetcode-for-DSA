class Solution {
public:
    int fib(int n) {
        int a=0, b=1, cnt=2,c;
        if(n==0 || n==1) return n;
        while(cnt<=n)
        {
            c=a+b;
            a=b;
            b=c;
            cnt++;
        }
        return c;
    }
    /*
The time complexity of the provided code is O(n), 
where n is the input number for which 
we are calculating the Fibonacci number.

Explanation:

The code uses an iterative approach to 
calculate the Fibonacci number.
It initializes three variables: a with 0 (Fibonacci number for n=0),
b with 1 (Fibonacci number for n=1), and
cnt with 2 to track the current count.
It then enters a while loop that continues until 
cnt reaches the value of n.
In each iteration of the loop, it calculates 
the next Fibonacci number by adding a and b and 
stores it in variable c. It then updates a with 
the value of b and b with the value of c. Finally, 
it increments cnt by 1.
Once the loop terminates, it returns the value of c,
which represents the Fibonacci number for the given input n.
Since the loop iterates n-2 times (starting from cnt=2), 
the time complexity is O(n).
The space complexity of the provided code is O(1) because
it uses a constant amount of additional space regardless
of the input size. The variables a, b, cnt, and c are all 
individual integer variables that require constant space, 
and the space used by these variables does not change with the input size.
    */
};