#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i;
    vector<float> length;
    float j;
    for(;;)
    {
        cin>>j;
        if(!j)
        {
            break;
        }
        length.push_back(j);
    }
    for(i=0;i<length.size();i++)
    {
        int p;
    float k=0;
    for(p=2;;p++)
    {
        k+=float(1)/p;
        if(k>length[i])
        {
            cout<<p-1<<" card(s)"<<'\n';
            break;
        }
    }
    }
    return 0;
}