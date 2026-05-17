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

# Studentu programos spartos analize

Buvo palygintos dvi studentu programos versijos:

1. versija naudojanti `std::vector`;
2. versija naudojanti sukurta `MyVector`.

Abi versijos buvo kompiliuojamos su tuo paciu flagu:

```bash
-O2
```

Buvo testuojamos trys studentu skirstymo strategijos.

---

## std::vector rezultatai

### std::vector, Strategija 1, -O2

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003311 | 0.005551 | 0.000097 | 0.003804 | 0.012764 |
| 10 000 | 0.025616 | 0.010488 | 0.000837 | 0.029144 | 0.066085 |
| 100 000 | 0.229144 | 0.107024 | 0.008967 | 0.237812 | 0.582949 |
| 1 000 000 | 2.290937 | 1.063981 | 0.098559 | 2.499278 | 5.952756 |
| 10 000 000 | 24.571981 | 12.109190 | 0.969910 | 25.948245 | 63.599327 |

---

### std::vector, Strategija 2, -O2

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003426 | 0.006483 | 0.000085 | 0.004128 | 0.014122 |
| 10 000 | 0.026352 | 0.015043 | 0.000708 | 0.029562 | 0.071665 |
| 100 000 | 0.258227 | 0.127356 | 0.011516 | 0.299307 | 0.696406 |
| 1 000 000 | 2.493317 | 1.292099 | 0.137395 | 2.462447 | 6.385259 |
| 10 000 000 | 25.385831 | 14.103753 | 1.377100 | 24.151549 | 65.018233 |

---

### std::vector, Strategija 3, -O2

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003574 | 0.006303 | 0.000038 | 0.004240 | 0.014154 |
| 10 000 | 0.027044 | 0.012833 | 0.000551 | 0.030001 | 0.070429 |
| 100 000 | 0.250867 | 0.147906 | 0.008935 | 0.271692 | 0.679401 |
| 1 000 000 | 2.569573 | 1.169679 | 0.126340 | 2.871681 | 6.737273 |
| 10 000 000 | 26.913728 | 13.749437 | 1.074918 | 25.648986 | 67.387069 |

---

## MyVector rezultatai

### MyVector, Strategija 1, -O2

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003518 | 0.006409 | 0.000167 | 0.003781 | 0.013875 |
| 10 000 | 0.030658 | 0.016129 | 0.001493 | 0.031867 | 0.080146 |
| 100 000 | 0.306473 | 0.152222 | 0.016381 | 0.279460 | 0.754536 |
| 1 000 000 | 2.547968 | 1.276743 | 0.184945 | 2.590297 | 6.599953 |
| 10 000 000 | 24.277082 | 8.694841 | 1.534597 | 26.472477 | 60.978996 |

---

### MyVector, Strategija 2, -O2

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003213 | 0.005855 | 0.000165 | 0.003976 | 0.013210 |
| 10 000 | 0.030978 | 0.013923 | 0.001406 | 0.032993 | 0.079300 |
| 100 000 | 0.261208 | 0.151498 | 0.018767 | 0.265543 | 0.697016 |
| 1 000 000 | 2.759056 | 1.388858 | 0.216714 | 2.876493 | 7.241121 |
| 10 000 000 | 27.736729 | 13.751126 | 2.311770 | 28.307928 | 72.107554 |

---

### MyVector, Strategija 3, -O2

Pradine `MyVector` Strategija 3 realizacija naudojo daugkartini `Erase(index)` kvietima:

```cpp
while (grupe.size() > index)
{
    grupe.Erase(index);
}
```

Si realizacija yra labai neefektyvi, nes kiekvienas `Erase(index)` perstumdo visus likusius elementus i kaire. Del to trinant daug elementu vykdymo laikas labai stipriai isauga.

