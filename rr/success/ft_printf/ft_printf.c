#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return i;
}

int	ft_putnbr(int nb)
{
	int count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return count;
}

int	ft_hex(unsigned int n)
{
	int count;
	char c[16] = "0123456789abcdef";

	count = 0;
	if (n >= 16)
	{
		count += ft_hex(n / 16);
		count += ft_hex(n % 16);
	}
	else
		count += ft_putchar(c[n]);
	return count;
}
int	ft_printf(const char *str, ...)
{
	va_list lst;
	int count;
	int i;

	count = 0;
	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == 's')
				count += ft_putstr(va_arg(lst, char *));
			else if (str[i] == 'd')
				count += ft_putnbr(va_arg(lst, int));
			else if (str[i] == 'x')
				count += ft_hex(va_arg(lst, unsigned int));
			else
				write (1, &str[i], 1);
		}
		else if (str[i] != '%')
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(lst);
	return count;
}
	
