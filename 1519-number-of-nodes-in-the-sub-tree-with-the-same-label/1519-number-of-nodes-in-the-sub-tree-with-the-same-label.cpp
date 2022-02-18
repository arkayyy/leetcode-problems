class Solution {
public:
    //INTUITION: This algo works because in DFS stack like working. So the storing of global frequency map will start from the lowest part of the graph, and keep on adding frequencies as we move up in the graph.
    //And since we have to output the sum of all frequencies of current letter in the subtree below the current node, this algo perfectly works.
    void dfs(int i, string &l, vector<vector<int>>& al, int cnt[], vector<int> &res) {
    if (res[i] == 0) {
        res[i] = 1; //counting the current node
        for (auto j : al[i]) {
            int cnt1[26] = {};
            dfs(j, l, al, cnt1, res); //running dfs starting from this node, in order to store the frequency map of this whole subtree under 'i' node, beginning from 'j' node
            for (auto k = 0; k < 26; ++k)
                cnt[k] += cnt1[k]; //adding the frequency map to the global frequency map till now
        }
        res[i] = ++cnt[l[i] - 'a']; //updating in our final answer array, the frequency of current character in the whole subtree below it
    }
}
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> res(n);
    int cnt[26] = {};
    vector<vector<int>> al(n);
    for (auto &e : edges) { //since graph is of undirected nature
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    dfs(0, labels, al, cnt, res);
    return res;
}
};