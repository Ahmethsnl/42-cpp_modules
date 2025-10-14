# 💎 C++ Modülleri (42 Cursus)

[![Son Commit](https://img.shields.io/github/last-commit/ahmethsnl/cpp_modules?style=flat)](https://github.com/ahmethsnl/cpp_modules/commits)

Bu repoda 42 okulu kapsamında gerçekleştirdiğim C++ modül projeleri yer almaktadır. Her modül nesne yönelimli programlama (OOP), bellek yönetimi, istisna yakalama, tür dönüştürme gibi konuları kademeli şekilde ele almaktadır.

---

## 📦 İçerik

### 📘 Modül 00 — Temel Sınıflar & Fonksiyonlar
- **ex00**: `megaphone.cpp`
- **ex01**: `Contact.cpp`, `PhoneBook.cpp`, `Utils.cpp`, `UtilsTwo.cpp`

### 📘 Modül 01 — Referanslar, Pointer'lar ve Bellek
- **ex00**: `newZombie.cpp`, `randomChump.cpp`, `Zombie.cpp`
- **ex01**: `zombieHorde.cpp`
- **ex02**: `main.cpp`
- **ex03**: `HumanA.cpp`, `HumanB.cpp`, `Weapon.cpp`
- **ex04**: `replace`
- **ex05**: `Harl.cpp`

### 📘 Modül 02 — Kalıtım (Inheritance)
- **ex00**: `Fixed.cpp`
- **ex01**: `Fixed.cpp`
- **ex02**: `Fixed.cpp`, `Operators.cpp`

### 📘 Modül 03 — Çok Biçimlilik (Polymorphism)
- **ex00**: `ClapTrap.cpp`
- **ex01**: `ScavTrap.cpp`
- **ex02**: `FragTrap.cpp`, `ScavTrap.cpp`

### 📘 Modül 04 — Arayüzler ve Type Casting
- **ex00**: `Animal.cpp`, `Cat.cpp`, `Dog.cpp`, `WrongAnimal.cpp`, `WrongCat.cpp`
- **ex01**: `Brain.cpp`, `Cat.cpp`, `Dog.cpp`
- **ex02**: `Brain.cpp`, `Cat.cpp`, `Dog.cpp`

### 📘 Modül 05 — Bürokrasi Simülasyonu
- **ex00**: `Bureaucrat.cpp`
- **ex01**: `Form.cpp`
- **ex02**: `AForm.cpp`, `PresidentialPardonForm.cpp`, `RobotomyRequestForm.cpp`

### 📘 Modül 06 — Tür Dönüştürme (Scalar Conversion)
- **ex00**: `ScalarConverter.cpp`, `ScalarConverter.hpp`, `main.cpp`
- **ex01**: `Serializer.cpp`, `Serializer.hpp`, `Data.cpp`, `Data.hpp`, `main.cpp`
- **ex02**: `A.cpp`, `A.hpp`, `B.cpp`, `B.hpp`, `C.cpp`, `C.hpp`, `Base.cpp`, `Base.hpp`, `Functions.cpp`, `Functions.hpp`, `main.cpp`

### 📘 Modül 07 — Şablonlar (Templates)
- **ex00**: `whatever.hpp`, `main.cpp`
- **ex01**: `iter.hpp`, `main.cpp`
- **ex02**: `Array.hpp`, `main.cpp`

### 📘 Modül 08 — STL Kapsayıcıları (STL Containers)
- **ex00**: `easyfind.hpp`, `main.cpp`
- **ex01**: `Span.cpp`, `Span.hpp`, `main.cpp`
- **ex02**: `MutantStack.hpp`, `main.cpp`

### 📘 Modül 09 — STL Algoritmaları ve Containers
- **ex00**: `BitcoinExchange.cpp`, `BitcoinExchange.hpp`, `main.cpp` - Bitcoin değişim oranları (`std::map`)
- **ex01**: `RPN.cpp`, `RPN.hpp`, `main.cpp` - Ters Polonya Notasyonu hesaplayıcısı (`std::stack`)
- **ex02**: `PmergeMe.cpp`, `PmergeMe.hpp`, `main.cpp` - Ford-Johnson merge-insert algoritması (`std::vector`, `std::deque`)
## 📦 Container Nedir?

“Container” = içinde veri tutan sınıf.

C++’ta container dediğimiz şeyler, **STL (Standard Template Library)** koleksiyonlarıdır — yani birden fazla veriyi tutan kutular.  
Her kutunun veriyi tutma biçimi farklıdır.

| Container | Ne işe yarar | Özellik |
|------------|--------------|----------|
| `std::vector` | Dizi gibidir ama boyutu değişebilir | Bellekte ardışık saklar (array gibi) |
| `std::list` | Bağlı liste (linked list) | Eleman ekleme/çıkarma hızlıdır, ama rastgele erişim yavaştır |
| `std::deque` | Çift uçlu sıra (Double Ended Queue) | Hem baştan hem sondan ekleme hızlıdır |
| `std::set` | Elemanları sıralı tutar, tekrar etmez | İçeride ağaç yapısı vardır |
| `std::map` | Anahtar-değer çifti tutar (dictionary gibi) | İçeride yine ağaç yapısı vardır |

Container’lar veriyi **saklamak** için vardır.

### Örnek:
```cpp
std::vector<int> sayilar;
sayilar.push_back(10);
sayilar.push_back(20);
```

Bu `vector`, içinde 10 ve 20 değerlerini tutan bir **kap** gibidir.

---

## 🧭 Iterator Nedir?

“Iterator” = bu kapların içinde gezmek için kullanılan bir işaretçi (pointer gibi).  
Yani container’ın içindeki elemanlara **sırayla erişmek** için iterator kullanırsın.

### Örnek:
```cpp
std::vector<int> v;
v.push_back(10);
v.push_back(20);

std::vector<int>::iterator it = v.begin();
while (it != v.end()) {
    std::cout << *it << std::endl;  // 10, sonra 20
    ++it;  // bir sonraki elemana geç
}
```

Burada:
- `v.begin()` → ilk elemana gider.  
- `v.end()` → son elemandan bir sonrasını gösterir (döngü orada biter).  
- `*it` → iterator’un gösterdiği değeri verir.  

Iterator, pointer gibi davranır ama container’a özel kuralları vardır.

---

## 🧱 Stack (Yığın) Nedir?

**Stack (yığın)** = *en son giren, ilk çıkar (LIFO: Last In First Out)*.  
Bardağa tabak dizer gibi düşün: En son koyduğun tabağı önce alırsın.

### Örnek:
```cpp
std::stack<int> s;
s.push(10);
s.push(20);
s.push(30);

std::cout << s.top(); // 30 (en üstteki)
s.pop();              // 30 çıkarıldı
std::cout << s.top(); // 20
```

Ama dikkat:
- `std::stack` aslında başka bir container kullanır — genelde `std::deque` veya `std::vector`.  
- Yani stack bir **container adapter**’dır: başka bir container’ı kullanarak farklı bir arayüz sunar.
- Ancak stack’in içindeki verilere **direkt erişemezsin.**
- Sadece `push()`, `pop()`, `top()` metodları vardır.
- Yani **for döngüsüyle gezmek mümkün değildir.**

---

## 🧬 MutantStack Nedir?

İşte burada **MutantStack** devreye girer.

MutantStack şunu söyler:
> “Ben `std::stack`’ten miras alıyorum ve onun içindeki gizli container’a iterator erişimi veriyorum.”

Yani:
- **Normal stack** gibi davranır.  
- Ama ek olarak, **içindeki elemanlarda dolaşabilmeni** sağlar.

### Normal Stack ile Yapılamayan:
```cpp
std::stack<int> s;
// for (...)  // YAPAMAZSIN, çünkü stack'te begin()/end() yok
```

### MutantStack ile Mümkün:
```cpp
MutantStack<int> s;
s.push(10);
s.push(20);
s.push(30);

for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << std::endl;
```

Bu mümkün olur çünkü MutantStack, `std::stack`’in altındaki gizli container’a (`this->c`) erişim sağlar:

```cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
```

Buradaki `this->c`, `std::stack`’in **protected** (korumalı) üyesidir.  
Yani `MutantStack`, ondan miras aldığı için erişebilir.

Bu sayede **stack’in içi görünür hale gelir.**

---

## 🔍 Kısaca Özet

| Kavram | Anlamı | Özellik |
|--------|---------|----------|
| **Container** | Veriyi saklayan sınıf | (vector, list, deque, map, set) |
| **Iterator** | Container içinde dolaşmayı sağlar | begin(), end(), ++it, *it |
| **Stack** | LIFO veri yapısı (son giren ilk çıkar) | Sadece `push`, `pop`, `top` vardır |
| **MutantStack** | Stack + iterator desteği | İçindekilerde gezebilirsin (begin/end) |

---

📘 **Sonuç:**  
> `stack` sadece en üstteki elemana erişebilmeni sağlar.  
> `MutantStack` ise stack’in içini açar, tüm elemanlarda gezebilmeni sağlar.

---

---

## 🔧 Derleme & Çalıştırma

Her modül klasöründe ayrı bir `Makefile` bulunur. Derleme işlemi:

```bash
make
./program_adı
```

---
