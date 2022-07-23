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
#include <list>
using namespace std;

int main(int argc, char **argv)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T = 10;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    freopen("input.txt", "r", stdin);
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N; //암호 원문의 길이
        cin >> N;
        list<int> Acode; //암호 원문 리스트
        for (int N_count = 0; N_count < N; N_count++)
        {
            int temp;
            cin >> temp;
            Acode.push_back(temp); //암호 원문 생성
        }

        int M; //명령어의 갯수
        cin >> M;
        int order_count = 0;
        while (order_count != M)
        {
            char function;
            int x, y, s;
            cin >> function;
            if (function == 'I')
            {
                cin >> x >> y;
                order_count += 1; // 명령어 개수 count
                list<int>::iterator iter = Acode.begin();
                for (int iter_count = 0; iter_count < x; iter_count++) // x만큼 iter 이동
                {
                    ++iter;
                }
                for (int insert_count = 0; insert_count < y; insert_count++) // y만큼 새로운 수 받기
                {
                    cin >> s;
                    Acode.insert(iter, s); // 새로운 암호문 추간
                }
            }
            else if (function == 'D')
            {
                cin >> x >> y;
                order_count += 1;
                list<int>::iterator iter = Acode.begin();
                for (int iter_count = 0; iter_count < x; iter_count++) // x만큼 iter 이동
                {
                    ++iter;
                }
                for (int erase_count = 0; erase_count < y; erase_count++) // y만큼 삭제
                {
                    iter = Acode.erase(iter);
                }
            }
            else if (function == 'A')
            {
                cin >> y;
                order_count += 1;
                for (int append_count = 0; append_count < y; append_count++)
                {
                    cin >> s;
                    Acode.push_back(s); // 맨 뒤에 y개 만큼 암호 추가하기
                }
            }
        }

        //freopen("output.txt", "w", stdout);
        list<int>::iterator last_iter = Acode.begin();
        last_iter = Acode.begin();
        cout << "#" << test_case << " ";
        for (int print_count = 0; print_count < 10; print_count++)
        {
            cout << *last_iter << " ";
            ++last_iter;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}