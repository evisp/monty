#include"monty.h"
/**
 * main - Main entry
 * Description: Monty bytecodes files interpreter
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error_arguments();
	open_and_read(argv);
	return (0);
}
