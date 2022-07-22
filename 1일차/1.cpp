#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
   int N;
   int count = 0;
   vector<int> v;
   cin >> N;
   int N_original = N;
   int N_copy = N;
   while(v.size() < 10)
   {
        while(N_copy>0)
        {
            auto it = find(v.begin(),v.end(),N_copy%10);
            if(it == v.end()) //찾지 못했을 경우
            {
                v.push_back(N_copy%10);
            }
            N_copy/=10;
        }
        N+=N_original;
        N_copy = N;
        count += 1;
   }
   cout<<count*N_original<<endl;
}