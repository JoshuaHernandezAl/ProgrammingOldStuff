clc;

function f = f(x)
  f = -x^2-2*x+1;
endfunction

function df = df(x)
  df = 3*x^2 - 4*x - 6;
endfunction

function ddf = df2(x)
  ddf = 6*x - 4;
endfunction

function d = dAdelante(xi,h)
  d = (f(xi + h) - f(xi))/(h);
endfunction

function d = dAtras(xi,h)
  d = (f(xi) - f(xi - h))/(h);
endfunction

function d = dCentral(xi,h)
  d = (f(xi + h) - f(xi - h))/(2*h);
endfunction

function d = d2Adelante(xi,h)
  d = (f(xi+(2*h)) - 2*f(xi+h) + f(xi))/(h^2);
endfunction

function d = d2Atras(xi,h)
  d = (f(xi) - 2*f(xi-h) + f(xi-2*h))/(h^2);
endfunction

function d = d2Central(xi,h)
  d = (f(xi+h) - 2*f(xi) + f(xi-h))/(h^2);
endfunction



xi = input("Ingresa x ");
h = input("Ingresa h ");
printf("\nAnaliticamente, f'(%f) = %f\n",xi,df(xi));
printf("Analiticamente, f''(%f) = %f\n\n",xi,df2(xi));

printf("f'(%f) = %f (Hacia adelante)\n",xi,dAdelante(xi,h));
printf("f'(%f) = %f (Hacia atras)\n",xi,dAtras(xi,h));
printf("f'(%f) = %f (Central)\n\n",xi,dCentral(xi,h));

printf("f''(%f) = %f (Hacia adelante)\n",xi,d2Adelante(xi,h));
printf("f''(%f) = %f (Hacia atras)\n",xi,d2Atras(xi,h));
printf("f''(%f) = %f (Central)\n\n",xi,d2Central(xi,h));