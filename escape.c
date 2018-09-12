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
	const char escaped[] = "5c2a282900";
	char *result;
	/* for the result we need at least as many bytes as the source string plus terminator */
	int len, new_len;
	len = new_len = strlen(string);

	/* measure the required buffer size for the escaped string */
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < sizeof(unsafe); j++) {
			if (unsafe[j] == string[i]) {
				/* each escaped character adds 2 more bytes */
				new_len += 2;
				break;
			}
		}
		new_len++;
	}

	/* allocate the buffer */
	result = (char *) malloc(new_len + 1);
	if (!result) return NULL;

	int pos = 0;
	for (int i = 0; i < len; i++) {
		/* copy each character, even if it's unsafe */
		result[pos] = string[i];
		for (int j = 0; j < sizeof(unsafe); j++) {
			if (unsafe[j] == string[i]) {
				result[pos] = '\\';
				memcpy(result + pos + 1, escaped + j * 2, 2);
				pos += 2;
				break;
			}
		}
		pos++;
	}

	result[new_len] = '\0';

	return result;
}
