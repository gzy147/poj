#include"iostream"
using namespace std;
int main()
{
    int i;
    float j;
    float sum=0;
    for(i=0;i<12;i++)
    {
        cin>>j;
        sum+=j;
    }
    cout<<'$';
    if(int(sum*1000/12)%10<5)
    {
        printf("%.2f",sum/12);
    }
    else
    {
        printf("%.2f",sum/12+0.005);
    }
    return 0;
}