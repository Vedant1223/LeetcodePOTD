class Solution {
public:

    int dfs(int src, vector<vector<int>>  &adj, int k, int prev){
        if( k < 0){
            return 0;
        }
        int count = 1;
        for( int v : adj[src]){
            if(v != prev) count += dfs(v, adj, k-1, src);
        }
        return count;

    }

    vector<int> dfsAllNodes(vector<vector<int>>  &adj, int k, int nodes){

        vector<int> ans(nodes, 0);
        for( int i = 0 ; i < nodes; i++){
            ans[i] = dfs(i, adj, k, -1);
        }
        
        return ans;
    }

    vector<vector<int>> buildList(const vector<vector<int>>& edges) {
        int N = edges.size()+1;
        vector<vector<int>> adj(N);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    vector<vector<int>> Gone = buildList(edges1);
    vector<vector<int>> Gtwo = buildList(edges2); 
    
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;



    vector<int> nearOne(n, 0);
    vector<int> nearTwo(m, 0);

    nearOne = dfsAllNodes(Gone, k, n);
    nearTwo = dfsAllNodes(Gtwo, k-1, m);

    int maxi = 0;
    for( auto node: nearTwo){
        maxi = max(maxi, node);
    }


    for( int i = 0; i < n ; i++){
        nearOne[i] = nearOne[i] + maxi;
    }

    return nearOne;
    }
};