#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 12
#define INF 987654321
using namespace std;

struct node {
    int x,y;
    
    node() { } //구조체 기본 생성자
    node(int _x,int _y) : x(_x),y(_y) { } //구조체 생성자 오버로딩
};

int testcase;
int n,ans1,ans2;
int map[MAX][MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<node> core;

void printMap(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

// ans1 = 설치 최대 개수
// ans2 = 전선 최소 개수
// ins = 설치 개수
// sum = 전선 개수
void dfs(int ind,int cnt,int ins,int sum){
    // 모든 코어 작업을 끝낸 경우
    if(cnt == core.size())
    {
        if(ins > ans1) //이전 경우들 보다 더 많은 전선을 설치 했을 경우 
        {
            ans1 = ins;
            ans2 = sum; 
        }
        else if(ins == ans1) //이전 경우들과 전선의 갯수가 같을 경우
        {
            ans1 = ins;
            ans2 = min(ans2,sum); // 전선의 길이가 가장 짧은거로 선택한다
        }
        return;
    }
    
    // 설치하는 경우
    for(int i=0; i<4; i++)
    {
        vector<node> tmp;
        
        bool flag = false;
        int nr = core[ind].x;
        int nc = core[ind].y;
        
        while(1)
        {
            if(nr==0 || nc==0 || nr==n-1 || nc==n-1) //전선에 연결 된 경우
            {
                flag = true;
                break;
            }
            
            nr += dx[i];
            nc += dy[i];
            
            if(map[nr][nc] == 0) // 이동할 수 있을 경우
            {
                tmp.push_back(node(nr,nc)); //node 삽입
            }
            else //이동 할 수 없을 경우
            {
                break; // 종료
            }
        }
        if(flag)
        {
            // 전선 설치
            for(int j=0; j<tmp.size(); j++)
            {
                map[tmp[j].x][tmp[j].y] = 2;
            }
            
            dfs(ind+1, cnt+1, ins+1, sum + (int)tmp.size());
            
            // 전선 해체
            for(int j=0; j<tmp.size(); j++)
            {
                map[tmp[j].x][tmp[j].y] = 0;
            }
        }
    }
    
    // 설치하지 않는 경우
    dfs(ind+1,cnt+1,ins,sum);
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> testcase;
    for(int tc=1; tc<=testcase; tc++){
        // 초기화
        core.clear();
        
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
                
                if(map[i][j] == 1){
                    // 가장자리 코어들은 제외
                    if(i==0 || j==0 || i==n-1 || j==n-1) continue;
                    
                    core.push_back(node(i,j));
                }
            }
        }
        
        ans1 = 0;
        ans2 = INF;
        dfs(0,0,0,0);
        cout << "#" << tc << " " << ans2 << "\n";
    }
    
    return 0;
}