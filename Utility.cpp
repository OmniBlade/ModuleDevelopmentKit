/*
	Licensed to the Apache Software Foundation (ASF) under one
	or more contributor license agreements.  See the NOTICE file
	distributed with this work for additional information
	regarding copyright ownership.  The ASF licenses this file
	to you under the Apache License, Version 2.0 (the
	"License"); you may not use this file except in compliance
	with the License.  You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing,
	software distributed under the License is distributed on an
	"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
	KIND, either express or implied.  See the License for the
	specific language governing permissions and limitations
	under the License.
*/
#define MDK_EXPORT_FUNCTIONS 1 /*Export the methods*/

#include "Utility.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

bool MDKDLLAPI strendswith(const char *buffer, const char *what)
{
	int endsize = strlen(what), buffsize = strlen(buffer);
	char *checkbuf = (char *)malloc(sizeof(char) * (endsize + 1));

	for (; endsize > -1; buffsize--, endsize--)
	{
		checkbuf[endsize] =  buffer[buffsize];
	}

	if (strcmp(checkbuf, what) == 0)
	{
		if (checkbuf)
			free(checkbuf);

		return true;
	}

	if (checkbuf)
		free(checkbuf);

	return false;
}

bool MDKDLLAPI strdelete(char *buffer, int buffersize, int number)
{
	int counter = 0;

	if (buffersize < number)
		return false;

	buffersize -= number;

	for (; counter < buffersize; counter++, number++)
	{
		buffer[counter] = buffer[number];
	}

	buffer[counter] = '\0';

	return true;
}

void MDKDLLAPI strrand(char *buffer, int buffersize, const char *table)
{
	int table_len = strlen(table), i = 0;

	for (; i < (buffersize - 1); i++)
	{
		int randnum = rand() % (table_len - 1);
		buffer[i] = table[randnum];
	}

	buffer[i] = '\0';
}

bool MDKDLLAPI strfind(char *buffer, const char what)
{
	while (*buffer != '\0')
	{
		if (*buffer == what)
			return true;

		buffer++;
	}

	return false;
}

bool MDKDLLAPI strstartswith(const char* buffer, const char* what)
{
	unsigned int whatsize = strlen(what), count = 0;
	char *checkbuf = (char *)malloc(sizeof(char) * (whatsize + 1));

	if (whatsize > strlen(buffer))
		return false;
	
	for (; count < whatsize; count++)
	{
		checkbuf[count] = buffer[count];
	}
	checkbuf[count] = '\0';

	if (strcmp(checkbuf, what) == 0)
	{
		if (checkbuf)
			free(checkbuf);

		return true;
	}

	if (checkbuf)
		free(checkbuf);

	return false;
}

void MDKDLLAPI CmdLoginInfoDisplay(const char *name, const char *type, const char *fmt, ...)
{
	va_list vl;
	
	if (!fmt)
		return;
	
	if (name)
		printf("[%s] ", name);
	
	if (type)
		printf("[%s] ", type);
		
	printf(">> ");
	va_start(vl, fmt);
	vprintf(fmt, vl);
	va_end(vl);
	printf("\n");
}
