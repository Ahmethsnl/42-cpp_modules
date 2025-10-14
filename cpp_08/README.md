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
