#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int two_plus_power(int N)
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            result += 1;
        }
        else
        {
            int temp_result = 1;
            int temp_i = i;
            while (temp_i > 0)
            {
                temp_result *= 2;
                temp_i--;
            }
            result += temp_result;
        }
    }
    return result;
}

int two_power(int N)
{
    int result = 1;
    while(N>0)
    {
        result *= 2;
        N--;
    }
    return result;
}

int main(void)
{
    int N, M;
    cin>>N>>M;
    int M_minus = M - two_plus_power(N);
    int N_power = two_power(N);
    if((M_power)%N_power == 0 )
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
}