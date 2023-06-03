# Clean line solutions

## Work 
```c
int    clean_line(char *buffer)
{
    int    i;
    int    j;
    int    result;
    int    end;
    
    i = 0;
    j = 0;
    result = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        buffer[i] = 0;
        i++;
    }
    if (buffer[i] == '\n')
        result = 1;
    i++;
    end = i;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    buffer[j] = '\0';
    while (end--)
        buffer[j++] = 0;
    return (result);
}
```

## Work very well
```c
size_t	clean_line(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	result = 0;
	while (buffer[i])
	{
		if (result)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			result = 1;
		buffer[i] = 0;
		i++;
	}
	return (result);
}
```
