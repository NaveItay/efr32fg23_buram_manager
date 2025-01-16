/*
 * efr32fg23_buram_manager.c
 *
 *  Created on: Sep 9, 2024
 *      Author: itay
 */

#include "libraries/efr32fg23_buram_manager/efr32fg23_buram_manager.h"

// ---------------------
// Initialization
// ---------------------

void BURAM_init(void)
{
  CMU_ClockEnable(cmuClock_BURAM, true);   // Enable clock for BURAM
}

// ---------------------
// Reading from BURAM
// ---------------------

uint8_t BURAM_read_uint8(uint8_t index, uint8_t offset) {
  if (index < 32 && offset < 4) {
      uint32_t reg_value = BURAM->RET[index].REG;
      return (uint8_t)((reg_value >> (offset * 8)) & 0xFF);
  } else {
      return 0;
  }
}

int8_t BURAM_read_int8(uint8_t index, uint8_t offset) {
  return (int8_t)BURAM_read_uint8(index, offset);
}

uint16_t BURAM_read_uint16(uint8_t index, uint8_t offset) {
  if (index < 32 && (offset == 0 || offset == 2)) {
      uint32_t reg_value = BURAM->RET[index].REG;
      return (uint16_t)((reg_value >> (offset * 8)) & 0xFFFF);
  } else {
      return 0;
  }
}

int16_t BURAM_read_int16(uint8_t index, uint8_t offset) {
  return (int16_t)BURAM_read_uint16(index, offset);
}

uint32_t BURAM_read_uint32(uint8_t index) {
  if (index < 32) {
      return BURAM->RET[index].REG;
  } else {
      return 0;
  }
}

int32_t BURAM_read_int32(uint8_t index) {
  return (int32_t)BURAM_read_uint32(index);
}

// ---------------------
// Writing to BURAM
// ---------------------

void BURAM_write_uint8(uint8_t index, uint8_t offset, uint8_t value) {
  if (index < 32 && offset < 4) {
      uint32_t current_value = BURAM->RET[index].REG;

      // Clear the targeted 8 bits
      current_value &= ~(0xFF << (offset * 8));

      // Set the new 8-bit value
      current_value |= ((uint32_t)value << (offset * 8));

      // Write back the modified value
      BURAM->RET[index].REG = current_value;
  }
}

void BURAM_write_int8(uint8_t index, uint8_t offset, int8_t value) {
  BURAM_write_uint8(index, offset, (uint8_t)value);
}

void BURAM_write_uint16(uint8_t index, uint8_t offset, uint16_t value) {
  if (index < 32 && (offset == 0 || offset == 2)) {
      uint32_t current_value = BURAM->RET[index].REG;

      // Clear the targeted 16 bits
      current_value &= ~(0xFFFF << (offset * 8));

      // Set the new 16-bit value
      current_value |= ((uint32_t)value << (offset * 8));

      // Write back the modified value
      BURAM->RET[index].REG = current_value;
  }
}

void BURAM_write_int16(uint8_t index, uint8_t offset, int16_t value) {
  BURAM_write_uint16(index, offset, (uint16_t)value);
}

void BURAM_write_uint32(uint8_t index, uint32_t value) {
  if (index < 32) {
      BURAM->RET[index].REG = value;
  }
}

void BURAM_write_int32(uint8_t index, int32_t value) {
  BURAM_write_uint32(index, (uint32_t)value);
}
