/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
using namespace std;
#define BOOM 999999

struct QNode
{
    QNode *next;
    int x;
    int y;
    QNode(int _x, int _y, QNode *_next) : x(_x), y(_y), next(_next) {} // 생성자
};
QNode *head;
QNode *tail;

int matrix[300][300];
// 상하좌우로 이동
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// 대각선으로 이동
int _dx[4] = {-1, 1, -1, 1};
int _dy[4] = {-1, -1, 1, 1};
int N;
int nonCheck;    //확인하지 않은 블록의 수
int checkedZero; //확인한 0의 개수

void init()
{
    for (int i = 0; i < 300; i++) // matrix 초기화
    {
        memset(matrix[i], 0, sizeof(int) * 300);
    }
    head = nullptr;
    nonCheck = 0;
    checkedZero = 0;
}

bool isZeroAround(int i, int j)
{
    QNode *node = head;
    while (node)
    {
        int x = node->x;
        int y = node->y;
        if (i == x && j == y)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

void zeroCheck()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool isZero = true;
            if (matrix[i][j] != BOOM)
            {
                for (int pos = 0; pos < 4; pos++)
                {
                    // 상하좌우 이동
                    if (i + dx[pos] < 0 || i + dx[pos] >= N || j + dy[pos] < 0 || j + dy[pos] >= N)
                    {
                        // 이동이 불가능 할 경우 --> 검사하지 않기
                    }
                    else
                    {
                        //이동이 가능 할 경우
                        if (matrix[i + dx[pos]][j + dy[pos]] == BOOM) //그 위치가 지뢰일 경우
                            isZero = false;                           // 0으로 표기 불가
                    }

                    // 대각선 이동
                    if (i + _dx[pos] < 0 || i + _dx[pos] >= N || j + _dy[pos] < 0 || j + _dy[pos] >= N)
                    {
                        // 이동이 불가능 할 경우 --> 검사하지 않기
                    }
                    else
                    {
                        //이동이 가능 할 경우
                        if (matrix[i + _dx[pos]][j + _dy[pos]] == BOOM) //그 위치가 지뢰일 경우
                            isZero = false;                             // 0으로 표기 불가
                    }
                }
            }
            else //지뢰일 경우
            {
                isZero = false;
            }
            // 지뢰가 아닐 경우
            if (isZero)
            {
                if (head == nullptr) //처음들어올 경우
                {
                    head = new QNode(i, j, nullptr);
                    tail = head;
                }
                else
                {
                    tail->next = new QNode(i, j, nullptr);
                    tail = tail->next;
                }
            }
        }
    }
}

void aroundCheck(int x, int y, bool firstcheck)
{
    if (matrix[x][y] == 1) //이미 처리된 0일 경우
        return;

    matrix[x][y] = 1; //방문 처리
    nonCheck -= 1;
    if (firstcheck)
        checkedZero += 1;

    for (int pos = 0; pos < 4; pos++)
    {
        //상하좌우 이동
        if (x + dx[pos] < 0 || x + dx[pos] >= N || y + dy[pos] < 0 || y + dy[pos] >= N)
        {
            // 이동이 불가능 할 경우 --> 검사하지 않기
        }
        else
        {
            if (isZeroAround(x + dx[pos], y + dy[pos])) // 0인 위치일 경우
            {
                aroundCheck(x + dx[pos], y + dy[pos], false);
            }
            else if (matrix[x + dx[pos]][y + dy[pos]] == -1) //방문을 안한 곳일 경우
            {
                matrix[x + dx[pos]][y + dy[pos]] = 1; //방문 처리
                nonCheck -= 1;
            }
        }

        // 대각선 이동
        if (x + _dx[pos] < 0 || x + _dx[pos] >= N || y + _dy[pos] < 0 || y + _dy[pos] >= N)
        {
            // 이동이 불가능 할 경우 --> 검사하지 않기
        }
        else
        {
            if (isZeroAround(x + _dx[pos], y + _dy[pos])) // 0인 위치일 경우
            {
                aroundCheck(x + _dx[pos], y + _dy[pos], false);
            }
            else if (matrix[x + _dx[pos]][y + _dy[pos]] == -1) //방문을 안한 곳일 경우
            {
                matrix[x + _dx[pos]][y + _dy[pos]] = 1; //방문 처리
                nonCheck -= 1;
            }
        }
    }
}

void BFS()
{
    while (head)
    {
        int x = head->x;
        int y = head->y;
        aroundCheck(x, y, true);
        QNode *next = head->next;
        delete (head); //사용했으므로 pop
        head = next;
    }
}

void test_print()
{
    cout << "체크하지 않은 block의 수 : " << nonCheck << endl;
    while (head)
    {
        int x = head->x;
        int y = head->y;
        cout << "x : " << x << ", y : " << y << endl;
        QNode *next = head->next;
        delete (head); //사용했으므로 pop
        head = next;
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    // freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        init();
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char input;
                cin >> input;
                if (input == '*') //지뢰일때
                {
                    matrix[i][j] = BOOM;
                }
                else if (input == '.')
                {
                    nonCheck += 1;
                    matrix[i][j] = -1;
                }
            }
        }
        // 0인 위치 확인
        zeroCheck();
        BFS();
        cout << "#" << test_case << " " << checkedZero + nonCheck << "\n";
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}