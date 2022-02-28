#include<iostream>
#include<map>
using namespace std;

void test(int a[3],int b)
{
    a[0]=1;
    b=3;
}
int main()
{
    int b[3]={0};
    int a=0;
    test(b,a);
    cout<<b[0]<<a;
    return 0;
}