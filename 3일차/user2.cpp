#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool symbol_check(string str)
{
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check(string parent, string child)
{
    bool p = symbol_check(parent);
    bool c = symbol_check(child);
    if (p && c || !p && !c)
    {
        return true;
    }
    else
    {
        return false;
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
    freopen("input.txt", "r", stdin);
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= 10; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        bool result = true;
        int N;
        vector<int> two_child_node_index;
        vector<string> str_vec;
        str_vec.push_back("dummy");
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            string str;
            float level, left, right;
            cin >> level >> str;
            if (level == float(N) / 2) // 자식이 한개일 때
            {
                //cout<<"짝수 :"<<N<<endl;
                cin >> left;
                result = false; // 자식이 한개일 경우 식 성립안함
            }
            else if (level < float(N) / 2) // 자식이 2개 일 때
            {
                cin >> left >> right;
                if (!symbol_check(str)) // 부호가 아닐 경우 식 성립안함
                {
                    //cout<<"부호 아님 : "<<str<<endl;
                    result = false;
                }
            }
            str_vec.push_back(str);
        }

        for (int i = 1; i <= N; i++)
        {
            if ((i / 2) > 0)
            {
                //부모와 자식의 타입이 다르다면
                if (!check(str_vec[i],str_vec[i / 2]))
                {
                    //result = false;
                    //break;
                }
            }
        }

        if (result)
        {
            cout << "#" << test_case << " "
                 << "1" << endl;
        }
        else
        {
            cout << "#" << test_case << " "
                 << "0" << endl;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}