#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    COL_EFF(*m) = nCols;
    ROW_EFF(*m) = nRows;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRowMatrix(Matrix m){
    return (ROW_EFF(m)-1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxColMatrix(Matrix m){
    return (COL_EFF(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMatrix(Matrix m, IdxType i, IdxType j){
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonalMatrix(Matrix m, IdxType i){
    return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(mIn); i++){
        for (j = 0; j < COL_EFF(mIn); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if (j!=COL_EFF(m)-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

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
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix hasil;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &hasil);
    int i, j;
    for (i = 0; i < ROW_EFF(hasil); i++){
        for (j = 0; j < COL_EFF(hasil); j++){
            ELMT(hasil, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix hasil;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &hasil);
    int i, j;
    for (i = 0; i < ROW_EFF(hasil); i++){
        for (j = 0; j < COL_EFF(hasil); j++){
            ELMT(hasil, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
// 1 2 9   1 2 3
// 6 3 8   3 5 8
// 2 1 2   6 7 7
// 5 6 9
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix hasil;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &hasil);
    int i, j;
    for (i = 0; i < ROW_EFF(hasil); i++){
        for (j = 0; j < COL_EFF(hasil); j++){
            int x,jumlah=0;
            for (x = 0; x < COL_EFF(m1);x++){
                jumlah += (ELMT(m1, i, x) * ELMT(m2, x, j));
            }
            ELMT(hasil, i, j) = jumlah;
            
        }
    }
    return hasil;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix hasil;
    hasil=multiplyMatrix(m1, m2);
    int i, j;
    for (i = 0; i < ROW_EFF(hasil); i++){
        for (j = 0; j < COL_EFF(hasil); j++){
            ELMT(hasil, i, j) = ELMT(hasil, i, j) % mod;
        }
    }
    return hasil;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyMatrixByConst(Matrix m, ElType x){
    Matrix hasil;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &hasil);
    for (i = 0; i < ROW_EFF(hasil); i++){
        for (j = 0; j < COL_EFF(hasil); j++){
            ELMT(hasil, i, j) = ELMT(m, i, j) * x;
        }
    }
    return hasil;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyMatrixbyConst(Matrix *m, ElType k){
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (ROW_EFF(m1)!=ROW_EFF(m2) || COL_EFF(m1)!=COL_EFF(m2)){
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1);i++){
        for (j = 0; j< COL_EFF(m1); j++){
            if (ELMT(m1, i,j) != ELMT(m2, i,j)){
                return false;
            } 
        }
    }
    return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxColMatrix(m1) = getLastIdxColMatrix(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return (!isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmtMatrix(Matrix m){
    return (ROW_EFF(m) * COL_EFF(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquareMatrix(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetricMatrix(Matrix m){
    if (!isSquareMatrix(m)){
      return false;
   }
   int i, j;   
   for (i = 0; i < ROW_EFF(m);i++){
      for (j = 0; j < COL_EFF(m);j++){
         if (ELMT(m, i, j) != ELMT(m, j, i)){
            return false;
         }
      }
   }
   return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquareMatrix(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentityMatrix(Matrix m){
    if (!isSquareMatrix(m)){
      return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (i == j && ELMT(m, i, j) != 1)
            {
                return false;
            }
            else if (i!=j && ELMT(m,i,j)!=0){
                return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquareMatrix(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparseMatrix(Matrix m){
    int i, j, count = 0;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (ELMT(m,i,j) !=0 ){
                count += 1;
            }
        }
    }
    return (count <= (0.05 * countElmtMatrix(m)));
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negationMatrix(Matrix m){
    return multiplyMatrixByConst(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegationMatrix(Matrix *m){
    pMultiplyMatrixbyConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinantMatrix(Matrix m){
    if (ROW_EFF(m) == 1 && COL_EFF(m) == 1) {
        return (float) ELMT(m, 0, 0);
    } else if (ROW_EFF(m) == 2 && COL_EFF(m) == 2) {
        return (float)(ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0));
    } else {
        int i, a,k,baris,kolom;
        float determinan;   
        determinan = 0;
        for (i = 0; i < ROW_EFF(m); i++){
            int new_length = ROW_EFF(m) - 1;
            Matrix submatriks;
            createMatrix(new_length, new_length, &submatriks);
            kolom = 0;
            baris = 0;
            for (a = 0; a < ROW_EFF(m); a++) {
                if (a == i) {
                    continue;
                }
                int kolom = 0;
                for (k = 1; k < COL_EFF(m); k++) {
                    ELMT(submatriks, baris, kolom) = ELMT(m, a, k);
                    kolom += 1;
                }
                baris += 1;
            }
            
            determinan += (float)(((i % 2 == 0) ? 1.0 : -1.0) * ELMT(m, i, 0) * determinantMatrix(submatriks));
        }
        return (float) determinan;
    }
}
/* Prekondisi: isSquareMatrix(m) */
/* Menghitung nilai determinan m */
Matrix transposeMatrix(Matrix m){
    Matrix m1;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (i = 0; i < ROW_EFF(m);i++){
        for (j = 0; j < COL_EFF(m);j++){
            ELMT(m1, i, j) = ELMT(m, j, i);
        }
    }
    return m1;
}
/* I.S. m terdefinisi dan isSquareMatrix(m) */
/* F.S. menghasilkan salinan transposeMatrix dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTransposeMatrix(Matrix *m){
    Matrix m1;
    m1 = transposeMatrix(*m);
    copyMatrix(m1, m);
}
/* I.S. m terdefinisi dan isSquareMatrix(m) */
/* F.S. m "di-transposeMatrix", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

