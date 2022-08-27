#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode
{
    int id;
    int next;
};
int n = 10; // 정점의 개수
vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {3, 2}, {4, 3}};
vector<LinkedListNode> nodes(edges.size());
vector<int> head(n, -1);

int main(void)
{
    for (int i = 0; i < static_cast<int>(edges.size()); ++i)
    {
        nodes[i].id = edges[i].second;
        nodes[i].next = head[edges[i].first];
        head[edges[i].first] = i;
    }
}