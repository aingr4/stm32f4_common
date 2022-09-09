/*
 * log.c
 *
 *  Created on: Sep. 4, 2022
 *      Author: Andrew Ingram
 */

#include <stdio.h>
#include <stdarg.h>
#include <log.h>
#include <inttypes.h>

static uint32_t log_id = 0;
static LogLevel_t log_level = LogLevel_DEBUG;

char* log_level_to_str(LogLevel_t level)
{
	char *levelStr = "";

	switch (level)
	{
		case LogLevel_INFO:
			levelStr = "INFO";
			break;
		case LogLevel_DEBUG:
			levelStr = "DEBUG";
			break;
		case LogLevel_ERROR:
			levelStr = "ERROR";
			break;
		default:
			break;
	}

	return levelStr;
}

void log_set_level(LogLevel_t level)
{
	log_level = level;
}

void _log_write(LogLevel_t level, const char * file_name, const int line, const char * func, const char * format_str, ...)
{
	if (level <= log_level)
	{
		va_list args;
		fprintf(LOG_OUTPUT_FILE,"[%"PRIu32"][file=\"%s\" line=\"%d\" func=\"%s\" log_level=\"%s\"] ", log_id++, file_name, line, func, log_level_to_str(log_level));


		va_start(args, format_str);
		vfprintf(LOG_OUTPUT_FILE, format_str, args);
		va_end(args);

		fprintf(LOG_OUTPUT_FILE, "\n");
	}
}


