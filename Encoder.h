/// @file Encoder.h
/**
@page Encoder.h
**Author:** Cesar Angeles
**Date:**  2021
## Module API dedicated to create, manage and encode text messages.
It is mainly used to create text frames that have to be encoded for encryption, network connections, etc. 
*/
#ifndef Encoder_H
#define Encoder_H
/**
 * Give an error code IDE to test for encoding success or failure
 */ 
typedef enum{
    FALSE, ///< Error code when an Encoder process was not completed
    TRUE ///< Error code when an Encoder process was successful.
}ERROR;
/**
 * Stores a given text message to be encoded.
 * It stores the memory a given message occupies.
*/
typedef struct _frame* Message;
/**
 * Constructs a new message container with a given string. 
 * If message = NULL - then an empty container is returned.
 * 
 * @param[in] message to be stored within the container.  
 * @param[out] Message created container reference.
 */ 
Message newMessageContainer(char* message);
/**
 * Sets a particular string message to a Message container module.
 * 
 * @param[in] frame objective to modify. 
 * @param[in] string to be set
 * 
 * @returns ERROR code. TRUE if was successfully set. FALSE otherwise.
 */ 
ERROR setMessage(Message frame, char* string);
/**
 * Returns a given char* reference to the string within a frame object. 
 * 
 * @param[in] frame object to be analised.
 * @param[out] message starting pointer.
 */ 
char* getMessage(Message frame);

#endif
