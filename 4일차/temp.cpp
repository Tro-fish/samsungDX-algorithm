#define MAXSIZE 10000
struct XandY
{
    int x;
    int y;
    int count;
};

XandY queue[MAXSIZE];
int front = 0, rear = 0;
int mapSize;
int matirx[11][11];
int visited[11][11];

void push(int x, int y, int count)
{
    queue[rear++].x = x;
    queue[rear++].y = y;
    queue[rear++].count = count;
}

XandY pop()
{
    XandY temp;
    temp.x = queue[front++].x;
    temp.y = queue[front++].y;
    temp.count = queue[front++].count;
    return temp;
}

bool isEmpty()
{
    if (rear == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bfs_init(int map_size, int map[10][10])
{
    /* 초기화 */
    for (int i = 0; i < map_size; i++)
    {
        for (int k = 0; k < map_size; k++)
        {
            matirx[i + 1][k + 1] = map[i][k];
            visited[i + 1][k + 1] = 0;
        }
    }
    for(int i=0;i<MAXSIZE;i++)
    {
        queue[i].x = 0;
        queue[i].y = 0;
        queue[i].count = 0;
    }
    front = 0;
    rear = 0;
    mapSize = map_size;
    /* 초기화 */
}

int bfs(int x1, int y1, int x2, int y2)
{
    int min = 99999;
    push(x1, y1, 0);
    visited[x1][y1] = 1; // 방문 체크
    while (!isEmpty())
    {
        XandY now = pop();
        //오른쪽 이동
        if (now.x + 1 <= mapSize && matirx[now.x + 1][now.y] != 1 && visited[now.x + 1][now.y] != 1)
        {
            if (now.x + 1 == x2 && now.y == y2)
            {
                if (min > now.count + 1)
                    min = now.count + 1;
            }
            else
            {
                visited[now.x + 1][now.y] = 1; // 방문 체크
                push(now.x + 1, now.y, now.count + 1);
            }
        }
        //왼쪽 이동
        if (now.x - 1 >= 1 && matirx[now.x - 1][now.y] != 1 && visited[now.x - 1][now.y] != 1)
        {
            if (now.x - 1 == x2 && now.y == y2)
            {
                if (min > now.count + 1)
                    min = now.count + 1;
            }
            else
            {
                visited[now.x - 1][now.y] = 1; // 방문 체크
                push(now.x - 1, now.y, now.count + 1);
            }
        }
        //아래 이동
        if (now.y + 1 <= mapSize && matirx[now.x][now.y + 1] != 1 && visited[now.x][now.y + 1] != 1)
        {
            if (now.x == x2 && now.y + 1 == y2)
            {
                if (min > now.count + 1)
                    min = now.count + 1;
            }
            else
            {
                visited[now.x][now.y + 1] = 1; // 방문 체크
                push(now.x, now.y + 1, now.count + 1);
            }
        }
        //위 이동
        if (now.y - 1 >= 1 && matirx[now.x][now.y - 1] != 1 && visited[now.x][now.y - 1] != 1)
        {
            if (now.x == x2 && now.y - 1 == y2)
            {
                if (min > now.count + 1)
                    min = now.count + 1;
            }
            else
            {
                visited[now.x][now.y - 1] = 1; // 방문 체크
                push(now.x, now.y - 1, now.count + 1);
            }
        }
    }
    if (min == 99999)
    {
        return -1;
    }
    else
    {
        return min;
    }
}