class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        #print(moveTime)
        num_rows = len(moveTime)
        num_cols =len(moveTime[0])
        visited = [[False for _ in range(num_cols)] for _ in range(num_rows)]

        dirs = [(0,1), (1,0) , (-1,0), (0,-1)]
        queues = [(0 ,0 ,0 )]     # distance r ,c
        
        while queues:
            distance, current_row, current_col = heapq.heappop(queues)
            
            if current_row == num_rows - 1 and current_col == num_cols - 1:
                return distance

            for _row, _col in dirs:
                new_row = current_row + _row 
                new_col = current_col + _col

                if (new_row >= num_rows or new_col >= num_cols or 
                    new_row < 0 or new_col < 0 or 
                    visited[new_row][new_col]):
                    continue
                    
                visited[new_row][new_col] = True
                heapq.heappush(queues, (max(distance + 1, moveTime[new_row][new_col] + 1), new_row, new_col))



        return -1