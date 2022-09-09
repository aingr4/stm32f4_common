/*
 * common.c
 *
 *  Created on: Sep. 7, 2022
 *      Author: Andrew Ingram
 */

#include <common.h>

char* coreStatusToStr(CoreStatus status)
{
	switch (status)
	{
	case CoreStatus_OK:
		return "OK";
	case CoreStatus_ERROR:
		return "Generic Error";
	default:
		return "Unknown Status";
	}
}


