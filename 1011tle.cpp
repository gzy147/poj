#include<iostream>
using namespace std;
int stick_min,sum,num,length;
int dfs_verify(int units[50],int x,int rest)//深搜2：验证搜索到的可能值
{
    int a,i;
    if(rest==length)//说明最后一根正好能凑出来，凑配完成，返回1成功
    {
        return 1;
    }
    for(i=1;i<num;i++)//i=1是因为最大的一根已经提前被取出并讨论了
    {
        if(units[i]!=0&&x+units[i]<length)//还没凑出来但还能往上加，继续迭代凑这根
        {
            a=units[i];
            units[i]=0;
            return dfs_verify(units,x+a,rest);
        }
        else if(x+units[i]==length)//凑出来了一根，就清掉，再凑下一根新的
        {
            a=units[i];
            units[i]=0;

            rest=rest-length;
            return dfs_verify(units,0,rest);
        }
    }
    return 0;//最开始的一层for循环完了还一直没有返回1。验证失败了。
}
void dfs(int units[50],int x)//深搜1：搜索树枝可能的长度。x为前面步骤凑配的时候叠加的长度。
{
    int a,i;
    for(i=1;i<num;i++)//i=1是因为最大的一根已经提前被取出并讨论了
    {
        if(units[i]!=0&&x+units[i]<stick_min&&x+units[i]<=sum/2)//对于已经被用过的单元，加和后大于总量一半的情况，以及加和后大于已有最优解的情况，不用讨论。不可能继续凑配出最优解
        {
            a=units[i];
            units[i]=0;
            if(sum%(x+a)==0)//可能是新的最优解。跳入验证函数。
            {
                length=x+a;//验证函数中要验证的值
                int rest=sum-length;
                int units_para[50]={0};
                int l;
                for(l=1;l<num;l++)
                {units_para[l]=units[l];}
                if(dfs_verify(units_para,0,rest)==1)//验证成功，得到新解
                {
                    stick_min=length;
                }
            }
            else
            {
                dfs(units,x+a);//不能整除，但还可以继续叠加凑配
            }
            units[i]=a;//复原数组
        }
    }
}
void bubble_sort(int units[50])//冒泡排序。从大往小凑，属于剪枝。因为小而碎的凑起来更麻烦。引用传参
{
    int i,c;
    int complete=0;
    while(complete==0)
    {
        complete=1;
        for(i=0;i<num-1;i++)
        {
            if(units[i]<units[i+1])
            {
                c=units[i];
                units[i]=units[i+1];
                units[i+1]=c;
                complete=0;
            }
        }
    }
}
int main()
{
    int i,a;
    int units[50]={0};
    while(cin>>num&&num!=0)
    {
        for(i=0;i<num;i++)
        {
            cin>>units[i];
            sum+=units[i];
        }
        stick_min=sum;
        bubble_sort(units);
        if(units[0]<sum/2)//sum/2是分水岭需要单独讨论。因为如果最大的大于总量的一半，则最多只有一根。
        {
            dfs(units,units[0]);//最大的那根不用清零。因为后面函数里的循环根本不会涉及这一根
        }
        else if(units[0]==sum/2)//等于总量的一半，则最多有两根
        {stick_min=sum/2;}
        cout<<stick_min<<endl;
        for(i=0;i<num;i++)//复原
        {units[i]=0;}
        sum=0;
    }
    return 0;
}