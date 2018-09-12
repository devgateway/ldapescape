#include <stdlib.h>
#include <stdio.h>

char *ldap_escape_filter(const char *string);

void main(int argc, char *argv[]) {
	char *escaped;
	for (int i = 1; i < argc; i++) {
		escaped = ldap_escape_filter(argv[i]);
		printf("%s\n", escaped);
		free(escaped);
	}
}
