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

function dy = df(x)
  dy = 6*x + 6;
endfunction

function NewtonRaphson(xi, eS)
    primera = true;
    epsilon = 0;

    printf("\n\nxi\t\t| x i+1\t\t| epsilon\n\n");
    while true

      xs = xi - f(xi)/df(xi);

      if !primera
        epsilon = abs((xs-xi)/xs)*100;
        printf("%f\t| %f\t| %f\n",xi,xs,epsilon);
        if epsilon<eS
          printf("\n5) Hay raíz en: %f\n\n",xs);
          break;
        endif
      else
        printf("%f\t| %f\t|\n",xi,xs);
        primera = false;
      endif
      
      xi = xs;
    endwhile
endfunction



%Se calculan las raíces analíticamente y se grafica la función.
general();

%Se pide el rango de valores entre los que se encuantra la raíz.
printf("\nMétodo de Newton - NewtonRaphson. Ingresa un valor cercano donde podría encontrarse la raíz:\n\n");
x0 = input("Ingresa x0 ");
cifras = input("Con cuántas cifras significativas de precisión? ");
eS = (0.5*10^(2-cifras));

%Se invoca la función que implementa el método de aproximación.
NewtonRaphson(x0, eS)


%Se pide comprobar el posible resultado.
printf("\n\nComprueba si el método de NewtonRaphson encontró la raíz:\n\n");
x = input("Ingresa x ");
printf("f(%f) = %f\n\n\n",x,f(x));