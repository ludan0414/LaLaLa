#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using std::map,std::string,std::vector,std::multimap,std::make_pair,std::pair;
map<string,int> NameToId;//把垃圾的名字转成id
map<int,int> GarbageidToTypeid[4];//把垃圾的id转成城市里面垃圾种类的id
map<int,string> TypeidToTypename[4];//把城市里面垃圾种类的id转换成字符串
int NameCount,begincustom;
//北京城市代码1，上海城市代码2，广州城市代码3
/*
北京可回收垃圾1，有害垃圾2，厨余垃圾3，其它垃圾4
上海可回收物1，有害垃圾2，湿垃圾3，干垃圾4
广州可回收物1，有害垃圾2，餐厨垃圾3，其他垃圾4
*/
void work(){
    TypeidToTypename[1][1]="可回收垃圾";
    TypeidToTypename[1][3]="厨余垃圾";
    TypeidToTypename[1][2]="有害垃圾";
    TypeidToTypename[1][4]="其它垃圾";
    TypeidToTypename[2][1]="可回收物";
    TypeidToTypename[2][3]="湿垃圾";
    TypeidToTypename[2][2]="有害垃圾";
    TypeidToTypename[2][4]="干垃圾";
    TypeidToTypename[3][1]="可回收物";
    TypeidToTypename[3][3]="餐厨垃圾";
    TypeidToTypename[3][2]="有害垃圾";
    TypeidToTypename[3][4]="其它垃圾";
    FILE *fp=fopen("D:\\qt\\LaLaLa\\projectdemo\\garbage.csv","r");
    char line[2000];
    char name[200];
    memset(name,0,sizeof(name));
    int sort=0,ptr=0;;
    while (fgets(line,2000,fp)){
        while (line[ptr]!=','){
            name[ptr]=line[ptr];
            ptr++;
        }
        ptr++;
        while (line[ptr]!='\n'){
            sort=sort*10+line[ptr]-'0';
            ptr++;
        }
        //printf("%s,%d\n",name,sort);
        sort%=16;//不考虑大件垃圾
        int thisid;
        if (!NameToId.count(name)){
            NameToId[name]=++NameCount;
            thisid=NameCount;
        }
        else    thisid=NameToId[name];
        if (sort&(1<<0)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort));
        }
        if (sort&(1<<1)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort));
        }
        if (sort&(1<<2)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort));
        }
        if (sort&(1<<3)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort));
        }
        memset(name,0,sizeof(name));
        ptr=sort=0;
    }
    begincustom=NameCount+1;
    fclose(fp);
}
void test(){
    char name[200];
    while (scanf("%s",name)!=EOF){
        int id=NameToId[name];
        int sort;
        sort=GarbageidToTypeid[1][id];
        printf("%s在北京市应该被分类为:",name);
        if (sort&1)   printf(" %s",TypeidToTypename[1][1].c_str());
        if (sort&2)   printf(" %s",TypeidToTypename[1][2].c_str());
        if (sort&4)   printf(" %s",TypeidToTypename[1][3].c_str());
        if (sort&8)   printf(" %s",TypeidToTypename[1][4].c_str());
        printf("\n");
        sort=GarbageidToTypeid[2][id];
        printf("%s在上海市应该被分类为:",name);
        if (sort&1)   printf(" %s",TypeidToTypename[2][1].c_str());
        if (sort&2)   printf(" %s",TypeidToTypename[2][2].c_str());
        if (sort&4)   printf(" %s",TypeidToTypename[2][3].c_str());
        if (sort&8)   printf(" %s",TypeidToTypename[2][4].c_str());
        printf("\n");
        sort=GarbageidToTypeid[3][id];
        printf("%s在广州市应该被分类为:",name);
        if (sort&1)   printf(" %s",TypeidToTypename[2][1].c_str());
        if (sort&2)   printf(" %s",TypeidToTypename[2][2].c_str());
        if (sort&4)   printf(" %s",TypeidToTypename[2][3].c_str());
        if (sort&8)   printf(" %s",TypeidToTypename[2][4].c_str());
        printf("\n");
        memset(name,0,sizeof(name));
    }
}
void search(){
    printf("请输入你想选择的城市：\n1. 北京 2.上海 3.广州\n");
    int city;
    while (1){
        scanf("%d",&city);
        if (city<=0||city>3){
            printf("输入非法，请重新输入。\n");
        }
        else    break;
    }
    bool keeptrying=1;//是否要继续搜索
    while (keeptrying){
        printf("请输入需要搜索的垃圾的名字，输入0退出\n");
        char name[200];
        memset(name,0,sizeof(name));
        scanf("%s",name);
        if (strcmp(name,"0")==0)    break;
        vector<pair<string,int> > gotid;
        for (auto i:NameToId){
            string strname=name;
            if (i.first.find(strname)!=string::npos){
                gotid.push_back(i);
            }
        }
        if (gotid.empty()){
            printf("未找到垃圾 %s ，请尝试自己手动添加。\n",name);
        }
        for (auto i:gotid){
            printf("垃圾 %s 在%s应该被分类为：\n",i.first.c_str(),(city==1)?("北京"):((city==2)?"上海":"广州"));
            int id=GarbageidToTypeid[city][i.second];
            if (id&1)   printf("%s ",TypeidToTypename[city][1].c_str());
            if (id&2)   printf("%s ",TypeidToTypename[city][2].c_str());
            if (id&4)   printf("%s ",TypeidToTypename[city][3].c_str());
            if (id&8)   printf("%s ",TypeidToTypename[city][4].c_str());
            printf("\n");
        }
    }
}
vector<string> findgarbage(string s,int cityid){
    vector<string> ret;
    vector<pair<string,int> > gotid;
    for (auto i:NameToId){
        string strname=s;
        if (i.first.find(strname)!=string::npos){
            gotid.push_back(i);
        }
    }
    for (auto i:gotid){
        int id=GarbageidToTypeid[cityid][i.second];
        string tmp="垃圾 "+i.first+(id>16?"（自定义）":"")+" 在"+((cityid==1)?("北京"):((cityid==2)?"上海":"广州"))+"应该被分类为：";
        if (id&1)   ret.push_back(tmp+TypeidToTypename[cityid][1]+" ");
        if (id&2)   ret.push_back(tmp+TypeidToTypename[cityid][2]+" ");
        if (id&4)   ret.push_back(tmp+TypeidToTypename[cityid][3]+" ");
        if (id&8)   ret.push_back(tmp+TypeidToTypename[cityid][4]+" ");
    }
    return ret;
}
struct ret{
    int a;
    string b,c;//垃圾id，垃圾名字，种类名字
};
vector<ret> listcustom(int cityid){
    vector<ret> res;
    vector<pair<string,int> > gotid;
    for (auto i:NameToId){
        if (GarbageidToTypeid[cityid][i.second]>16){
            gotid.push_back(i);
        }
    }
    for (auto i:gotid){
        ret tmp;
        tmp.a=i.second;
        tmp.b=i.first;
        int id=GarbageidToTypeid[cityid][i.second];
        if (id&1)   tmp.c=TypeidToTypename[cityid][1];
        if (id&2)   tmp.c=TypeidToTypename[cityid][2];
        if (id&4)   tmp.c=TypeidToTypename[cityid][3];
        if (id&8)   tmp.c=TypeidToTypename[cityid][4];
        res.push_back(tmp);
    }
    return res;
}
//书
void readcustomdic(){
    FILE *fp=fopen("customdic.csv","r");
    if (fp==NULL)   return;
    char line[2000];
    char name[200];
    memset(name,0,sizeof(name));
    int sort=0,ptr=0;;
    while (fgets(line,2000,fp)){
        while (line[ptr]!=','){
            name[ptr]=line[ptr];
            ptr++;
        }
        ptr++;
        while (line[ptr]!='\n'){
            sort=sort*10+line[ptr]-'0';
            ptr++;
        }
        //printf("%s,%d\n",name,sort);
        sort%=16;//不考虑大件垃圾
        int thisid;
        if (!NameToId.count(name)){
            NameToId[name]=++NameCount;
            thisid=NameCount;
        }
        else    thisid=NameToId[name];
        if (sort&(1<<0)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
        }
        if (sort&(1<<1)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
        }
        if (sort&(1<<2)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
        }
        if (sort&(1<<3)){
            GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
            GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
        }
        memset(name,0,sizeof(name));
        ptr=sort=0;
    }
    fclose(fp);
}
void writecustomdic(){
    FILE *fp=fopen("customdic.csv","w");
    for (auto &i:GarbageidToTypeid[1]){
        if (i.second>=16){//这个是我们自己添加进去的垃圾
            for (auto &j:NameToId){
                if (j.second==i.first){
                    fprintf(fp,"%s,%d\n",j.first.c_str(),i.second-16);
                }
            }
        }
    }
    fclose(fp);
}
void add(string name,int sort){
    int thisid;
    if (!NameToId.count(name)){
        NameToId[name]=++NameCount;
        thisid=NameCount;
    }
    else    return;
    if (sort&(1<<0)){
        GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
    }
    if (sort&(1<<1)){
        GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
    }
    if (sort&(1<<2)){
        GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
    }
    if (sort&(1<<3)){
        GarbageidToTypeid[1].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[2].insert(make_pair(thisid,sort+16));
        GarbageidToTypeid[3].insert(make_pair(thisid,sort+16));
    }
    std::cout<<name<<sort+16<<" "<<thisid<<true;
}
void changesort(int id,int sort){
    if (sort&(1<<0)){
        GarbageidToTypeid[1][id]=sort+16;
        GarbageidToTypeid[2][id]=sort+16;
        GarbageidToTypeid[3][id]=sort+16;
    }
    if (sort&(1<<1)){
        GarbageidToTypeid[1][id]=sort+16;
        GarbageidToTypeid[2][id]=sort+16;
        GarbageidToTypeid[3][id]=sort+16;
    }
    if (sort&(1<<2)){
        GarbageidToTypeid[1][id]=sort+16;
        GarbageidToTypeid[2][id]=sort+16;
        GarbageidToTypeid[3][id]=sort+16;
    }
    if (sort&(1<<3)){
        GarbageidToTypeid[1][id]=sort+16;
        GarbageidToTypeid[2][id]=sort+16;
        GarbageidToTypeid[3][id]=sort+16;
    }
}

void del(int id){
    for (auto i:NameToId){
        if (i.second==id){
            for (auto j:GarbageidToTypeid[1]){
                if (j.first==i.second){
                    GarbageidToTypeid[1].erase(j.first);
                    GarbageidToTypeid[2].erase(j.first);
                    GarbageidToTypeid[3].erase(j.first);
                    GarbageidToTypeid[4].erase(j.first);
                    break;
                }
            }
            NameToId.erase(i.first);
            return;
        }
    }
}


