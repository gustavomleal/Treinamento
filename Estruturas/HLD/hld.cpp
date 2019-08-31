
vector<pi> lista[N];
int tree[4*N],av[N];
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


int hldquery(int a, int b) {
    int res = 0;
    while(head[a] != head[b])  {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        //if(head[b]!=b){
        	//
        	//int cur = query(1,pos[head[b]]+1, pos[b],1,cur_pos);
        	int cur = query(1,pos[head[b]], pos[b],1,cur_pos);
        	res =max(cur,res);
    	//}
    	// Para quando o peso é na aresta
    	// res=max(res,mat[parent[head[b]]][head[b]]);
    	b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    //if(a!=b){
    	//int last = query(1,pos[a]+1, pos[b],1,cur_pos);
    	int last = query(1,pos[a], pos[b],1,cur_pos);
    	res =max(last,res);
    //}
    return res;
}

void hldupdate(int i,int x){
	// if(head[a]==head[b]){
		update(1,pos[i],x,1,cur_pos);

	/*}else
		mat[a][b]=mat[b][a]=x;
    */
	
}
