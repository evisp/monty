#include"monty.h"
/**
 * error_arguments -Main entry
 *Description: If user doesnt give file or more than valid arguments
 * Return: void
 **/
void error_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error -Main entry
 *Description: print message if its not possible to open the file
 * @argv: arguments received by main, ni this case te filename
 * Return: void
 **/
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * invalidInstruction_error -Main entry
 *Description: print message if le to open the filehas an invalid instruction
 * @invInstruction: instruction
 * @line: line
 * Return: void
 **/
void invalidInstruction_error(char *invInstruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, invInstruction);
	exit(EXIT_FAILURE);
}
/**
 * not_int_err -Main entry
 *Description: print message if parameter received is not integer
 * @line: line
 * Return: void
 **/
void not_int_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error -Main entry
 *Description: print message if cant malloc anymore
 * Return: void
 **/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
