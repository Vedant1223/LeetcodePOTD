class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();

        unordered_map<int, list<int>> adj;
        vector<int> indegree(N,0);

        for( int i = 0 ; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>> t( N + 1 , vector<int>(26,0) );
        queue<int> q;
        for( int i = 0; i < N; i++){
            if(indegree[i]== 0){
                q.push(i);
                t[i][colors[i]- 'a'] = 1;
            }
        }
        
        int ans = 0;
        int countNodes  = 0;

        while( !q.empty() ){
            int node = q.front();
            q.pop();

            countNodes++;
            ans = max(ans, t[node][colors[node]-'a']);

            for( int neighbor : adj[node]){

                for( int i = 0; i < 26; i++){
                    t[neighbor][i] = max(t[neighbor][i], t[node][i] + (colors[neighbor]- 'a' == i));   
                }
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        if(countNodes != N){
            return -1;
        }
        else{
            return ans;
        }
    }
};