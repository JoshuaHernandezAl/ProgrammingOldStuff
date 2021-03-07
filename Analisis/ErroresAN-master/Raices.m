clc

function f = factorial(n)
  f=1;
  i=1;
  while i<=n
    f = f*i;
    i = i+1;
  endwhile 
end

x = input("Igresa x ");
n = input("Igresa n ");

s = 0;
i=0;
while i<=n
	s = s + (x^i)/(factorial(i))
	i = i+1;
endwhile
 

 
 
 
 
 
 
 
 
 
 
 
 
 