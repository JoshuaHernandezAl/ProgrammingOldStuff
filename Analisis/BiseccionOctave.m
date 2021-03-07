clc;

function general()
  a = 3;
  b = 6;
  c = -4;  
  x1 = (-b + sqrt((b^2)-4*a*c)) / (2*a);
  x2 = (-b - sqrt((b^2)-4*a*c)) / (2*a);
  printf("f(x) = 3x^2 + 6x -4\n\n");
  printf("Calculadas analíticamente, con la fórmula general, las ríces están en:\n\n");
  printf("x1 = %f\nx2 = %f\n\n\n",x1,x2);

  coordX = [-7 : .1 : 5];
  coordY = 3*(coordX.^2) + 6*coordX -4;
  plot(coordX,coordY);
endfunction

function y = f(x)
  y = 3*(x^2) + 6*x - 4;
endfunction

function biseccion(a, b, eS)
  
  if a==b && f(a)>(-eS) && f(a)<eS
    printf("\n1) Hay raíz en: %f\n\n",a);
  elseif f(a)>(-eS) && f(a)<eS
    printf("\n2) Hay raíz en: %f\n\n",a);
  elseif f(b)>(-eS) && f(b)<eS
    printf("\n3) Hay raíz en: %f\n\n",b);
  elseif !(f(a)*f(b) < 0)
    printf("\n4) No hay raíz  entre %f y %f\n\n",a,b);  
  else
    
    nuevo = 0;
    anterior = 0;
    epsilon = 0;

    printf("\n\na\t\t| b\t\t| m\t\t| epsilon\n\n");
    while true
      
      m = (b+a)/2;
      nuevo = m;
      epsilon = abs((nuevo-anterior)/nuevo)*100;
      printf("%f\t| %f\t| %f\t| %f\n",a,b,m,epsilon);

      if epsilon<eS
        printf("\n5) Hay raíz en: %f\n\n",m);
        break;
      elseif f(a)*f(m) < 0
        b = m;
      else
        a = m;
      endif
      
      anterior = nuevo;

    endwhile

  endif
endfunction


%Se calculan las raíces analíticamente y se grafica la función.
general();

%Se pide el rango de valores entre los que se encuantra la raíz.
printf("\nMétodo de la bisección. Ingresa el segmento entre los que podría encontrarse la raíz:\n\n");
a = input("Ingresa a ");
b = input("Ingresa b ");
cifras = input("Con cuántas cifras significativas de precisión? ");
eS = (0.5*10^(2-cifras))

%Se invoca la función que implementa el método de aproximación.
biseccion(a, b, eS)


%Se pide comprobar el posible resultado.
printf("\n\nComprueba si el método de la bisección encontró la raíz:\n\n");
x = input("Ingresa x ");
printf("f(%f) = %f\n\n\n",x,f(x));