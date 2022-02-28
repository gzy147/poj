#include"iostream"
#include"cmath"
using namespace std;
int main()
{
    int Point_Num;
    cin>>Point_Num;
    int i,year;
    double x,y;
    for(i=1;i<=Point_Num;i++)
    {
        cin>>x;
        cin>>y;
        int year=int(acos(-1)*(x*x+y*y)/100)+1;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<year<<'.'<<'\n';
    }
    cout<<"END OF OUTPUT.";
    return 0;
}