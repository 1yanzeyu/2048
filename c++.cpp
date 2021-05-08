#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include<cmath>
#include<string>
#include<fstream>
#include"head.h"
#define random(x) (rand()%x)
using namespace std;
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//创建句柄变量并实例化句柄
void cunchu()
{
    char s[20];
    strcpy(s,ipt.zhanghao);
    strcat(s,".txt");
    ofstream file(s,ios_base::out);//打开一个以账户账号为文件名的文件
    file.write(reinterpret_cast<char*>(&ipt),sizeof(ipt));//将操作对象作为账户信息存入该文件，该文件作为该账户信息存放的文件
    file.close();
}
void k(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        cout<<' ';
    }
}//输出特定的空格
void rule()

{
    cout<<"\n\n";
    int i;
    cout << "2048游戏共有16个格子，初始时初始数字由2或者4构成。" << endl;

    cout << "1、控制方向键，所有格子会向那个方向运动。" << endl;

    cout << "2、相同数字的两个格子，相撞时数字会相加。" << endl;

    cout << "3、每次滑动时，空白处会随机刷新出一个数字的格子。" << endl;

    cout << "4、当界面不可运动时（当界面全部被数字填满时），游戏结束。" << endl;

    cout << endl;
    cout << "返回初始界面请输入1！" <<endl;//输出各项规则
    cin >> i;
    if(i==1)
    {
        system("cls");
        start();
    }

    //输入1即可返回主菜单
    else
    {
        system("cls");
        rule();
        cout<<"请按要求输入"<<endl;
    }//输入错误数据则再次输入
}
void start()
{
    int i;

    cout<<"\n\n";
    cout <<"请输入您的要求： "<< endl ;

    cout << "1.开始游戏 " << endl;
    cout << "2.游戏规则" << endl;
    cout << "3.历史排行榜" <<endl;
    cout << "4.商店 " << endl;
    cout << "5.退出当前账号 " << endl;//展示主菜单
    cin >> i;
    system("cls");
    if(i==2)rule();//输入2显示规则
    if(i==4)
    {

        ipt.display();//商店道具展示与购买
    }
    if(i==3)
    {
        cout<<endl<<"您的历史最高分为："<<ipt.r1<<endl<<endl;
        cout<<"请按任意键退出"<<endl;//展示最后高分
        char c;
        cin>>c;
        system("cls");
        start();//返回
    }
    if(i==1)
    {
        ipt.begin();//开始游戏
    }
    if(i==5)
    {
        cunchu();//存储账户信息
        ipt=Arry();//将操作对象与当前账户脱离
        welcome();
    }//退出当前账号
}
void denglu()
{
    cout<<"请输入账号："<<endl;
    char s[20];//输入账号
    cin>>s;
    strcat(s,".txt");
    ifstream file(s,ios_base::in);//打开以该账号为文件名的文件
    if (file)
    {
        file.read(reinterpret_cast<char*>(&ipt),sizeof(ipt));
        string s1;
        cout<<"请输入密码"<<endl;
        cin>>s1;
        if(s1==ipt.mima)
        {
            system("cls");
            cout<<"登录成功"<<endl;
            start();
        }//密码正确，登录成功，进入主菜单
        else
        {
            cout<<"密码错误，请重新登录"<<endl;
            denglu();
        }
    }//密码错误，从新登陆
    else
    {
        cout<<"账号有误"<<endl;
        denglu();
    }//文件无法打开，说明文件不存在即账号不存在
    file.close();
}
void zhuce()
{
    cout<<"请输入注册的账号"<<endl;
    cin>>ipt.zhanghao;
    cout<<"请输入注册的密码"<<endl;
    cin>>ipt.mima;//输入注册的账号
    char filename[20];
    strcpy(filename,ipt.zhanghao);
    strcat(filename,".txt");
    ofstream out(filename,ios_base::out);//建立一个以该账号为文件名的文件并打开

    out.write(reinterpret_cast<char*>(&ipt),sizeof(ipt));
    cout<<"注册成功，即将为您自动登录";
    Sleep(3000);
    system("cls");
    start();//注册成功，三秒后进入主菜单
    out.close();

}
void welcome()
{
    cout<<endl<<"欢迎来到2048，请选择："<<endl<<endl;
    cout<<"1.登录"<<endl;
    cout<<"2.注册"<<endl;
    int i;
    cin>>i;
    if(i==1)denglu();//输入1可以登录
    if(i==2)zhuce();//输入2可以注册
}
void Store::back1()
{
    system("cls");
    start();
}//返回主菜单
void Store::display()
{
    k(51);
    cout<<"欢迎来到店铺"<<endl;
    k(47);
    cout<<"welcome to the store";
    k(4);
    cout<<"我的金币:"<<money<<endl<<endl;
    int i;
    for(i=0;i<7;i++)
    {
        k(45);
        cout<<i+1<<"：  "<<pow(2,i+6)<<"开局  现有个数";
        cout<<rr[i]<<"  价格"<<pow(2,i+1)<<"金币"<<endl;
    }//循环输出各种开局道具的个数
    k(45);
    cout<<"8:   撤销道具  现有个数";
    cout<<r<<"  价格"<<3<<"金币";//输出撤销道具的个数

    cout<<endl;
    k(47);
    cout<<"购买请按道具前的数字"<<endl;
    k(47);
    cout<<"退出请按0"<<endl;

    cin>>i;//选择购买的道具
    char c;
    if (i==0)back1();
    if(i>=1&&i<=7)
    {
        k(45);
        cout<<"是否购买"<<pow(2,i+5)<<"开局?"<<endl;
        k(45);
        cout<<"确认(y),取消(n)"<<endl;
        c=getch();//确定是否购买该道具
        if(c=='y')
        {
            int ii;
            k(45);
            cout<<"请输入购买个数";
            cin>>ii;
            if(money<ii*pow(2,i))
            {
                k(45);

                cout<<"金币不足"<<endl;//金币不足

            }
            else
            {
            money-=ii*pow(2,i);
            rr[i-1]+=ii;
            k(45);
            cout<<"购买成功"<<endl;
            }//购买成功
        }
        Sleep(1500);
        system("cls");
        display();
    }
    if(i==8)//购买撤销道具
    {
        k(45);
        cout<<"是否购买"<<"撤销道具？"<<endl;
        k(45);
        cout<<"确认(y),取消(n)"<<endl;
        c=getch();
        if(c=='y')
        {
            int ii;
            k(45);
            cout<<"请输入购买个数";
            cin>>ii;
            if(money<ii*3)
            {
                k(45);

                cout<<"金币不足"<<endl;

            }
            else
            {
            r=r+ii;
            money-=ii*3;
            k(45);
            cout<<"购买成功"<<endl;
            }
        }
        Sleep(1500);
        system("cls");
        display();
    }
    cunchu();//将账户信息存储
}

