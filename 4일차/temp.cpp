#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 12
#define INF 987654321
using namespace std;

struct node
{
    int x, y;                              // core의 x,y 좌표
    node(int _x, int _y) : x(_x), y(_y) {} // 구조체 생성자
}

int map[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int conneted_core_result = 0;
int length_result = 0;
vector<node> core;

dfs(int index, int checked_core, int connected_core, int length)
{
    if(checked_core == core.size()) // 모든 core의 검사가 끝난 경우
    {
        // 더 많은 코어를 연결 했을 경우
        if(connected_core > conneted_core_result)
        {
            conneted_core_result = connected_core;
            length_result = length;
        }
        // 코어의 갯수는 같지만 연결 길이가 더 짧을 경우
        else if(connected_core == conneted_core_result)
        {
            conneted_core_result = connected_core;
            length_result = min(length_result, length);
        }
        // 코어의 수가 더 적을 경우
        else
        {
            return;
        }
        return;
    }

    for (int i = 0; i < 4; i++) // 상하좌우로 이동
    {
        vector<node> connected;
        bool connect = false;
        int nx = core[index].x;
        int ny = core[index].y;
        while (1) // 연결 가능한거는 다 찾기
        {
            // 현재 연결이 된 경우
            if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1)
            {
                connect = true;
                break;
            }
            // 상하좌우로 이동
            nx += dx[i];
            ny += dy[i];
            // 이동 할 수 있는 경우
            if(map[nx][ny] == 0)
            {
                connected.push_back(node(nx,ny));
            }
            //이동 할 수 없는 경우
            else
            {
                break;
            }
        }
        if(connect) //연결 할 수 있는 코어가 있을 경우
        {
            // 전선 연결
            for(int j=0;j<connected.size();j++)
            {
                map[connected[j].x][connected[j].y] = 2;
            }
            dfs(index+1,checked_core+1,connected_core+1,length + (int)connected.size());
            // 전선 해제
            for(int j=0;j<connected.size();j++)
            {
                map[connected[j].x][connected[j].y] = 0;
            }
        }
    }
dfs(index+1,checked_core+1,connected_core,length);
    
}

int main(void)
{
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    core.clear(); // 구조체 초기화
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                // 가장자리 코어들은 제외
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                    continue;
                core.push_back(node(i, j)); // 코어 삽입
            }
        }
    }
    dfs(0, 0, 0, 0);
}