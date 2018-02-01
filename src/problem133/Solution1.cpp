/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (UndirectedGraphNode * n : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return mp[node];
    }

private:
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};