## v1.5 versijos pakeitimai

Šioje versijoje programa buvo perdaryta pritaikant paveldėjimą. Vietoje vienos `Studentas` klasės buvo sukurtos dvi klasės:

| Klasė | Tipas | Paskirtis |
|---|---|---|
| `Zmogus` | Abstrakti bazinė klasė | Saugo bendrus žmogaus duomenis: vardą ir pavardę |
| `Studentas` | Išvestinė klasė | Paveldi iš `Zmogus` ir saugo studento pažymius, egzamino rezultatą, vidurkį ir medianą |

---

## Abstrakti bazinė klasė `Zmogus`

Sukurta bazinė klasė `Zmogus`, skirta bendrai aprašyti žmogų. Joje saugomi bendri laukai:

- `_vardas`
- `_pavarde`

Klasė `Zmogus` yra abstrakti, nes turi pure virtual metodą:

### zmogus.h

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
