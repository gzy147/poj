#include<iostream>
using namespace std;

int num_cat,num_total,max_stamp,rep,exist,i,req;
int stamps[100];
int result[4];
void dfs(int result_temp[4],int j,int sum,int num)//核心算法深搜。参数为临时已加和邮票序列的下标（注意是下标），当前的面值和，当前加和的邮票个数
{
    int m=j;
    num++;
    for(m=j;m<=i;m++)//第二处剪枝：只从大往小加，避免重复值
    {
        if(sum+stamps[m]==req)//大于则直接无视。等于则讨论结果。小于则继续迭代下一层，迭代到四层为止。
        {
            exist=1;//结果存在判定
            result_temp[num-1]=m;
            int category=1;
            int n;
            for(n=0;n<num-1;n++)
            {
                if(result_temp[n]!=result_temp[n+1])
                {
                    category++;
                }
            }
            if(category>num_cat||
            (category==num_cat&&num<num_total)||
            (category==num_cat&&num==num_total&&stamps[result_temp[0]]>max_stamp))//三个评价指标。由主到次。如出现了新结果则取消之前的重复判定
            {
                num_cat=category;
                num_total=num;
                max_stamp=stamps[result_temp[0]];
                rep=0;
                int s;
                for(s=0;s<num_total;s++)
                {
                    result[s]=stamps[result_temp[s]];
                }
            }
            else if(category==num_cat&&num==num_total&&max_stamp==stamps[result_temp[0]])//出现与原来结果指标完全相同的结果，暂时判定为存在重复
            {
                rep=1;
            }
        }
        else if(sum+stamps[m]<req)//stamps[m]是第n++个数。如果n++已经到达了上限4，而sum加了stamps[m]还不如req大，那就不用试比stamps[m]更小的数了
        {
            if(num==4)
            {break;}
            else
            {
                result_temp[num-1]=m;
                dfs(result_temp,m,sum+stamps[m],num);
            }
        }
    }
}
int main()
{
    int j,stamp;
    while(cin>>stamp)//判断是否有新一轮的邮票输入。先输入一个邮票值。
    {
        for(i=0;;i++)
        {
        stamps[i]=stamp;
        cin>>stamp;//再输入后续值
        if(stamp==0)
        {
            break;
        }
        }
    int c;
    int comp=0;//排序完成的标志
    while(comp==0)//冒泡排序，从大到小，目的为剪枝。因为从小数开始搜索的话，初始搜索深度更大，因而试错成本更高。
        {
        comp=1;
        for(j=0;j<i;j++)
        {
            if(stamps[j]<stamps[j+1])
            {
                c=stamps[j];
                stamps[j]=stamps[j+1];
                stamps[j+1]=c;
                comp=0;//交换。若尚有需要交换的部分则完成标志改为0
            }
        }
        }
        cin>>req;//先输入一个顾客需求进行处理
        int s;
        int result_temp[4];
        result_temp[0]=result_temp[1]=result_temp[2]=result_temp[3]=-1;
        while(req!=0)//直到输入的顾客需求为0，则停止这一轮
        {
            num_cat=max_stamp=rep=exist=0;
            num_total=5;
            dfs(result_temp,0,0,0);
            if(exist==0)//不存在方案
            {cout<<req<<" ---- none"<<endl;}
            else if(rep==1)//存在两种及以上方案，三个评价维度全部相同
            {cout<<req<<" ("<<num_cat<<"): tie"<<endl;}
            else
            {
                cout<<req<<" ("<<num_cat<<"):";
                for(s=num_total-1;s>=0;s--)
                {
                    cout<<' '<<result[s];
                }
                cout<<'\n';
            }
            cin>>req;//每处理完一个，再输入并处理下一个
        }
    }
    return 0;
}