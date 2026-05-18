class Solution {
public:
  int minJumps(std::vector<int> &arr) {
    int last = arr.size() - 1;
    if (arr.size() == 1)return 0;
    if (arr.size() == 2 || arr[0] == arr[last]) return 1;
    if (arr.size() == 3)return 2;
    
    std::unordered_map<int, std::vector<int>> nodes_by_value;
    nodes_by_value.reserve(arr.size());
    int max_repetitions = 1;
    for (size_t i = 0; i < arr.size(); i++) {
      auto &node = nodes_by_value[arr[i]];
      node.push_back(i);
      if (node.size() > max_repetitions) {
        max_repetitions = node.size();
      }
    }

    if (max_repetitions == 1) {
      return arr.size() - 1;
    }

    std::vector<int> depth(arr.size(), 0);
    std::vector<int> depth_mirror(arr.size(), 0);
    std::vector<int> deq;
    deq.reserve(arr.size());
    std::vector<int> deq_mirror;
    deq_mirror.reserve(arr.size());
    int deq_head = 0;
    int deq_mirror_head = 0;
    depth[0] = 1;
    depth_mirror[last] = 1;

    {

      // enqueue right node
      // not applicable yet
      // if (depth_mirror[1] != 0) {
      //   return depth[0] + depth_mirror[1] - 1;
      // }

      depth[1] = 2;
      deq.push_back(1);

      auto &connections = nodes_by_value[arr[0]];
      for (auto &c : connections) {
        if (depth[c] == 0) {
          depth[c] = 2; // depth[0] + 1
          deq.push_back(c);
        }
      }
      connections.clear();

      {
        int left_mirror = last - 1;
        if (depth[left_mirror] != 0) {
          return depth_mirror[last] + depth[left_mirror] - 1;
        }

        depth_mirror[left_mirror] = 2;
        deq_mirror.push_back(left_mirror);

        auto &connections = nodes_by_value[arr[last]];
        for (auto &c : connections) {
          if (depth[c] != 0) {
            return depth_mirror[last] + depth[c] - 1;
          }

          if (depth_mirror[c] == 0) {
            depth_mirror[c] = 2; // depth_mirror[last] + 1
            deq_mirror.push_back(c);
          }
        }
        connections.clear();
      }
    }

    while (true) {
      auto index = deq[deq_head];
      deq_head++;

      // std::cout << "extracted index from deque: " << index << "\n";
      if (depth_mirror[index] != 0) {
        return depth[index] + depth_mirror[index] - 2;
      }
      // enqueue connected nodes
      auto right = index + 1;
      // check if the right index trace is found
      // if (/*right < arr.size() && */ depth_mirror[right] != 0) {
      //   return depth[index] + depth_mirror[right] - 1;
      // }

      if (/*right < arr.size() && */ depth[right] == 0) {
        depth[right] = depth[index] + 1;
        // std::cout << " DEQ " << "Adding right index: " << right << "\n";
        deq.push_back(right);
      }

      auto left = index - 1;
      // if (/*left >= 0 && */ depth_mirror[left] != 0) {
      //   return depth[index] + depth_mirror[left] - 1;
      // }

      if ( depth[left] == 0) {
        depth[left] = depth[index] + 1;
        deq.push_back(left);
      }

      auto &connections = nodes_by_value[arr[index]];
      for (auto &c : connections) {
        if (depth[c] == 0) {
          depth[c] = depth[index] + 1;
          deq.push_back(c);
        }
      }
      connections.clear();

      {
        auto index_mirror = deq_mirror[deq_mirror_head];
        deq_mirror_head++;

        if (depth[index_mirror] != 0) {
          return depth_mirror[index_mirror] + depth[index_mirror] - 2;
        }
        auto right = index_mirror + 1;
        if (depth_mirror[right] == 0) {
          depth_mirror[right] = depth_mirror[index_mirror] + 1;
          deq_mirror.push_back(right);
        }

        auto left = index_mirror - 1;
        if (depth_mirror[left] == 0) {
          depth_mirror[left] = depth_mirror[index_mirror] + 1;
          deq_mirror.push_back(left);
        }

        auto &connections = nodes_by_value[arr[index_mirror]];
        for (auto &c : connections) {
          if (depth_mirror[c] == 0) {
            depth_mirror[c] = depth_mirror[index_mirror] + 1;
            deq_mirror.push_back(c);
          }
        }
        connections.clear();
      }
    }
    return depth[arr.size() - 1];
  }
};