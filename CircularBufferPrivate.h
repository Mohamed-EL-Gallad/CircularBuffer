/*
Date: 12/06/2021
Author: Mohamed EL-Gallad
Description : This file will contain the errors MACROS .
*/

//if the buffer is full the CBuffer_PushData function should return the following MACROS 
#define ERROR_BUFFER_FULL     (unsigned char)0x01

//if the buffer is empty the CBuffer_PopData function should return the following MACROS 
#define ERROR_BUFFER_EMPTY    (unsigned char)0x02

//when a successful operation is porformed by either CBuffer_PushData or CBuffer_PopData they should return the following MACROS
#define SUCCESSFUL_OPERATION  (unsigned char)0x03

//the following MACROS is used as boolean return values for CBuffer_IsTheBufferFull and CBuffer_IsTheBufferEmpty
#define TRUE   (unsigned char)1
#define FALSE  (unsigned char)0