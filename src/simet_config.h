#ifndef SIMET_CONFIG_H

#define SIMET_CONFIG_H

#include <inttypes.h> 

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

typedef struct configEntry
{
	char* key;
	char* value;
	struct configEntry* next;
	int read;

} CONFIG_ENTRY;

typedef struct config 
{
	CONFIG_ENTRY* head;
	CONFIG_ENTRY* tail;
	uint8_t readSuccess;
} CONFIG;

void loadConfig(CONFIG* config, const char* filename);
uint8_t readEntry(char* line, CONFIG_ENTRY* entry);
void newEntry(CONFIG* config, char* line);
int getValue(CONFIG* config, const char* key, char* value);
char* getValuePtr(CONFIG* config, const char* key);
void destroyConfig(CONFIG* config);
void freeUnreadEntries(CONFIG* config);

#ifdef __cplusplus
}
#endif

#endif