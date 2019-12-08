#include <stdio.h>
#include "libftprintf.h"
int main ()
{
    printf("%d\n", printf("%1.c", 0));
    printf("%d\n", ft_printf("%1.c", 0));
}