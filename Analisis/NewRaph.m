clc;

function general()
  a = 3;
  b = 6;
  c = -4;  
  x1 = (-b + sqrt((b^2)-4*a*c)) / (2*a);
  x2 = (-b - sqrt((b^2)-4*a*c)) / (2*a);
  printf("f(x) = 3x^2 + 6x -4\n\n");
  printf("Calculadas anal�ticamente, con la f�rmula general, las r�ces est�n en:\n\n");
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
          printf("\n5) Hay ra�z en: %f\n\n",xs);
          break;
        endif
      else
        printf("%f\t| %f\t|\n",xi,xs);
        primera = false;
      endif
      
      xi = xs;
    endwhile
endfunction



%Se calculan las ra�ces anal�ticamente y se grafica la funci�n.
general();

%Se pide el rango de valores entre los que se encuantra la ra�z.
printf("\nM�todo de Newton - NewtonRaphson. Ingresa un valor cercano donde podr�a encontrarse la ra�z:\n\n");
x0 = input("Ingresa x0 ");
cifras = input("Con cu�ntas cifras significativas de precisi�n? ");
eS = (0.5*10^(2-cifras));

%Se invoca la funci�n que implementa el m�todo de aproximaci�n.
NewtonRaphson(x0, eS)


%Se pide comprobar el posible resultado.
printf("\n\nComprueba si el m�todo de NewtonRaphson encontr� la ra�z:\n\n");
x = input("Ingresa x ");
printf("f(%f) = %f\n\n\n",x,f(x));