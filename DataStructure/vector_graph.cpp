#include <iostream>
#include <vector>

using namespace std;

int n = 10; //정점의 개수
vector<pair<int,int>> edges; //간선
vector<vector<int>> graph(n); //그래프 생성 --> 처음에 정점의 개수를 할당을 해줘야 함

int main(void)
{
    for(int i=0;i<5;i++)
    {       
        edges.emplace_back(i,i+1); // 간선 삽입
    }      
    edges.emplace_back(0,2); // 간선 삽입
    edges.emplace_back(0,3); // 간선 삽입

    for(int i=0;i<edges.size();i++)
    {
        graph[edges[i].first].emplace_back(edges[i].second); // 그래프에 간선 연결
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