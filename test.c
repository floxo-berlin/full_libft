#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    // Test ft_printf
    ft_printf("Testing ft_printf: %d, %s, %c\n", 42, "Hello, World!", 'A');

    // Test get_next_line
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("Read line: %s", line);
        free(line);
    }
    close(fd);

    // Test ft_strdup
    char *str = "Hello, strdup!";
    char *dup = ft_strdup(str);
    ft_printf("Original: %s, Duplicate: %s\n", str, dup);
    free(dup);

    // Test ft_memmove
    char src[] = "memmove can be very useful......";
    ft_memmove(src + 20, src + 15, 11);
    ft_printf("After ft_memmove: %s\n", src);

    // Test ft_calloc
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr)
    {
        int i = 0;
        while (i < 5)
        {
            ft_printf("arr[%d] = %d\n", i, arr[i]);
            i++;
        }
        free(arr);
    }

    // Test ft_split
    char *split_str = "This.is.a.test.string";
    char **split_arr = ft_split(split_str, '.');
    for (int i = 0; split_arr[i] != NULL; i++)
    {
        ft_printf("split_arr[%d] = %s\n", i, split_arr[i]);
        free(split_arr[i]);
    }
    free(split_arr);

    return 0;
}
