#include"iostream"
using namespace std;
int main()
{
    int p,e,i,d,j,day;
    for(j=1;;j++)
    {
        cin>>p>>e>>i>>d;
        if(p!=-1)
        {
            if((p-d+46)%23==0&&(e-d+56)%28==0&&(i-d+66)%33==0)
            {
                cout<<"Case "<<j<<": the next triple peak occurs in 21252 days."<<'\n';
            }
            else
            {
            p=(p-d+460)%23;
            e=(e-d+560)%28;
            i=(i-d+660)%33;
            int x,y,m;            
            for(x=0;(5*x)%23!=(p-e+46)%23;x++)
            {}
            for(y=0;(5*y)%28!=(e-i+56)%28;y++)
            {}
            for(m=0;(280*m)%(644)!=(x*28+e-(y*33+i)+1288)%644;m++)
            {}
            day=m*28*33+y*33+i;
            cout<<"Case "<<j<<": the next triple peak occurs in "<<day<<" days."<<'\n';
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}