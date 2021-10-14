#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

unsigned char red[MAX][MAX];
unsigned char green[MAX][MAX];
unsigned char blue[MAX][MAX];

void scriviFileBMP( 
  char* nomeFile, int w, int h, 
  unsigned char red[][MAX], 
  unsigned char green[][MAX], 
  unsigned char blue[][MAX] 
  );



void scriviIntestazione(FILE* f, int, int);
void scriviDati(FILE* f,int w, int h, unsigned char red[MAX][MAX], unsigned char green[MAX][MAX], unsigned char blue[MAX][MAX] );

int main() {
	// dimensioni dell'immagine
	int w = 100, h = 100, i,j;  
	
	// colori casuali
//	for(i=0; i<w; i++) {
//	  for( j=0; j<h; j++) {
//	  	red[i][j] = rand()%256;   
//	  	green[i][j] = rand()%256;
//	  	blue[i][j] = rand()%256;
//	  }
//	}
	
	// gradiente verticale da bianco a nero
//	(255,255,255)   --> (250,250,250) ... 
//	(10,10,10) -->   (0,0,0)
	
	//voglio un'immagine finale 100x100 pixel
	//diminuisco di circa 255/100 = 2 unit? ogni riga
	w = 100;  h=100;
	
	unsigned char k = 255;
	
	for(i=0; i<w; i++) {
	  	for( j=0; j<h; j++) {
	  		red[i][j] = i;   
	  		green[i][j] = k;
	  		blue[i][j] = i;
	  	}
		k = k - 2;
	}
	
	
	
	
	  
   /*
	for(i=0; i<w; i++)
	  for( j=0; j<h; j++) {
	  	red[i][j] =0;
	  	green[i][j] = i*j;
	  	blue[i][j] =0 ;
	}*/
	 
	
	// generazione del file su disco   
    scriviFileBMP("gradiente_bianco_nero.bmp", w, h, red, green, blue);
}

void scriviFileBMP(
	char* nomeFile, 
	int w, 
	int h, 
	unsigned char red[MAX][MAX], 
	unsigned char green[MAX][MAX], 
	unsigned char blue[MAX][MAX]) 
{
	FILE* out = fopen(nomeFile,"wb");
	if (!out) {
		printf("Impossibile scrivere il file %s", nomeFile  );
	} 
	else {
		scriviIntestazione(out,w,h);
   		scriviDati(out, w, h, red, green, blue);
   		close(out);
   		printf("File creato con successo!\n");
	}
}


void scriviIntestazione(FILE* f, int w, int h) {
	char c1 = 'B';
	char c2 = 'M';
	int zeri = 0;
	int fSize = 54 + w*h*3;
	int pOffset = 54;
	int bhSize = 40;
	int width = w;
	int height = h;
	short int cPanes =1;
	short int bpp = 24;
	int compr = 0;
	int dataSize = w*h;
	int hRes = 2835;
	int vRes = 2835;
	int nCol = 0;
	int nICol = 0;

	//Byte		Value			Comment
	//0			0x42			ASCII for ?B?
	fwrite(&c1,1,1,f);
	
	//1			0x4D			ASCII for ?M?
	fwrite(&c2,1,1,f);
	
	//2-5		File Size		This will be the full size of the file including the header, the pixel data, and all padding
	fwrite(&fSize,1,4,f);
	
	//6-9		0x00000000		This data is reserved but can just be set to 0
	fwrite(&zeri,1,4,f);
	
	//10-13		Pixel Offset	This will be how many bytes are in the file before you get to the actual pixel data. In our header the value will be 54.
	fwrite(&pOffset,1,4,f);
	
	//14-17		40				We?re going to be writing the BITMAPINFOHEADER header which has a size of 40 bytes
	fwrite(&bhSize,1,4,f);
	
	//18-21		Pixel Width		The width of the image in pixels
	fwrite(&width,1,4,f);
	
	//22-25		Pixel Height	The height of the image in pixels
	fwrite(&height,1,4,f);
	
	//26-27		1				The number of color planes, must be set to 1
	fwrite(&cPanes,1,2,f);
	
	//28-29		24				The number of bits per pixel. For an RGB image with a single byte for each color channel the value would be 24
	fwrite(&bpp,1,2,f);
	
	//30-33		0				Disable Compression
	fwrite(&compr,1,4,f);
	
	//34-37		Size of raw pixel data	This will have the number of bytes in the pixel data section of the file (the part after the header). Since padding will be added to the rows you cannot simply multiple height * width * 24 and expect it to work
	fwrite(&dataSize,1,4,f);
	
	//38-41		2835			This is the horizontal resolution. Just leave it at 2835.
	fwrite(&hRes,1,4,f);
	
	//42-45		2835			This is the vertical resolution. Just leave it at 2835.
	fwrite(&vRes,1,4,f);
	
	//46-49		0				The number of colors, leave at 0 to default to all colors
	fwrite(&nCol,1,4,f);
	
	//50-53		0				The important colors, leave at 0 to default to all colors
	fwrite(&nICol,1,4,f);
	
}

void scriviDati( FILE* f, int w, int h, unsigned char red[MAX][MAX], unsigned char green[MAX][MAX], unsigned char blue[MAX][MAX]  ) {
    int i,j;
    for(i=h-1; i>=0; i--){
      	for(j=0; j<w; j++) {
      		fwrite(&blue[i][j],1,1,f); 
      		fwrite(&green[i][j],1,1,f); 
      		fwrite(&red[i][j],1,1,f); 
	  	}
	}
}
