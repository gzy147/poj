#include"iostream"
#include"map"
#include"vector"
#include"string"
using namespace std;
int main()
{
    int length,num;
    cin>>length>>num;
    map<int,vector<string>> Dna_List;
    int i,j,k,sortedness;
    string dna;
    for(i=0;i<num;i++)
    {
        cin>>dna;
        sortedness=0;
        for(j=0;j<length-1;j++)
        {
            for(k=j+1;k<length;k++)
            {
                if(dna[j]>dna[k])
                {
                    sortedness++;
                }
            }
        }
        Dna_List[sortedness].push_back(dna);
    }
    map<int,vector<string>>::iterator point,end;
    end=Dna_List.end();
    int size;
    for(point=Dna_List.begin();point!=end;point++)
    {
        size=point->second.size();
        for(i=0;i<size;i++)
        {
            cout<<point->second[i]<<'\n';
        }
    }
    return 0;
}