#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define OFFSETBITS 15
#define LENGTHBITS 8
#define OFFSETMASK ((1 << (OFFSETBITS)) - 1)
#define LENGTHMASK ((1 << (LENGTHBITS)) - 1)
#define OFFSETLENGTH(x,y) (x << LENGTHBITS | y)
struct Huffman{
char data;
struct Huffman *left,*rigth;
};
struct token{
uint16_t offset;
char c;
};
void frekansbul(char *metin,int size,int harfler[]){
//harfler={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
for(metin;metin<size;metin++){
if(*metin=='a'){
    harfler[0]=50;

}
if(metin=='b'){
    harfler[1]++;
}
if(metin=='c'){
    harfler[2]++;
}
if(metin=='d'){
    harfler[3]++;
}
if(metin=='e'){
    harfler[4]++;
}
if(metin=='f'){
    harfler[5]++;
}
if(metin=='g'){
    harfler[6]++;
}
if(metin=='h'){
    harfler[7]++;
}
if(metin=='i'){
    harfler[8]++;
}
if(metin=='j'){
    harfler[9]++;
}
if(metin=='k'){
    harfler[10]++;
}
if(metin=='l'){
    harfler[11]++;
}
if(metin=='m'){
    harfler[12]++;
}
if(metin=='n'){
    harfler[13]++;
}
if(metin=='o'){
    harfler[14]++;
}
if(metin=='p'){
    harfler[15]++;
}
if(metin=='q'){
    harfler[16]++;
}
if(metin=='r'){
    harfler[17]++;
}
if(metin=='s'){
    harfler[18]++;
}
if(metin=='t'){
    harfler[19]++;
}
if(metin=='u'){
    harfler[20]++;
}
if(metin=='v'){
    harfler[21]++;
}
if(metin=='w'){
    harfler[22]++;
}
if(metin=='x'){
    harfler[23]++;
}
if(metin=='y'){
    harfler[24]++;
}
if(metin=='z'){
    harfler[25]++;
}
if(metin=='A'){
    harfler[26]++;
}
if(metin=='B'){
    harfler[27]++;
}
if(metin=='C'){
    harfler[28]++;
}
if(metin=='D'){
    harfler[29]++;
}
if(metin=='E'){
    harfler[30]++;
}
if(metin=='F'){
    harfler[31]++;
}
if(metin=='G'){
    harfler[32]++;
}
if(metin=='H'){
    harfler[33]++;
}
if(metin=='I'){
    harfler[34]++;
}
if(metin=='J'){
    harfler[35]++;
}
if(metin=='K'){
    harfler[36]++;
}
if(metin=='L'){
    harfler[37]++;
}
if(metin=='M'){
    harfler[38]++;
}
if(metin=='N'){
    harfler[39]++;
}
if(metin=='O'){
    harfler[40]++;
}
if(metin=='P'){
    harfler[41]++;
}
if(metin=='Q'){
    harfler[42]++;
}
if(metin=='R'){
    harfler[43]++;
}
if(metin=='S'){
    harfler[44]++;
}
if(metin=='T'){
    harfler[45]++;
}
if(metin=='U'){
    harfler[46]++;
}
if(metin=='V'){
    harfler[47]++;
}
if(metin=='W'){
    harfler[48]++;
}
if(metin=='X'){
    harfler[49]++;
}
if(metin=='Y'){
    harfler[50]++;
}
if(metin=='Z'){
    harfler[51]++;
}
if(metin==' '){
    harfler[52]++;
}
}
}


int uzunluk(char *s1, char *s2, int limit)
{
    int len = 0;

    while (*s1++ == *s2++ && len < limit)
        len++;

    return len;
}

struct token *encode(char *text, int limit,int *numTokens)
{
    int _numTokens = 0;
    struct token t;
    char *ileritampon, *arama;
    struct token *encoded = malloc(50000000000000 * sizeof(struct token));

    for (ileritampon = text; ileritampon < text + limit; ileritampon++)
    {
        arama = ileritampon - OFFSETMASK;
        if (arama < text)
            arama = text;
        int max_len = 0;
        char *max_match = ileritampon;
        for (; arama < ileritampon;arama++)
        {
            int len = uzunluk(arama, ileritampon, LENGTHMASK);

            if (len > max_len)
            {
                max_len = len;
                max_match = arama;
            }
        }
        if (ileritampon + max_len >= text + limit)
        {
            max_len = text + limit - ileritampon - 1;
        }
        t.offset =OFFSETLENGTH(ileritampon - max_match, max_len);
        ileritampon =ileritampon+ max_len;
        t.c = *ileritampon;
        encoded[_numTokens] = t;
        _numTokens++;
    }
    if (numTokens)
        *numTokens = _numTokens;
    return encoded;
}
char *file_read(FILE *f, int *size)
{
    char *content;
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    content = malloc(*size);
    fseek(f, 0, SEEK_SET);
    fread(content, 1, *size, f);
    return content;
}



int main()
{
    FILE *f;
    int metin_boyutu = 8, token_sayisi, decode_boyutu;
    char *kaynak_metin = "aaaaaaaa", *decoded_metin = "";
    struct token *encoded_metin;

    if (f = fopen("C:\\Users\\lem_l\\OneDrive\\Masaüstü\\at.txt", "rb"))
    {
        kaynak_metin = file_read(f, &metin_boyutu);
        fclose(f);
    }



    encoded_metin = encode(kaynak_metin, metin_boyutu,&token_sayisi);

    f = fopen("C:\\Users\\lem_l\\OneDrive\\Masaüstü\\encoded.txt", "wb");
       fwrite(encoded_metin,sizeof(struct token),token_sayisi,f);


int harf[52]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};;
frekansbul(kaynak_metin,metin_boyutu,harf);


    printf("Dosyanin Orjinal Boyut: %d bayt \nDosyanin Sikistirilmis Boyutu: %d bayt", metin_boyutu,token_sayisi * sizeof(struct token));
   int i;
    for(i=0;i<52;i++){
        printf("\n%d",harf[i]);
    }

    return 0;
}
