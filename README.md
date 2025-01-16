# EFR32FG23 BURAM Manager Library

The `EFR32FG23 BURAM Manager` library provides an interface to access and manipulate the Backup RAM (BURAM) on the EFR32FG23 microcontroller. BURAM is a section of RAM that retains its content even in deep sleep or low-power modes (such as EM4). This library enables developers to perform read and write operations on BURAM efficiently using different data types.

---

## Features

- **Retention Memory Access**: Access 32 retention registers (RET[0] to RET[31]), each 32 bits wide (4 bytes).
- **Data Manipulation**: Read and write 8-bit, 16-bit, and 32-bit values at specific byte offsets.
- **Low-Power Compatibility**: Works seamlessly in low-power modes, retaining data in BURAM.
- **Ease of Use**: Simple API functions to initialize and manage BURAM operations.

---

## Getting Started

### Prerequisites

- **Hardware**: EFR32FG23 microcontroller.
- **Software**: Silicon Labs Gecko SDK with an embedded C development environment (e.g., Simplicity Studio).

---

## Installation

1. Clone or download the repository:
   ```bash
   git clone https://github.com/NaveItay/efr32fg23_buram_manager.git
2. Include the `efr32fg23_buram_manager.h` and `efr32fg23_buram_manager.c` files in your project directory.
3. Add the necessary include paths in your compiler settings to ensure the library files are recognized.
4. Make sure your project includes the required device-specific headers (`em_device.h`, `em_cmu.h`) for the EFR32FG23 microcontroller.

---

## API Reference

### Initialization

- **`void BURAM_init(void)`**  
  Initializes the BURAM by enabling its clock. This function must be called before using any BURAM-related operations.

### Reading Data

- **`uint8_t BURAM_read_uint8(uint8_t index, uint8_t offset)`**  
  Reads an 8-bit unsigned value from the specified register and byte offset.

- **`int8_t BURAM_read_int8(uint8_t index, uint8_t offset)`**  
  Reads an 8-bit signed value from the specified register and byte offset.

- **`uint16_t BURAM_read_uint16(uint8_t index, uint8_t offset)`**  
  Reads a 16-bit unsigned value from the specified register and byte offset (valid offsets: 0 or 2).

- **`int16_t BURAM_read_int16(uint8_t index, uint8_t offset)`**  
  Reads a 16-bit signed value from the specified register and byte offset (valid offsets: 0 or 2).

- **`uint32_t BURAM_read_uint32(uint8_t index)`**  
  Reads a 32-bit unsigned value from the specified register.

- **`int32_t BURAM_read_int32(uint8_t index)`**  
  Reads a 32-bit signed value from the specified register.

### Writing Data

- **`void BURAM_write_uint8(uint8_t index, uint8_t offset, uint8_t value)`**  
  Writes an 8-bit unsigned value to the specified register and byte offset.

- **`void BURAM_write_int8(uint8_t index, uint8_t offset, int8_t value)`**  
  Writes an 8-bit signed value to the specified register and byte offset.

- **`void BURAM_write_uint16(uint8_t index, uint8_t offset, uint16_t value)`**  
  Writes a 16-bit unsigned value to the specified register and byte offset (valid offsets: 0 or 2).

- **`void BURAM_write_int16(uint8_t index, uint8_t offset, int16_t value)`**  
  Writes a 16-bit signed value to the specified register and byte offset (valid offsets: 0 or 2).

- **`void BURAM_write_uint32(uint8_t index, uint32_t value)`**  
  Writes a 32-bit unsigned value to the specified register.

- **`void BURAM_write_int32(uint8_t index, int32_t value)`**  
  Writes a 32-bit signed value to the specified register.

---

## Usage Example

### Example: Writing and Reading from BURAM

```c
#include "efr32fg23_buram_manager.h"

int main(void)
{
    // Initialize BURAM
    BURAM_init();

    // Write a 16-bit value to RET[10] at offset 2
    BURAM_write_uint16(10, 2, 0x1234);

    // Read the 16-bit value back from RET[10] at offset 2
    uint16_t value = BURAM_read_uint16(10, 2);

    // Verify the value
    if (value == 0x1234)
    {
        // Perform an action (e.g., toggle an LED)
    }

    return 0;
}

```
