clc;

%Función que calcula la serie para e^x
function calculaSerieE(x,eS)
  fprintf("\n\ni\t | e^x\t\t | epsilon\n");
  nuevo = 0;
  anterior = 0;
  epsilon = 0;
  s = 0;
  i = 0;

  while(true)

    if i!=0
      anterior = nuevo;
    endif

    s = s + (x^i)/factorial(i);
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

  fprintf("\n\ne^%f = %f\n\n",x,s);
endfunction


%Funcion factorial
function f = factorial(n)
  f=1;
  for i=1: 1: n
    f = f*i;
  endfor
endfunction


x = input('Ingresa x ');
decimales = input("Con cuántos decimales de precisión? ");
eS = (0.5*10^(2-decimales));
calculaSerieE(x,eS)

