#include <stdio.h>
#include "charMatriks.h"

void createMatrix_CharMatriks(int nRows, int nCols, CharMatrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    COL_EFF_CharMatriks(*m) = nCols;
    ROW_EFF_CharMatriks(*m) = nRows;
}

boolean isMatrixIdxValid_CharMatriks(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i >= 0 && i < ROW_CAP_CharMatriks && j >= 0 && j < COL_CAP_CharMatriks);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
int getLastIdxRowMatrix_CharMatriks(CharMatrix m)
/* Mengirimkan Index baris terbesar m */
{
    return (ROW_EFF_CharMatriks(m)-1);
}
int getLastIdxColMatrix_CharMatriks(CharMatrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return (COL_EFF_CharMatriks(m)-1);
}
boolean isIdxEffMatrix_CharMatriks(CharMatrix m, int i, int j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i >= 0 && i < ROW_EFF_CharMatriks(m) && j >= 0 && j < COL_EFF_CharMatriks(m));
}
int getElmtDiagonalMatrix_CharMatriks(CharMatrix m, int i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT_CharMatriks(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix_CharMatriks(CharMatrix mIn, CharMatrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrix_CharMatriks(ROW_EFF_CharMatriks(mIn), COL_EFF_CharMatriks(mIn), mOut);
    int i, j;
    for (i = 0; i < ROW_EFF_CharMatriks(mIn); i++){
        for (j = 0; j < COL_EFF_CharMatriks(mIn); j++){
            ELMT_CharMatriks(*mOut, i, j) = ELMT_CharMatriks(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix_CharMatriks(CharMatrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
a b c
d e f
g h i
*/
{
    createMatrix_CharMatriks(nRow, nCol, m);
    int i, j;
    for (i = 0; i < ROW_EFF_CharMatriks(*m); i++){
        for (j = 0; j < COL_EFF_CharMatriks(*m); j++){
            scanf("%c", &ELMT_CharMatriks(*m, i, j));
        }
    }
}

void displayMatrix_CharMatriks(CharMatrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
a b c 
d e f
g h i
*/
{
    int i, j;
    for (i = 0; i < ROW_EFF_CharMatriks(m); i++){
        for (j = 0; j < COL_EFF_CharMatriks(m); j++){
            printf("%c", ELMT_CharMatriks(m, i, j));
            if (j!=COL_EFF_CharMatriks(m)-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual_CharMatriks(CharMatrix m1, CharMatrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    if (ROW_EFF_CharMatriks(m1)!=ROW_EFF_CharMatriks(m2) || COL_EFF_CharMatriks(m1)!=COL_EFF_CharMatriks(m2)){
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF_CharMatriks(m1);i++){
        for (j = 0; j< COL_EFF_CharMatriks(m1); j++){
            if (ELMT_CharMatriks(m1, i,j) != ELMT_CharMatriks(m2, i,j)){
                return false;
            } 
        }
    }
    return true;
}
boolean isMatrixNotEqual_CharMatriks(CharMatrix m1, CharMatrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !isMatrixEqual_CharMatriks(m1, m2);
}
boolean isMatrixSizeEqual_CharMatriks(CharMatrix m1, CharMatrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return (ROW_EFF_CharMatriks(m1) == ROW_EFF_CharMatriks(m2) && COL_EFF_CharMatriks(m1) == COL_EFF_CharMatriks(m2));
}

/* ********** Operasi lain ********** */
int countElmtMatrix_CharMatriks(CharMatrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFF_CharMatriks(m) * COL_EFF_CharMatriks(m));
}
