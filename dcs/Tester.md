# Test 01
```c
int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("\nFile Descriptor: %d\n\n", fd);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
```
