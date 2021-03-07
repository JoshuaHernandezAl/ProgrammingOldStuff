
clc;

%Función que calcula la serie para sen(x)
function calculaSerieSeno(x,eS)

  xRads = convierteGradosARadianes(x);
  nuevo = 0;
  anterior = 0;
  epsilon = 0;
  s = 0;
  i = 0;

  fprintf("\n\ni\t | seno(x)\t | epsilon\n");
  while(true)

    if i!=0
      anterior = nuevo;
    endif

    s = s + (-1)^i * xRads^(2*i+1) / factorial(2*i+1);
    nuevo = s;
    epsilon = abs((nuevo-anterior)/nuevo)*100;

    if i!=0
      fprintf("%d\t | %f\t | %f\n",i,s,epsilon);
    else
      fprintf("%d\t | %f\t |\n",i,s);
    endif

    i=i+1;

    if(epsilon < eS)
      break;
    endif

  endwhile

  fprintf("\n\nseno(%f) = %f\n\n",x,s);
endfunction

%Funcion factorial
function f = factorial(n)
  f=1;
  for i=1: 1: n
    f = f*i;
  endfor
endfunction

%Funcion para conversión
function radianes = convierteGradosARadianes(grados)
  radianes = grados * pi / 180;
%  printf("grados = %f\tpi = %f\tradianes = %f\n",grados,pi,radianes);
endfunction

x = input('Ingresa x ');
decimales = input("Con cuántos decimales de precisión? ");
eS = (0.5*10^(2-decimales));
calculaSerieSeno(x,eS)

