
/*
Date: 12/06/2021
Author: Mohamed EL-Gallad
Description : This header file will contain the main Circular Buffer configuration "Buffer size and buffer data type"
*/
#ifndef _CIRCULARBUFFERCONFIG_H_
#define _CIRCULARBUFFERCONFIG_H_

/*
  The BUFFER_SIZE MACRO will define the buffer size 
  all the buffers that being created will have the same size defined by this MACRO  
*/
#define BUFFER_SIZE (int)10


/*
  BuffData_t MACRO will define the data type of the circular buffer elements "default type is int"
*/
#define BuffData_t   int

#endif