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
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//�������������ʵ�������
void cunchu()
{
    char s[20];
    strcpy(s,ipt.zhanghao);
    strcat(s,".txt");
    ofstream file(s,ios_base::out);//��һ�����˻��˺�Ϊ�ļ������ļ�
    file.write(reinterpret_cast<char*>(&ipt),sizeof(ipt));//������������Ϊ�˻���Ϣ������ļ������ļ���Ϊ���˻���Ϣ��ŵ��ļ�
    file.close();
}
void k(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        cout<<' ';
    }
}//����ض��Ŀո�
void rule()

{
    cout<<"\n\n";
    int i;
    cout << "2048��Ϸ����16�����ӣ���ʼʱ��ʼ������2����4���ɡ�" << endl;

    cout << "1�����Ʒ���������и��ӻ����Ǹ������˶���" << endl;

    cout << "2����ͬ���ֵ��������ӣ���ײʱ���ֻ���ӡ�" << endl;

    cout << "3��ÿ�λ���ʱ���հ״������ˢ�³�һ�����ֵĸ��ӡ�" << endl;

    cout << "4�������治���˶�ʱ��������ȫ������������ʱ������Ϸ������" << endl;

    cout << endl;
    cout << "���س�ʼ����������1��" <<endl;//����������
    cin >> i;
    if(i==1)
    {
        system("cls");
        start();
    }

    //����1���ɷ������˵�
    else
    {
        system("cls");
        rule();
        cout<<"�밴Ҫ������"<<endl;
    }//��������������ٴ�����
}
void start()
{
    int i;

    cout<<"\n\n";
    cout <<"����������Ҫ�� "<< endl ;

    cout << "1.��ʼ��Ϸ " << endl;
    cout << "2.��Ϸ����" << endl;
    cout << "3.��ʷ���а�" <<endl;
    cout << "4.�̵� " << endl;
    cout << "5.�˳���ǰ�˺� " << endl;//չʾ���˵�
    cin >> i;
    system("cls");
    if(i==2)rule();//����2��ʾ����
    if(i==4)
    {

        ipt.display();//�̵����չʾ�빺��
    }
    if(i==3)
    {
        cout<<endl<<"������ʷ��߷�Ϊ��"<<ipt.r1<<endl<<endl;
        cout<<"�밴������˳�"<<endl;//չʾ���߷�
        char c;
        cin>>c;
        system("cls");
        start();//����
    }
    if(i==1)
    {
        ipt.begin();//��ʼ��Ϸ
    }
    if(i==5)
    {
        cunchu();//�洢�˻���Ϣ
        ipt=Arry();//�����������뵱ǰ�˻�����
        welcome();
    }//�˳���ǰ�˺�
}
void denglu()
{
    cout<<"�������˺ţ�"<<endl;
    char s[20];//�����˺�
    cin>>s;
    strcat(s,".txt");
    ifstream file(s,ios_base::in);//���Ը��˺�Ϊ�ļ������ļ�
    if (file)
    {
        file.read(reinterpret_cast<char*>(&ipt),sizeof(ipt));
        string s1;
        cout<<"����������"<<endl;
        cin>>s1;
        if(s1==ipt.mima)
        {
            system("cls");
            cout<<"��¼�ɹ�"<<endl;
            start();
        }//������ȷ����¼�ɹ����������˵�
        else
        {
            cout<<"������������µ�¼"<<endl;
            denglu();
        }
    }//������󣬴��µ�½
    else
    {
        cout<<"�˺�����"<<endl;
        denglu();
    }//�ļ��޷��򿪣�˵���ļ������ڼ��˺Ų�����
    file.close();
}
void zhuce()
{
    cout<<"������ע����˺�"<<endl;
    cin>>ipt.zhanghao;
    cout<<"������ע�������"<<endl;
    cin>>ipt.mima;//����ע����˺�
    char filename[20];
    strcpy(filename,ipt.zhanghao);
    strcat(filename,".txt");
    ofstream out(filename,ios_base::out);//����һ���Ը��˺�Ϊ�ļ������ļ�����

    out.write(reinterpret_cast<char*>(&ipt),sizeof(ipt));
    cout<<"ע��ɹ�������Ϊ���Զ���¼";
    Sleep(3000);
    system("cls");
    start();//ע��ɹ��������������˵�
    out.close();

}
void welcome()
{
    cout<<endl<<"��ӭ����2048����ѡ��"<<endl<<endl;
    cout<<"1.��¼"<<endl;
    cout<<"2.ע��"<<endl;
    int i;
    cin>>i;
    if(i==1)denglu();//����1���Ե�¼
    if(i==2)zhuce();//����2����ע��
}
void Store::back1()
{
    system("cls");
    start();
}//�������˵�
void Store::display()
{
    k(51);
    cout<<"��ӭ��������"<<endl;
    k(47);
    cout<<"welcome to the store";
    k(4);
    cout<<"�ҵĽ��:"<<money<<endl<<endl;
    int i;
    for(i=0;i<7;i++)
    {
        k(45);
        cout<<i+1<<"��  "<<pow(2,i+6)<<"����  ���и���";
        cout<<rr[i]<<"  �۸�"<<pow(2,i+1)<<"���"<<endl;
    }//ѭ��������ֿ��ֵ��ߵĸ���
    k(45);
    cout<<"8:   ��������  ���и���";
    cout<<r<<"  �۸�"<<3<<"���";//����������ߵĸ���

    cout<<endl;
    k(47);
    cout<<"�����밴����ǰ������"<<endl;
    k(47);
    cout<<"�˳��밴0"<<endl;

    cin>>i;//ѡ����ĵ���
    char c;
    if (i==0)back1();
    if(i>=1&&i<=7)
    {
        k(45);
        cout<<"�Ƿ���"<<pow(2,i+5)<<"����?"<<endl;
        k(45);
        cout<<"ȷ��(y),ȡ��(n)"<<endl;
        c=getch();//ȷ���Ƿ���õ���
        if(c=='y')
        {
            int ii;
            k(45);
            cout<<"�����빺�����";
            cin>>ii;
            if(money<ii*pow(2,i))
            {
                k(45);

                cout<<"��Ҳ���"<<endl;//��Ҳ���

            }
            else
            {
            money-=ii*pow(2,i);
            rr[i-1]+=ii;
            k(45);
            cout<<"����ɹ�"<<endl;
            }//����ɹ�
        }
        Sleep(1500);
        system("cls");
        display();
    }
    if(i==8)//����������
    {
        k(45);
        cout<<"�Ƿ���"<<"�������ߣ�"<<endl;
        k(45);
        cout<<"ȷ��(y),ȡ��(n)"<<endl;
        c=getch();
        if(c=='y')
        {
            int ii;
            k(45);
            cout<<"�����빺�����";
            cin>>ii;
            if(money<ii*3)
            {
                k(45);

                cout<<"��Ҳ���"<<endl;

            }
            else
            {
            r=r+ii;
            money-=ii*3;
            k(45);
            cout<<"����ɹ�"<<endl;
            }
        }
        Sleep(1500);
        system("cls");
        display();
    }
    cunchu();//���˻���Ϣ�洢
}

