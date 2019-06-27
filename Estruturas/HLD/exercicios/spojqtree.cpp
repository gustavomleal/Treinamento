#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define it int
#define pi pair<int,int>
#define ft first
#define sd second
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
const int N=10100;

vector<pi> lista[N];
vector<pair<int,int>> edge;
it mat[N][N];
it tree[4*N],av[N];
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
    if (heavy[v] != -1){
    	av[pos[v]+1]=mat[v][heavy[v]];

    	// cout<<v<<" "<<pos[v]<<" "<<av[pos[v]]<<"\n";
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

void build(int p,int tl,int tr){
	if(tl==tr){
		tree[p]=av[tl];
	}else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p]=max(tree[lef(p)],tree[rig(p)]);
	}
}

it query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return 0LL;
	if(tl==l && tr==r)
		return tree[p];
	int mid=(tl+tr)/2;
	return max(query(lef(p),l,min(r,mid),tl,mid),
		query(rig(p),max(l,mid+1),r,mid+1,tr));
}

void update(int p,int k,int x,int tl,int tr){
	if(tl==tr){
		// cout<<tl<<"\n";
		tree[p]=x;
	}else{
		int mid=(tl+tr)/2;
		if(mid>=k){
			update(lef(p),k,x,tl,mid);
		}else{
			update(rig(p),k,x,mid+1,tr);
		}
		tree[p]=max(tree[lef(p)],tree[rig(p)]);
	}
}

it hldquery(int a, int b) {
    it res = 0;
    // if (depth[head[a]] > depth[head[b]])
    //         swap(a, b);
    while(head[a] != head[b])  {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        // cout<<a<<" "<<b<<"\n";
        if(head[b]!=b){
        	it cur_heavy_path_max = query(1,pos[head[b]]+1, pos[b],1,cur_pos);
        	res =max(cur_heavy_path_max,res);
    	}
    	// cout<<mat[parent[head[b]]][head[b]]<<"\n";
    	res=max(res,mat[parent[head[b]]][head[b]]);
    	b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    // cout<<a<<" "<<b<<"\n";
    // cout<<pos[a]<<" "<<pos[b]<<"\n";
    if(a!=b){
    	it last_heavy_path_max = query(1,pos[a]+1, pos[b],1,cur_pos);
    	res =max(last_heavy_path_max,res);
    }
    return res;
}

void hldupdate(int i,it x){
	i--;
	int a=edge[i].ft,b=edge[i].sd;
	if (depth[a] < depth[b])
		swap(a,b);
	if(head[a]==head[b]){
		update(1,pos[a],x,1,cur_pos);

	}else
		mat[a][b]=mat[b][a]=x;
	// cout<<pos[a]<<" "<<pos[b]<<"\n";
	
}






int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		// memset(mat,0,sizeof(mat));
		memset(av,0,sizeof(av));
		memset(tree,0,sizeof(tree));
		cin>>n;
		it a,b;
		it c;
		string s;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>a>>b>>c;
			edge.emplace_back(a,b);
			lista[a].emplace_back(b,c);
			lista[b].emplace_back(a,c);
			mat[a][b]=c;
			mat[b][a]=c;
		}
		lista[0].emplace_back(1,0);
		lista[1].emplace_back(0,0);
		init();
		// cur_pos++;
		build(1,1,cur_pos);
		cin>>s;
		while(s[0]!='D'){
			cin>>a>>b;
			if(s[0]=='Q'){
				// if(a==b)
				// 	cout<<0<<"\n";
				// else
					cout<<hldquery(a,b)<<"\n";
			}else{
				hldupdate(a,b);
			}
			cin>>s;
		}
		edge.clear();
		for (int i = 0; i <=n; ++i)
		{
			// cout<<i<<" "<<pos[i]<<"\n";
			lista[i].clear();
		}
	}



	return 0;
}