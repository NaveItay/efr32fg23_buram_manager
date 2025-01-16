/*
 * efr32fg23_buram_manager.h
 *
 *  Created on: Sep 9, 2024
 *      Author: itay
 *
 * This library provides functions to interface with the Backup RAM (BURAM) on the EFR32FG23
 * microcontroller. The BURAM (Backup Retention RAM) is a section of RAM that retains its content
 * even when the device is in deep sleep or low-power modes (such as EM4).
 *
 * The EFR32FG23 microcontroller has 32 Backup Retention (BURAM) registers, and each register
 * is 32 bits wide, which is equivalent to 4 bytes. Therefore, the total size of the available
 * retention memory is:
 *
 * 32 registers * 4 bytes = **128 bytes**
 *
 * This library includes functions for manipulating different data types (8-bit, 16-bit, and 32-bit)
 * stored in these retention registers. You can read or write specific values by specifying the
 * register index and the byte offset within each 32-bit register.
 *
 * The library also provides macros to access 32 individual retention registers (RET[0] to RET[31]).
 * Each retention register is a 32-bit register and can be accessed by an index.
 *
 * Parameters:
 * - `index`: This refers to the retention register index (from 0 to 31) in BURAM.
 *   BURAM consists of 32 retention registers (RET[0] to RET[31]), and the index specifies
 *   which retention register you want to access.
 *
 * - `offset`: This is the byte offset within the 32-bit retention register. A 32-bit register
 *   can hold 4 bytes of data, and the `offset` specifies which byte (0 to 3) to access.
 *   This is useful when working with 8-bit or 16-bit data types stored inside a 32-bit retention register.
 *
 * Examples:
 * - To read an 8-bit value from the second byte of RET[5]:
 *   `BURAM_read_uint8(5, 1); // Index 5 (RET[5]), offset 1 (second byte)`
 *
 * - To write a 16-bit value to the last two bytes of RET[10]:
 *   `BURAM_write_uint16(10, 2, 0x1234); // Index 10 (RET[10]), offset 2 (third byte)`
 */

#ifndef EFR32FG23_BURAM_MANAGER_H_
#define EFR32FG23_BURAM_MANAGER_H_

#include "em_device.h"     // Include device-specific definitions (must be first)
#include "em_cmu.h"        // Clock Management Unit (CMU) peripheral access
#include "stdint.h"

// Initialization
void BURAM_init(void);

// Functions to read from BURAM
uint8_t BURAM_read_uint8(uint8_t index, uint8_t offset);
int8_t BURAM_read_int8(uint8_t index, uint8_t offset);
uint16_t BURAM_read_uint16(uint8_t index, uint8_t offset);
int16_t BURAM_read_int16(uint8_t index, uint8_t offset);
uint32_t BURAM_read_uint32(uint8_t index);
int32_t BURAM_read_int32(uint8_t index);

// Functions to write to BURAM
void BURAM_write_uint8(uint8_t index, uint8_t offset, uint8_t value);
void BURAM_write_int8(uint8_t index, uint8_t offset, int8_t value);
void BURAM_write_uint16(uint8_t index, uint8_t offset, uint16_t value);
void BURAM_write_int16(uint8_t index, uint8_t offset, int16_t value);
void BURAM_write_uint32(uint8_t index, uint32_t value);
void BURAM_write_int32(uint8_t index, int32_t value);

#endif /* EFR32FG23_BURAM_MANAGER_H_ */
