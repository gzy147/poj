//水题。核心：a[i]为数列，表示第i次取出的编号，可以由数学归纳法得到递推公式以大大简化计算。然后直接遍历试就行，试完打表下次直接检索，这样不会超时。反正就13个数。
#include<iostream>
using namespace std;
int ans[14]={0};
int main()
{
    int k,m;
    int i=1;
    int a[14];
    a[0]=1;
    while(cin>>k&&k!=0)
    {
        if(ans[k-1]==0)
        {
            m=k+1;
            while(i<=k)
        {
            for(i=1;i<=k;i++)
            {
                a[i]=(a[i-1]+m-2)%(2*k-i+1)+1;
                if(a[i]<=k)
                {
                    m++;
                    break;
                }
            }
        }
        ans[k-1]=m;
        }
        else{m=ans[k-1];}
        cout<<m<<endl;
    }
    return 0;
}