#include "Internal_EEPROM.h"

Bool EEPROM_Update(u16 address , u8 data)
{
	Bool result = FALSE;
	u8 LocalData ;
	Int_EEPROM_Read(address , &LocalData);
	if(LocalData != data)
	{
		if(address <= INT_EEPROM_SIZE)
		{
			while((EECR & (1<<EEWE)));
			EEAR = address;
			EEDR = data;
			EECR |= (1<<EEMWE);
			EECR |= (1<<EEWE);
			result = TRUE;
		}
	}
	return result;
}

Bool Int_EEPROM_Write(u16 address , u8 data)
{
	Bool result = FALSE;
	if(address <= INT_EEPROM_SIZE)
	{
		while((EECR & (1<<EEWE)));
		EEAR = address;
		EEDR = data;
		EECR |= (1<<EEMWE);
		EECR |= (1<<EEWE);
		result = TRUE;
	}
	return result;
}
Bool Int_EEPROM_Read(u16 address , u8* data)
{
	Bool result = FALSE;
	if(address <= INT_EEPROM_SIZE)
	{
		while((EECR & (1<<EEWE)));
		EEAR  = address;
		EECR |= (1<<EERE);
		*data = EEDR;
		result = TRUE;
	}
	return result;
}