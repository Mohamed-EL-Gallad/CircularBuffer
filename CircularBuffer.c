/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "CircularBuffer.h"
//#include "CircularBufferPrivate.h"
#include <stdio.h>

void CBuffer_BufferInit(CircularBuffer *BufferPtr)
{
    BufferPtr->headptr=BufferPtr->data;;
    BufferPtr->tailptr=BufferPtr->data;
    BufferPtr->AvailablePosition =BUFFER_SIZE;
}

unsigned char CBuffer_PushData(CircularBuffer* Buffer ,BuffData_t data)
{
	unsigned char PushDataError;
    if(Buffer->AvailablePosition>0)
    {
	*(Buffer->headptr)=data;
	PushDataError=SUCCESSFUL_OPERATION;
    Buffer->AvailablePosition--;
	    if(Buffer->headptr == &Buffer->data[BUFFER_SIZE-1])
	     {
		    Buffer->headptr =Buffer->data;
	     }
	     else
		 {
			 Buffer->headptr++;
		 }
      }
     else 
	{
		PushDataError=ERROR_BUFFER_FULL;
	}
    return PushDataError;
}

unsigned char CBuffer_PopData(CircularBuffer* Buffer, BuffData_t *DataPtr)
{
	unsigned char PopDataError;
	if(Buffer->AvailablePosition < BUFFER_SIZE)
	{
    *DataPtr=*(Buffer->tailptr);
	PopDataError =SUCCESSFUL_OPERATION;
    Buffer->AvailablePosition++;
	 if(Buffer->tailptr == &Buffer->data[BUFFER_SIZE-1])
	     {
		    Buffer->tailptr =Buffer->data;
	     }
	     else
		 {
			 Buffer->tailptr++;
		 }
	}
	else
	{
    PopDataError=ERROR_BUFFER_EMPTY;
	}
	return PopDataError;
}

void CBuffer_BufferReset(CircularBuffer *BufferAddress)
{
	CBuffer_BufferInit(BufferAddress);
}

unsigned char CBuffer_IsTheBufferEmpty(CircularBuffer *Buffer)
{
	unsigned char EmptyFlag;
	if(Buffer->AvailablePosition==BUFFER_SIZE)
	{
		EmptyFlag=TRUE;
	}
	else
	{
		EmptyFlag=FALSE;
	}
	return EmptyFlag;
}

unsigned char CBuffer_IsTheBufferFull(CircularBuffer *Buffer)
{
	unsigned char FullFlag;
	if(Buffer->AvailablePosition==0)
	{
		FullFlag=TRUE;
	}
	else
	{
		FullFlag=FALSE;
	}
	return FullFlag;
}