# 💎 C++ Modülleri (42 Cursus)

[![Son Commit](https://img.shields.io/github/last-commit/ahmethsnl/cpp_modules?style=flat)](https://github.com/ahmethsnl/cpp_modules/commits)

Bu repoda 42 okulu kapsamında gerçekleştirdiğim C++ modül projeleri yer almaktadır. Her modül nesne yönelimli programlama (OOP), bellek yönetimi, istisna yakalama, tür dönüştürme gibi konuları kademeli şekilde ele almaktadır.

---

## 📦 İçerik

### 📘 Modül 00 — Temel Sınıflar & Fonksiyonlar
- C++'da sınıf tanımı, constructor/destructor kullanımı
- Farklı erişim belirleyiciler (`public`, `private`, `protected`)
- `this` pointer'ı ve member initializer list yapısı

### 📘 Modül 01 — Referanslar, Pointer'lar ve Bellek
- Referanslar ve sabit referanslar
- Dinamik bellek yönetimi (`new` / `delete`)
- Sınıf içinde pointer kullanımı ve ownership kavramı

### 📘 Modül 02 — Kalıtım (Inheritance)
- Tekli kalıtım
- Sanal fonksiyonlar (`virtual`) ve override işlemleri
- "is-a" ilişkisi üzerinden OOP kavramları

### 📘 Modül 03 — Çok Biçimlilik (Polymorphism)
- Soyut sınıflar ve saf sanal fonksiyonlar
- Sanal destructor kullanımı
- Polimorfik diziler, fonksiyonel kalıtım yapıları

### 📘 Modül 04 — Arayüzler ve Type Casting
- Arayüz kavramı ve çok biçimli sınıf yapıları
- `dynamic_cast`, `static_cast`, `reinterpret_cast` kullanımları
- `try-catch` bloklarıyla istisna (exception) yönetimi

> Diğer modüller eklendikçe içerik güncellenecektir.

---

## 🔧 Derleme & Çalıştırma

Her modül klasöründe ayrı bir `Makefile` bulunur. Derleme işlemi:

```bash
make
./program_adı
