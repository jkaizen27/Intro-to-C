#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
	while (*y != '\0') {
		*x = *y;
		x++;
		y++;
	}
	*x = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
	while (*str != '\0') {
		if (*str == c) {
			return str;
		}
		str++;
	}
	return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
	    while (*haystack != '\0') // While there's a value for haystack and not "\0" aka 0 or false
    {
        char *pHaystack = haystack; // Set up a pointer to the pointer to haystack string, because we need return a pointer at the end

        while (*haystack != '\0' &&
               *needle != '\0' &&
               *haystack == *needle) // While both values exist and are equal to each other
        {
            haystack++; // Increment the address of haystack by 1 byte (char = 1 byte) in memory, subsequently the next letter
            needle++;   // Increment the address of needle by 1 byte (char = 1 byte) in memory, subsequently the next letter
        }

        if (*needle == '\0') // If the value of needle reaches the end
        {
            return pHaystack; // Return the pointer to *haystack, pHaystack incremented only if
        }

        haystack++; // Increments haystack if the letters don't match, pHaystack also updates
    }

    return NULL; // If nothing is found
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