void Arry::show()
{
    int i,j;
    system("cls");
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);//����������ɫ
    cout<<setw(45)<<"Welcome to 2048"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<setw(50)<<"|-----------------------|"<<endl;//����4*4���
    for(i=0;i<=3;i++)
    {
        cout<<setw(24)<<" ";
        for(j=0;j<=3;j++)
        {

         switch(a[i][j])//ʹ�����в�ͬ���ֳ��ֲ�ͬ��ɫ
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



         if(j==3)//����4*4���
         {
             SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
             cout<<setw(2)<<"|"<<endl;
             cout<<setw(50)<<"|-----------------------|"<<endl;
         }
        }
    }
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
    cout<<setw(42)<<"��ĵ÷֣�";
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<score<<endl;//��ʾ���յ÷�
    cout<<setw(50)<<"c.����(ʣ�ࣺ"<<r<<')'<<endl;//��ʾʣ�������Ŀ
    cout<<setw(50)<<"0.������Ϸ"<<endl;
}
void Arry::cancel()//��������
{
    //system("cls");
    cout<<endl;
    k(26);
    cout<<"ȷ������һ������������"<<endl;
    k(29);
    cout<<"ȷ��(y)��ȡ��(n)"<<endl;//
    char c;
    cin>>c;
    system("cls");
    if(c=='y'&&r>0)//ȷ�������ҵ��߳���
    {

       int i,j;
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
            a[i][j]=bb[i][j];
           }
        }//������ǰ�Ķ�ά���鸳����ǰ�����Ķ�ά����
        r--;//�������߼���

    show();
    }
    else if(c=='n') show();//ȡ����������
    else//���߲���
    {
        cout<<setw(50)<<"�������߲���"<<endl;
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
        cout<<endl<<endl<<setw(43)<<"**��Ϸ�������¼�¼";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<r1;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<"��**"<<endl<<setw(43)<<"���+";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<r1/800;
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
        r1=score;//���¼�¼
        money=money+r1/800;//�����������
    }
    else
    {   SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<endl<<endl<<setw(37)<<"**��Ϸ��������ǰ�÷�";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<score;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED);
        cout<<"��**"<<endl<<setw(37)<<"���+";
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE);
        cout<<score/800;
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
        money=score/800+money;//�����������
    }
    cunchu();//�洢�˻���Ϣ
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
    }//����0��flag=1
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
    }//ÿ�л���ÿ�д�����������ȵ���,flag=1
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
    }//��ȫ�����鿪��
    srand( (unsigned)time( NULL ) );//�������һ����ֵ
    a[random(4)][random(4)]=2;
    show();//�������
}
void Arry::begin1()//���ض����鿪��
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
void Arry::begin2()//���ض����鿪��
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
void Arry::begin3()//���ض����鿪��
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
void Arry::begin4()//���ض����鿪��
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
void Arry::begin5()//���ض����鿪��
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
void Arry::begin6()//���ض����鿪��
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
void Arry::begin7()//���ض����鿪��
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
void Arry::operate()//��Ϸ���ֲ���
    {

        char ch;
        ch=getch();//�������
        switch(ch)
        {
        case (char)75://����
            moveLeft();
            if(!test())
            {
                gameOver();
                break;
            }//��Ϸ����
            else Arry::operate();//�ݹ飬��������
            break;
        case (char)72:
            moveUp();//����
            if(!test())
            {
                gameOver();
                break;
            }//��Ϸ����
            else Arry::operate();//�ݹ飬��������
            break;
        case (char)77:
            moveRight();
            if(!test())
            {
                gameOver();
                break;
            }//��Ϸ����
            else Arry::operate();//�ݹ飬��������
            break;
        case (char)80:
            moveDown();
            if(!test())

            {
                gameOver();
                break;
            }//��Ϸ����
            else Arry::operate();//�ݹ飬��������
            break;

        case 'c':
            cancel();//��������
            operate();//�ݹ��������
            break;

        case '0'://������Ϸ
            gameOver();//��Ϸ����
            cout<<endl;
            cout<<setw(50)<<"��������������˵�";
            char c;
            cin>>c;
            system("cls");
            start();
        default:
            Arry::operate();
            break;
        }
    }
