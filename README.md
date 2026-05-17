## MyVector funkciju pavyzdziai

### PushBack

```cpp
MyVector<int> v;
v.PushBack(10);
v.PushBack(20);
```

### Resize

```cpp
MyVector<int> v = {1, 2, 3};
v.Resize(5, 9);
// Rezultatas: 1 2 3 9 9
```

### Insert

```cpp
MyVector<int> v = {1, 2, 3};
v.Insert(1, 99);
// Rezultatas: 1 99 2 3
```

### Erase

```cpp
MyVector<int> v = {1, 2, 3};
v.Erase(1);
// Rezultatas: 1 3
```

### operator==

```cpp
MyVector<int> a = {1, 2, 3};
MyVector<int> b = {1, 2, 3};

if (a == b) {
    // vektoriai lygus
}
```

---

## Unit testai

### Testai buvo vykdomi kompiuteryje su šiais parametrais:
  
| Komponentas | Specifikacija                                |
| ----------- | -------------------------------------------- |
| CPU         | AMD Ryzen 9 9900X (12 branduolių, 4.40 GHz) |
| RAM         | 32 GB DDR5 RAM (6000 MT/s)                   |
| GPU         | NVIDIA GeForce RTX 5070 Ti (16 GB VRAM)      |
| OS          | Windows PRO 64-bit                           |
| MotherBoard | B850 Pro RS WiFi                             |


Testavimui naudotas doctest framework.

Rezultatas:

```txt
[doctest] test cases:  28 | 28 passed | 0 failed | 0 skipped
[doctest] assertions: 103 | 103 passed | 0 failed |
[doctest] Status: SUCCESS!
```

---

## std::vector ir MyVector spartos palyginimas

| Elementai | std::vector, s | MyVector, s | std perskirstymai | MyVector perskirstymai | ratio |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.000011 | 0.000009 | 11 | 10 | 0.834862 |
| 10 000 | 0.000079 | 0.000065 | 15 | 14 | 0.823380 |
| 100 000 | 0.000609 | 0.000469 | 18 | 17 | 0.770734 |
| 1 000 000 | 0.005748 | 0.004508 | 21 | 20 | 0.784335 |
| 10 000 000 | 0.058093 | 0.048645 | 25 | 24 | 0.837364 |
| 100 000 000 | 0.572705 | 0.470027 | 28 | 27 | 0.820714 |

Ratio reiksme apskaiciuota kaip `MyVector laikas / std::vector laikas`.

Kai `ratio < 1`, `MyVector` konkreciame teste buvo greitesnis.

Atminties perskirstymas skaiciuojamas tada, kai pries elemento pridejima konteinerio `size()` yra lygus `capacity()`. Tokiu atveju konteineryje nebera laisvos vietos naujam elementui, todel reikia alokuoti nauja didesni masyva ir perkelti esamus elementus.

## Dokumentacija

MyVector konteineris dokumentuotas naudojant Doxygen.

Dokumentacijos generavimas:

```bash
doxygen Doxyfile
```

Dokumentacija rasite:

```bash
Vector/docs/html/index.html
```