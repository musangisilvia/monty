# Monty Interpreter


## *INTRODUCTION*

Monty 0.98 is a scripting language that is first compiled into Monty byte codes.
It relies on a unique stack with specific instructions to manipulate it.
By convention, the files containing Monty bytecodes have the *.m* extension. There is no more than one instruction per line  and there can be any number of spaces before or after the opcode and its argument.

## Monty byte code file

Monty byte code files can contain blank lines (empty or made of spaces only and any additional text after the opcode or its required argument is not taken into account:

```
musangi@ubuntu:~/monty$ cat -e testfiles/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
musangi@ubuntu:~/monty$
```

## The Monty program

- Usage: *monty file*
	* where *file* is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message *USAGE: monty file*, followed by a new line, and exit with the status *EXIT_FAILURE*
- If, for any reason, it's not possible to open the file, the program prints the error message *Error: Can't open file <file>*, followed by a new line, and exit with the status *EXIT_FAILURE*
	* where *<file>* is the name of the file.
- If the file contains an invalid instruction, the program prints the error message *L<line_number>: unknown instruction <opcode>*, followed by a new line, and exit with the status *EXIT_FAILURE*
	* where *<line_number>* is the line number where the instruction appears.
	* Line numbers always start at 1.
- The monty program runs the bytecodes line by line and stop if either:
	* it executed properly every line of the file.
	* it finds an error in the file.
	* an error occured
- If the program can't malloc anymore, the error message *Error: malloc failed* is printed, followed by a new line, and exit with status *EXIT_FAILURE*.
- Only *malloc* and *free* are used to manage heap memory.

### OPCODES AND FUNCTIONS

| OPCODE  | FUNCTION				  | Usage |
| :-----  | :------------------------------------ | :---  |
| *push*  | pushes an element to the stack.	  | push <int> |
| *pall*  | prints all the values on the stack starting from the top of the stack | pall |
| *pint*  | prints the value at the top of the stack, followed by a new line. | pint |
| *pop*   | removes the top element of the stack. | pop |
| *swap*  | swaps the top two elements of the stack. | swap |
| *add*   | adds the top two elements of the stack. - The result is stored in the second element. - The list is one element short. | add |
| *nop*   | does nothing | nop |
| *sub*   | subtracts the top element of the stack from the second top element of the stack.| sub |
| *div*     | divides the second top element of the stack by the top element of the stack | div |
| *mul*     | multiplies the second top element of the stack with the top element of the stack. | mul |
| *mod* | computes the rest of the division of the second top element of the stack by the top element of the stack | mod |
| *pchar* | prints the char at the top of the stack. | pchar |
| *pstr*  | prints the string starting at the top of the stack. | pstr |
| *rotl*  | rotates the stack to the top. | rotl |
| *rotr*  | rotates the stack to the bottom. | rotr |

#### OPCODE ERRORS AND EXIT CODES

| OPCODE  | ERROR		| CAUSE OF ERROR	| EXIT CODE  |
| :---    | :---		| :---			| :---	     |
| push    | L<line_number>: usage: push integer | Argument passed is not an integer or was not passed | EXIT_FAILURE |
| pall    | nothing is printed | empty stack | none |
| pint    | L<line_number>: can't pint, stack empty | empty  stack | EXIT_FAILURE |
| pop     | L<line_number>: can't pop an empty stack | empty stack | EXIT_FAILURE |
| swap    | L<line_number>: can't swap, stack too short | stack has less than 2 elements | EXIT_FAILURE |
| add     | L<line_number>: can't add, stack too short | stack has less than 2 elements | EXIT_FAILURE |
| sub     | L<line_number>: can't sub, stack too short | stack has less than 2 elements | EXIT_FAILURE |
| div     | L<line_number>: can't div, stack too short | stack has less than 2 elements | EXIT_FAILURE |
|         | L<line_number>: division by zero | top element of the stack is *0* | EXIT_FAILURE |
| mul     | L<line_number>: can't mul, stack too short | stack hass less than 2 elements | EXIT_FAILURE |
| mod     | L<line_number>: can't mod, stack too short | stack hass less than 2 elements | EXIT_FAILURE |
|         | L<line_number>: division by zero | top element of the stack is 0 | EXIT_FAILURE |
| 


