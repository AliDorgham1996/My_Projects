#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

#define F_CPU	8000000UL

#include "avr/io.h"
#include "avr/interrupt.h"
#include "bit_handle.h"
#include "data_types.h"

#define INT_EEPROM_SIZE    4095

Bool Int_EEPROM_Write(u16 address , u8 data);
Bool Int_EEPROM_Read(u16 address , u8* data);
Bool EEPROM_Update(u16 address , u8 data);


#endif /* INTERNAL_EEPROM_H_ */