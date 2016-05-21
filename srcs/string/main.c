
#include <stdio.h>

char			*ft_strtrim_string(char const *s, char const *c);

int main(int argc, char **argv)
{
	char *string;

	if (argc == 3)
	{
			string = ft_strtrim_string(argv[1], argv[2]);
			printf("old->%s\nnew->%s\n", argv[1], string);
	}
	return (0);
}
