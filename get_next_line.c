#include "get_next_line.h"
// static char *set_line(char *str)
// {
//     static size_t track;
//     size_t pos_nline;
//     char *line ;

//     if (!str || !str[track])
//         return (NULL);
//     if (ft_strchr(str + track, '\n'))
//         pos_nline = ft_strchr(&str[track], '\n') - str;
//     else 
//         pos_nline = ft_strlen(str);
//     if (str[pos_nline] == '\n')
//         pos_nline++;
//     line = ft_substr(str, track, pos_nline - track);
//     track = pos_nline;
//    return (line);
// } 
//0x7f81b2d00000
//0x7ff8c9500000
//0x7f8d9fd00000
static char *set_line(char **str)
{
    size_t pos_nline;
    char *line;
    char *temp;
    if (!(*str) || !(*str)[0])
        return (NULL);
    if (ft_strchr(*str, '\n'))
        pos_nline = ft_strchr(*str, '\n') - *str;
    else
        pos_nline = ft_strlen(*str);
    if ((*str)[pos_nline] == '\n')
        pos_nline++;
    line = ft_substr(*str, 0, pos_nline);
    if (!line)
        return (free(*str), NULL);
    temp = ft_substr(*str, pos_nline, ft_strlen(*str) - pos_nline);
    if (!temp) 
        return (free(line), free(*str), NULL);
    free(*str);
    *str = temp;   
    return (line);
}
static char *ft_readfile(int fd, char **str, char *buffer)
{
    ssize_t readbuf;
    char *line;
 
    readbuf = read(fd, buffer, BUFFER_SIZE);
    if (readbuf < 0)
        return (free(buffer),free(*str), NULL);
    while (readbuf)
    {
        if (readbuf < 0)
            return (free(buffer),free(*str), NULL);
        buffer[readbuf] = '\0';
        char *temp = *str;
        if (readbuf == 0)
            return (free(buffer), NULL);
        *str = ft_strjoin(*str, buffer);
        if (!(*str))
            return (free(buffer), NULL);
        free(temp);
        if (ft_strchr(buffer, '\n'))
            break ;
        readbuf = read(fd, buffer, BUFFER_SIZE);
    }
    line = set_line(str);
    free(buffer);
    return (line);  
}


char *get_next_line(int fd){
    char *line;
    char *buffer;
    static char *str;


    
    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) < 0) {
        if (str)
            free(str);
        return (NULL);
    }
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    
    if (!buffer) {
        if (str)
            free(str);
        return (NULL);
    }
    line = ft_readfile(fd, &str, buffer);
    if (!line) {
        free(str);
        return (NULL);
    }

    return (line);
}
#include <stdio.h>

void l() { 
    system("leaks a.out");
}
int main()
{
    // atexit(l);
    int fd = open("test.txt", O_RDONLY);
    char *line; 
    // int tab[fs1, fd2, fd3]
    line = get_next_line(fd);
    printf("line1 :%s", line);
    // free(line);
    // line = NULL;
    // printf("----------------------------\n");
    line = get_next_line(fd);
    //printf("line2 :%s", line);//
    // free(line);
    // line = NULL;
    // //   printf("----------------------------\n");
    // line = get_next_line(fd);
    // printf("line3 :%s", line);
    // free(line);
    // line = NULL;
    // //   printf("----------------------------\n");
    // line = get_next_line(fd);
    // printf("line4 :%s", line);
    // //   printf("----------------------------\n");
    // free(line);
    // line = NULL;
    
    return (0);

}
