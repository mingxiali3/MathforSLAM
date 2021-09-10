#include "complex.h"
#include <iostream>
using namespace std;
int main()
{
    int n=5;//求n次根
    Complex c1(2,3),c2(1,2),p[n];//声明并实例化两个复数,一个复数数组(用来存放求了1~n次根后的复数)
    cout << "复数1：" << c1 << endl;
    cout << "复数2：" << c2 << endl;
   cout << "求复数1的模: " << c1.cfabs() << endl;
    cout << "求复数1的幅角: " << c1.angle() << endl;
    cout << "求两个复数的乘积: " << c1*c2 << endl;
    cout << "求两个复数的和: " << c1+c2 << endl;
    cout << "求两个复数的差: " << c1-c2 << endl;
    cout << "求复数的商: " << c1/c2 << endl;
    cout << "求复数1的乘幂: " << c1.cpow(3)<< endl;
    cout << "求复数1的5次根: " << c1.croot(n,p)<< endl;;
    cout << "求复数1的指数：" << c1.cexp(n) << endl;
    cout << "求复数1的对数: " << c1.clog() << endl;
    cout << "求复数1的正弦值: " << c1.csin() << endl;
    cout << "求复数1的余弦值: " << c1.ccos() << endl;
 

}
