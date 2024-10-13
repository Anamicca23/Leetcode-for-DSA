import heapq

class Solution:
    def smallestRange(self, nums):
        # A list of iterators that keeps track of the current position in each list
        iterators = [iter(num_list) for num_list in nums]
        
        # Min-heap to always get the minimum element from the iterators
        min_heap = []
        max_val = float('-inf')

        # Initialize the heap with the first element of each list
        for i, num_list in enumerate(nums):
            val = next(iterators[i], None)
            heapq.heappush(min_heap, (val, i))
            max_val = max(max_val, val)
        
        # Track the best range
        range_start, range_end = 0, float('inf')

        while True:
            # Get the smallest element from the heap
            min_val, list_idx = heapq.heappop(min_heap)

            # If the current range is smaller than the best range, update it
            if max_val - min_val < range_end - range_start:
                range_start, range_end = min_val, max_val

            # Move the iterator for the list that contributed the smallest element
            next_val = next(iterators[list_idx], None)
            if next_val is None:
                # If any of the lists runs out, we're done
                break

            # Push the next element of the current list into the heap
            heapq.heappush(min_heap, (next_val, list_idx))
            max_val = max(max_val, next_val)  # Update the max value seen so far

        return [range_start, range_end]
