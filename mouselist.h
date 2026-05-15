/******************************************************************************
 * @file    mouselist.h
 * @brief   Header for the mouselist
 * @author  Mikhail ysph Subbotin, Phillip Blunck
 * @date    2026-05-14
 *
 * @details
 *
 ******************************************************************************/

#ifndef MOUSE_LIST_H
#define MOUSE_LIST_H

/* ============================================================================
 * INCLUDES
 * ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "miscellaneous.h"


/* ============================================================================
 * DEFINES / MACROS
 * ========================================================================== */

#define WIRED_OR_CABLE 			1
#define WIRELESS_RECEIVER 		2
#define CABLE_BUT_SECOND		2
#define ID_PRODUCT_UNIDENTIFIED 0xc539
#define ID_VENDOR 				0x046d


/* ============================================================================
 * TYPEDEFS / STRUCTS / ENUMS
 * ========================================================================== */

typedef struct Item {
    uint16_t idProduct;
    const char* name;
    uint8_t interface;
    uint8_t mByte3;

    struct Item* next;
} Item;


/* ============================================================================
 * PUBLIC CONSTANTS
 * ========================================================================== */

static const int size_of_Item = sizeof(Item);


/* ============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 * ========================================================================== */

int printAllItems(Item* node);
int deleteLinkedList(Item** head_ref);
int pushItem(Item** head_ref, const int new_idProduct,
    const char* new_name, const uint8_t new_interface,
    const uint8_t new_byte3);
bool searchItem(Item* head, const int search_idProduct);
const int getInterface(Item* head, const int search_idProduct);
const char* getName(Item* head, const int search_idProduct);
const uint8_t getByte3(Item* head, const int search_idProduct);
const int getSize(Item* head);
const int getNthId(Item* head, int nth);


/* ============================================================================
 * INLINE FUNCTIONS
 * ========================================================================== */


/* ============================================================================
 * C++ COMPATIBILITY
 * ========================================================================== */


/* ============================================================================
 * END OF FILE
 * ========================================================================== */


#endif  // MOUSE_LIST_H
