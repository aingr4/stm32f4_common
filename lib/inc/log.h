/*
 * log.h
 *
 *  Created on: Sep. 4, 2022
 *      Author: Andrew Ingram
 */

#ifndef LOG_H_
#define LOG_H_

#include <string.h>
#include <stdio.h>

/* DEFINES */
#define ENABLE_LOGGING
#define LOG_LEVEL LogLevel_DEBUG
#define LOG_OUTPUT_FILE stdout

/* ENUMS */
typedef enum {
	LogLevel_ERROR = 0,
	LogLevel_INFO  = 1,
	LogLevel_DEBUG = 2,
} LogLevel_t;

/* FUNCTIONS */
void _log_write(LogLevel_t, const char * file_name, const int line, const char * func, const char * format_str, ...);

/* MACROS */
#define LOG(log_level, format_str, ...) _log_write(log_level, __FILE_NAME__, __LINE__, __func__, format_str, ##__VA_ARGS__)


#endif /* LOG_H_ */
