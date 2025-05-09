#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    int	i;
	int	c;
	int	d;

	i = 0;
	c = 1;
	d = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-' && s[i+1] == '+' || s[i] == '+' && s[i+1] == '-' || s[i] == '-' && s[i+1] == '-' || s[i] == '+' && s[i+1] == '+')
            return 0;
        if (s[i] == '-')
			c = c * -1;
		i++;
        }
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (d > (INT_MAX - (s[i] - '0')) / 10)
            if (c == 1) {
                return INT_MAX;
            }else {
                return INT_MIN;
            }
        d = (d * 10) + (s[i] - '0');
        i++;
	}
	return (d * c);

}

int main() {
    char str[] = "   -123abc";
    int r = myAtoi(str);
    printf("Result: %d\n", r);

    return 0;
}

