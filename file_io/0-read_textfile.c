#include "main.h"

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int fd;
	ssize_t r, w;

	if (filename == NULL)
		return (0);
	/* open the file in read only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	/* allocate buffer for letters chars */
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}
	/* read letters bytes from file into buffer */
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	/* write buffer content to stdout */
	w = write(STDOUT_FILENO, buf, r);
	free(buf);
	close(fd);
	if (w != r)
		return (0);
	return (w);
}
