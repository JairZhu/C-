public class IndexMinPQ<Key extends Comparable<Key>>
{
    private int[] pq;           //��������ѣ���1��ʼ
    private int[] qp;           //pq������qp[i]��ֵ��i��pq[]�е�λ��
    private int N = 0;
    private Key[] keys;         //�����ȼ�֮�ֵ�Ԫ��
    public IndexMinPQ(int maxN)
    {
        keys = (Key[]) new Comparable[maxN + 1];
        pq = new int[maxN + 1];
        qp = new int[maxN + 1];
        for (int i = 0; i <= maxN; i++) qp[i] = -1; 
    }
    public boolean isEmpty() { return N == 0; }
    public boolean contains(int k) { return qp[k] != -1; }
    public int size() { return N; }
    private void swim(int k)                //���¶��ϵĶ����򻯣��ϸ���
    {
        while (k > 1 && less(k / 2, k))
        {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    private void sink(int k)                //���϶��µĶ����򻯣��³���
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && less(j, j + 1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }
    public void insert(int k, Key key)
    {
        N++;
        qp[k] = N;
        pq[N] = k;
        keys[k] = key;
        swim(N);
    }
    public Key min() { return keys[pq[1]]; } 
    public int delMin() 
    {
        int indexOfMin = pq[1];
        exch(1, N--);
        sink(1);
        keys[pq[N + 1]] = null;
        qp[pq[N + 1]] = -1;
        return indexOfMin;
    }
    public int minIndex() { return pq[1]; }
    public void change(int k, Key key) 
    {
        keys[k] = key;
        swim(qp[k]);
        sink(qp[k]);
    }
    public void delete(int k)
    {
        int index = qp[k];
        exch(index, N--);
        swim(index);
        sink(index);
        keys[k] = null;
        qp[k] = -1;
    }
}