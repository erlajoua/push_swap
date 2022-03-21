## push_swap

### Description ✨
Push_swap is a 42 project, written in C, which consisted in sorting a stack.
As parameters, a list of unique unsorted integers. These integers are contained in the stack **A**, but there is also a stack **B** that you can use to sort **A**.

To do this, a list of operations is available:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no element.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no element.
- ss (swap a and b): sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : (reverse rotate a and b): rra and rrb at the same time.

Another checker program is available, which depending on the given inputs, displays **OK** or **KO** if the integer list is sorted at the end of the sort.

### Main purpose :page_facing_up:
The objective is to use as few operations as possible to sort the A list.
The necessary operations are displayed on the output.
The objective of this exercise is to understand the notion of optimization, and the complexity of each program, also to discover the different methods of sorting in algorithm. 

### How to use :rocket:
First, run ``make``
Once executed, two programs appeared, `push_swap` and `checker`

``./push_swap 5 2 3 1``
is going to show you the operations needed to sort these 4 integers in the stack A.

if you want to check if the list is sorted, use the checker as below:
``./push_swap 5 2 3 1 | ./checker 5 2 3 1``

**OK** if the list is well sorted or **KO** if not.
