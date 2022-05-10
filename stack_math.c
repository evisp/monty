#include "monty.h"

void _swap(stack_t **top, unsigned int line_number)
{
	int num;

	if (*top == NULL || (*top)->next == NULL)
		swap_error(line_number);

	num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = num;
}

void _add(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp;

  if (*top == NULL || (*top)->next == NULL)
    add_error(line);

  tmp = (*top)->next;
  tmp->n += (*top)->n;
  _pop(top, line);
}

void _sub(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp;

  if (*top == NULL || (*top)->next == NULL)
	sub_error(line);

  tmp = (*top)->next;
  tmp->n -= (*top)->n;
  _pop(top, line);
}


void _div(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp;

  if (*top == NULL || (*top)->next == NULL)
    div_error(line);

  if ((*top)->n == 0)
    div_error2(line);

  tmp = (*top)->next;
  tmp->n /= (*top)->n;
  _pop(top, line);
}

void _mul(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp;

  if (*top == NULL || (*top)->next == NULL)
	mul_error(line);

  tmp = (*top)->next;
  tmp->n *= (*top)->n;
  _pop(top, line);
}
