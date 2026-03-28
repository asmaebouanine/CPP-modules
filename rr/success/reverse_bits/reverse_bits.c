unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int byts;
	unsigned char resul;

	byts = 8;
	resul = 0;
	while (byts--)
	{
		resul = (resul << 1) | (octet & 1);
		octet >>= 1;
	}
	return (resul);
}
