#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
struct mymsg {
    long type;
    char text[100];
};
int main() {
    key_t key;
    int msgid;
    struct mymsg message;
    key = ftok("file.txt", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    int child = fork();
    if (child > 0) {
        message.type = 1;
        strcpy(message.text, "Hello from parent!");
        msgsnd(msgid, &message, sizeof(message.text), 0);
        printf("Parent: Message sent.\n");
        sleep(2);
        msgctl(msgid, IPC_RMID, NULL);
    }
    else if (child == 0) {
        sleep(1);
        msgrcv(msgid, &message, sizeof(message.text), 1, 0);
        printf("Child: Got message -> %s\n", message.text);
    }
    else {
        printf("Fork failed.\n");
        return 1;
    }
    return 0;
}


