#include <stdlib.h>
#include <string.h>

/* Escape a string to be used in search filter.
Args:
	string - string to escape
Returns:
	escaped string or NULL
Copyright:
	2018, Development Gateway, GPLv3+ */
char *ldap_escape_filter(const char *string) {
	const char unsafe[] = "\\*()\0";
	/* for the result we need at least as many bytes as the source string plus terminator */
	int len = strlen(string) + 1;

	/* measure the required buffer size for the escaped string */
	int unsafe_len = strlen(string);
	for (i = 0; i < unsafe_len; i++) {
		for (j = 0; j < sizeof(unsafe); j++) {
			if (unsafe[j] == string[i]) {
				/* each escaped character adds 2 more bytes */
				len += 2;
				break;
			}
		}
	}

	/* allocate the buffer */
	result = (char *) malloc(len);
	if (!result) return NULL;

	return result;
}
