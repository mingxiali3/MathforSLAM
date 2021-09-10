#include <sstream>
#include <string>
#include <string.h>
#include <memory>
#include <math.h>
using namespace std;
class Complex
{
    private:
        double R;
        double I;
        string initialInput;//用于打印
    public:
        //默认构造函数
        Complex():R(0),I(0){};
        //构造函数重载
        Complex(double real,double imag):R(real),I(imag){};
    
        //转换运算符（）:用于打印
        operator const char* ()
        {
            ostringstream printcomplex;
            printcomplex <<"< " << R << " , " << I << ">" << endl;
            initialInput = printcomplex.str();
            return initialInput.c_str();
        }
        //加法+
        Complex operator + (Complex& c)
        {
            return Complex(R+c.R,I+c.I);
        }
        //减法-
        Complex operator - (Complex& c)
        {
            return Complex(R-c.R,I-c.I);
        }
        //乘法*
        Complex operator * (Complex& c)
        {
            Complex c1;
            c1.R=R*c.R-I*c.I;
            c1.I=R*c.I+I*c.R;
            return Complex(c1.R,c1.I);
        }
        //除法
        Complex operator / (Complex& c)
        {
            Complex c1;
            double w;
            w= c.R*c.R+c.I*c.I;
            double p;
            p=R*c.R;
            double q;
            q=-I*c.I;
            double s;
            s=(R+I)*(c.R-c.I);
            if (w +1 !=0)
            {
            c1.R=(p-q)/w;
            c1.I=(s-p-q)/w;
            }
            else
            {
                c1.R=1e+200;
                c1.I=1e+200;
            }
            return c1;
        }
        //乘幂
        /*
        令z= x+jy = r(cosa+jsina)//根据欧拉公式e^i*a=cosa+isina;
        r=sqrt(x*x+y*y);
        a=atan2(y/x);
        target complex u+jv=z^n;
        step1:r=n*ln(r);
        step2:r=exp(r);//r^n
        step3:u=r*cosa;v=r*sina;
        */
       Complex cpow(int n)
       {
           Complex c1;
           double r;
           r = sqrt(R*R+I*I);
           if (R)
           {
             double a;
             a = atan2(I,R);
             r = n*log(r);
             r = exp(r);
             c1.R=r*cos(a);
             c1.I= r*sin(a);
           }
           else
           {
             c1.R=1e+200;
             c1.I=1e+200;
           }
          return c1;
       }
       
       //复数的n次方根
       /*
       令z=x+jy=r(cosa+jsina);
       r=sqrt(x*x+y*y);
       a=atan2(y/x);
       target complex u+jv=z^(1/n);
       step1:r=(1/n)*log(r);
       step2:r=exp(r);

       */
      //输入n次方根以及传入一个Complex对象实例化一个指针p，来充当数组传入
      Complex croot(int n,Complex* p)
      {
          Complex c1,c2;//c1是中间对象，p是Complex实例化的指针，用来存放1~n次求根结果；只要结束for循环后c2的值，它代表第n次根
          double r = sqrt(R*R+I*I);
          if(R)
          {
              double a;
              a = atan2(I,R);
              r = (1/n)*log(r);
              r = exp(r);
              for(int k=0;k<n;++k)
              {
                  int t =0;
                  t=(2*k*3.1415926+a)/n;
                  c1.R=r*cos(t);
                  c1.I=r*sin(t);
                  p[k]=c1; 
                  c2=p[k];
              }
                return c2;//返回最后一次根，也就是第n次根；
          }

      }
      
      //求指数，这个倒是不难
      /*
      令z=x+jy;
      u+jv=e^z=e^(x+jy)=(e^(x))*(e^(jy))=(e^(x))*(cosy+jsiny)=(e^(x))*(cosy+jsiny)=(e^(x))*cosy+j*(e^(x))*siny;
      简单地说: u=(e^(x))*cosy;v=(e^(x))*siny;
      */
     Complex cexp(int n)
     {
        Complex c1;
        c1.R = exp(R)*cos(I);
        c1.I = exp(R)*sin(I);
        return c1;
     }
     
     //求对数
     /*
     令z=x+jy;a=atan2(y/x);
     同时借助欧拉公式:z=r*e^(i*a);
     u+jv=ln(z)=ln(r*e^(i*a))=ln(r)+ln(e^(i*a))=i*a+ln(r);
     so:
     u=ln(r);v=a;
     */
    Complex clog()
    {
        Complex c1;
        double a;
        if (R)
        {
          a=atan2(I,R); 
        }
        double r;
        r=sqrt(I*I+R*R);
        c1.R=log(r);
        c1.I=a;
        return c1;
    }
       
     //求复数的正弦值
     /*
    令z=x+jy; 
    u+jv=sin(z)=sin(x+jy)=sin(x)cos(jy)+cos(x)sin(jy);
    Al final:
    u=sin(x)*(exp(y)+exp(-y))/2;
    v=cos(x)*(exp(y)+exp(-y))/2;
     */
    Complex csin()
    {
        Complex c1;
        c1.R=sin(R)*(exp(I)+exp(-I))/2;
        c1.I=cos(R)*(exp(I)+exp(-I))/2;
        return c1;
    }
    //求复数的余弦值
    Complex ccos()
    {
        Complex c1;
        c1.R=cos(R)*(exp(I)+exp(-I))/2;
        c1.I=sin(R)*(exp(I)+exp(-I))/2;
        return c1;
    }
     
     //求复数的模
     double cfabs()
     {
         double m;
         m=sqrt(R*R+I*I);
         return m;
     }
     //求复数的幅角
     double angle()
     {
         double a;
         a=atan2(I,R);
         return a;
     }
};