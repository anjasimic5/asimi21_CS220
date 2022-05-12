

typedef unsigned char byte;

typedef struct  {
	byte *digits;    // array of digits
	int n;           // the length of the array of digits
} BigInt;

extern BigInt *make_int(const char *s);

extern void print_int(const BigInt *b);

//extern BigInt *add(const BigInt *x, const BigInt *y);

extern BigInt *div10(const BigInt *x);

extern BigInt *mul10(const BigInt *x);

extern byte mod10(const BigInt *b);

extern int checksum(const BigInt *x);
