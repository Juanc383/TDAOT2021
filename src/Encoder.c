#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Encoder.h"

struct _frame{
    char* code;
    size_t length;
};

static ERROR isString(char* message){
    if(message == NULL){
        return FALSE;
    }return TRUE;
}

Message newMessageContainer(char* message){
    Message myMessage = NULL;
    myMessage = malloc(sizeof(Message));
    

    myMessage->code = calloc(BUFSIZ, sizeof(char));
    if(isString(message)){
        strncpy(myMessage->code, message, BUFSIZ);
        myMessage -> length = strnlen(message, BUFSIZ);
    }else myMessage -> length = 0;
    return myMessage;
}

char* getMessage(Message frame){
    if(isString(frame->code))return frame->code;
    else return NULL;
}

ERROR setMessage(Message frame, char* string){
    if(string){strncpy(frame->code, string, BUFSIZ);
    return TRUE;}
    else return FALSE;
}

ERROR encodeMessage(Message frame, size_t offset){
    if(!frame)return FALSE;
    if(!frame->code)return FALSE;
    for(int letter=0; letter<frame->length; letter++){
        frame->code[letter]+=offset;
    }return TRUE;
}



