clc;

m = input("Cuantas ecuaciones? ");
n = m+1;

%Se genera una matriz aumentada llena de ceros
M = zeros(m,n);

%Se pide la matriz aumentada
for i=1:m
  for j=1:n
    printf("Ingresa [%d][%d] ",i,j);
    M(i,j)=input("");
  endfor
  printf("\n");
endfor



%Se muestra La matriz ingresada
for i=1:m
  for j=1:n
    printf("%d\t",M(i,j));
  endfor
  printf("\n");
endfor
printf("\n\n");


%Se convierte en ceros el triangulo inferior de la matriz
for h=1:m-1
    for k=h+1:m
        Valor = -M(k,h)/M(h,h);
        printf("(F%d * %f) + F%d\n",h,Valor,k);
        for j=1:n
            M(k,j) = M(k,j) + (Valor*M(h,j));
        endfor

        for i=1:m
          for j=1:n
            printf("%d\t",M(i,j));
          endfor
          printf("\n");
        endfor
        printf("\n");

        endfor
endfor
printf("\n\n");



%Se convierte en unos la diagonal principal
for i=1:m
    Valor = M(i,i);
    for j=1:n
        M(i,j) = M(i,j) / Valor;
    endfor
endfor
for i=1:m
  for j=1:n
    printf("%d\t",M(i,j));
  endfor
  printf("\n");
endfor
printf("\n\n");



%Se calculan, por sustitucion, los valores de las incognitas
for i=m-1: -1: 1
  for j=n-1: -1: i+1
    M(i,n) = M(i,n) - M(i,j)*M(j,n);
  endfor
endfor



for i=1:m
  printf("x%d = %f\n",i,M(i,n))
endfor