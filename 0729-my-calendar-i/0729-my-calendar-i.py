class Node:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __lt__(self, other):
        return self.end <= other.start

class MyCalendar:

    def __init__(self):
        self.bookings = set()

    def book(self, start: int, end: int) -> bool:
        node = Node(start, end)
        for booked in self.bookings:
            if not (booked.end <= start or end <= booked.start):
                return False
        self.bookings.add(node)
        return True

# Example usage:
# obj = MyCalendar()
# param_1 = obj.book(start, end)
