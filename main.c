
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1  
char *get_next_line(int fd) {
    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL; 
    }

    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!line) {
        return NULL; 
    }

    int i = 0;
    char c;
    ssize_t bytes_read;

    while ((bytes_read = read(fd, &c, 1)) > 0) {
        if (c == '\n') { 
            break;
        }
        line[i++] = c; 
    }

    if (bytes_read == -1 || (bytes_read == 0 && i == 0)) {
        free(line); 
		
	
        return NULL;
    }

    line[i] = '\0'; 
    return line;
}
int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line; 
    line = get_next_line(fd);
    printf("line1 :%s\n", line);
    line = get_next_line(fd);
    printf("line2 :%s\n", line);
	line = get_next_line(fd);
	printf("line3 :%s\n", line);

   
    system("leaks -q a.out");
    return (0);

}