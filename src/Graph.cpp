#include "Graph.h"
/*
dijstra算法代码实现思想
1. 首先维护两个数组,一个数组dist[]用来保存src到各个顶点的最短距离，另一个数组isset[]用来保存当前顶点是否已经拓展
2. 初始化dist[]数组，将src到各个顶点的距离初始化为无穷大，将src到自身的距离初始化为0，将isset[]数组初始化为false
3. 每轮循环从dist[]数组中选择一个距离最小的顶点，将其isset数组设置为True，然后循环查找与该顶点相连的顶点，如果该顶点的距离加上与当前顶点的距离小于dist[]数组中对应顶点的距离，则更新dist[]数组中对应顶点的距离
4. 重复步骤3，直到isset数组全部为True为止
 */

int MinDistance(std::vector<double> &dist, std::vector<bool> &isset)
{
    // 初始化最小值
    double min = std::numeric_limits<double>::max();
    int min_index;
    for (int v = 0; v < dist.size(); v++)
        if (isset[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void Dijkstra(std::vector<std::vector<double>> &graph, int src)
{
    std::vector<double> dist(graph.size(), std::numeric_limits<double>::max());
    std::vector<bool> isset(graph.size(), false);
    // src与自身的距离始终为0，不需要进行计算
    dist[src] = 0;
    for (size_t i = 0; i < graph.size() - 1; i++)
    {
        int min_index = MinDistance(dist, isset);
        isset[min_index] = true;
        for (size_t v = 0; v < 9; v++)
        {
            if (!isset[v] && graph[min_index][v] && dist[min_index] != std::numeric_limits<double>::max() && dist[min_index] + graph[min_index][v] < dist[v])
            {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }
    // 打印距离数组
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << ":" << dist[i] << endl;
    }
}
void GraphTest(void)
{
    std::vector<std::vector<double>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    ;
    // 将给定的二维数组值赋给嵌套vector
    Dijkstra(graph, 1);
}