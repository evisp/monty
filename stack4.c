#include "monty.h"
/**
 * pstr_stack -main entry
 * Description: prints the string starting at the top of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void pstr_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int ascii_num;

	(void)line_number;
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		ascii_num = tmp->n;

		if (ascii_num <= 0 || ascii_num > 127)
			break;
		putchar(ascii_num);
		tmp = tmp->next;
	}
	putchar('\n');
}
