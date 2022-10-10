#include "cub3d.h"
void fun()
{
	char *a = malloc(sizeof(char) * 8);
	// a = "shjdf";
}
int main()
{
	fun();
	system("leaks a.out");
}