void Arry::show()
{
    int i,j;
    system("cls");
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);//设置字体颜色
    cout<<setw(45)<<"Welcome to 2048"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<setw(50)<<"|-----------------------|"<<endl;//制作4*4表格
    for(i=0;i<=3;i++)
    {
        cout<<setw(24)<<" ";
        for(j=0;j<=3;j++)
        {

         switch(a[i][j])//使数组中不同数字呈现不同颜色
         {
             case 0:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|"<<setw(4)<<" ";break;
             case 2:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
                    cout<<setw(4)<<a[i][j];break;
             case 4:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
                    cout<<setw(4)<<a[i][j];break;
             case 8:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
                    cout<<setw(4)<<a[i][j];break;
             case 16:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                    cout<<setw(4)<<a[i][j];break;
             case 32:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(4)<<a[i][j];break;
             case 64:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<setw(4)<<a[i][j];break;
             case 128:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN);
                    cout<<setw(4)<<a[i][j];break;
             case 256:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED);
                    cout<<setw(4)<<a[i][j];break;
             case 512:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED);
                    cout<<setw(4)<<a[i][j];break;
             case 1024:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<setw(4)<<a[i][j];break;
             case 2048:SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(2)<<"|";
                    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<setw(4)<<a[i][j];break;
         }



         if(j==3)//制作4*4表格
         {
             SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
             cout<<setw(2)<<"|"<<endl;
             cout<<setw(50)<<"|-----------------------|"<<endl;
         }
        }
    }
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
    cout<<setw(42)<<"你的得分：";
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<score<<endl;//显示最终得分
    cout<<setw(50)<<"c.撤销(剩余："<<r<<')'<<endl;//显示剩余道具数目
    cout<<setw(50)<<"0.结束游戏"<<endl;
}
void Arry::cancel()//撤销操作
{
    //system("cls");
    cout<<endl;
    k(26);
    cout<<"确定花费一个撤销道具吗？"<<endl;
    k(29);
    cout<<"确定(y)，取消(n)"<<endl;//
    char c;
    cin>>c;
    system("cls");
    if(c=='y'&&r>0)//确定撤销且道具充足
    {

       int i,j;
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
            a[i][j]=bb[i][j];
           }
        }//将操作前的二维数组赋给当前操作的二维数组
        r--;//撤销道具减少

    show();
    }
    else if(c=='n') show();//取消撤销操作
    else//道具不足
    {
        cout<<setw(50)<<"撤销道具不足"<<endl;
        Sleep(1000);
        show();
    }
}
void Arry::gameOver()
{
    if(score>r1)
    {
        r1=score;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<endl<<endl<<setw(43)<<"**游戏结束，新纪录";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<r1;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<"分**"<<endl<<setw(43)<<"金币+";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<r1/800;
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
        r1=score;//更新纪录
        money=money+r1/800;//金币数量增加
    }
    else
    {   SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<endl<<endl<<setw(37)<<"**游戏结束，当前得分";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<score;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<"分**"<<endl<<setw(37)<<"金币+";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<score/800;
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
        money=score/800+money;//金币数量增加
    }
    cunchu();//存储账户信息
}
int Arry::test()
{
    int flag=0;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                flag=1;
                break;
            }
        }
    }//存在0，flag=1
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==a[i][j+1])
            {
                flag=1;
            }
            if(a[j][i]==a[j+1][i])
            {
                flag=1;
            }
        }
    }//每行或者每列存在相邻且相等的数,flag=1
    return flag;
}

