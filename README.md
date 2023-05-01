# General-purpose programming language compiler

This is a general-purpose compiler that compiles a high-level programming language into x86 machine code for execution on a computer. 

## Tools
- C++
- CMake 
- Bison
- Flex

## Language features
- **Math Expressions:** The language supports basic arithmetic operators such as +, -, *, and /, as well as parentheses for grouping expressions.
- **Variables:** The language supports variables, which can be assigned values using the = operator. Variables can be of any supported data type, including integers and strings.
- **Functions:** The language supports functions, which can be defined using the `func` keyword. Functions can have arguments and return values, and can be called from other parts of the code.
- **if Operator:** The language includes an if operator for conditional branching. 
- **Loop:** The language supports `for`  loop.
- **Typing:** The language is statically typed, which means that variables must be declared with their data type before they can be used.

In addition to these features, the language also includes the `sys_write()` function, which allows users to write data to the console.

## Example code

```golang
func main() {
	var str: string = "Hello, world";
	var str_size: u32 = 12;
	sys_write(str, str_size);
}
```
