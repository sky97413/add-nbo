#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf


uint16_t my_ntohs(uint16_t n) {
    return ((n & 0xff) << 8) | (n >> 8);
}

uint32_t my_ntohl(uint32_t n) {
    return my_ntohs((n & 0xffff) << 16) | my_ntohs(n >> 16);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("syntax : add-nbo <file1> <file2>\nsample : add-nbo a.bin c.bin\n");
    } else {
        FILE *stream1;
        if ((stream1 = fopen(argv[1], "rb")) == NULL) {
            printf("Could not open data file.\n");
            fclose(stream1);
        }
        uint32_t n1 = 0;
        fread(&n1, sizeof(uint32_t), 1, stream1);
        fclose(stream1);
        n1 = my_ntohl(n1);

        FILE *stream2;
        if ((stream2 = fopen(argv[2], "rb")) == NULL) {
            printf("Could not open data file.\n");
            fclose(stream2);
        }
        uint32_t n2 = 0;
        fread(&n2, sizeof(uint32_t), 1, stream2);
        fclose(stream2);
        n2 = my_ntohl(n2);

        uint32_t sum = n1 + n2;
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);
    }

    return 0;
}