void Arry::begin0()
{
    score=0;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=0;
        }
    }//以全零数组开局
    srand( (unsigned)time( NULL ) );//随机产生一个数值
    a[random(4)][random(4)]=2;
    show();//输出数组
}
void Arry::begin1()//以特定数组开局
{
    score=350;
    int a1[4][4]={ {4,0,0,0},{8,4,0,0},{16,8,4,0},{64,32,16,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin2()//以特定数组开局
{
    score=900;
    int a1[4][4]={ {8,0,0,0},{16,4,0,0},{32,8,4},{128,64,32,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin3()//以特定数组开局
{
    score=1900;
    int a1[4][4]={ {4,0,0,0},{16,4},{64,16,4,0},{256,128,64,16}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin4()//以特定数组开局
{
    score=4500;
    int a1[4][4]={ {4,0,0,0},{8,4,0,0},{64,16,8},{512,256,64,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin5()//以特定数组开局
{
    score=9000;
    int a1[4][4]={ {4,0,0,0},{64,8,0,0},{128,16,8},{1024,256,64,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin6()//以特定数组开局
{
    score=18000;
    int a1[4][4]={ {4,0,0,0},{64,8,0,0},{128,16,8},{1024,256,64,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::begin7()//以特定数组开局
{
    score=36000;
    int a1[4][4]={{4,0,0,0},{64,8,0,0},{512,16,8},{2048,256,64,8}};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    show();
}
void Arry::operate()//游戏各种操作
    {

        char ch;
        ch=getch();//输入操作
        switch(ch)
        {
        case (char)75://向左
            moveLeft();
            if(!test())
            {
                gameOver();
                break;
            }//游戏结束
            else Arry::operate();//递归，继续操作
            break;
        case (char)72:
            moveUp();//向上
            if(!test())
            {
                gameOver();
                break;
            }//游戏结束
            else Arry::operate();//递归，继续操作
            break;
        case (char)77:
            moveRight();
            if(!test())
            {
                gameOver();
                break;
            }//游戏结束
            else Arry::operate();//递归，继续操作
            break;
        case (char)80:
            moveDown();
            if(!test())

            {
                gameOver();
                break;
            }//游戏结束
            else Arry::operate();//递归，继续操作
            break;

        case 'c':
            cancel();//撤销操作
            operate();//递归继续操作
            break;

        case '0'://结束游戏
            gameOver();//游戏结束
            cout<<endl;
            cout<<setw(50)<<"按任意键返回主菜单";
            char c;
            cin>>c;
            system("cls");
            start();
        default:
            Arry::operate();
            break;
        }
    }
void Arry::moveDown()//向下
{
        int aa[4][4];//定义一个二维数组

        int i=0;
        int j=0;//两个计数器
        int k=3;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                bb[i][j]=a[i][j];
            }
        }//将a[4][4]赋给bb[4][4]
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                aa[i][j]=0;
            }
        }//归零

            k=3;
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    if(a[j][i]!=0)
                    {
                        aa[k][i]=a[j][i];
                        k--;

                    }
                }
                k=3;
            }//将原数组中所有非零数按顺序向下移动，结果存于aa[4][4]中
                for(i=0;i<4;i++)
                {
                    for(j=3;j>0;j--)
                    {
                        if((aa[j][i]==aa[j-1][i])&&(aa[j][i]!=0))
                        {
                             aa[j][i]=aa[j][i]*2;
                             aa[j-1][i]=0;
                             j--;
                             score+=aa[j+1][i];
                        }
                    }
                }//合并相邻且相等的非零数字，一个变为0，一个变为2倍
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }//将aa数组赋给a数组
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       aa[i][j]=0;
                    }
                }
                k=3;

                for(i=0;i<4;i++)
                {
                    for(j=3;j>=0;j--)
                    {
                        if(a[j][i]!=0)
                        {
                           aa[k][i]=a[j][i];
                           k--;

                        }
                    }
                    k=3;
                }//假若有数字合并，则产生新的0，重复之前的步骤，使得非零数字按顺序移到最下方
                int flag=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(bb[i][j]!=aa[i][j])
                        {
                            flag=1;
                            break;
                        }
                    }
                }//加入上述移动步骤发生，即数字发生过合并，即bb数组与aa数组，flag=1，执行下面步骤
    if(flag==1)
    {
            int rand1=random(5);
            if(rand1==4)rand1=4;
            else rand1=2;
            int rand2,rand3;
            do
            {
               rand2=random(4);
               rand3=random(4);
               if(aa[rand2][rand3]==0)

               {
                   aa[rand2][rand3]=rand1;
                   break;
               }
            }while(1);
            for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
            system("cls");
            show();//随即在数字为0的地方产生2或4
    }
}
void Arry::moveRight()//原理同moveDown()，只是方向改变
{
        int aa[4][4];//定义一个新数组
        int i=0;
        int j=0;
        int k=3;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                bb[i][j]=a[i][j];
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                aa[i][j]=0;
            }
        }

            k=3;
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    if(a[i][j]!=0)
                    {
                        aa[i][k]=a[i][j];
                        k--;

                    }
                }
                k=3;
            }
                for(i=0;i<4;i++)
                {
                    for(j=3;j>0;j--)
                    {
                        if((aa[i][j]==aa[i][j-1])&&(aa[i][j]!=0))
                        {
                             aa[i][j]=aa[i][j]*2;
                             aa[i][j-1]=0;

                             j--;
                             score+=aa[i][j+1];
                        }
                    }

                }

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       aa[i][j]=0;
                    }
                }
                k=3;
                for(i=0;i<4;i++)
                {
                    for(j=3;j>=0;j--)
                    {
                        if(a[i][j]!=0)
                        {
                           aa[i][k]=a[i][j];
                           k--;

                        }
                    }
                    k=3;
                }
                int flag=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(bb[i][j]!=aa[i][j])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
    if(flag==1)
    {
            int rand1=random(5);
            if(rand1==4)rand1=4;
            else rand1=2;
            int rand2,rand3;
            do
            {
               rand2=random(4);
               rand3=random(4);
               if(aa[rand2][rand3]==0)

               {
                   aa[rand2][rand3]=rand1;
                   break;
               }
            }while(1);
            for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
            system("cls");
            show();
    }
}
void Arry::moveLeft()//原理同moveDown()，只是方向改变
    {
        int aa[4][4];
        int i=0;
        int j=0;
        int k=0;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                bb[i][j]=a[i][j];
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                aa[i][j]=0;
            }
        }

            k=0;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(a[i][j]!=0)
                    {
                        aa[i][k]=a[i][j];
                        k++;

                    }
                }
                k=0;
            }
                for(i=0;i<4;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if((aa[i][j]==aa[i][j+1])&&(aa[i][j]!=0))
                        {
                             aa[i][j]=aa[i][j]*2;
                             aa[i][j+1]=0;

                             j++;
                             score+=aa[i][j-1];
                        }
                    }

                }

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       aa[i][j]=0;
                    }
                }
                k=0;

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(a[i][j]!=0)
                        {
                           aa[i][k]=a[i][j];
                           k++;

                        }
                    }
                    k=0;
                }
                int flag=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(bb[i][j]!=aa[i][j])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
    if(flag==1)
    {
            int rand1=random(5);
            if(rand1==4)rand1=4;
            else rand1=2;
            int rand2,rand3;
            do
            {
               rand2=random(4);
               rand3=random(4);
               if(aa[rand2][rand3]==0)

               {
                   aa[rand2][rand3]=rand1;
                   break;
               }
            }while(1);
            for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
            system("cls");
            show();
    }

    }
