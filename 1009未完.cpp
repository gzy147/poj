#include<iostream>

using namespace std;
int width;
int pixel_num[1100][2];
int main()
{
    int pixel,num,i;
    cin>>width;
    pixel_num[0][0]=pixel;
    pixel_num[0][1]=num;
    while(cin>>width&&width!=0)
    {
        for(i=1;;i++)
        {
            cin>>pixel>>num;
            if(pixel==0&&num==0)
            {break;}
            pixel_num[i][0]=pixel;
            pixel_num[i][1]=num+pixel_num[i-1][1];
        }
    }
    return 0;
}