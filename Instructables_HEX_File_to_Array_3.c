DATA.C

void clear_special_char(FILE * file, uint8_t * charToPut, int * totalCharsRead)
{
	//Removes CR, LF, ':'  --Bdk6's
	while (*charToPut == '\n' || *charToPut == '\r' || *charToPut ==':'){
		(*charToPut = fgetc (file));
		*totalCharsRead++;
	}
}