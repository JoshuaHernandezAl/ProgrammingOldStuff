clc;
function f = f(x)
  f = 5*x^4 -8*x^3 +6;
endfunction

function s = calculaSuma(x0,h,n)
  s = 0;
  for i=1:n-1
    mod(i,2)
    if mod(i,2)!=0
      s = s + 4*f(x0+(h*i));
      
    else 
      s = s + 2*f(x0+(h*i));
      
    endif
  endfor
endfunction

x0 = input("Ingresa limite inferior ");
xn = input("Ingresa limite superior ");
op = input("Ingresa 1 para Simpson 1/3 o 2 para Simpson3/8 ");

if op==1
  n = input("Ingresa cantidad (par) de segmentos ");
  h = (xn-x0)/n
  integral = (h/3)*(f(x0) + calculaSuma(x0,h,n) + f(xn))
else
  h = (xn-x0)/3
  x1 = x0+h;
  x2 = x1+h;
  integral = (3*h/8)*(f(x0) + 3*f(x1) + 3*f(x2) + f(xn))
endif
  
real = 545
error = abs((real-integral)/real)*100