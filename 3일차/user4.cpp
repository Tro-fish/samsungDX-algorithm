#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int id;
    int parent = 0;
    int size = 0;
    int child[2];
};

int get_size(Node *nodes, int index)
{
    if (nodes[index].size == 2) // 자식이 2개 일 때
    {
        return (1 + get_size(nodes, nodes[index].child[0]) + get_size(nodes, nodes[index].child[1]));
    }
    else if (nodes[index].size == 1) // 자식이 1개 일 때
    {
        return (1 + get_size(nodes, nodes[index].child[0]));
    }
    else // 자식이 없을 때
    {
        return 1;
    }
}
int min_parent;
int get_min_size(Node *nodes, vector<int> same_parent)
{
    int min = 999999;
    for (int i = 0; i < same_parent.size(); i++)
    {
        if (min > get_size(nodes, same_parent[i]))
        {
             min = get_size(nodes, same_parent[i]);
             min_parent = same_parent[i];
             cout<<"same_parent[i] : "<<same_parent[i]<<endl;
        }
    }
    return min;
}

vector<int> find_parent(Node *nodes, int index, vector<int> parents)
{
    if (nodes[index].parent > 0)
    {
        parents.push_back(nodes[index].parent);
        return find_parent(nodes, nodes[index].parent, parents);
    }
    else
    {
        return parents;
    }
}

vector<int> marge_parents(vector<int> parent1, vector<int> parent2)
{
    vector<int> same_parent;
    for (int v1 = 0; v1 < parent1.size(); v1++)
    {
        for (int v2 = 0; v2 < parent2.size(); v2++)
        {
            if (parent1[v1] == parent2[v2])
            {
                same_parent.push_back(parent1[v1]);
            }
        }
    }
    return same_parent;
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, N, target1, target2;
    int parent, child;
    cin >> V >> N >> target1 >> target2;
    Node nodes[V + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> parent >> child;
        // 부모에서 자식 저장
        nodes[parent].child[nodes[parent].size] = child;
        nodes[parent].size += 1;
        // 자식에서 부모 저장
        nodes[child].parent = parent;
    }

    vector<int> target1_parent;
    target1_parent = find_parent(nodes, target1, target1_parent);
    vector<int> target2_parent;
    target2_parent = find_parent(nodes, target2, target2_parent);
    vector<int> same_parent = marge_parents(target1_parent, target2_parent);
    print_vector(same_parent);
    cout<<get_min_size(nodes, same_parent)<<endl;
    //cout << "#" << test_case << " " << min_parent << " " << get_min_size(nodes, same_parent) << endl;
}