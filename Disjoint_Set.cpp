class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n ) {
        parent.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find (int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void union (int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        if (rank[root2] > rank[root1])
            parent[root1] = root2;
        else if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else {
            parent[root2] = root1;
            rank[root1] += 1;
        }

    }
    int count() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); i++)
            if (i == parent[i])
                cnt++;
        return cnt;
    }
};
