#include <iostream>
#include <cmath>
#define PI 3.141593
using namespace std;
class Triangle
{
    float x;//сторона
    float a;//1 угол
    float b;//2 угол

     float fy ()/*функция вычисления стороны y*/
     {
        return x * sin(a*PI/180)/sin((180-a-b)*PI/180);
     }

    float fz ()/*функция вычисления стороны z*/
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

    Triangle(float x, float a, float b)/**/
    {
        this->x = x;
        this->a = a;
        this->b = b;
        cout << "Вызвался конструктор с параметрами" << endl;
    }

    Triangle(Triangle &t)/*конструктор копирования*/
    {
        this->x = t.x;
        this->a = t.a;
        this->b = t.b;
        cout << "Вызвался конструктор копирования" << endl;
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
    void f1 ()/*вычисление длин всех сторон*/
    {
        float y;
        float z;
        if (a+b < 180 && a+b > 0 && x>0)
        {
            y = fy();
            z = fz();
            cout << "1 сторона: " << endl << y << endl << "2 сторона: "<< endl << z << endl;
        }
        else
            cout << "Треугольник не существует - вычислить стороны не удалось" << endl ;
    }

    void f2 ()/*вычисление биссекрис всех сторон*/
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
            cout << "1 биссекриса - " << l << endl;
            l= 2 * sqrt(x*y*p*(p-z))/(x+y);
            cout << "2 биссекриса - " << l << endl;
            l= 2 * sqrt(y*z*p*(p-x))/(y+z);
            cout << "3 биссекриса - " << l << endl;
        }
         else
            cout << "треугольник не существует" << endl;
    }
    bool operator ==( Triangle &t)/*сравнение на равенстро площадей треугольников*/
    {
       if (this->a + this->b < 180 && this->a > 0 && this->b > 0 && this->x > 0)
       {
           return 0.5 * this->fz() * this->x * sin(this->a) == 0.5 * t.fz() * t.Get_x() * sin(t.Get_a());
       }
       else
       {
           cout << "Одного из треугольников не существует" << endl;
           return false;
       }

    }
    ~Triangle()/*деструктор*/
    {
        cout << "Вызвался деструктор" << endl;
    }

};

int main()
{   setlocale(LC_ALL,"rus");
    int menu;
    int x, a, b;
    cout << "Введите сторону треугольника:" << endl;
    cin >> x;
    cout << "Введите первый угол треугольника:" << endl;
    cin >> a;
    cout << "Введите второй угол треугольника:" << endl;
    cin >> b;
    if (a+b>=180 || a<=0 || b<=0 || x<=0)
     {
        cout << "Вы неправильно ввели данные. Такого треугольника не существует."<< endl;
        exit (-1);
     }
    Triangle tr(x, a, b);/**/
    cout << "Воспользуемся конструктором копирования для второго треугольника:" << endl;
    Triangle tr2(tr);
    cout << "сторона = " << tr2.Get_x() << endl << "угол 1 = " << tr2.Get_a()<< endl << "угол 2 =" << tr2.Get_b() << endl;
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
        tr.f1();
        break;
    case 8 :
        cout << "Биссектрисы треугольника: " << endl;
        tr.f2();
        break;
    case 9 :
        if (tr==tr2)
        {
            cout <<"Площади равны"<< endl;
        }
        else cout <<"Площади не равны"<< endl;


    }
} while(menu!=10);

 return 0;
}
