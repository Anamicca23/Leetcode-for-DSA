class MyCalendarTwo:

    def __init__(self):
        self.single_booked = []
        self.double_booked = []
        
    def intersection(self, intervals, s, e):

        l = bisect.bisect_left(intervals, s)
        r = bisect.bisect_right(intervals, e)
        
        intersection = []
        
        if l % 2:
            # we may create empty interval where s == intervals[l]
            if intervals[l] != s:
                intersection.append(s)
            else:
                l = l + 1

        intersection += intervals[l:r]

        if r % 2:
            # we may create empty interval where e == intervals[r-1]
            if intervals[r-1] != e:
                intersection.append(e)
            else:
                intersection.pop()

        return intersection
        
    def add(self, intervals, s, e):

        l = bisect.bisect_left(intervals, s)
        r = bisect.bisect_right(intervals, e)
        
        new = []
        if not l % 2:
            new.append(s)
            
        if not r % 2:
            new.append(e)

        intervals[l:r] = new

    def book(self, start: int, end: int) -> bool:

        if self.intersection(self.double_booked, start, end):
            return False
        
        intersection = self.intersection(self.single_booked, start, end)

        if intersection:
            for i in range(len(intersection) // 2):
                i1 = intersection[2*i]
                i2 = intersection[2*i+1]
                self.add(self.double_booked, i1, i2)

        self.add(self.single_booked, start, end)

        return True