#!/bin/sh
if [ "$(command -v valgrind)" == "" ]; then
	brew install valgrind
else
	norminette ../*.[ch]
	norminette ../libft/
	norminette ../libft/includes/
	make -j -C ../libft/
	make -j -C ../libft/ clean
	cd ../
	gcc -g -Wall -Werror -Wextra get_next_line.c ./test/main.c ./libft/libft.a -I./ -I./libft/includes/
	grep -a "BUFF_SIZE" get_next_line.h get_next_line.c
fi
