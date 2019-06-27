#include<bits/stdc++.h>
using namespace std;
const int N=10100;
int pref[N];


vector<pi> lista[N];
int av[N];
vector<int> parent, depth, heavy, head, pos;
int cur_pos=1,n;

int dfs(int v) {
    int size = 1;
    int max_c_size = 0;
    for (pi c : lista[v]) {
        if (c.ft != parent[v]) {
            parent[c.ft] = v, depth[c.ft] = depth[v] + 1;
            int c_size = dfs(c.ft);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c.ft;
        }
    }
    return size;
}

int decompose(int v, int h) {
    head[v] = h, pos[v] = cur_pos++;
    av[pos[v]]=v;
    if (heavy[v] != -1){
    	// Para quando o peso é na aresta
        // av[pos[v]+1]=mat[v][heavy[v]];
        decompose(heavy[v], h);
    }
    for (pi c : lista[v]) {
        if (c.ft != parent[v] && c.ft != heavy[v])
            decompose(c.ft, c.ft);
    }
}

void init() {
	n++;
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 1;
    n--;
    dfs(0);
    decompose(0, 0);
}




int lca(int a, int b)
{
    while(head[a] != head[b])  {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
    	b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    return b;
}


int hldquery1(int a, int b,int k) {
    int lc=lca(a,b);
    int x;
    while(head[a]!=head[lc]){
    	if(pos[a]-pos[head[a]]>=k){
    		return av[pos[a]-k];
    	}
    	k-=pos[a]-pos[head[a]]+1;
    }
}
ll hldquery2(int a, int b) {
    ll res = 0;
    while(head[a] != head[b])  {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        if(head[b]!=b){
        	res +=pref[pos[head[b]]]-pref[pos[b]-1];
    	}
    	b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    res +=pref[pos[a]]-pref[pos[b]-1];
    return res;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a>>b>>c;
		lista[a].emplace_back(b,c);
		lista[b].emplace_back(a,c);
	}



	return 0;
}