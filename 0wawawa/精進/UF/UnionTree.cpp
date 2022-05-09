struct UnionFind{
    vector<int> par;

    UnionFind(int N): par(N+1){
        for(int i=1;i<=N;i++) par[i]=i;//最初は全てが根
    }

    int root(int x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    void unite(int x, int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry)return;
        par[rx]=ry;//xの根rxをyの根ryにつける
    }

    bool same(int x, int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
};