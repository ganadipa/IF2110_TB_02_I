/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef CHARMATRIX_H
#define CHARMATRIX_H

#include "../../boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP_CharMatriks 100
#define COL_CAP_CharMatriks 100

typedef struct
{
   char mem[ROW_CAP_CharMatriks][COL_CAP_CharMatriks];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} CharMatrix;
#define ROW_EFF_CharMatriks(M) (M).rowEff
#define COL_EFF_CharMatriks(M) (M).colEff
#define ELMT_CharMatriks(M, i, j) (M).mem[(i)][(j)]
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix_CharMatriks(int nRows, int nCols, CharMatrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */


boolean isMatrixIdxValid_CharMatriks(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */


int getLastIdxRowMatrix_CharMatriks(CharMatrix m);
/* Mengirimkan Index baris terbesar m */
int getLastIdxColMatrix_CharMatriks(CharMatrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMatrix_CharMatriks(CharMatrix m, int i, int j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
int getElmtDiagonalMatrix_CharMatriks(CharMatrix m, int i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix_CharMatriks(CharMatrix mIn, CharMatrix *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix_CharMatriks(CharMatrix *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix_CharMatriks(CharMatrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual_CharMatriks(CharMatrix m1, CharMatrix m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual_CharMatriks(CharMatrix m1, CharMatrix m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual_CharMatriks(CharMatrix m1, CharMatrix m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmtMatrix_CharMatriks(CharMatrix m);
/* Mengirimkan banyaknya elemen m */


#endif