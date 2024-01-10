//1. Convert the binary tree to an undirected graph

void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
    if (current == nullptr) {
        return;
    } 
    if (map.find(current->val) == map.end()) {
        map[current->val] = unordered_set<int>();
    }
    unordered_set<int>& adjacentList = map[current->val];
    if (parent != 0) {
        adjacentList.insert(parent);
    } 
    if (current->left != nullptr) {
        adjacentList.insert(current->left->val);
    } 
    if (current->right != nullptr) {
        adjacentList.insert(current->right->val);
    }
    convert(current->left, current->val, map);
    convert(current->right, current->val, map);
    }
