clc;
function f = f(x)
  f = 5*x^4 -8*x^3 +6;
endfunction

function s = calculaSuma(x0,h,n)
  s = 0;
  for i=1:n-1
    s = s+f(x0+(h*i));
  endfor
endfunction

x0 = input("Ingresa limite inferior ");
xn = input("Ingresa limite superior ");
n = input("Ingresa cantidad de segmentos ");
h = (xn-x0)/n
integral = h*(f(x0) + 2*calculaSuma(x0,h,n) + f(xn))/2

real = 544
error = abs((real-integral)/real)*100