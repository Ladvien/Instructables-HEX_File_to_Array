DATA.C

int hex_file_to_array(FILE * file, uint8_t hex_data[])
{
	// 1. Get line count.
	// 2. Read a line. From ':' to '\n'
	// 3. Parse a line. 
	//   Repeat for all lines.

	// Data per line.
	uint8_t line_of_data[32];
	long int combined_address[4096];

	// Indices and counters
	int hex_line_index = 0;
	int chars_this_line = 0;
	int total_chars_read = 0;
	// How many lines in the hexfile?
	int hex_lines_in_file = 0;
	int bytes_this_line[4096];

	// Let's count how many lines are in this file.
	hex_lines_in_file = hex_file_line_count(file);

	// Indices for parsing.
	int line_index = 0;
	int byte_index = 0;
	bool read_line_ok = false;

	// Parse all lines in file.
	while(line_index < hex_lines_in_file)
	{
		read_line_ok = read_line_from_hex_file(file, line_of_data, &combined_address[line_index], &bytes_this_line[line_index]);
		if (!read_line_ok)
		{
			printf("Line#: %i. Dude, that's not data!\n", line_index);
			read_line_ok = true;
		}
		while(byte_index < bytes_this_line[line_index])
		{
			hex_data[combined_address[line_index] + byte_index] = line_of_data[byte_index];
			line_of_data[byte_index] = '\0';
			byte_index++;
		}
		byte_index = 0;
		line_index++;
	}

	// Print out parsed data.
	int k = 0;
	int j = 0;
	int printed_bytes = 0;
	while (k < hex_lines_in_file)
	{
		while(j < bytes_this_line[k])
		{
			printf("%02X ", hex_data[j+(printed_bytes)]);
			j++;
		}
		printed_bytes += bytes_this_line[k];
		j=0;
		printf("\n");
		k++;
	}
	
	return total_chars_read;
} // End hex_file_to_array