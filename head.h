
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<string>
using namespace std;
class Record
{
public:
    Record()//���캯��
    {
        r1=0;
        r=0;
        int i;
        for(i=0;i<7;i++)
        {
            rr[i]=0;
        }
    }//Ĭ��ȫΪ0
    int r1;//��߷�
    int rr[7];//���ֵ���
    int r;//��������
};
class Account:public Record
{
public:
    Account():Record()
    {

        money=100;
    }//���캯�������Ĭ��100
    int money;//�������
    char zhanghao[20];//�˺�
    string mima;//����


};
class Store:public Account
{
public:
    void display();//�̵�չʾ�����߹���
    void back1();//�������˵�
};
class Arry:public Store
{
private:
    int score;//��Ϸ�����еļƷ���
    int bb[4][4];
    int a[4][4];
public:
    void operate();//�����ж�����
    void begin();//��ʼ��Ϸ����
    void begin0();
    void begin1();
    void begin2();
    void begin3();
    void begin4();
    void begin5();
    void begin6();
    void begin7();//���ֿ���
    void show();//չʾ��ά����
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();//���ַ������
    int test();//�����Ϸ�Ƿ���Լ�������

    void gameOver();//��Ϸ����
    void cancel();//��������
};
Arry ipt;//����ֱ�����õĶ���
void start();//���˵�����
void denglu();//��¼
void zhuce();//ע��
void welcome();//��ӭ����
void rule();//��Ϸ����
void k(int x);//����ո�
void cunchu();//�����˻���ʱ����Ϣ
#endif // HEAD_H_INCLUDED
