class MyCalendar:

    def __init__(self):
        self.bookings = [ (-1,-1), (float('inf'), float('inf')) ]

    def book(self, start: int, end: int) -> bool:
        index = bisect_left(self.bookings, (start, end))
        if start < self.bookings[index - 1][1]:
            return False
        if end > self.bookings[index][0]:
            return False
        self.bookings.insert(index, (start, end))
        return True