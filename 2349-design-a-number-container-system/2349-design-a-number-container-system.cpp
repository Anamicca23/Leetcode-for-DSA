class NumberContainers {
public:
  void change(int index, int number) {
    entries[index] = number;
    number_to_indexes[number].push(index);
  }
  
  int find(int number) {
    if (auto find_it = number_to_indexes.find(number);
        find_it == end(number_to_indexes)) {
      return -1;
    } else {
      auto& q = find_it->second;
      while (!empty(q) && entries[q.top()] != number) q.pop();
      return empty(q) ? -1 : q.top();
    }
  }

private:
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
      number_to_indexes;
  unordered_map<int, int> entries;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */