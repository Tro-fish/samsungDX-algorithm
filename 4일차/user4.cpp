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
int nonCheck; //확인하지 않은 블록의 수

void init()
{
    for (int i = 0; i < 300; i++) // matrix 초기화
    {
        memset(matrix[i], 0, sizeof(int) * 300);
    }
    head = nullptr;
    nonCheck = 0;
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
                    if (i + dx[pos] < 0 || i + dx[pos] >= N || j + dy[pos] < 0 || j + dy[pos] >= N) { }
                    else if(matrix[i + dx[pos]][j + dy[pos]] == BOOM)
                        isZero = false;
                    if(i + _dx[pos] < 0 || i + _dx[pos] >= N || j + _dy[pos] < 0 || j + _dy[pos] >= N) { }
                    else if(matrix[i + _dx[pos]][j + _dy[pos]] == BOOM)
                        isZero = false;
                        
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

int main(void)
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

    // 테스트용 출력코드
    test_print();
}