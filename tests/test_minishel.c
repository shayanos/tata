/*
** EPITECH PROJECT, 2022
** test
** File description:
** test unite
*/


#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_putnbr(int n);

Test (my_putstr, printadam, .init=cr_redirect_stdout)
{
    char str[] = "adam" ;
    my_putstr(str);
    cr_assert_stdout_eq_str("adam", "");
}

Test (my_strlen, strlenadam)
{
    char *str = "adam";
    cr_assert_eq(my_strlen(str), 4);
}

Test (my_putchar, printf_c, .init=cr_redirect_stdout)
{
    char c = 'c';
    my_putchar(c);
    cr_assert_stdout_eq_str("c", "");
}

Test (my_putnbr, printf_pos, .init=cr_redirect_stdout)
{
    int  nb = 123456789;
    my_putnbr(nb);
    cr_assert_stdout_eq_str("123456789", "");
}

Test (my_putnbr, printf_neg, .init=cr_redirect_stdout)
{
    int  nb = -123456789;
    my_putnbr(nb);
    cr_assert_stdout_eq_str("-123456789", "");
}
