from cmath import sqrt

print('\nFor the equation in form:\na*x^2+b*x+c=0\n')

a=float(input("Enter the value of a: "))
b=float(input("Enter the value of b: "))
c=float(input("Enter the value of c: "))

sol1=(complex(-b)+complex(sqrt((b**2.0)-(4*a*c))))/complex((2*a))
sol2=(complex(-b)-complex(sqrt((b**2.0)-(4*a*c))))/complex((2*a))

print(f"\nThe solutions to the quadratic equation are {sol1} and {sol2}")
