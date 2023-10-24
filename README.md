Temporary readme. 
1. Setup
   - Download WSL (setupnya bebas, fullnya coba liat youtube).
   - Clone repo ini. By doing this code below
```bash
git clone https://github.com/ganadipa/IF2110_TB_02_I.git
```
atau (klo udah pake ssh)
```bash
git clone git@github.com:ganadipa/IF2110_TB_02_I.git
```
2. Branching
   - Bikin branch nama panggilan kalian (i.e. Gana), Disitu kalian ngerjain bagian kalian.
   - Bakal ada 2 branch utama, main sama develop. branch main JANGAN PERNAH diapa-apain, kalo mau merge dari branch kalian atau edit edit branch utama, EDIT DEVELOP AJA.
   - INGET BRANCH MAIN JANGAN PERNAH DIAPA-APAIN (MENCEGAH TERJADI HAL YANG NGGAK DIINGINKAN).
3. Workflow
   - Setiap kalian mau mulai ngoding pastiin sebelumnya kalian pull branch develop (biar kode kalian udah sinkron sama di github). dengan cara:
```bash
git pull origin develop
```
   - Lanjut ngoding...
   - Kalo udah selesai, PULL LAGI DARI BRANCH DEVELOP (Biar sinkronnya realtime karena siapa tau ada anggota tim yang udah memperbarui developnya pas kalian lagi ngoding). dengan cara:
```bash
git pull origin develop
```
   - Commit hasil ngoding, dengan cara:
```bash
git add .
git commit -m "<message-yang-informatif>"
```
   - Push hasil kerja, dengan cara:
```bash
git push
```
   - Pull request (pastiin ke branch develop bukan ke main)
   - Kalo ngga ada konflik merge aja, kalo ada kabarin grup atau coba resolve conflict (pastiin kalian tau kode mana yang harus diambil dan dibuang pas lg benerin, jangan ngasal)

