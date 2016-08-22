//
//  DHJson.h
//  dhspine
//
//  Created by youbin on 13-10-3.
//
//

#ifndef __dhspine__DHJson__
#define __dhspine__DHJson__

#include "cocos2d.h"

NS_CC_BEGIN

/* DHJson Types: */
#define Json_False 0
#define Json_True 1
#define Json_NULL 2
#define Json_Number 3
#define Json_String 4
#define Json_Array 5
#define Json_Object 6

/* The DHJson structure: */
typedef struct DHJson {
	struct DHJson* next;
	struct DHJson* prev; /* next/prev allow you to walk array/object chains. Alternatively, use getSize/getItemAt/getItem */
	struct DHJson* child; /* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */
    
	int type; /* The type of the item, as above. */
    int size; /* The number of children. */
    
	const char* valueString; /* The item's string, if type==Json_String */
	int valueInt; /* The item's number, if type==Json_Number */
	float valueFloat; /* The item's number, if type==Json_Number */
    
	const char* name; /* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
} DHJson;

/* Supply a block of DHJson, and this returns a DHJson object you can interrogate. Call Json_dispose when finished. */
DHJson* Json_create (const char* value);

/* Delete a DHJson entity and all subentities. */
void Json_dispose (DHJson* DHJson);

/* Returns the number of items in an array (or object). */
int Json_getSize (DHJson* DHJson);

/* Retrieve item number "item" from array "array". Returns NULL if unsuccessful. */
DHJson* Json_getItemAt (DHJson* DHJson, int item);

/* Get item "string" from object. Case insensitive. */
DHJson* Json_getItem (DHJson* DHJson, const char* string);
const char* Json_getString (DHJson* DHJson, const char* name, const char* defaultValue);
float Json_getFloat (DHJson* DHJson, const char* name, float defaultValue);
int Json_getInt (DHJson* DHJson, const char* name, int defaultValue);

/* For analysing failed parses. This returns a pointer to the parse error. You'll probably need to look a few chars back to make sense of it. Defined when Json_create() returns 0. 0 when Json_create() succeeds. */
const char* Json_getError (void);

NS_CC_END

#endif /* defined(__dhspine__DHJson__) */
