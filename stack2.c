#include "monty.h"
/**
 *_swap -main entry.
 *Description: Function that swaps the top 2 elements of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _swap(stack_t **top, unsigned int line_number)
{
	int num;

	if (*top == NULL || (*top)->next == NULL)
		swap_error(line_number);

	num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = num;
}
/**
 *_add -main entry.
 *Description: Function that adds the top two elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		add_error(line_number);

	tmp = (*top)->next;
	tmp->n += (*top)->n;
	pop_stack(top, line_number);
}
/**
 *_sub -main entry.
 *Description:Sub the top element of stck from the 2d top elem of the stak
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		sub_error(line_number);

	tmp = (*top)->next;
	tmp->n -= (*top)->n;
	pop_stack(top, line_number);
}
/**
 * _div - main entry
 * Description: Divides the seccond top element of the stack by the top element
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */

void _div(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		div_error(line_number);

	if ((*top)->n == 0)
		div_error2(line_number);

	tmp = (*top)->next;
	tmp->n = (tmp->n) / (*top)->n;
	pop_stack(top, line_number);
}
/**
 * _mul - main entry
 * Description: multiply the seccond top element of stack and the top element
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _mul(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		mul_error(line_number);

	tmp = (*top)->next;
	tmp->n *= (*top)->n;
	pop_stack(top, line_number);
}
