#include "cub3d.h"
void fun(int *b)
{
	 unsigned char *ptr = (unsigned char *)b;
	 for (int i =0; i < 4; i++)
	 {
		printf("%d  |   ", ptr[i]);
	 } 
	//  ptr[]

}
int main()
{

	char c;
	int a = 258;
	// char c = 2;
	// int a = 258;
	// if (c == (unsigned char)a)
	// {
	// 	printf("khdama \n");
	// }
	// int arr[] = {258};
	fun (&a);
}