
# Sistem Manajemen Atlet dan Klub Olahraga

Program C++ untuk mengelola data atlet, klub olahraga, dan relasi kontrak antara mereka.

## Fitur

✅ Manajemen data atlet (tambah, edit, hapus)  
✅ Manajemen data klub (tambah, edit, hapus)  
✅ Sistem kontrak atlet-klub  
✅ Pencarian dan analisis data  
✅ Antarmuka menu berbasis konsol  

## Struktur File

```
Struktur Data
├── Child.cpp       # Implementasi fungsi untuk manajemen klub
├── Child.h         # Header file untuk struktur data klub
├── Parent.cpp      # Implementasi fungsi untuk manajemen atlet
├── Parent.h        # Header file untuk struktur data atlet
├── Relasi.cpp      # Implementasi fungsi untuk relasi atlet-klub
├── Relasi.h        # Header file untuk struktur relasi
└── main.cpp        # Program utama dengan menu antarmuka
```

## Panduan Penggunaan

1. **Menu Utama**:
   - Pilih opsi dari 1-20 sesuai kebutuhan
   - Setiap operasi akan memberikan konfirmasi hasil

2. **Contoh Penggunaan**:
   - Daftarkan atlet baru (menu 1)
   - Daftarkan klub baru (menu 2)
   - Buat kontrak atlet-klub (menu 5)
   - Lihat daftar kontrak (menu 6)

3. **Fitur Analisis**:
   - Klub dengan atlet terbanyak (menu 7)
   - Atlet dengan klub terbanyak (menu 8)
   - Atlet tanpa klub (menu 18)
   - Klub tanpa atlet (menu 19)

## Teknologi Digunakan

- Bahasa C++
- Struktur data linked list (single, double, circular)
- Input/output konsol
- Pembangkitan ID otomatis
