#pragma once

#include "lexer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Flags.h"
#include "fileHelper.h"

#ifndef WIN_API
#include <Windows.h>
#endif

int lex(char* inputFileName)
{
	int errorSize = 0;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// Set up the STARTUPINFO structure
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	char* cmdLine = (char*)calloc(41 + strlen(inputFileName), 1);
	if (cmdLine == NULL)
	{
		if (userFlags.printLogs)
		{
			printf("error with path allocation\n");
		}
		return 0;
	}
	sprintf(cmdLine, "lexicalAndSyntaxAnalysis.exe %s %s", inputFileName, LEXER_OUTPUT_FILE_NAME);

	if (CreateProcessA(NULL,
		cmdLine,
		NULL,
		NULL,
		false,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{

		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);

		free(cmdLine);
		// Close process and thread handles. 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		errorSize = fileSize(ERROR_LOG_FILE);
		if (errorSize == 0)
		{
			if (userFlags.printLogs)
			{
				printf("Successfully activated lexer\n");
			}

			return true;
		}
		if (errorSize > 0)
		{
			if (userFlags.printLogs)
			{
				printf("Syntax errors were found:\n");
				writeLexErrorsIntoLog(errorSize);
			}
			if (userFlags.keepTokensErrorFile != 1)
			{
				DeleteFile(ERROR_LOG_FILE);
			}
			if (userFlags.keepTokenFile != 1)
			{
				DeleteFile(LEXER_OUTPUT_FILE_NAME);
			}
			return false;
		}
	}
	else // did not open file
	{
		free(cmdLine);
		if (userFlags.printLogs)
		{
			printf("Could not start lexer\n");
		}
		return false;
	}

}
