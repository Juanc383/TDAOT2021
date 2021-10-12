#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/unity.h"
#include "../libs/Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE "77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33"
#define CODE 77, 112, 33, 105, 98, 116, 33, 109, 112, 104, 115, 98, 101, 112, 34, 33


static char* buffer = NULL;
static int code[] = {CODE};

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
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}

void test_encoderSetMessage(void){
    puts("Positive Test Set Message");
    Message frame = newMessageContainer(TEST_ARRAY);
    setMessage(&frame,TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}

void test_encoderGetMessage(void){
    puts("Positive Test Get Message");
    Message frame = newMessageContainer(TEST_ARRAY);
    getMessage(&frame);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(&frame), strlen(TEST_ARRAY));
}



int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_encoderInit, __LINE__);
    RUN_TEST(test_encoderSetMessage, __LINE__);
    RUN_TEST(test_encoderGetMessage, __LINE__);

    return UNITY_END();

}
