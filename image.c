#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BitmapFileHeader BitmapFileHeader;
typedef struct BitmapInfoHeader BitmapInfoHeader;
typedef struct Pixel Pixel;

struct BitmapFileHeader {
  unsigned short bfType;
  unsigned int bfSize;
  unsigned short bfReserved1;
  unsigned short bfReserved2;
  unsigned int bfOffBits;
};

struct BitmapInfoHeader{
  unsigned int biSize;
  int biWidth;
  int biHeight;
  unsigned short biPlanes;
  unsigned short biBitCount;
  unsigned int biCompression;
  unsigned int biSizeImage;
  int biXPixPerMeter;
  int biYPixPerMeter;
  unsigned int biClrUsed;
  unsigned int biClrImportant;
};

BitmapFileHeader ReadBmpHeader(FILE *fp_in) {
  BitmapFileHeader fileh;

  fread(&(fileh.bfType), 2, 1, fp_in);
  fread(&(fileh.bfSize), 4, 1, fp_in);
  fread(&(fileh.bfReserved1), 2, 1, fp_in);
  fread(&(fileh.bfReserved2), 2, 1, fp_in);
  fread(&(fileh.bfOffBits), 4, 1, fp_in);
  return fileh;
}

BitmapInfoHeader ReadBmpInfoHeader(FILE *fp_in) {
  BitmapInfoHeader infoh;

  fread(&(infoh.biSize), 4, 1, fp_in);
  fread(&(infoh.biWidth), 4, 1, fp_in);
  fread(&(infoh.biHeight), 4, 1, fp_in);
  fread(&(infoh.biPlanes), 2, 1, fp_in);
  fread(&(infoh.biBitCount), 2, 1, fp_in);
  fread(&(infoh.biCompression), 4, 1, fp_in);
  fread(&(infoh.biSizeImage), 4, 1, fp_in);
  fread(&(infoh.biYPixPerMeter), 4, 1, fp_in);
  fread(&(infoh.biXPixPerMeter), 4, 1, fp_in);
  fread(&(infoh.biClrUsed), 4, 1, fp_in);
  fread(&(infoh.biClrImportant), 4, 1, fp_in);

  return infoh;
}

void CopyBmpInfoHeader(BitmapInfoHeader infoh, FILE *fp_out){
  fwrite(&(infoh.biSize), 4, 1, fp_out);
  fwrite(&(infoh.biWidth), 4, 1, fp_out);
  fwrite(&(infoh.biHeight), 4, 1, fp_out);
  fwrite(&(infoh.biPlanes), 2, 1, fp_out);
  fwrite(&(infoh.biBitCount), 2, 1, fp_out);
  fwrite(&(infoh.biCompression), 4, 1, fp_out);
  fwrite(&(infoh.biSizeImage), 4, 1, fp_out);
  fwrite(&(infoh.biYPixPerMeter), 4, 1, fp_out);
  fwrite(&(infoh.biXPixPerMeter), 4, 1, fp_out);
  fwrite(&(infoh.biClrUsed), 4, 1, fp_out);
  fwrite(&(infoh.biClrImportant), 4, 1, fp_out);
  return;
}

void CopyBmpFileHeader(BitmapFileHeader fileh, FILE *fp_out) {
  fwrite(&(fileh.bfType), 2, 1, fp_out);
  fwrite(&(fileh.bfSize), 4, 1, fp_out);
  fwrite(&(fileh.bfReserved1), 2, 1, fp_out);
  fwrite(&(fileh.bfReserved2), 2, 1, fp_out);
  fwrite(&(fileh.bfOffBits), 4, 1, fp_out);
  return; 
}

struct Pixel{
  unsigned char R;
  unsigned char G;
  unsigned char B;
};

void RemoveColorsExcept(FILE *fp_in, FILE *fp_out, char *string){
  BitmapFileHeader fileh = ReadBmpHeader(fp_in);
  BitmapInfoHeader infoh = ReadBmpInfoHeader(fp_in);

  CopyBmpFileHeader(fileh, fp_out);
  CopyBmpInfoHeader(infoh, fp_out);

  if (strcmp(string, "green") != 0 && strcmp(string, "red") != 0 && strcmp(string, "blue") != 0){
    printf("Insert valid argument for color\n");
    return;
  }
  int i = 0;
  for (i = 0; i < infoh.biWidth*infoh.biHeight; ++i){
    Pixel old_pixel;
    Pixel new_pixel;
    new_pixel.R = 0;
    new_pixel.B = 0;
    new_pixel.G = 0;
    fread(&(old_pixel.B), 1, 1, fp_in);
    fread(&(old_pixel.G), 1, 1, fp_in);
    fread(&(old_pixel.R), 1, 1, fp_in);
    if (strcmp(string, "green") == 0) {
       new_pixel.G = old_pixel.G;
    } else if (strcmp(string, "red") == 0) {
       new_pixel.R = old_pixel.R;
    } else if (strcmp(string, "blue") == 0) {
       new_pixel.B = old_pixel.B;
     } 
  fwrite(&(new_pixel.B), 1, 1, fp_out);
  fwrite(&(new_pixel.G), 1, 1, fp_out);
  fwrite(&(new_pixel.R), 1, 1, fp_out);
  }
}

int main() {
  
  FILE *fp_in;
  FILE *fp_out_g;
  FILE *fp_out_b;
  FILE *fp_out_r;

  fp_in = fopen("bmpsample.bmp", "rb");
  fp_out_g = fopen("bmpgreen.bmp", "wb");
  fp_out_b = fopen("bmpblue.bmp", "wb");
  fp_out_r = fopen("bmpred.bmp", "wb");

  RemoveColorsExcept(fp_in, fp_out_g, "green");
  rewind(fp_in);
  RemoveColorsExcept(fp_in, fp_out_b, "blue");
  rewind(fp_in);
  RemoveColorsExcept(fp_in, fp_out_r, "red");
  fclose(fp_in);
  fclose(fp_out_g);
  fclose(fp_out_b);
  fclose(fp_out_r);
  return 0;

}
