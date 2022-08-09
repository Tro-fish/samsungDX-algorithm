int map[10][10];
int mapB[10][10];
int N;

const int dx[4] = {0, 0, 1, -1}; // x축 이동
const int dy[4] = {1, -1, 0, 0}; // y축 이동

struct QNode {
    QNode* next;
    int x;
    int y;
    int dist;
    QNode(int _x, int _y, int _dist, QNode* _next): x(_x), y(_y), dist(_dist), next(_next){} //생성자
};

void bfs_init(int _N, int _map[10][10]) {
    N = _N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            map[i][j] = _map[i][j];
}

int bfs(int y1, int x1, int y2, int x2) {
    x1--;
    y1--;
    x2--;
    y2--;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mapB[i][j] = map[i][j];
    QNode *head = new QNode(x1, y1, 0, nullptr); //시작 지점 설정
    QNode *tail = head;

    while(head) {
        int x = head->x; // 현재 위치 설정
        int y = head->y; // 현재 위치 설정
        int dist = head->dist; //총 거리
        if(x == x2 && y == y2) return dist; // 목적지 도달 했을 경우 return
        mapB[x][y] = 2; // 방문 체크
        for(int i = 0; i < 4; i++) {
            // 벽에 막히거나 더이상 갈 곳이 없으면 패스
            if(x+dx[i] >= N || x+dx[i] < 0 || y+dy[i] < 0 || y+dy[i] >= N) continue;
            if(mapB[x+dx[i]][y+dy[i]] == 0) // 안가본 장소일 경우만
            {
                tail->next = new QNode(x+dx[i], y+dy[i], dist+1, nullptr); // 방문한 곳 넣기
                tail = tail->next;
            }
        }
        QNode* tmp = head->next;
        delete(head); // 방문 했으니깐 삭제
        head = tmp; // 더 이상 방문할 길이 없으면 null이됨 
    }
    return -1;
}