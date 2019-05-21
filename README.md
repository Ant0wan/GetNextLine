# Getnextline [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

---

Getnextline [a 42 project] is a function that reads from file descriptors and returns a line - ending with a newline at each call.

---

## Description

Getnextline is a function that returns a line read from a file descriptor.

It has the following prototype:

```
int	get_next_line(const int fd, char **line);
```

- first paramter is the file descriptor that is used to read

- second parameter is the address of a pointer to a character that is used to save the line read from the file descriptor

The return value is either 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has occurred respectively.

Calling `get_next_line` in a loop will then allow a program to read on a file descriptor one line at a time until the end of the file.

```C
while ((ret = get_next_line(fd, &ptr)) > 0)
{
	if (ptr){free(ptr);}
	printf("%d,%s\n", ret, ptr);
}
```

- a "line" here is defined as a succession of characters that en with '\n' (ascii code 0x0a)

The end of line character can be set by modifying `#define CHR_SRCH '\n'` to the appropriate looked up character in this macro.

---

## Usage

- Clone repository

```shell=
git clone https://github.com/Ant0wan/Getnextline.git && cd Getnextline
```

- Compile lib used by getnextline: `Libft`

```shell=
make -C -j ./libft/
```

- Compile with a main

```shell=
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
```

---

## Test

- Go to `./test/

```shell=
cd ./test/
```

- Run check.sh script

Warning: check.sh will install valgrind if not found !

```shell=
sh check.sh
```

- Run `a.out` with valgrind debug options and text file as argument

```shell=
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out ./test/text
```

- Uncomment `__attribute((destructor)) void    end(void);` and `void	end(void){ while(1); }` to use `leaks`
