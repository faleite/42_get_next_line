# Test 01
```c
int	main(void)
{
	char	*line;
	/* char	*line1; */
	/* char	*line2; */

	int		fd;
	fd = open("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	/* line1 = get_next_line(fd); */
	/* line2 = get_next_line(fd); */
	printf("%s", line);
	/* printf("%s", line1); */
	/* printf("%s", line2); */
	printf("\nFile Descriptor: %d\n\n", fd);
	printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	free(line);
	/* free(line1); */
	/* free(line2); */
	return (0);
}
```

# Test 02
```c
int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("test1.txt", O_RDONLY);
	printf("\nFile Descriptor: %d\n\n", fd);
	i = 1;
	while (i <= 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	return (0);
}
```