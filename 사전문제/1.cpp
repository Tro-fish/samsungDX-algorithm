#include <iostream>
#include <algorithm>
using namespace std;

int Matrix[100][100]; // Total area
int Matrix_copy[100][100];
int MaxArea = 0; //# of max area
int result = 0;

void waterdeptChange(int N, int depth) // Reflects changes in water depth
{
    for (int i = 0; i < N; i++) // Initalize Matrix
    {
        for (int k = 0; k < N; k++)
        {
            if (Matrix[i][k] <= depth)
            {
                Matrix[i][k] = -1;
            }
        }
    }
}

void DFS(int N, int row, int col, int count)
{
    // When first entered
    if (count == 1)
        MaxArea += 1;
    Matrix_copy[row][col] = -1; // Check visited
    // Top check
    if (row - 1 >= 0 && Matrix_copy[row - 1][col] != -1)
    {
        DFS(N, row - 1, col, 0);
    }
    // Bottom check
    if (row + 1 < N && Matrix_copy[row + 1][col] != -1)
    {
        DFS(N, row + 1, col, 0);
    }
    // Right check
    if (col + 1 < N && Matrix_copy[row][col + 1] != -1)
    {
        DFS(N, row, col + 1, 0);
    }
    // Left check
    if (col - 1 >= 0 && Matrix_copy[row][col - 1] != -1)
    {
        DFS(N, row, col - 1, 0);
    }
}

int main(int argc, char **argv)
{
    // Boost cin & cout
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
    //freopen("sample_input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N; // The length of a side
        cin >> N;
        int MaxHeight = 0;
        for (int i = 0; i < N; i++) // Initalize Matrix
        {
            for (int k = 0; k < N; k++)
            {
                int temp;
                cin >> temp;
                if (temp > MaxHeight)
                    MaxHeight = temp;
                Matrix[i][k] = temp;
            }
        }

        for (int depth = 0; depth <= MaxHeight; depth++)
        {
            waterdeptChange(N, depth);
            copy(&Matrix[0][0], &Matrix[0][0] + 100 * 100, &Matrix_copy[0][0]);
            for (int row = 0; row < N; row++)
            {
                for (int col = 0; col < N; col++)
                {
                    if (Matrix_copy[row][col] != -1)
                    {
                        DFS(N, row, col, 1);
                    }
                }
            }
            if (result < MaxArea)
                result = MaxArea;
            MaxArea = 0;
        }

        cout << "#" << test_case << " " << result << endl;
        result = 0;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}