| Studentu kiekis | Generavimas, s | Nuskaitymas, s | Skirstymas, s | Isvedimas, s | Bendras, s |
|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.003431 | 0.006805 | 0.000524 | 0.003844 | 0.014603 |
| 10 000 | 0.030990 | 0.016367 | 0.035970 | 0.032530 | 0.115857 |
| 100 000 | 0.253407 | 0.132751 | 3.362305 | 0.283403 | 4.031867 |

Testas su didesniu nei `100 000` studentu failu buvo nutrauktas po mazdaug 30 minuciu, nes vykdymo laikas buvo per ilgas praktiniam naudojimui.

---

# Bendras std::vector ir MyVector palyginimas

## Strategija 1

| Studentu kiekis | std::vector bendras, s | MyVector bendras, s | ratio |
|---:|---:|---:|---:|
| 1 000 | 0.012764 | 0.013875 | 1.087042 |
| 10 000 | 0.066085 | 0.080146 | 1.212777 |
| 100 000 | 0.582949 | 0.754536 | 1.294344 |
| 1 000 000 | 5.952756 | 6.599953 | 1.108725 |
| 10 000 000 | 63.599327 | 60.978996 | 0.958800 |

Strategijoje 1 `MyVector` buvo letesnis mazesniuose testuose, taciau su `10 000 000` irasu bendras laikas buvo siek tiek geresnis negu `std::vector`.

---

## Strategija 2

| Studentu kiekis | std::vector bendras, s | MyVector bendras, s | ratio |
|---:|---:|---:|---:|
| 1 000 | 0.014122 | 0.013210 | 0.935420 |
| 10 000 | 0.071665 | 0.079300 | 1.106536 |
| 100 000 | 0.696406 | 0.697016 | 1.000876 |
| 1 000 000 | 6.385259 | 7.241121 | 1.134034 |
| 10 000 000 | 65.018233 | 72.107554 | 1.109034 |

Strategijoje 2 `std::vector` dazniausiai buvo greitesnis, ypac su didesniais duomenu kiekiais. `MyVector` skirstymo laikas buvo didesnis, nes naudojama paprastesne konteinerio realizacija.

---

## Strategija 3

| Studentu kiekis | std::vector bendras, s | MyVector bendras, s | ratio |
|---:|---:|---:|---:|
| 1 000 | 0.014154 | 0.014603 | 1.031723 |
| 10 000 | 0.070429 | 0.115857 | 1.645038 |
| 100 000 | 0.679401 | 4.031867 | 5.935913 |

Strategijoje 3 `MyVector` buvo daug letesnis del neefektyvaus daugkartinio `Erase(index)` naudojimo. Su didesniais duomenu kiekiais testas buvo nutrauktas, nes vykdymo laikas tapo praktiskai netinkamas.

---

## Strategija 3 skirstymo problemos iliustracija

| Studentu kiekis | std::vector skirstymas, s | MyVector skirstymas, s | Kiek kartu leciau |
|---:|---:|---:|---:|
| 100 000 | 0.008935 | 3.362305 | 376.31 |

Si lentele parodo, kad problema yra ne visas konteineris, o konkrecios operacijos realizacija. `std::vector` turi efektyvu intervalo trynima `erase(first, last)`, o pradine `MyVector` versija trynima dare po viena elementa.

---

# Isvados

1. `MyVector` konteineris sekmingai realizuoja pagrindini `std::vector` tipo funkcionaluma.
2. Unit testai patvirtino, kad pagrindines `MyVector` funkcijos veikia korektiskai.
3. Paprastame `PushBack` teste `MyVector` buvo greitesnis uz `std::vector`.
4. Studentu programoje rezultatai priklauso nuo naudojamos strategijos ir konkreciu operaciju.
5. Strategijoje 1 su `10 000 000` irasu `MyVector` bendras laikas buvo geresnis uz `std::vector`.
6. Strategijoje 2 `std::vector` daugeliu atveju buvo greitesnis.
7. Strategijoje 3 `MyVector` pradine realizacija buvo neefektyvi del daugkartinio `Erase(index)` naudojimo.

---