#include <stdio.h>
#include "CircularBuffer.h"
	
unsigned char poperror,pusherror;
int data,count;

CircularBuffer TX_Buffer;
int main()
{
	CBuffer_BufferInit(&TX_Buffer);
	printf("head ptr %p\n",TX_Buffer.headptr);
	printf("tail ptr %p\n",TX_Buffer.tailptr);
	printf("max ptr %p\n\n",&TX_Buffer.data[BUFFER_SIZE-1]);

	for(count=0;count<5;count++)
	{
		
		pusherror=CBuffer_PushData(&TX_Buffer,count*10);
		if(pusherror==ERROR_BUFFER_FULL)
		{
			printf("buffer is full\n");
		}
		else{
			printf("success push\n");
			
		}
	
	}
	
	printf("\n\n");

	 for(count=0;count<10;count++)
	{
	poperror=CBuffer_PopData(&TX_Buffer ,&data);
	if(poperror == ERROR_BUFFER_EMPTY)
	{
		printf("buffer is empty\n");
	}
	else{
		printf("pop value %d\n",data);
		}
	} 
	
	printf("\n\n");
	
	
	for(count=0;count<10;count++)
	{
	
		pusherror=CBuffer_PushData(&TX_Buffer,count*11);
		if(pusherror==ERROR_BUFFER_FULL)
		{
			printf("buffer is full\n");
		}
		else{
			printf("success push\n");
		    }
	}
	
	
    return 0;
}
