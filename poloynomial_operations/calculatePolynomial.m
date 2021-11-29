format long
n = 1;
m = 0;
%p = makeParabola(1,1,1);
p = nest(1,1);
X = 1.00001;
Y = p(1.00001);
while n < 50 
   
    Y = 1 + X*Y;
    n = n+1;
end
%Y是P(x)的计算值
Y
%q是标准计算值
q = ((1.00001)^51 - 1)/(1.00001-1)
%m表示P(x)与Q(x)误差
m = Y - q