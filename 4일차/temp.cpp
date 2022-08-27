#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
 
using namespace std;
 
int testcase, n;
string s;
char game[301][301];
int visited[301][301] = {0, };
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
int num = 0;
 
// 주위 8칸에 모두 지뢰가 없는지 확인
bool check(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<n) // 이동할수 없거나
        {
            if(game[nx][ny]=='*') //지뢰일 경우
            {
                return false; // 0이 될수 없다
            }
        }
    }
    return true;
}   
 
void play()
{
    // 주위 8칸에 지뢰가 없는 빈칸을 찾는다.
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //방문을 안한 0일때
            if(!visited[i][j] && game[i][j]=='.' && check(i, j))
            {
                num++;
                // visited[i][j] = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j)); //0의 위치를 queue에 삽입
 
                while(!q.empty())
                {
                    //queue의 head에서 0을 꺼내서 방문
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = 1;
                    q.pop();
                    for(int k=0; k<8; k++) // 0 주위의 8칸 방문
                    {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny] && game[nx][ny]=='.'){
                            visited[nx][ny] = 1;
                            if(check(nx, ny)) // 주위의 0
                            { 
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
}
 
int main()
{
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        num = 0;
        memset(visited, 0, sizeof(visited));
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>s;
            for(int k=0; k<s.size(); k++){
                game[j][k] = s[k];
            }
        }
 
        play();
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(!visited[j][k] && game[j][k]=='.')
                {
                    num++; // 아직 방문 안된것들 개별적으로 방문
                }
            }
        }
        cout<<"#"<<i+1<<" "<<num<<"\n";
    }
}