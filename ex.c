# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int main()
{
	int fds[2];
	char *re;
	
	pipe(fds);
	printf("%d, %d\n", fds[0], fds[1]);
	write(fds[1], "123\n", 5);
	read(fds[0], re, 5);
	write(2, re, 5);
	// Тоже самое
	dup2(fds[0], 0);
	write(fds[1], "123\n", 5);
	read(0, re, 5);
	write(2, re, 5);
	return (0);
}

// fds[0] - для вывода, fds[1] - для записи
// всё что приходит в fds[1] можно считать c fds[0]