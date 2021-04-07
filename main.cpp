#include <iostream>
#include <cmath>
#define PI 3.141593
using namespace std;
class Triangle
{
    float x;//�������
    float a;//1 ����
    float b;//2 ����

     float fy ()/*������� ���������� ������� y*/
     {
        return x * sin(a*PI/180)/sin((180-a-b)*PI/180);
     }

    float fz ()/*������� ���������� ������� z*/
     {
        return x * sin(b*PI/180)/sin((180-a-b)*PI/180);
     }

    public:
        Triangle()/*�����������*/
    {
        x = 0;
        a = 0;
        b = 0;
        cout << "�������� �����������" << endl;
    }

    Triangle(float x, float a, float b)/**/
    {
        this->x = x;
        this->a = a;
        this->b = b;
        cout << "�������� ����������� � �����������" << endl;
    }

    Triangle(Triangle &t)/*����������� �����������*/
    {
        this->x = t.x;
        this->a = t.a;
        this->b = t.b;
        cout << "�������� ����������� �����������" << endl;
    }
    float Get_x()
    {
        return x;
    }
    float Get_a()
    {
        return a;
    }
    float Get_b()
    {
        return b;
    }
    void Set_x(float x)
    {
        this->x = x;
    }
    void Set_a(float a)
    {
        this->a = a;
    }
    void Set_b(float b)
    {
        this->b = b;
    }
    void f1 ()/*���������� ���� ���� ������*/
    {
        float y;
        float z;
        if (a+b < 180 && a+b > 0 && x>0)
        {
            y = fy();
            z = fz();
            cout << "1 �������: " << endl << y << endl << "2 �������: "<< endl << z << endl;
        }
        else
            cout << "����������� �� ���������� - ��������� ������� �� �������" << endl ;
    }

    void f2 ()/*���������� ��������� ���� ������*/
    {
        float p;
        float l;
        float y;
        float z;
        if (a+b < 180 && a> 0 && b>0 && x>0)
        {
            y = fy ();
            z = fz ();
            p = (x + y + z)/2;
            l= 2 * sqrt(x*z*p*(p-y))/(x+z);
            cout << "1 ���������� - " << l << endl;
            l= 2 * sqrt(x*y*p*(p-z))/(x+y);
            cout << "2 ���������� - " << l << endl;
            l= 2 * sqrt(y*z*p*(p-x))/(y+z);
            cout << "3 ���������� - " << l << endl;
        }
         else
            cout << "����������� �� ����������" << endl;
    }
    bool operator ==( Triangle &t)/*��������� �� ��������� �������� �������������*/
    {
       if (this->a + this->b < 180 && this->a > 0 && this->b > 0 && this->x > 0)
       {
           return 0.5 * this->fz() * this->x * sin(this->a) == 0.5 * t.fz() * t.Get_x() * sin(t.Get_a());
       }
       else
       {
           cout << "������ �� ������������� �� ����������" << endl;
           return false;
       }

    }
    ~Triangle()/*����������*/
    {
        cout << "�������� ����������" << endl;
    }

};

int main()
{   setlocale(LC_ALL,"rus");
    int menu;
    int x, a, b;
    cout << "������� ������� ������������:" << endl;
    cin >> x;
    cout << "������� ������ ���� ������������:" << endl;
    cin >> a;
    cout << "������� ������ ���� ������������:" << endl;
    cin >> b;
    if (a+b>=180 || a<=0 || b<=0 || x<=0)
     {
        cout << "�� ����������� ����� ������. ������ ������������ �� ����������."<< endl;
        exit (-1);
     }
    Triangle tr(x, a, b);/**/
    cout << "������������� ������������� ����������� ��� ������� ������������:" << endl;
    Triangle tr2(tr);
    cout << "������� = " << tr2.Get_x() << endl << "���� 1 = " << tr2.Get_a()<< endl << "���� 2 =" << tr2.Get_b() << endl;
    cout << "1 - �������� ������� ������������ x " << endl;
    cout << "2 - �������� ������ ���� ������������ a" << endl;
    cout << "3 - �������� ������ ���� ������������ b" << endl;
    cout << "4 - �������� ������� ������������ x " << endl;
    cout << "5 - �������� ������ ���� ������������ a" << endl;
    cout << "6 - �������� ������ ���� ������������ b" << endl;
    cout << "7 - �������� ����������� ������� ������������ " << endl;
    cout << "8 - �������� ��� ����������� ������������ " << endl;
    cout << "9 - �������� �� ��������� ������� ������������ " << endl;
    cout << "10 - ����� " << endl;
do
{
     cin >> menu;
        switch(menu)
    {
    case 1 :
        cout << "������� ������������ = " << tr.Get_x() << endl;
        break;
    case 2 :
        cout << "������ ���� ������������ = " << tr.Get_a() << endl;
        break;
    case 3 :
        cout << "������ ���� ������������ = " << tr.Get_b() << endl;
        break;
    case 4 :
        cout << "�������� ������� ������������ x: " << endl;
        cin >> x;
        tr.Set_x(x);
        break;
    case 5 :
        cout << "�������� ������ ���� ������������ a. ������� ����� ������ 0 � ������ 180: " << endl;
        cin >> x;
        tr.Set_a(x);
        break;
    case 6 :
        cout << "�������� ������ ���� ������������ b. ������� ����� ������ 0 � ������ 180: " << endl;
        cin >> x;
        tr.Set_b(x);
        break;
    case 7 :
        cout << "����������� ������� ������������: " << endl;
        tr.f1();
        break;
    case 8 :
        cout << "����������� ������������: " << endl;
        tr.f2();
        break;
    case 9 :
        if (tr==tr2)
        {
            cout <<"������� �����"<< endl;
        }
        else cout <<"������� �� �����"<< endl;


    }
} while(menu!=10);

 return 0;
}
