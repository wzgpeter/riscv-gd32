////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-30
//

#include "FreeRTOS.h"
#include "task.h"


//TODO ... develop more efficient code in future

void memcpy(void *dst, void *src, size_t len)
{
	uint32_t i;
	uint8_t *pDst = (uint8_t *)dst;
	uint8_t *pSrc = (uint8_t *)src;

	for (i=0; i<len; i++)
		pDst[i] = pSrc[i];
}

void memset(void *dst, int val, size_t len)
{
	uint32_t i;
	uint8_t *pDst = (uint8_t *)dst;

	for (i=0; i<len; i++)
		pDst[i] = (uint8_t)val;
}

