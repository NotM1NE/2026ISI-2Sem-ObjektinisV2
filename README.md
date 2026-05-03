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

## v1.2 versijos pakeitimai

Šioje versijoje buvo įgyvendinti šie reikalavimai:

| Reikalavimas | Būsena |
|---|---|
| Sukurta `v1.2` šaka | Atlikta |
| Realizuota Rule of Five `Studentas` klasei | Atlikta |
| Realizuotas įvesties operatorius `operator>>` | Atlikta |
| Realizuotas išvesties operatorius `operator<<` | Atlikta |
| Parašytas Rule of Five testas | Atlikta |
| Išleistas `v1.2` release | Atlikta |
| README papildytas lentelėmis ir nuotraukomis | Atlikta |

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