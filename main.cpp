#include <iostream>
#include <cmath>
#define PI 3.141593
using namespace std;
class Triangle
{
    private:
    double x;/*сторона*/
    double a;/*1 угол*/
    double b;/*2 угол*/

    double fy ()/*функция вычисления стороны y*/
     {
        return x * sin(a*PI/180)/sin((180-a-b)*PI/180);
     }

    double fz ()/*функция вычисления стороны z*/
     {
        return x * sin(b*PI/180)/sin((180-a-b)*PI/180);
     }

    public:
        Triangle()/*конструктор*/
    {
        x = 0;
        a = 0;
        b = 0;
        cout << "Вызвался конструктор" << endl;
    }

    Triangle(double x, double a, double b)/*конструктор с параметрами*/
    {
        Set_x(x);
        Set_a(a);
        Set_b(b);
        cout << "Вызвался конструктор с параметрами" << endl;
    }

    Triangle(Triangle &t)/*конструктор копирования*/
    {
        this->x = t.x;
        this->a = t.a;
        this->b = t.b;
        cout << "Вызвался конструктор копирования" << endl;
    }
    double Get_x()
    {
        return x;
    }
    double Get_a()
    {
        return a;
    }
    double Get_b()
    {
        return b;
    }
    void Set_x(double x)
    {
        if (x>0)
        {
            this->x = x;
        }
        else cout << "Неправильно ввели значение" << endl;
    }
    void Set_a(double a)
    {
        if (a>0 && a<180)
        {
            this->a = a;
        }
        else cout << "Неправильно ввели значение" << endl;
    }
    void Set_b(double b)
    {
      if (b>0 && b<180 )
        {
            this->b = b;
        }
      else cout << "Неправильно ввели значение" << endl;
    }
    void f1 ()/*вычисление длин всех сторон*/
    {
        double y;
        double z;
        y = fy();
        z = fz();
        cout << "1 сторона: " << y << endl << "2 сторона: " << z << endl;
    }

    void f2 ()/*вычисление биссекрис всех сторон*/
    {
        double p;
        double l;
        double y;
        double z;
        y = fy ();
        z = fz ();
        p = (x + y + z)/2;
        l= 2 * sqrt(x*z*p*(p-y))/(x+z);
        cout << "1 биссекриса - " << l << endl;
        l= 2 * sqrt(x*y*p*(p-z))/(x+y);
        cout << "2 биссекриса - " << l << endl;
        l= 2 * sqrt(y*z*p*(p-x))/(y+z);
        cout << "3 биссекриса - " << l << endl;
    }

    bool operator ==( Triangle &t)/*сравнение на равенстро площадей треугольников*/
    {
        return 0.5 * this->fz() * this->x * sin(this->a) == 0.5 * t.fz() * t.Get_x() * sin(t.Get_a());
    }

    ~Triangle()/*деструктор*/
    {
        cout << "Вызвался деструктор" << endl;
    }

};

int main()
{   setlocale(LC_ALL,"rus");
    int menu;
    double x, a, b;
    cout << "Введите сторону треугольника x:" << endl;
    cin >> x;
    cout << "Введите первый угол треугольника a:" << endl;
    cin >> a;
    cout << "Введите второй угол треугольника b:" << endl;
    cin >> b;
    if (a+b>=180 || a<=0 || b<=0 || x<=0)
     {
        cout << "Вы неправильно ввели данные. Такого треугольника не существует."<< endl;
        exit (-1);
     }
    Triangle tr(x, a, b);/*треугольник с которым будет сравниваться второй треугольник*/
    cout << "1 - Получить сторону треугольника x " << endl;
    cout << "2 - Получить первый угол треугольника a" << endl;
    cout << "3 - Получить второй угол треугольника b" << endl;
    cout << "4 - Изменить сторону треугольника x " << endl;
    cout << "5 - Изменить первый угол треугольника a" << endl;
    cout << "6 - Изменить второй угол треугольника b" << endl;
    cout << "7 - Получить неизвестные стороны треугольника " << endl;
    cout << "8 - Получить все биссектрисы треугольника " << endl;
    cout << "9 - Сравнить на равенство площади трегольников " << endl;
    cout << "10 - Выход " << endl;
do
{
     cin >> menu;
        switch(menu)
    {
    case 1 :
        cout << "Сторона треугольника = " << tr.Get_x() << endl;
        break;
    case 2 :
        cout << "Первый угол треугольника = " << tr.Get_a() << endl;
        break;
    case 3 :
        cout << "Второй угол треугольника = " << tr.Get_b() << endl;
        break;
    case 4 :
        cout << "Измените сторону треугольника x: " << endl;
        cin >> x;
        tr.Set_x(x);
        break;
    case 5 :
        cout << "Измените первый угол треугольника a. Введите число больше 0 и меньше 180: " << endl;
        cin >> x;
        tr.Set_a(x);
        break;
    case 6 :
        cout << "Измените второй угол треугольника b. Введите число больше 0 и меньше 180: " << endl;
        cin >> x;
        tr.Set_b(x);
        break;
    case 7 :
        cout << "Неизвестные стороны треугольника: " << endl;
        if (tr.Get_a()+ tr.Get_b() < 180)
        {
            tr.f1();
        }
        else cout << "Треугольник не существует, вычислить стороны не удалось." << endl;
        break;
    case 8 :
        cout << "Биссектрисы треугольника: " << endl;
        if (tr.Get_a()+ tr.Get_b() < 180)
        {
            tr.f2();
        }
        else cout << "Треугольник не существует, вычислить биссекрисы не удалось." << endl;
        break;
    case 9 :
        if (tr.Get_a()+ tr.Get_b() < 180)
        {
            cout << "Введите данные для нового треугольника"<< endl;
            cout << "Введите сторону треугольника x:" << endl;
            cin >> x;
            cout << "Введите первый угол треугольника a:" << endl;
            cin >> a;
            cout << "Введите второй угол треугольника b:" << endl;
            cin >> b;
            if (a+b>=180 || a<=0 || b<=0 || x<=0)
              {
                cout << "Вы неправильно ввели данные. Такого треугольника не существует."<< endl;
                exit (-2);
              }
            Triangle tr2(x, a, b);
            if (tr==tr2)
              {
                cout <<"Площади равны"<< endl;
              }
            else cout <<"Площади не равны"<< endl;
        }
        else cout << "Неправильно введены данные. Измените данные треугольника" << endl;

    }
} while(menu!=10);

 return 0;
}
