class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        s = list(s)

        intervals = []
        i = 0
        while i < n:
            start = i
            char = s[i]
            while i < n and s[i] == char:
                i += 1
            intervals.append([start, i - 1, char])        
        max_length = max(end - start + 1 for start, end, char in intervals)
        
        def binary_search_intervals(pos):
            left, right = 0, len(intervals) - 1
            
            while left <= right:
                mid = (left + right) // 2
                start, end, char = intervals[mid]
                
                if start <= pos <= end:
                    return mid
                elif pos < start:
                    right = mid - 1
                else: 
                    left = mid + 1
            
            return -1
        
        def recalculate_max():
            return max(end - start + 1 for start, end, char in intervals)
        
        results = []
        
        for query_idx in range(len(queryIndices)):
            pos = queryIndices[query_idx]
            new_char = queryCharacters[query_idx]
            if s[pos] == new_char:
                results.append(max_length)
                continue
            s[pos] = new_char
            interval_idx = binary_search_intervals(pos)
            start, end, old_char = intervals[interval_idx]
            new_length=1
            changed= max_length==end-start+1
            if start<pos<end:
                intervals[interval_idx]=[start,pos-1,old_char]
                intervals.insert(interval_idx+1,[pos+1,end,old_char])
                intervals.insert(interval_idx+1,[pos,pos,new_char])
                new_length= max(intervals[interval_idx][1]-intervals[interval_idx][0]+1,
                                intervals[interval_idx+1][1]-intervals[interval_idx+1][0]+1,
                                intervals[interval_idx+2][1]-intervals[interval_idx+2][0]+1)

            elif start==pos==end:
                leftmatch= intervals[interval_idx-1][2]==new_char if interval_idx-1>=0 else False
                rightmatch = intervals[interval_idx+1][2]==new_char if interval_idx+1<len(intervals) else False
                leftstart,_,_=intervals[interval_idx-1] if interval_idx-1>=0 else [-1,-1,None]
                _,rightend,_=intervals[interval_idx+1] if interval_idx+1<len(intervals) else[-1,-1,None]
                if leftmatch and rightmatch:
                    leftstart,_,_=intervals[interval_idx-1]
                    _,rightend,_=intervals[interval_idx+1]
                    intervals[interval_idx-1]=[leftstart,rightend,new_char]
                    new_length=rightend+1-leftstart
                    del intervals[interval_idx]
                    del intervals[interval_idx]
                elif leftmatch:
                    intervals[interval_idx-1]=[leftstart,pos,new_char]
                    new_length=pos+1-leftstart
                    del intervals[interval_idx]
                elif rightmatch:
                    intervals[interval_idx+1]=[pos,rightend,new_char]
                    new_length=rightend+1-pos
                    del intervals[interval_idx]
                else:
                    intervals[interval_idx]=[pos,pos,new_char]
                    new_length=1

            elif start==pos:
                if interval_idx==0:
                    intervals[interval_idx]=[1,end,old_char]
                    intervals.insert(0,[0,0,new_char])
                else:
                    intervals[interval_idx]=[start+1,end,old_char]
                    prevs,preend,prechar=intervals[interval_idx-1]
                    if prechar==new_char:
                        intervals[interval_idx-1]=[prevs,preend+1,prechar]
                        new_length=preend+2-prevs
                    else:
                        intervals.insert(interval_idx,[pos,pos,new_char])
            elif end==pos:
                if interval_idx==len(intervals)-1:
                    intervals[interval_idx]=[start,end-1,old_char]
                    intervals.append([pos,pos,new_char])
                else:
                    intervals[interval_idx]=[start,end-1,old_char]
                    nexts,nextend,nextchar=intervals[interval_idx+1]
                    if nextchar==new_char:
                        intervals[interval_idx+1]=[nexts-1,nextend,nextchar]
                        new_length=nextend-nexts+2
                    else:
                        intervals.insert(interval_idx+1,[pos,pos,new_char])
            if new_length>=max_length:
                max_length=new_length
            elif changed:
                max_length=recalculate_max()
            results.append(max_length)
        return results