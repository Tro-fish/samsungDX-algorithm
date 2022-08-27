#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> edges;
vector<vector<int>> graph(100); //node의 개수

int main(void)
{
    for(int i=0;i<5;i++)
    {       
        edges.emplace_back(i,i+1); // 간선 삽입
    }      
    edges.emplace_back(0,2);
    edges.emplace_back(0,3);

    for(int i=0;i<edges.size();i++)
    {
        graph[edges[i].first].emplace_back(edges[i].second);
    }  

    // 그래프 출력
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}