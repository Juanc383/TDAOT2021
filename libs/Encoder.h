#ifndef Encoder_H
#define Encoder_H

typedef enum{
    FALSE,
    TRUE
}ERROR;

typedef struct _frame* Message;



Message newMessage(char* message);
ERROR setMessage(Message frame, char* string);
char* getMessage(Message frame);

#endif
