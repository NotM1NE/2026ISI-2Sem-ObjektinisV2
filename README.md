# Studentų rūšiavimo aplikacija V1.1

## Aprašymas

Šioje versijoje ankstesnė `struct Studentas` realizacija buvo pakeista į `class Studentas` realizaciją.

Programa skirta studentų duomenims nuskaityti, generuoti, rūšiuoti, suskirstyti į dvi grupes pagal galutinį rezultatą ir išvesti rezultatus į failus.

Pagrindiniai V1.1 pakeitimai:

- `struct Studentas` pakeistas į `class Studentas`;
- klasės duomenų laukai padaryti privatūs;
- pridėti getteriai ir setteriai;
- pridėtas numatytasis konstruktorius;
- pridėtas konstruktorius su `std::istream`;
- pridėtas destruktorius;
- atnaujintas visas kodas, kuris anksčiau tiesiogiai pasiekdavo `Studentas` laukus;
- atliktas `struct` ir `class` versijų veikimo spartos palyginimas;

## Kompiliatoriaus optimizavimo flag'ų analizė

Papildomai buvo atliktas `struct Studentas` ir `class Studentas` versijų testavimas su skirtingais kompiliatoriaus optimizavimo lygiais:

- `-O1`
- `-O2`
- `-O3`

---

## Naudota testavimo sistema

| Komponentas | Specifikacija |
|---|---|
| CPU | AMD Ryzen 9 9900X, 12 branduolių, 4.40 GHz |
| RAM | 32 GB DDR5 RAM, 6000 MT/s |
| GPU | NVIDIA GeForce RTX 5070 Ti, 16 GB VRAM |
| OS | Windows PRO 64-bit |
| Motherboard | B850 Pro RS WiFi |


## `struct` ir `class` realizacijų palyginimas

Palyginimui naudotas:

- konteineris: `std::deque`;
- dalijimo strategija: `SplitStudentsStrategy2`;
- testavimo failai: `studentaiGen100000.txt` ir `studentaiGen1000000.txt`.
.

**Visi testai buvo paleisti 5 kartus.**

## Optimizavimo flag'ų rezultatai

| Versija | Optimizavimo flag'as | `.exe` failo dydis | `100000` bendras laikas | `1000000` bendras laikas |
|---|---|---:|---:|---:|
| Struct | `-O1` |277 KB| 0.577948 s | 5.860945 s |
| Struct | `-O2` |267 KB| 0.562259 s | 6.301766 s |
| Struct | `-O3` |262 KB| 0.583135 s | 5.935834 s |
| Class | `-O1` | 269 KB | 0.531903 s | 6.274581 s |
| Class | `-O2` | 265 KB | 0.587221 s | 6.116466 s |
| Class | `-O3` | 268 KB | 0.596006 s | 5.801101 s |

## Optimizavimo flag'ų analizės apibendrinimas

Atlikus `struct` ir `class` versijų testavimą su skirtingais kompiliatoriaus optimizavimo flag'ais, matyti, kad rezultatai nėra visiškai vienodi skirtingiems failų dydžiams.

Su `100000` studentų failu greičiausiai veikė `class` versija su `-O1` flag'u. Jos bendras laikas buvo `0.531903 s`. Lėčiausias rezultatas šiame teste buvo `class` versijos su `-O3` flag'u - `0.596006 s`, tačiau skirtumai tarp visų rezultatų nėra labai dideli.

Su `1000000` studentų failu geriausią rezultatą parodė `class` versija su `-O3` flag'u. Jos bendras laikas buvo `5.801101 s`. Lėčiausias rezultatas šiame teste buvo `struct` versija su `-O2` flag'u - `6.301766 s`.

Pagal `.exe` failo dydžius mažiausias vykdomasis failas buvo gautas `struct` versijoje su `-O3` flag'u - `262 KB`. Didžiausias failas buvo `struct` versijoje su `-O1` flag'u - `277 KB`.

Bendrai galima pastebėti, kad didesniame `1000000` studentų teste agresyvesnis optimizavimas `-O3` davė geriausią rezultatą `class` versijoje. Vis dėlto mažesniame `100000` teste geriausiai pasirodė `-O1`, todėl galima teigti, kad optimizavimo flag'ų poveikis priklauso nuo duomenų dydžio ir konkrečios programos vykdymo situacijos.

Galutinė išvada: `class` realizacija su tinkamai panaudotais getteriais, `const&` perdavimais ir sumažintu kopijavimu gali veikti labai panašiai arba net greičiau už `struct` realizaciją. Didžiausią įtaką veikimo laikui turėjo ne pats `struct` ar `class` pasirinkimas, o failų nuskaitymas, išvedimas, objektų kopijavimas ir kompiliatoriaus optimizavimo lygis.

---

## Nuotraukos
`struct`
**O1**
<img width="331" height="292" alt="image" src="https://github.com/user-attachments/assets/57426e78-86ca-4d6e-93dc-2660db14a9de" />
**O2**
<img width="284" height="287" alt="image" src="https://github.com/user-attachments/assets/f4d8f8e4-2b71-4d02-9ec7-30a6c957c958" />
**O3**
<img width="299" height="296" alt="image" src="https://github.com/user-attachments/assets/c4a89d28-6d86-4bab-84d0-9d17343540aa" />

`class`
**O1**
<img width="318" height="335" alt="image" src="https://github.com/user-attachments/assets/c1f17dc1-3ab2-4193-b1c3-7e4b54ff6eda" />

**O2**
<img width="316" height="303" alt="image" src="https://github.com/user-attachments/assets/69b5682e-5d1d-49ab-b731-bd2c79011c80" />

**O3**
<img width="286" height="288" alt="image" src="https://github.com/user-attachments/assets/e9486ce5-94f6-42c2-9447-82dca985e533" />



