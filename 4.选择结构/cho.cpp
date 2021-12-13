#include <iostream>
using namespace std;

int main()
{
    int score = 0;
    cin >> score ;
    switch (score)
    {
    case 10:
        cout << "classical" << endl;
        break;//勿忘break，否则后续分支仍执行
    case 1:
        cout << "bad" << endl;
        break;
    default:
         cout<<"hehe"<<endl;

    }
}