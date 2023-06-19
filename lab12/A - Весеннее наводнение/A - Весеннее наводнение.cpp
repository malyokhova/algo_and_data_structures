#include <iostream>
using namespace std;

struct Edge
{
    int v1;
    int v2;
    int w;
};

int Kruskal(Edge*, int, int);
void HeapSort(int, Edge*);
void SiftDown(int, int, Edge*);
void BuildHeap(int, Edge*);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Edge* edges = new Edge[m];
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].v1 >> edges[i].v2 >> edges[i].w;
        edges[i].v1--;
        edges[i].v2--;
	}

    cout << Kruskal(edges, n, m);
}

int Kruskal(Edge* edges, int n, int m)
{
    int* MST = new int[n] {0};
    int* colors = new int[n];
    int sumMST = 0;
    for (int i = 0; i < n; i++)
    {
        colors[i] = i;
    }

    HeapSort(m, edges);

    for (int i = 0; i < m; i++)
    {
        if (colors[edges[i].v1] != colors[edges[i].v2])
        {
            MST[edges[i].v1] = 1;
            MST[edges[i].v2] = 1;
            colors[edges[i].v1] = colors[edges[i].v2] = -1;
            sumMST += edges[i].w;
        }
    }

    return sumMST;
}

void HeapSort(int n, Edge* edges)
{
    BuildHeap(n, edges);
    int heapSize = n;
    for (int i = 0; i < n; i++)
    {
        swap(edges[0], edges[n - 1 - i]);
        heapSize--;
        SiftDown(0, heapSize, edges);
    }
}

void BuildHeap(int n, Edge* edges)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        SiftDown(i, n, edges);
    }
}

void SiftDown(int i, int n, Edge* edges)
{
    int j = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && edges[j].w < edges[leftChild].w)
    {
        j = leftChild;
    }
    if (rightChild < n && edges[j].w < edges[rightChild].w)
    {
        j = rightChild;
    }
    if (i != j)
    {
        swap(edges[i], edges[j]);
        SiftDown(j, n, edges);
    }
}
