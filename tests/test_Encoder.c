#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "../libs/unity.h"
#include "../libs/Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE "LO HAS LOGRADO CHICX, MUY BIEN!\0"
static char* buffer = NULL;
static char* code = {SECRET_CODE};

void setUp(void){
    buffer = calloc(BUFSIZ, sizeof(char));
    strncpy(buffer, TEST_ARRAY, BUFSIZ);
}

void tearDown(void){
    free(buffer);
}

void test_encoderInit(void){
    puts("Positive Test");
    Message frame = newMessageContainer(TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(frame), strlen(TEST_ARRAY));

}

void test_encoderOffset(void){
    puts("Testing Encoder offset");
    Message frame = newMessageContainer(SECRET_CODE);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(frame), strlen(TEST_ARRAY));
    if(encodeMessage(frame, -2))
    puts(getMessage(frame));
}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_encoderInit, __LINE__);
    RUN_TEST(test_encoderOffset, __LINE__);
    return UNITY_END();

}