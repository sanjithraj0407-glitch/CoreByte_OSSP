#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    int index;

while (1) {
index = 0;

printf("skill2-shell> ");
fflush(stdout);

while (1) {
char ch;
if (read(STDIN_FILENO, &ch, 1) <= 0) {
return 0;
}
if (ch == '\n') {
buffer[index] = '\0';
printf("\n");
if (strcmp(buffer, "exit") == 0 ||
strcmp(buffer, "quit") == 0) {
printf("Exiting Skill 2 interactive loop...\n");
return 0;
}
printf("Command entered: %s\n", buffer);
break;
}
if (ch == 127 || ch == '\b') {
if (index > 0) {
index--;
printf("\b \b");
fflush(stdout);
}
continue;
}
if (index < BUFFER_SIZE - 1) {
buffer[index++] = ch;
write(STDOUT_FILENO, &ch, 1);
}
}
}
return 0;
}