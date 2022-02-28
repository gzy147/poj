#include"iostream"
#include"string"
#include"vector"
#include"map"
using namespace std;
int main()
{
    int num;
    map<string,int>Month_List;
    Month_List["pop"]=1;Month_List["no"]=2;Month_List["zip"]=3;Month_List["zotz"]=4;Month_List["tzec"]=5;Month_List["xul"]=6;
    Month_List["yoxkin"]=7;Month_List["mol"]=8;Month_List["chen"]=9;Month_List["yax"]=10;Month_List["zac"]=11;Month_List["ceh"]=12;
    Month_List["mac"]=13;Month_List["kankin"]=14;Month_List["muan"]=15;Month_List["pax"]=16;Month_List["koyab"]=17;Month_List["cumhu"]=18;
    Month_List["uayet"]=19;
    vector<string> Day_List;
    Day_List.push_back("imix");Day_List.push_back("ik");Day_List.push_back("akbal");Day_List.push_back("kan");
    Day_List.push_back("chicchan");Day_List.push_back("cimi");Day_List.push_back("manik");Day_List.push_back("lamat");
    Day_List.push_back("muluk");Day_List.push_back("ok");Day_List.push_back("chuen");Day_List.push_back("eb");Day_List.push_back("ben");
    Day_List.push_back("ix");Day_List.push_back("mem");Day_List.push_back("cib");Day_List.push_back("caban");Day_List.push_back("eznab");
    Day_List.push_back("canac");Day_List.push_back("ahau");
    cin>>num;
    cout<<num<<'\n';
    int i;
    int date;
    int year;
    string month;
    string point;
    int time;
    for(i=0;i<num;i++)
    {
        cin>>date>>point>>month>>year;
        int _month=Month_List[month];
        time=year*365+(_month-1)*20+date+1;
        int _year=(time-1)/260;
        int _date=((time-1)%260+1)%13+(((time-1)%260+1)%13==0)*13;
        cout<<_date<<" "<<Day_List[((time-1)%260)%20]<<' '<<_year<<'\n';
    }
    return 0;
}