void Arry::moveUp()//原理同moveDown()，只是方向改变
{
    int aa[4][4];
        int i=0;
        int j=0;
        int k=0;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                bb[i][j]=a[i][j];
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                aa[i][j]=0;
            }
        }

            k=0;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(a[j][i]!=0)
                    {
                        aa[k][i]=a[j][i];
                        k++;

                    }
                }
                k=0;
            }
                for(i=0;i<4;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if((aa[j][i]==aa[j+1][i])&&(aa[j][i]!=0))
                        {
                             aa[j][i]=aa[j][i]*2;
                             aa[j+1][i]=0;

                             j++;
                             score+=aa[j-1][i];
                        }
                    }

                }

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       aa[i][j]=0;
                    }
                }
                k=0;

                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(a[j][i]!=0)
                        {
                           aa[k][i]=a[j][i];
                           k++;

                        }
                    }
                    k=0;
                }
                int flag=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(bb[i][j]!=aa[i][j])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
    if(flag==1)
    {
            int rand1=random(5);
            if(rand1==4)rand1=4;
            else rand1=2;
            int rand2,rand3;
            do
            {
               rand2=random(4);
               rand3=random(4);
               if(aa[rand2][rand3]==0)

               {
                   aa[rand2][rand3]=rand1;
                   break;
               }
            }while(1);
            for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }
            system("cls");
            show();
    }
}
void Arry::begin()//选择开局道具
{
    cout<<"请选择开局道具，如不选择请按0"<<endl;
    int i;
    for(i=0;i<7;i++)
    {
        cout<<i+1<<"：  "<<pow(2,i+6)<<"开局  现有个数"<<rr[i]<<endl;
    }
    cin>>i;//选择开局道具
    system("cls");
    if(i==0)
    {
        begin0();
        operate();
    }//正常开局
    else if(i==1)
    {
        i--;//序号减一作为数组下标
        rr[i]=rr[i]-1;//道具减一
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }//选择此种开局
        else
        {
           begin1();
           operate();
        }//道具不足，正常开局
    }
    else if(i==2)//原理同i=1
    {
        i--;
        rr[i]=rr[i]-1;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");

            begin0();
            operate();
        }
        else
        {
           begin2();
           operate();
        }
    }
    else if(i==3)//原理同i=1
    {
        i--;
        rr[i]--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }
        else
        {
           begin3();
           operate();
        }
    }
    else if(i==4)//原理同i=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }
        else
        {
           begin4();
           operate();
        }
    }
    else if(i==5)//原理同i=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }
        else
        {
           begin5();
           operate();
        }
    }
    else if(i==6)//原理同i=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }
        else
        {
           begin6();
           operate();
        }
    }
    else if(i==7)//原理同i=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"该道具不足，即将为您开始正常模式";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }
        else
        {
           begin7();
           operate();
        }
    }
    else
    {
        system("cls");
        cout<<"请按要求输入"<<endl;
        begin();
    }
}


