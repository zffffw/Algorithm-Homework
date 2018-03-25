#include <stdio.h>

int main() {
    char res[200][20] = {
            "1",
        "1111111111111111110",
        "111",
        "1111111111111111100",
        "1111111111111111110",
        "1111111111111111110",
        "111111",
        "1111111111111111000",
        "111111111",
        "1111111111111111110",
        "11",
        "11111111111111100",
        "111111",
        "1111111111111111110",
        "1111111111111111110",
        "1111111111111110000",
        "1111111111111111",
        "1111111111111111110",
        "111111111111111111",
        "1111111111111111100",
        "111111",
        "1111111111111111110",
        "111111111111110001",
        "111111111111111000",
        "1111111111111111100",
        "1111111111111111110",
        "1111111111111111011",
        "1111111111111101100",
        "111111111111111001",
        "1111111111111111110",
        "111111111111111",
        "1111111111111100000",
        "111111",
        "11111111111111110",
        "1111111111111111110",
        "11111111100",
        "111",
        "1111111111111111110",
        "111111",
        "1111111111111111000",
        "11111",
        "1111111111111111110",
        "1111111111110000001",
        "111111111111111100",
        "1111111111111111110",
        "1111111111111100010",
        "111111111111101011",
        "1111111111111110000",
        "1111111111111001",
        "1111111111111111100",
        "1111111111111100001",
        "1111111111111101100",
        "1111111111111",
        "11111111010",
        "1111111111111111110",
        "1111111111111001000",
        "111111111111111111",
        "1111111111111110010",
        "1111111111111110111",
        "11111111111111100",
        "1111111111111100011",
        "1111111111111110",
        "111111111111111111",
        "1111111111111000000",
        "1111111111111111110",
        "1111111111111111110",
        "111111111111101",
        "111111111111111100",
        "111111111111110001",
        "1111111111111111110",
        "1111111111110000101",
        "111111111000",
        "11111111",
        "1111111111111111110",
        "11111111111111100",
        "1111111111111001100",
        "111111",
        "1111111111111111110",
        "1111111111111",
        "1111111111111110000",
        "1111111111111111011",
        "1111111111111110",
        "111111111111101111",
        "1111111111111010100",
        "11111111111111110",
        "111111111110010110",
        "11111111111101011",
        "1111111111111111000",
        "1111111111101000001",
        "1111111111111111110",
        "111111",
        "111111111111101100",
        "111111111111111",
        "1111111111111010110",
        "1111111111111111110",
        "11111111111100000",
        "1111111111101101011",
        "11111111111110010",
        "111111111111111111",
        "1111111111111111100",
        "1111",
        "1111111111111001010",
        "1111111111110110111",
        "1111111111111001000",
        "1111111111111111110",
        "11111111111110",
        "1111111111110000001",
        "111111110100",
        "11111111111010111",
        "1111111111111111110",
        "111",
        "1111111111110000",
        "111111111111111101",
        "1111111111111111110",
        "1111111111111100010",
        "1111111111111000100",
        "111111111111111111",
        "11111111111100110",
        "1111111111111100001",
        "111111111111111000",
        "111111111111100001",
        "111111111111001110",
        "111111111111111",
        "11111111111111100",
        "1111111111111111000",
        "1111111111111111110",
        "1111111111110011",
        "1111111111110000000",
        "1111111111100100111",
        "1111111111111111110",
        "111111111110111101",
        "11111111111100",
        "111111111111111111",
        "1111111111111010",
        "11111111010",
        "1111111111111111000",
        "11111111",
        "1111111111111100010",
        "11111111111101",
        "1111111111111101100",
        "1111111111110111",
        "1111111111101010010",
        "111111",
        "1111111110000",
        "1111111111111110010",
        "11111111111111110",
        "1111111111110111111",
        "11111111111111100",
        "11111111111100111",
        "11111111111111100",
        "1111111111110100111",
        "111111111111011000",
        "1111111111110111111",
        "1111111111111111110",
        "1111111111111110",
        "1111111111111010100",
        "1111111111101001011",
        "11111111111110",
        "1111111111010110101",
        "1111111111111100000",
        "1111111111110001001",
        "11111111010",
        "1111111111110011",
        "11111111111111100",
        "1111111111111111110",
        "1111111111111011110",
        "1111111111110011011",
        "111111111111000",
        "1111111111110010101",
        "11111111111111110",
        "111111111111111111",
        "1111111111100101100",
        "1111111111111110101",
        "111111111111010110",
        "1111111111111101100",
        "111111111111110000",
        "1111111111111110111",
        "1111111111000010010",
        "111111111111010101",
        "11111111100",
        "1111111111111101101",
        "1111111111111111110",
        "11111111111100111",
        "1111111111111011000",
        "1111111111111111110",
        "1111111111111110",
        "1111111111111111",
        "111111111111011100",
        "1111111100001",
        "1111111111111111110",
        "1111111111111001011",
        "111111111111000000",
        "111111111100101011",
        "11111111110110110",
        "1111111111111111110",
        "111111111111100100",
        "1111111111111101101",
        "1111111111111111110",
        "1111111111010111001",
        "1111111111111111000"
    };
    int n[200];
    int temp ;
    int pos = 0;
    scanf("%d", &temp);
    while(temp != 0) {
        puts(res[temp - 1]);
        scanf("%d", &temp);
    }
    return 0;

}