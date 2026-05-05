# Studentų pažymių skaičiavimo programa

Programa skirta studentų duomenims apdoroti. Ji leidžia įvesti arba nuskaityti studentų vardus, pavardes, namų darbų pažymius ir egzamino rezultatą. Pagal šiuos duomenis apskaičiuojamas galutinis balas pagal vidurkį ir medianą.

## Funkcionalumas

- Duomenų įvedimas ranka.
- Atsitiktinis pažymių generavimas.
- Atsitiktinis studentų vardų, pavardžių ir pažymių generavimas.
- Duomenų nuskaitymas iš failo.
- Studentų rūšiavimas pagal vardą, pavardę, galutinį balą pagal vidurkį arba medianą.
- Studentų skirstymas į išlaikiusius ir neišlaikiusius.
- Darbas su `vector`, `list` ir `deque` konteineriais.
- Realizuota `Studentas` klasė.
- Realizuota abstrakti bazinė klasė `Zmogus`.
- Realizuota Rule of Five.
- Pridėti unit testai.
- Sugeneruota Doxygen dokumentacija.

## Projekto struktūra

- `include/` – antraštiniai failai.
- `src/` – programos realizacijos failai.
- `tests/` – unit testai.
- `docs/` – Doxygen dokumentacija.
- `Doxyfile` – Doxygen konfigūracija.
- `Makefile` – kompiliavimo instrukcijos.

## Kompiliavimas

Sukompiliuoti visas programos versijas:

`make all`

## Programos paleidimas

Paleisti `deque` versiją:

`./deque_app`


Paleisti `vector` versiją:

`./vector_app`

Paleisti `list` versiją:

`./list_app`

## Failų išvalymas

Ištrinti sukompiliuotus failus:

`make clean`


## Unit testai

Unit testai realizuoti naudojant `doctest` framework.

Testai tikrina:

- numatytąjį `Studentas` konstruktorių;
- setterius ir getterius;
- galutinio balo skaičiavimą pagal vidurkį;
- galutinio balo skaičiavimą pagal medianą;
- pažymių išvalymą;
- kopijavimo konstruktorių;
- kopijavimo priskyrimo operatorių;
- perkėlimo konstruktorių;
- perkėlimo priskyrimo operatorių.

Testų sukompiliavimas:

`make test`


Testų paleidimas:

`./student_tests.exe`



## Doxygen dokumentacija

Dokumentacija sugeneruota naudojant `Doxygen`.

Dokumentacijos generavimas:

`doxygen Doxyfile`

Po sugeneravimo dokumentacija randama:

- HTML: `docs/html/index.html`
- LaTeX: `docs/latex/`
- PDF: `docs/latex/refman.pdf`

PDF sugeneravimas iš LaTeX:

1. Pereiti į `docs/latex`
2. Paleisti `pdflatex refman.tex` kelis kartus
3. Gautas failas: `refman.pdf`

## Versijos

| Versija | Aprašymas |
|---|---|
| v1.0 | Pradinė programos versija. Realizuotas studentų duomenų įvedimas ir galutinio balo skaičiavimas. |
| v1.1 | Programa papildyta `Studentas` klase. |
| v1.2 | Realizuota Rule of Five. |
| v1.5 | Sukurta abstrakti bazinė klasė `Zmogus`, kurią paveldi `Studentas`. |
| v2.0 | Pridėti unit testai su `doctest` ir sugeneruota Doxygen dokumentacija HTML, LaTeX ir PDF formatais. |

## Rule of Five

`Studentas` klasėje realizuoti šie metodai:

| Metodas | Paskirtis |
|---|---|
| Destruktorius | Sunaikina objektą. |
| Kopijavimo konstruktorius | Sukuria naują objektą kopijuojant kitą objektą. |
| Kopijavimo priskyrimo operatorius | Priskiria vieno objekto duomenis kitam jau egzistuojančiam objektui. |
| Perkėlimo konstruktorius | Sukuria naują objektą perkeliant kito objekto duomenis. |
| Perkėlimo priskyrimo operatorius | Perkelia kito objekto duomenis į jau egzistuojantį objektą. |

## Naudoti įrankiai

- C++
- Makefile
- Doxygen
- MiKTeX
- doctest
- Git / GitHub

## Šaltiniai

- doctest: https://github.com/doctest/doctest/blob/master/doctest/doctest.h
- MikTeX: https://miktex.org/