//使用深度优先搜索找出图中所有的连通分量
public class CC
{
    private boolean[] marked;
    private int[] id;
    private int count;
    
    public CC(Graph G)
    {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        for (int s = 0; s < G.V(); s++)
        if (!marked[s])
        {
            dfs(G, s);
            count++;
        }
    }

    private void dfs(Graph G, int s)
    {
        marked[v] = true;
        id[v] = count;
        for (int w : G.adj(v))
        {
            if (!marked[w])
                dfs(G, s);
        }
    }

    public boolean connected(int v, int w)
    { return id[v] == id[w]; }

    public int id(int v)
    { return id[v]; }

    public int count()
    { return count; }
}