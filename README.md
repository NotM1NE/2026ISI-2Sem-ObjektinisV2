## v1.5 versijos pakeitimai

Šioje versijoje programa buvo perdaryta pritaikant paveldėjimą. Vietoje vienos `Studentas` klasės sukurtos dvi klasės:

| Klasė | Tipas | Paskirtis |
|---|---|---|
| `Zmogus` | Abstrakti bazinė klasė | Saugo bendrus žmogaus duomenis: vardą ir pavardę |
| `Studentas` | Išvestinė klasė | Paveldi iš `Zmogus` ir saugo studento pažymius, egzamino rezultatą, vidurkį ir medianą |

---

## Abstrakti bazinė klasė `Zmogus`

`Zmogus` klasė skirta bendriems žmogaus duomenims saugoti. Į ją iškelti laukai, kurie tinka kiekvienam žmogui:

- `_vardas`
- `_pavarde`

Ši klasė yra abstrakti, nes joje yra pure virtual metodas:
```cpp
virtual void spausdinti() const = 0;
```

---
### Pagrindiniai pakeitimai
## zmogus.h
Sukurta nauja klase:

```cpp
#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

using std::string;

class Zmogus
{
protected:
    string _vardas;
    string _pavarde;

public:
    Zmogus() {}
    Zmogus(const string &vardas, const string &pavarde)
        : _vardas(vardas), _pavarde(pavarde) {}

    virtual ~Zmogus() {}

    virtual void spausdinti() const = 0;

    inline const string vardas() const { return _vardas; }
    inline const string pavarde() const { return _pavarde; }

    void SetVardas(const string &vardas) { _vardas = vardas; }
    void SetPavarde(const string &pavarde) { _pavarde = pavarde; }
};

#endif
```
## Studentas klasė
`Studentas` klasė yra išvestinė klasė, kuri paveldi iš abstrakčios bazinės klasės `Zmogus`:

```cpp
class Studentas : public Zmogus
```

`spausdinti()` metodas:

```cpp
void spausdinti() const override;
```
Kadangi Zmogus klasėje metodas spausdinti() yra pure virtual, Studentas klasė privalo jį realizuoti:

## Studentas.cpp

```cpp
void Studentas::spausdinti() const
{
    cout << vardas() << " " << pavarde() << " " << vid() << " " << med() << endl; 
}
```


