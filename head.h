
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<string>
using namespace std;
class Record
{
public:
    Record()//构造函数
    {
        r1=0;
        r=0;
        int i;
        for(i=0;i<7;i++)
        {
            rr[i]=0;
        }
    }//默认全为0
    int r1;//最高分
    int rr[7];//开局道具
    int r;//撤销道具
};
class Account:public Record
{
public:
    Account():Record()
    {

        money=100;
    }//构造函数，金币默认100
    int money;//金币数量
    char zhanghao[20];//账号
    string mima;//密码


};
class Store:public Account
{
public:
    void display();//商店展示，道具购买
    void back1();//返回主菜单
};
class Arry:public Store
{
private:
    int score;//游戏过程中的计分器
    int bb[4][4];
    int a[4][4];
public:
    void operate();//操作判定函数
    void begin();//开始游戏函数
    void begin0();
    void begin1();
    void begin2();
    void begin3();
    void begin4();
    void begin5();
    void begin6();
    void begin7();//多种开局
    void show();//展示二维数组
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();//四种方向操作
    int test();//检测游戏是否可以继续进行

    void gameOver();//游戏结束
    void cancel();//撤销操作
};
Arry ipt;//操作直接作用的对象
void start();//主菜单函数
void denglu();//登录
void zhuce();//注册
void welcome();//欢迎界面
void rule();//游戏规则
void k(int x);//输出空格
void cunchu();//保存账户此时的信息
#endif // HEAD_H_INCLUDED
