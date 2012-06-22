echo flashing optic wire
avrdude -c usbasp -p m8 -U flash:w:WSN_Protocol_FW.elf.hex
pause