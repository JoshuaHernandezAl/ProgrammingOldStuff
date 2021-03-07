clc;

function [x, fx] = leePuntos (n)
  x = zeros(n, 1);
  fx = zeros(n, 1);
  for i=1:n
    printf("Ingresa la x de P%d ",i);
    x(i,1) = input("");
    printf("Ingresa la y de P%d ",i);
    fx(i,1) = input("");
  endfor
endfunction

function M = calculaDiferenciasDivididas (x, fx, n)
  M = zeros(n-1);
  for j=1:n-1
    k=1;
    for i=j:n-1
      if j==1
        M(i,j) = (fx(i+1)-fx(i))/(x(i+1)-x(k));
        M;
      else
        M(i,j) = (M(i,j-1)-M(i-1,j-1))/(x(i+1)-x(k));
        M;
      endif
      k = k + 1;
    endfor
  endfor
endfunction

function e = bases(x, xi, k)
  e = 1;
  for i=1:k
    e = e * (x - xi(i));  
  endfor
endfunction

function s = calculaSuma (x, xi, fxi, M, n)
  s = fxi(1);
  for i=2:n
    s = s + (bases(x, xi, i-1)*M(i-1,i-1));
  endfor
endfunction


grado = input("De que grado sera el polinomio de Newton? ");
n = grado + 1;
x = input("Ingresa el valor a interpolar ");
printf("\n");


%Se genera una matriz aumentada llena de ceros
[xi, fxi] = leePuntos(n);
M = calculaDiferenciasDivididas(xi, fxi, n);
y = calculaSuma(x, xi, fxi, M, n);
printf("\nf(%f) = %f\n\n",x,y);