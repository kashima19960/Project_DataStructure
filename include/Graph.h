#ifndef GRAPH_H
#define GRAPH_H
#include "common.h"
void Dijkstra(std::vector<std::vector<double>> &graph, int src);
void GraphTest(void);
int MinDistance(std::vector<double> &dist, std::vector<bool> &isset);
#endif