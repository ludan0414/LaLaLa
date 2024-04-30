#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using std::map,std::string,std::vector,std::multimap,std::make_pair,std::pair;
map<string,int> NameToId;//把垃圾的名字转成id
map<int,int> GarbageidToTypeid[4];//把垃圾的id转成城市里面垃圾种类的id
map<int,string> TypeidToTypename[4];//把城市里面垃圾种类的id转换成字符串
int NameCount;
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
    FILE *fp=fopen("garbage.csv","r");
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