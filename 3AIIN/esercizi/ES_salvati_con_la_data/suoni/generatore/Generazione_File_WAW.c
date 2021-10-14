/*  PROGRAMMA CHE GENERA UN FILE .WAW (MONO)   */

#include <stdio.h>
#include <math.h>
#define MAX 4410000    // massimo numero di campioni audio
#define PIGRECO 3.14
 
void crea_file_waw(char * filename, unsigned long num_samples, short int * data, int s_rate);
void write_little_endian(unsigned int word, int num_bytes, FILE *wav_file);

short int campioni[MAX];
 
int main(int argc, char ** argv) {
	int durata = 10;    	// durata del suono da generare (in secondi)
    float a = 32000; 		// ampiezza del suono da generare (deve essere compreso tra -2^15 ... +2^15-1 )
    float f = 440;   		// frequenza del suono da generare (in Hz)
    float periodo = 1.0/f;  // periodo del suono (= durata di una "ripetizione" )
    int sr = 44100;  		// sample rate = frequenza di campionamento
    int n = durata*sr;      // numero totale di campioni (deve essere inferiore a MAX)
    int np = periodo*sr;    // numero di campioni in un periodo
    float dt = 1.0/sr;      // delta t = intervallo tra un campione e il successivo (in secondi)
    int i;
    
    // Esempio 1:  rumore casuale
    for (i=0; i<n; i++) { 
    	campioni[i] = 1000*( -2 + rand()%100 );
    }
    crea_file_waw("es1_rumore_casuale.wav", n, campioni, sr );
    
//    // Esempio 2: onda sinusoidale con frequenza f
//    f=440; // 440 Hertz  (frequenza del "LA" centrale del pianoforte, timbro del diapason)
//    for (i=0; i<n; i++) { 
//       campioni[i] = a*sin( 2*PIGRECO*f*i*dt );
//    }
//    crea_file_waw("es2_nota_LA_440_Hz.wav", n, campioni, sr );
//    
//    // esempio 3: onda sinusiodale con frequenza f e ampiezza descrescente (fading)
//    for (i=0; i<n; i++) { 
//       campioni[i] = a*sin( 2*PIGRECO*f*i*dt );
//       if (i%5==0 && a>0 )   
//         a--;
//    }
//    crea_file_waw("es3_fading.wav", n, campioni, sr );
//    
//    // esempio 4: onda quadra di frequenza f
//    int livello = 32000;
//    for (i=0; i<n; i++) { 
//       if ( i%np == 0) {
//       	  livello = -livello;
//	   }
//       campioni[i] = livello;
//    }
//    crea_file_waw("es4_onda_quadra.wav", n, campioni, sr ); 
//	
	printf("fine!") ;
}

 
void write_little_endian(unsigned int word, int num_bytes, FILE *wav_file)
{
    unsigned buf;
    while(num_bytes>0)
    {   buf = word & 0xff;
        fwrite(&buf, 1,1, wav_file);
        num_bytes--;
    word >>= 8;
    }
}

void crea_file_waw(char * filename, unsigned long num_samples, short int * data, int s_rate) {
    FILE* wav_file;
    unsigned int num_channels;
    unsigned int bytes_per_sample;
    unsigned int byte_rate;
    unsigned long i;    
    num_channels = 1;  
    bytes_per_sample = 2;
    byte_rate = s_rate*num_channels*bytes_per_sample;
    wav_file = fopen(filename, "wb");
    /* write RIFF header */
    fwrite("RIFF", 1, 4, wav_file);
    write_little_endian(36 + bytes_per_sample* num_samples*num_channels, 4, wav_file);
    fwrite("WAVE", 1, 4, wav_file);
    /* write fmt  subchunk */
    fwrite("fmt ", 1, 4, wav_file);
    write_little_endian(16, 4, wav_file);   /* SubChunk1Size is 16 */
    write_little_endian(1, 2, wav_file);    /* PCM is format 1 */
    write_little_endian(num_channels, 2, wav_file);
    write_little_endian(s_rate, 4, wav_file);
    write_little_endian(byte_rate, 4, wav_file);
    write_little_endian(num_channels*bytes_per_sample, 2, wav_file);  /* block align */
    write_little_endian(8*bytes_per_sample, 2, wav_file);  /* bits/sample */
    /* write data subchunk */
    fwrite("data", 1, 4, wav_file);
    write_little_endian(bytes_per_sample* num_samples*num_channels, 4, wav_file);
    for (i=0; i< num_samples; i++){ 
	  write_little_endian((unsigned short)(data[i]),bytes_per_sample, wav_file);
    }
    fclose(wav_file);
}

