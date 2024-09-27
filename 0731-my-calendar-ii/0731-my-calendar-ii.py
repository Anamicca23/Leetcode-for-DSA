class MyCalendarTwo:
    def __init__(self):
        self.cal = []  
        self.overlap = []  

    def overlapped(self, start1, end1, start2, end2):
        return max(start1, start2) < min(end1, end2)

    def overlapped_interval(self, start1, end1, start2, end2):
        return (max(start1, start2), min(end1, end2))

    def book(self, start, end):
        for book in self.overlap:
            if self.overlapped(book[0], book[1], start, end):
                return False  


        for book in self.cal:
            if self.overlapped(book[0], book[1], start, end):
                self.overlap.append(self.overlapped_interval(book[0], book[1], start, end))


        self.cal.append((start, end))
        return True 

# Example usage:
# obj = MyCalendarTwo()
# param_1 = obj.book(start, end)