void Arry::moveDown()//����
{
        int aa[4][4];//����һ����ά����

        int i=0;
        int j=0;//����������
        int k=3;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                bb[i][j]=a[i][j];
            }
        }//��a[4][4]����bb[4][4]
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                aa[i][j]=0;
            }
        }//����

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
            }//��ԭ���������з�������˳�������ƶ����������aa[4][4]��
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
                }//�ϲ���������ȵķ������֣�һ����Ϊ0��һ����Ϊ2��
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        a[i][j]=aa[i][j];
                    }
                }//��aa���鸳��a����
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
                }//���������ֺϲ���������µ�0���ظ�֮ǰ�Ĳ��裬ʹ�÷������ְ�˳���Ƶ����·�
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
                }//���������ƶ����跢���������ַ������ϲ�����bb������aa���飬flag=1��ִ�����沽��
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
            show();//�漴������Ϊ0�ĵط�����2��4
    }
}
void Arry::moveRight()//ԭ��ͬmoveDown()��ֻ�Ƿ���ı�
{
        int aa[4][4];//����һ��������
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
void Arry::moveLeft()//ԭ��ͬmoveDown()��ֻ�Ƿ���ı�
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
void Arry::moveUp()//ԭ��ͬmoveDown()��ֻ�Ƿ���ı�
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
void Arry::begin()//ѡ�񿪾ֵ���
{
    cout<<"��ѡ�񿪾ֵ��ߣ��粻ѡ���밴0"<<endl;
    int i;
    for(i=0;i<7;i++)
    {
        cout<<i+1<<"��  "<<pow(2,i+6)<<"����  ���и���"<<rr[i]<<endl;
    }
    cin>>i;//ѡ�񿪾ֵ���
    system("cls");
    if(i==0)
    {
        begin0();
        operate();
    }//��������
    else if(i==1)
    {
        i--;//��ż�һ��Ϊ�����±�
        rr[i]=rr[i]-1;//���߼�һ
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
            Sleep(1500);
            system("cls");
            begin0();
            operate();
        }//ѡ����ֿ���
        else
        {
           begin1();
           operate();
        }//���߲��㣬��������
    }
    else if(i==2)//ԭ��ͬi=1
    {
        i--;
        rr[i]=rr[i]-1;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
    else if(i==3)//ԭ��ͬi=1
    {
        i--;
        rr[i]--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
    else if(i==4)//ԭ��ͬi=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
    else if(i==5)//ԭ��ͬi=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
    else if(i==6)//ԭ��ͬi=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
    else if(i==7)//ԭ��ͬi=1
    {
        rr[i]--;
        i--;
        if(rr[i]<0)
        {
            rr[i]=0;
            cout<<"�õ��߲��㣬����Ϊ����ʼ����ģʽ";
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
        cout<<"�밴Ҫ������"<<endl;
        begin();
    }
}


