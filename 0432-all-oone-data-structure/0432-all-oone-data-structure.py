class AllOne:

    def __init__(self):
        self.count = {}  # Stores the count of each key
        self.key_map = {}  # Maps count to keys with that count
    
    def inc(self, key: str) -> None:
        # Get the current count of the key
        current_count = self.count.get(key, 0)
        
        # Remove key from current count mapping (if it exists)
        if current_count > 0:
            self.key_map[current_count].remove(key)
            if not self.key_map[current_count]:
                del self.key_map[current_count]
        
        # Increment the count of the key
        new_count = current_count + 1
        self.count[key] = new_count
        
        # Add the key to the new count mapping
        if new_count not in self.key_map:
            self.key_map[new_count] = set()
        self.key_map[new_count].add(key)
    
    def dec(self, key: str) -> None:
        # Get the current count of the key
        current_count = self.count.get(key, 0)
        if current_count == 0:
            return
        
        # Remove key from the current count mapping
        self.key_map[current_count].remove(key)
        if not self.key_map[current_count]:
            del self.key_map[current_count]
        
        # Decrease the count of the key
        new_count = current_count - 1
        if new_count > 0:
            self.count[key] = new_count
            if new_count not in self.key_map:
                self.key_map[new_count] = set()
            self.key_map[new_count].add(key)
        else:
            del self.count[key]
    
    def getMaxKey(self) -> str:
        if not self.count:
            return ""
        max_count = max(self.key_map)
        return next(iter(self.key_map[max_count]))
    
    def getMinKey(self) -> str:
        if not self.count:
            return ""
        min_count = min(self.key_map)
        return next(iter(self.key_map[min_count]))
