/**
 *  Copyright Snake Oil, Ltd
 **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static unsigned char keytable[] = {
        0x1c, 0x17, 0x62, 0x17, 0x80, 0x46, 0x9a, 0x65, 0x26, 0xd4, 0x4b, 0xaf, 0x5b, 0xb3, 0x9b, 0xd9,
        0x94, 0xac, 0xde, 0x19, 0x40, 0xbd, 0x42, 0xd2, 0xf4, 0x71, 0x19, 0xf7, 0xb7, 0x28, 0xfa, 0x1b,
        0x78, 0x9f, 0xff, 0xd5, 0x8a, 0xd6, 0xff, 0xa3, 0x90, 0xec, 0x4d, 0x9c, 0x1b, 0xb4, 0x8a, 0xf9,
        0x8c, 0xc2, 0x51, 0x87, 0x1b, 0x3a, 0xca, 0xab, 0xc1, 0xe3, 0xaf, 0x0c, 0x78, 0x98, 0xdd, 0xe2,
        0xac, 0x32, 0x40, 0xca, 0xd2, 0xef, 0xb4, 0x2f, 0xb5, 0xb3, 0x91, 0xd8, 0xd7, 0xc3, 0x8d, 0xc4,
        0xd1, 0xd3, 0x9d, 0xa0, 0x31, 0xbe, 0x4a, 0x48, 0x8b, 0x73, 0x00, 0x7f, 0x0b, 0xe6, 0x7d, 0x4a,
        0x9a, 0x68, 0xc1, 0x12, 0xb7, 0xe8, 0x52, 0x14, 0x29, 0xfc, 0xb3, 0x7e, 0xc5, 0x7d, 0x3d, 0x29,
        0xca, 0x0c, 0x13, 0x38, 0xa3, 0x44, 0x09, 0x43, 0x66, 0xd9, 0x4e, 0x6a, 0xbb, 0x56, 0x43, 0x63,
        0x6b, 0xf7, 0xbf, 0x79, 0x77, 0x50, 0xb7, 0xa3, 0xc8, 0x2f, 0xa6, 0xc6, 0x64, 0x17, 0x84, 0x47,
        0xde, 0xbe, 0xed, 0x24, 0x7e, 0xa3, 0x0c, 0x88, 0xcd, 0xe7, 0xd4, 0x5d, 0xa0, 0xcc, 0xbf, 0xe9,
        0x00, 0xe2, 0x52, 0x8a, 0xf0, 0x44, 0x7f, 0xc6, 0xee, 0xe9, 0x5c, 0xa6, 0xc6, 0x3f, 0x1d, 0xf7,
        0x48, 0x96, 0xd7, 0x94, 0x6c, 0x97, 0x37, 0x64, 0xd8, 0x04, 0x5c, 0xb5, 0xa8, 0x08, 0x76, 0xef,
        0xc5, 0x23, 0xf6, 0x51, 0x48, 0x37, 0xb7, 0xab, 0x1a, 0x36, 0xff, 0x10, 0xbd, 0xb6, 0xae, 0x5a,
        0x9c, 0xe2, 0xc8, 0x1d, 0xdf, 0x35, 0xe3, 0xfb, 0xd8, 0x96, 0xbd, 0xc9, 0x37, 0x0a, 0xb4, 0x75,
        0x58, 0x6c, 0x8d, 0x5f, 0x8d, 0xad, 0xa0, 0x31, 0x6e, 0x1e, 0xe2, 0x44, 0x01, 0x72, 0x48, 0x5a,
        0x2c, 0x4c, 0x4f, 0x47, 0x76, 0xca, 0x1d, 0x61, 0xff, 0xed, 0x08, 0x3f, 0xa3, 0xcf, 0x9e, 0x7b,
        0xc9, 0x1e, 0xe2, 0x8f, 0xef, 0x60, 0xc6, 0xe6, 0xd6, 0x3a, 0x2f, 0x6d, 0x58, 0xc9, 0x3f, 0x35,
        0x38, 0x37, 0xba, 0x5a, 0x05, 0x8f, 0x6a, 0x2f, 0x9c, 0x47, 0xbd, 0xdb, 0xb1, 0x43, 0x67, 0x1d,
        0x17, 0x04, 0xca, 0x73, 0x8a, 0x4a, 0xd7, 0xe3, 0x7a, 0xb9, 0xb0, 0x52, 0xfe, 0x62, 0x25, 0xc4,
        0x9b, 0x2e, 0x92, 0x9f, 0x69, 0xee, 0xda, 0x26, 0x5e, 0xb7, 0x16, 0x19, 0x2e, 0x98, 0xde, 0x16,
        0xb0, 0xdb, 0x52, 0x31, 0x70, 0xe8, 0xaf, 0x04, 0xc6, 0xea, 0xc5, 0xd2, 0x06, 0xbc, 0x53, 0x70,
        0x16, 0xb7, 0xc3, 0xc2, 0xae, 0x08, 0xb1, 0x86, 0x36, 0x79, 0x5b, 0x37, 0x2e, 0xca, 0x90, 0x42,
        0x46, 0xa0, 0x24, 0x25, 0x61, 0x06, 0x79, 0xca, 0x9b, 0x79, 0x58, 0x45, 0xa7, 0x74, 0xf2, 0xfd,
        0x06, 0xb8, 0xd1, 0xd3, 0x7a, 0x75, 0x4e, 0x80, 0x78, 0xef, 0x1f, 0x30, 0x56, 0x65, 0x81, 0x29,
        0x89, 0x9d, 0x05, 0x06, 0xff, 0xa5, 0x3d, 0x6f, 0x9d, 0x8c, 0xba, 0x01, 0xf9, 0x66, 0xf0, 0x3c,
        0x8c, 0x40, 0x5b, 0x6c, 0xb7, 0xea, 0xee, 0x71, 0x6e, 0xe0, 0x7b, 0x22, 0x08, 0xc7, 0x9c, 0xcc,
        0xad, 0x28, 0xd5, 0xa4, 0xc7, 0x06, 0x55, 0x45, 0x7f, 0xcc, 0x18, 0xa6, 0x46, 0x74, 0xf4, 0x1c,
        0x28, 0x5a, 0x59, 0x6c, 0x25, 0xe8, 0x5e, 0x23, 0x0b, 0x92, 0x55, 0x25, 0x0e, 0xcb, 0x13, 0x45,
        0x0b, 0xd3, 0x3f, 0x1d, 0x0f, 0xb3, 0x8a, 0x77, 0xc8, 0x56, 0xf6, 0xbf, 0x00, 0x07, 0xfd, 0x8f,
        0x57, 0x33, 0xc2, 0x8e, 0xdb, 0x6a, 0x3f, 0x18, 0x60, 0xe2, 0x2c, 0xdd, 0xe6, 0x96, 0x9c, 0x1b,
        0xf1, 0xf6, 0xef, 0x26, 0xcc, 0x60, 0x49, 0x4b, 0xee, 0x90, 0xeb, 0x8c, 0xd3, 0x70, 0x52, 0xf8,
        0xec, 0x09, 0x94, 0x2e, 0xa8, 0xa9, 0x7f, 0x85, 0x8d, 0xfa, 0xb6, 0xa9, 0xa5, 0xee, 0x4c, 0x5c,
        0x6f, 0x77, 0x1b, 0xf2, 0xc8, 0x25, 0x60, 0x7b, 0x8e, 0xe9, 0xab, 0x6c, 0x73, 0xa3, 0x4f, 0x9c,
        0x42, 0x8e, 0x1f, 0x4d, 0x37, 0x49, 0x7b, 0x82, 0xbf, 0x68, 0x38, 0xf0, 0xbc, 0xf0, 0x13, 0x94,
        0x24, 0xae, 0x00, 0x6c, 0x2c, 0x24, 0x70, 0xdc, 0x80, 0x2f, 0xe5, 0x19, 0x4c, 0xe6, 0x07, 0x2a,
        0x5d, 0xd9, 0x28, 0x14, 0x97, 0x91, 0x1d, 0x56, 0x0d, 0x11, 0x73, 0x35, 0x25, 0xb5, 0x51, 0x26,
        0xb8, 0xc7, 0xf6, 0xc9, 0xce, 0xd5, 0x27, 0x8c, 0x4b, 0x1d, 0x61, 0x4f, 0x4c, 0xeb, 0xc0, 0x1f,
        0xed, 0xa9, 0x15, 0xa1, 0xb9, 0x9a, 0x87, 0x91, 0x1d, 0x85, 0x61, 0xd4, 0xb9, 0xa7, 0x73, 0x3f,
        0x37, 0xe2, 0xf8, 0x12, 0x15, 0xdd, 0xb4, 0x1d, 0xcf, 0x5f, 0xfe, 0x87, 0xf5, 0x1d, 0x59, 0x8e,
        0xad, 0xd6, 0x11, 0xa0, 0xdc, 0x6c, 0xa5, 0xb3, 0x5b, 0xc5, 0x53, 0x78, 0xd9, 0x14, 0x2d, 0x0e,
        0xd0, 0xf1, 0xef, 0xfc, 0x5f, 0x9c, 0x80, 0x0f, 0x85, 0xc3, 0x77, 0x84, 0x76, 0x86, 0xf5, 0x03,
        0xcc, 0x32, 0x63, 0x97, 0x43, 0xa5, 0xf7, 0xcc, 0x9a, 0xff, 0x44, 0x4e, 0xcb, 0x81, 0x8e, 0x8e,
        0x89, 0x0a, 0xa5, 0xf3, 0x19, 0x58, 0x66, 0x9a, 0xa3, 0x7a, 0x16, 0xb5, 0xba, 0x2e, 0xb7, 0x47,
        0x53, 0x34, 0x90, 0x9a, 0x37, 0x9c, 0x78, 0x08, 0xc2, 0xc3, 0x35, 0x01, 0xf7, 0xf2, 0x30, 0x35,
        0x14, 0xea, 0xd4, 0x26, 0x93, 0xb4, 0xa4, 0x5f, 0xaa, 0x78, 0x0e, 0x26, 0xc0, 0xf9, 0x34, 0x63,
        0xab, 0x8a, 0x9f, 0x87, 0x81, 0x43, 0xe1, 0xbf, 0xb5, 0x88, 0x76, 0x22, 0x3b, 0x7d, 0xd6, 0x22,
        0x0f, 0x2c, 0x43, 0xaa, 0xce, 0xac, 0xbf, 0xcb, 0xea, 0xe1, 0xb8, 0x7c, 0xc4, 0x7b, 0x60, 0x06,
        0x5e, 0x7e, 0xae, 0x3b, 0x52, 0xea, 0x65, 0x3e, 0x02, 0x0e, 0xbe, 0x5b, 0xe1, 0x48, 0x65, 0xef,
        0x47, 0xe8, 0x78, 0x59, 0x95, 0xf1, 0x93, 0x34, 0xa6, 0xf2, 0x4d, 0xcc, 0x04, 0xad, 0x88, 0xa8,
        0x4d, 0x69, 0x67, 0xca, 0x6a, 0x5d, 0x4e, 0xe6, 0x36, 0x24, 0x42, 0x83, 0xc2, 0xaf, 0xa4, 0x1a,
        0x76, 0xc3, 0xa0, 0xf2, 0x70, 0xbd, 0x7f, 0x59, 0xd2, 0xa6, 0x91, 0x3b, 0x9f, 0x61, 0xe8, 0x0a,
        0x64, 0x93, 0xa4, 0xc7, 0x98, 0xdb, 0xb3, 0xd1, 0xf7, 0xde, 0x3c, 0x8e, 0x9d, 0x16, 0x70, 0x1d,
        0xd3, 0xd0, 0x3b, 0xe1, 0x13, 0x37, 0x36, 0x89, 0xf5, 0x35, 0x91, 0xe2, 0x11, 0x38, 0x1b, 0x63,
        0x93, 0x6a, 0x07, 0xa1, 0x2a, 0x4a, 0xe8, 0x87, 0xc7, 0x9d, 0xd0, 0x3f, 0xb8, 0xd4, 0xc8, 0x6b,
        0x41, 0x15, 0x2f, 0x85, 0x0d, 0x86, 0x9d, 0xbe, 0xac, 0x37, 0xe9, 0xfd, 0xf8, 0xd5, 0x6c, 0x5b,
        0xee, 0x41, 0x8f, 0x2b, 0x16, 0xe6, 0x41, 0x76, 0x47, 0xa9, 0x4a, 0x74, 0x3d, 0xa1, 0x1e, 0x11,
        0xe8, 0xd7, 0x05, 0x10, 0x80, 0x8e, 0x18, 0x48, 0x3b, 0x5d, 0x9b, 0x89, 0xdc, 0xef, 0x51, 0xb4,
        0xbd, 0x4f, 0xb8, 0xd7, 0x61, 0x64, 0xa0, 0x48, 0xf3, 0x3a, 0xac, 0x42, 0x58, 0x32, 0x31, 0x31,
        0xd4, 0x30, 0x3b, 0xcb, 0x06, 0xa2, 0x07, 0x31, 0x05, 0x1f, 0x94, 0x27, 0xc9, 0x75, 0x92, 0xe9,
        0xe4, 0x98, 0x87, 0xdb, 0xa9, 0xb3, 0x57, 0x52, 0x7c, 0x42, 0xcc, 0xa5, 0x7c, 0x6d, 0x93, 0x0f,
        0x88, 0x33, 0xf7, 0x5d, 0x56, 0x48, 0x3c, 0xd7, 0xb8, 0x4e, 0xf2, 0xfc, 0x20, 0xb4, 0xfd, 0xed,
        0xbf, 0x0d, 0xe2, 0x9d, 0x14, 0xe9, 0x1d, 0xdb, 0x0b, 0x86, 0xf1, 0xe3, 0x27, 0x05, 0xd3, 0xfd,
        0xf5, 0x08, 0x82, 0x30, 0x06, 0x4c, 0x8e, 0x9c, 0x5a, 0x21, 0x02, 0xb5, 0x5e, 0xe5, 0x28, 0x07,
        0x45, 0xdb, 0xcf, 0xb4, 0x1c, 0xf4, 0xe2, 0x22, 0x7a, 0x86, 0x82, 0x08, 0x0b, 0xfe, 0x2f, 0xac
};

static unsigned char box[] = {
        0x46, 0x85, 0xf0, 0x4d, 0x58, 0x12, 0xf4, 0x57, 0xdf, 0x4c, 0x20, 0x87, 0xb1, 0x6a, 0x9d, 0x68, 
        0x17, 0x96, 0xcd, 0xc5, 0xa7, 0xbd, 0xa2, 0x26, 0x49, 0xa8, 0x6c, 0x0c, 0x84, 0x06, 0xbc, 0x13, 
        0xd6, 0x5b, 0x2e, 0xfe, 0xb9, 0x92, 0x0d, 0xf7, 0x6b, 0x28, 0x1d, 0x05, 0x98, 0x79, 0x34, 0xed, 
        0x74, 0x9b, 0xf5, 0x5c, 0x56, 0xa0, 0x37, 0xfc, 0x35, 0xa3, 0xf8, 0x6f, 0x19, 0xfd, 0x10, 0xcc, 
        0x0a, 0x61, 0x9f, 0x9c, 0xe3, 0x9a, 0x36, 0xd5, 0x83, 0x39, 0x73, 0x63, 0xbf, 0xfb, 0xe4, 0x97, 
        0xbe, 0x0b, 0xb6, 0xa1, 0x08, 0xe9, 0x9e, 0x75, 0xda, 0x95, 0x09, 0xb7, 0xc7, 0x00, 0x80, 0xce, 
        0x5f, 0xac, 0x29, 0xd4, 0x3f, 0x59, 0x81, 0xe2, 0x31, 0x5d, 0x82, 0xc6, 0xb3, 0xdd, 0x30, 0x2b, 
        0x14, 0x47, 0xc8, 0xa9, 0x53, 0xc4, 0xe1, 0x99, 0x16, 0xff, 0x18, 0xae, 0x33, 0xc0, 0x2d, 0x60, 
        0x86, 0x54, 0x40, 0x3e, 0x27, 0x0f, 0x8c, 0xdb, 0xaa, 0xee, 0x55, 0x15, 0xde, 0x76, 0xf9, 0x45, 
        0x65, 0x8f, 0xe8, 0x89, 0x1c, 0xba, 0x66, 0x64, 0x8e, 0x0e, 0xfa, 0x67, 0x02, 0x93, 0x1b, 0x90, 
        0x94, 0xef, 0xf1, 0x44, 0x2c, 0x77, 0x32, 0x03, 0xf6, 0x25, 0x3a, 0x01, 0xc1, 0x07, 0x04, 0xc2, 
        0x1a, 0x8d, 0xf2, 0x1e, 0xab, 0x50, 0xaf, 0x4f, 0x6e, 0x24, 0xf3, 0x72, 0x6d, 0x52, 0x91, 0x2f, 
        0xc9, 0xe5, 0x42, 0xad, 0x51, 0x71, 0xd7, 0xd2, 0x1f, 0x5a, 0xbb, 0x11, 0xeb, 0xea, 0x69, 0x38, 
        0x22, 0xa5, 0xb8, 0xa6, 0x2a, 0x70, 0x3d, 0x8a, 0xdc, 0xe7, 0x62, 0x3c, 0xd3, 0x3b, 0x21, 0x23, 
        0x7f, 0x5e, 0xe0, 0x7e, 0x4a, 0xec, 0xa4, 0xb4, 0x7a, 0xd9, 0x4b, 0x7c, 0xb2, 0x7b, 0x4e, 0x48, 
        0xb5, 0x41, 0xcf, 0x7d, 0xe6, 0xb0, 0x8b, 0x88, 0xd0, 0xd1, 0xcb, 0xd8, 0x43, 0x78, 0xca, 0xc3
};

void encrypt(unsigned char *from, unsigned char *to, int len) {
    int i, round;
    unsigned char seed = 0x42;
    for (i = 0; i < len; i++) {
        unsigned char b = from[i]; 
        seed = box[seed ^ *(i % sizeof(keytable) + keytable)] ^ keytable[i % 0x400];
        for (round = 0x00; round <= 0x0F; round++)
            b = box[seed ^ b ^ * (i * (round | round<<4) % 1024 + keytable)];
        to[i] = b;
    }
}

char backbox(unsigned char in) { int i; for (i=0; i < sizeof(box); i++) if (box[i] == in) return i; }
void decrypt(unsigned char *from, unsigned char *to, int len) {
    int i, round;
    unsigned char seed = 0x42;
    for (i = 0; i < len; i++) {
        unsigned char b = from[i];
        seed = box[seed ^ keytable[i % sizeof(keytable)]] ^ keytable[i % sizeof(keytable)];
        for (round = 0x0F; round >= 0x00; round--)
            b = backbox(b) ^ seed ^ keytable[i * (round | round<<4)  % sizeof(keytable)];
        to[i] = b; 
    }
}

int main(int argc, char *argv[]) {
    char  in[1000];
    char out[1000];
    int len;
    
    if (argc != 2 || (strcmp(argv[1], "-e") && strcmp(argv[1], "-d"))) {
        fprintf(stderr, "%s {-e|-d}\n", argv[0]);
        exit(1);
    } else if (!strcmp(argv[1], "-e")) {
        while ((len = read(0, in, sizeof(in)))) {
            encrypt(in, out, len);
            write(1, out, len);
        }
    } else if (!strcmp(argv[1], "-d")) {
        while ((len = read(0, in, sizeof(in)))) {
            decrypt(in, out, len);
            write(1, out, len);
        }
    }
    return 0;
}


