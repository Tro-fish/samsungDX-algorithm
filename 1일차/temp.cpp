#include<iostream>

using namespace std;

string str;
int len;
int** cache;

int c2i(int i) {
    char c = str[i];

    if (c == 'A') return 8;
    if (c == 'B') return 4;
    if (c == 'C') return 2;
    return 1;
}

int solve(int i, int key) {
    if (cache[i][key] > 0) return cache[i][key];
    if (i >= len) return 0;

    int must = c2i(i), result = 0;

    for (int j = 1; j <= 16; j++) {
        if ((must & j) > 0 && (key & j) > 0) {

            if (i == len - 1) result++;
            else result = (result + solve(i + 1, j)) % 1000000007;
        }
    }

    cache[i][key] = result;
    return result;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> str;
        len = str.size();
        cache = new int* [len + 1];
        for (int i = 0; i <= len; i++) {
            cache[i] = new int[16];
            for (int j = 0; j < 16; j++) cache[i][j] = -1;
        }

        printf("#%d %d\n", test_case, solve(0, 8));
    }

    return 0;
}