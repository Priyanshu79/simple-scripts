#include <stdio.h>

int main()
{
    int a[200], n, counter, temp, i;
    a[0] = 1;
    counter = 0;
    printf("Enter a whole number: ");
    scanf("%d", &n);
    
    if (n < 0)
        printf("Please enter a whole number");
    else
    {
        for (; n >= 2; n--)
        {
            t= 0;
            for (i = 0; i <= counter; i++)
            {
                t = (a[i] * n) + t;
                a[i] = t % 10;
                t = t / 10;
            }
            while (t > 0)
            {
                a[++counter] = t % 10;
                t = t / 10;
            }
        }
        for (i = counter; i >= 0; i--) printf("%d", a[i]);
    }
    
    return 0;
}
