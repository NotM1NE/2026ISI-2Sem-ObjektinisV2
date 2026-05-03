# Studentų rezultatų skaičiavimo programa

## Aprašymas

Programa skirta studentų galutiniams rezultatams skaičiuoti pagal namų darbų pažymius ir egzamino rezultatą.

Galutinis balas skaičiuojamas dviem būdais:

- pagal vidurkį;
- pagal medianą.

Programa palaiko kelis konteinerių tipus:

| Konteineris | Programa |
|---|---|
| `vector` | `vector_app` |
| `list` | `list_app` |
| `deque` | `deque_app` |

---

## Studentas klasės Rule of Five

`Studentas` klasėje realizuoti visi penki Rule of Five metodai:

| Metodas | Paskirtis |
|---|---|
| `~Studentas()` | Destruktorius. Iškviečiamas, kai objektas sunaikinamas |
| `Studentas(const Studentas& other)` | Copy konstruktorius. Sukuria naują objektą kopijuojant kitą objektą |
| `Studentas& operator=(const Studentas& other)` | Copy assignment operatorius. Nukopijuoja duomenis į jau egzistuojantį objektą |
| `Studentas(Studentas&& other) noexcept` | Move konstruktorius. Sukuria naują objektą perkeliant duomenis iš kito objekto |
| `Studentas& operator=(Studentas&& other) noexcept` | Move assignment operatorius. Perkelia duomenis į jau egzistuojantį objektą |

Nors `Studentas` klasėje naudojami `std::string` ir `std::vector`, kurie patys valdo atmintį, Rule of Five metodai buvo realizuoti rankiniu būdu pagal užduoties reikalavimą. Kopijavimo metodai nukopijuoja visus klasės laukus, o perkėlimo metodai naudoja `std::move`.

---

## Rule of Five realizacijos paaiškinimas

### Destruktorius

Destruktorius realizuotas tam, kad objektui baigus gyvavimą būtų išvalomi jo duomenys.

```cpp
Studentas::~Studentas()
{
    _vardas.clear();
    _pavarde.clear();
    _paz.clear();
    _egz = 0;
    _vid = 0.0;
    _med = 0.0;
}
```

### Copy konstruktorius

```cpp
Studentas::Studentas(const Studentas& other)
    : _vardas(other._vardas),
      _pavarde(other._pavarde),
      _paz(other._paz),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
}
```
### Copy priskyrimo operatorius

```cpp
Studentas& Studentas::operator=(const Studentas& other)
{
    if (this != &other)
    {
        _vardas = other._vardas;
        _pavarde = other._pavarde;
        _paz = other._paz;
        _egz = other._egz;
        _vid = other._vid;
        _med = other._med;
    }

    return *this;
}
```
### Move konstruktorius

```cpp
Studentas::Studentas(Studentas &&other) noexcept
    : _vardas(std::move(other._vardas)),
      _pavarde(std::move(other._pavarde)),
      _paz(std::move(other._paz)),
      _egz(other._egz),
      _vid(other._vid),
      _med(other._med)
{
    other._vardas.clear();
    other._pavarde.clear();
    other._paz.clear();
    other._egz = 0;
    other._vid = 0.0;
    other._med = 0.0;
}
```
### Move priskyrimo operatorius

```cpp
Studentas& Studentas::operator=(Studentas&& other) noexcept
{
    if (this != &other)
    {
        _vardas = std::move(other._vardas);
        _pavarde = std::move(other._pavarde);
        _paz = std::move(other._paz);
        _egz = other._egz;
        _vid = other._vid;
        _med = other._med;

        other._vardas.clear();
        other._pavarde.clear();
        other._paz.clear();
        other._egz = 0;
        other._vid = 0.0;
        other._med = 0.0;
    }

    return *this;
}
```
