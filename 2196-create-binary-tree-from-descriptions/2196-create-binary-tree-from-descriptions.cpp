class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map; // Map to store nodes by value
        unordered_set<int> children; // Set to store child nodes

        // Iterate over descriptions to create nodes and link them
        for (auto& arr : descriptions) {
            int parent = arr[0], child = arr[1], isLeft = arr[2];
            children.insert(child); // Add child to set of children

            // Create parent node if it does not exist
            if (map.find(parent) == map.end()) {
                map[parent] = new TreeNode(parent);
            }

            // Create child node if it does not exist
            if (map.find(child) == map.end()) {
                map[child] = new TreeNode(child);
            }

            // Link child to parent based on isLeft flag
            if (isLeft == 1) {
                map[parent]->left = map[child];
            } else {
                map[parent]->right = map[child];
            }
        }

        int root = -1;
        // Find the root node (node that is not a child of any other node)
        for (auto& arr : descriptions) {
            if (children.find(arr[0]) == children.end()) {
                root = arr[0];
                break;
            }
        }

        // Return the root node
        return map[root];
    }
};