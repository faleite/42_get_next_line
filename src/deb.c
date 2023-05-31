# include    <stdio.h>
# include    <stdlib.h>
# include    <string.h>
# include    <unistd.h>
# include <fcntl.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

size_t    ft_strlen(char *s)
{
    int    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    if (s[i] == '\n')
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *string;
    int        i;
    int        j;

    i = 0;
    j = 0;
    string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!string)
        return (NULL);
    while (s1 && s1[i])
        string[j++] = s1[i++];
    i = 0;
    while (s2[i])
    {
        string[j++] = s2[i];
        if (s2[i++] == '\n')
            break ;
    }
    string[j] = 0;
    free(s1);
    return (string);
}

int    ft_clean(char *s)
{
    int    bool;
    int    i;
    int    j;

    i = 0;
    j = 0;
    bool = 0;
    while (s[i])
    {
        if (bool)
            s[j++] = s[i];
        if (s[i] == '\n')
            bool = 1;
        s[i] = 0;
        i++;
    }
    return (bool);
}

char    *get_next_line(int fd)
{
    static char    cursor[BUFFER_SIZE + 1];
    char        *line;

    if (fd < 0 || FOPEN_MAX < fd)
        return (NULL);
    line = NULL;
    while (cursor[0] || read(fd, cursor, BUFFER_SIZE) > 0)
    {
        line = ft_strjoin(line, cursor);
        if (ft_clean(cursor) == 1)
            break ;
        if (read(fd, cursor, 0) < 0)
        {
            free (line);
            return (NULL);
        }
    }
    return (line);
}

int    main(void)
{
    char    *line;
    /* char    *line1; */
    /* char    *line2; */
    int        fd;
    int        i;

    fd = open("test1.txt", O_RDONLY);
    /* line = get_next_line(fd); */
    /* line1 = get_next_line(fd); */
    /* line2 = get_next_line(fd); */
    /* printf("%s", line); */
    /* printf("%s", line1); */
    /* printf("%s", line2); */
    printf("\nFile Descriptor: %d\n\n", fd);
    i = 1;
    while (i <= 3)
    {
        line = get_next_line(fd);
        /* printf("line [%02d]: %s", i, line); */
        printf("%s", line);
        free(line);
        i++;
    }
    printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
    close(fd);
    /* free(line); */
    /* free(line1); */
    /* free(line2); */
    return (0);
}
