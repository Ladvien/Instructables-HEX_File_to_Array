MAIN.C

int main(int argc, char *argv[])
{
	//If the user fails to give us two arguments yell at him.	
	if ( argc != 2 ) {
		fprintf ( stderr, "Usage: %s <readfile1>\n", argv[0] );
		exit ( EXIT_FAILURE );
	}
	// Data array
	uint8_t HEX_array[32768];

	// Bytes read into array.
	int HEX_array_size;
	
	//File to be loaded.	
	FILE *hex_file;

	//Open file using command-line info; for reading.
	hex_file = open_file (argv[0], "rb" );

	// Load the data from file
	HEX_array_size = hex_file_to_array(hex_file, HEX_array);


} // END PROGRAM