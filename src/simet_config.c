#include "simet_config.h"


#include <stdlib.h>
#include <string.h>

void loadConfig(CONFIG* config, const char* filename)
{
	FILE *file;
	char* line;
	int fileSize;

	config->head = NULL;
	config->tail = NULL;
	config->readSuccess = 1;

	file = fopen (filename,"r");
	if (!file)
	{
		config->readSuccess = 0;
		fprintf(stderr, "%s\n", "Error opening config file");
		return;
	}

	fseek (file, 0, SEEK_END);
	fileSize = ftell (file);
	rewind(file);
	line = (char *) malloc (sizeof (char) * (fileSize + 1));

	if (line == NULL)
	{
		config->readSuccess = 0;
		return;
	}

	while (fgets(line, fileSize, file) != NULL)
	{
		newEntry(config, line);
	}

	fclose (file);
	free(line);

}

uint8_t readEntry(char* line, CONFIG_ENTRY *entry)
{

	uint8_t success = 1;
	char* pch = NULL;
	char* pos = NULL;

	char trimmedLine[300];

	int i;
	int j = 0;

	for (i = 0; i < strlen(line) ; i++)
	{
		if ( line[i] != '\n' && line[i] != ' ')
		{
			trimmedLine[j++] = line[i];
		}
	}

	trimmedLine[j] = '\0';

	pos = strchr(trimmedLine, '#');
	if (pos != NULL)
	{
		*pos = '\0';
	}


	int len = strlen(trimmedLine);
	pos = strchr(trimmedLine, '=');
	if (pos != NULL)
	{
		*pos = ' ';

		int keyLen = pos - trimmedLine + 1;
		int valueLen = len - keyLen + 1;

		entry->key = (char*) malloc(keyLen*sizeof(char));
		entry->value = (char*) malloc(valueLen*sizeof(char));

		if (entry->key == NULL || entry->value == NULL)
			success = 0;
		else
			sscanf(trimmedLine, "%s %s", entry->key, entry->value);
	}

	return success;
	
}

void newEntry(CONFIG* config, char* line)
{

	CONFIG_ENTRY* entry = (CONFIG_ENTRY*) malloc(sizeof(CONFIG_ENTRY));
	entry->key = NULL;
	entry->value = NULL;
	entry->read = 0;

	if (entry == NULL)
	{
		config->readSuccess = 0;
	}
	else
	{

		uint8_t success =  readEntry(line, entry);
		config->readSuccess &= success;
		if (entry->key != NULL)
		{
			entry->next = NULL;

			if (config->head == NULL)
				config->head = entry;
			else
				config->tail->next = entry;

			config->tail = entry;
		}
	}
		
	

}

char* getValuePtr(CONFIG* config, const char* key)
{

	CONFIG_ENTRY* entry = config->head;

	while(entry != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			entry->read = 1;
			return entry->value;
		}
		entry = entry->next;
	}

	return NULL;
}

int getValue(CONFIG* config, const char* key, char* value)
{
	char* ptr = getValuePtr(config, key);

	if (ptr)
	{
		strcpy(value,ptr);
		return 1;
	}
	else 
		return 0;
}

void freeUnreadEntries(CONFIG* config)
{
	CONFIG_ENTRY* entry = config->head;
	CONFIG_ENTRY* nextEntry = NULL;

	while(entry != NULL)
	{
		nextEntry = entry->next;
		if (!entry->read)
		{
			if (entry->key)
				free(entry->key);
			if (entry->value)
				free(entry->value);

			entry->value = NULL;
			entry->key = NULL;
		}
		entry = nextEntry;
	}	
}

void destroyConfig(CONFIG* config)
{
	CONFIG_ENTRY* entry = config->head;
	CONFIG_ENTRY* nextEntry = NULL;

	while(entry != NULL)
	{
		nextEntry = entry->next;
		if (entry->key)
			free(entry->key);
		if (entry->value)
			free(entry->value);
		free(entry);
		entry = nextEntry;
	}

}

void printEntries(CONFIG* config)
{
	CONFIG_ENTRY* entry = config->head;

	printf("File read status: %d\n", config->readSuccess);

	while(entry != NULL)
	{
		printf("%s %s\n", entry->key, entry->value);
		entry = entry->next;
	}
}

/*

int main()
{
	CONFIG config;

	loadConfig(&config, "/home/gabriel/workspace/OpenWRT-SIMETBox/packages/simet-base-files/src/simet.conf");

	printEntries(&config);

	destroyConfig(&config);
}

*/
