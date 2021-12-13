#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int scores[3][3]= {{100,100,100},{50,60,80},{10,20,99}};
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for (int j=0;j<3;j++)
        {
            sum+=scores[i][j];
        }
        cout<<sum<<endl;
    }
}