#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "unity.h"
#include "Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE 77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33 

static char* buffer = NULL;
static int code[] = {SECRET_CODE};

void setUp(void){
    buffer = calloc(BUFSIZ, sizeof(char));
    strncpy(buffer, TEST_ARRAY, BUFSIZ);
}

void tearDown(void){
    free(buffer);
}

void test_encoderInit(void){
    puts("Positive Test");
    Message frame = newMessage(TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(frame), strlen(TEST_ARRAY));

}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_encoderInit, __LINE__);
    return UNITY_END();

}