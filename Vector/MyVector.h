#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <utility>
#include <stdexcept>
#include <initializer_list>

/**
 * @file MyVector.h
 * @brief Vektoriaus klases aprasymas.
 */

template <typename T>

/**
 * @class MyVector
 * @brief Dinaminio masyvo konteineris, panasus i originalu std::vector.
 *
 * MyVector saugo elementus dinamiskai alokuotame masyve
 * Konteineris palaiko elementu pridejima, salinima, dydzio keitima,
 * rezervavima, kopijavima, perkelima, palyginimo, iteratoriu operatorius
 *
 * @tparam T Konteineryje saugomu elementu tipas.
 */

class MyVector
{
private:
    T *_data;      /**< Rodykle i masyva */
    int _size;     /**< Dabartinis vektoriaus dydis */
    int _capacity; /**< Rezervuotas atminties vietu skaicius */

    /**
     * @brief Padidina vektoriaus talpa.
     *
     * Jei dabartine talpa lygi 0, nauja talpa tampa 1.
     * Kitu atveju talpa padvigubinama.
     * Funkcija naudojama viduje, kai pridedant nauja elemente nebera laisvos vietos.
     */
    void Grow()
    {
        int newCapacity;
        if (_capacity == 0)
            newCapacity = 1;
        else
            newCapacity = _capacity * 2;

        Reserve(newCapacity);
    }

public:
    using size_type = int;            /**< Tipas, naudojamas vektoriaus dydziui ir talpai saugoti */
    using value_type = T;             /**< Vektoriuje saugomu elementu tipas. */
    using iterator = T *;             /**< Iteratoriaus tipas, rodantis i elementa. */
    using const_iterator = const T *; /**< Const iteratorio tipas, neleidziantis keisti elementa */

    /**
     * @brief Konstruktorius
     *
     * Sukuria tuscia vektoriaus objekta
     * Pradinis dydis yra 0, o pradine talpa yra 1.
     */
    MyVector() : _size(0), _capacity(1), _data(new T[_capacity]) {}

    /**
     * @brief Sukuria vektoriu is initializer_list saraso.
     *
     * Leidzia sukurti vektoriu tokiu budu: MyVector<int> v = {1, 2, 3}.
     *
     * @param values Pradiniu reiksmiu sarasas.
     */
    MyVector(std::initializer_list<T> values);

    /**
     * @brief Kopijavimo konstruktorius.
     *
     * Sukuria nauja vektoriu su atskira atmintimi ir nukopijuotais elementais.
     *
     * @param other Vektorius, is kurio kopijuojama.
     */
    MyVector(const MyVector &other);

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     *
     * Pakeicia dabartinio vektoriaus turini kito vektoriaus kopija.
     *
     * @param other Vektorius, is kurio kopijuojama.
     * @return Nuoroda i dabartini objekta.
     */
    MyVector &operator=(const MyVector &other);

    /**
     * @brief Perkelimo konstruktorius.
     *
     * Perima kito vektoriaus valdoma atminti be elementu kopijavimo.
     * Perkeltas objektas paliekamas tuscias.
     *
     * @param other Vektorius, is kurio perkeliami duomenys.
     */
    MyVector(MyVector &&other) noexcept;

    /**
     * @brief Perkelimo priskyrimo operatorius.
     *
     * Atlaisvina dabartine atminti ir perima kito vektoriaus resursus.
     *
     * @param other Vektorius, is kurio perkeliami duomenys.
     * @return Nuoroda i dabartini objekta.
     */
    MyVector &operator=(MyVector &&other) noexcept;

    /**
     * @brief Sunaikina vektoriu ir atlaisvina dinamiskai alokuota atminti.
     */
    ~MyVector()
    {
        delete[] _data;
    }

    /**
     * @brief Sukuria vektoriu su nurodytu elementu skaiciumi.
     *
     * @param size Pradinis vektoriaus dydis.
     * @throws std::out_of_range Jei size yra neigiamas.
     */
    explicit MyVector(int size)
    {
        if (size < 0)
            throw std::out_of_range("Size cannot be negative");

        _size = size;
        _capacity = size;
        _data = new T[_capacity];
    }
    /**
     * @brief Sukuria vektoriu su nurodytu dydziu ir reiksme.
     *
     * Visi elementai uzpildomi perduota reiksme.
     *
     * @param size Pradinis vektoriaus dydis.
     * @param value Reiksme, kuria uzpildomi elementai.
     * @throws std::out_of_range Jei size yra neigiamas.
     */
    explicit MyVector(int size, const T &value)
    {
        if (size < 0)
            throw std::out_of_range("Size cannot be negative");

        _size = size;
        _capacity = size;
        _data = new T[_capacity];

        for (int i = 0; i < size; i++)
        {
            _data[i] = value;
        }
    }

    /**
     * @brief Grazina dabartini elementu skaiciu.
     *
     * @return Vektoriaus dydis.
     */
    inline int size() const { return _size; }
    /**
     * @brief Grazina rezervuota talpa.
     *
     * @return Kiek elementu gali tilpti be papildomo atminties perskirstymo.
     */
    inline int capacity() const { return _capacity; }
    /**
     * @brief Patikrina, ar vektorius yra tuscias.
     *
     * @return true jei vektorius neturi elementu, false kitu atveju.
     */
    inline bool empty() const
    {
        if (_size == 0)
            return true;
        else
            return false;
    }

    /**
     * @brief Grazina rodykle i vidini duomenu masyva.
     *
     * @return Rodykle i pirma elementa.
     */
    T *Data() { return _data; }

    /**
     * @brief Grazina const rodykle i vidini duomenu masyva.
     *
     * @return Const rodykle i pirma elementa.
     */
    const T *Data() const { return _data; }

    /**
     * @brief Grazina iteratoriu i pirma elementa.
     *
     * @return Iteratorius i vektoriaus pradzia.
     */
    T *begin() { return _data; }

    /**
     * @brief Grazina const iteratoriu i pirma elementa.
     *
     * @return Const iteratorius i vektoriaus pradzia.
     */
    const T *begin() const { return _data; }

    /**
     * @brief Grazina iteratoriu uz paskutinio elemento.
     *
     * @return Iteratorius i pozicija po paskutinio elemento.
     */
    T *end() { return _data + _size; }

    /**
     * @brief Grazina const iteratoriu uz paskutinio elemento.
     *
     * @return Const iteratorius i pozicija po paskutinio elemento.
     */
    const T *end() const { return _data + _size; }

    /**
     * @brief Pasalina paskutini elementa.
     *
     * @throws std::out_of_range Jei vektorius tuscias.
     */
    void PopBack()
    {
        if (_size == 0)
            throw std::out_of_range("PopBack on empty vector");

        _size--;
    }
    /**
     * @brief Pasalina visus elementus.
     *
     * Talpa nesumazinama, tik dydis nustatomas i 0.
     */
    void Clear() { _size = 0; }

    /**
     * @brief Prideda elementa i vektoriaus pabaiga.
     *
     * Jei nebera vietos, talpa automatiskai padidinama.
     *
     * @param value Pridedama reiksme.
     */
    void PushBack(T value)
    {
        if (_size == _capacity)
            Grow();
        _data[_size] = std::move(value);
        _size++;
    }

    /**
     * @brief Rezervuoja vieta nurodytam elementu kiekiui.
     *
     * Jei newAlloc yra mazesnis arba lygus dabartinei talpai, nieko nedaro.
     * Funkcija nekeicia vektoriaus dydzio.
     *
     * @param newAlloc Nauja norima talpa.
     */
    void Reserve(int newAlloc)
    {
        if (newAlloc <= _capacity)
            return;

        T *newData = new T[newAlloc];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = std::move(_data[i]);
        }
        delete[] _data;
        _data = newData;
        _capacity = newAlloc;
    }

    /**
     * @brief Pakeicia vektoriaus dydi.
     *
     * Jei naujas dydis didesnis uz talpa, atmintis rezervuojama is naujo.
     *
     * @param newSize Naujas vektoriaus dydis.
     * @throws std::out_of_range Jei newSize yra neigiamas.
     */
    void Resize(int newSize)
    {
        if (newSize < 0)
            throw std::out_of_range("Size cannot be negative");

        if (newSize > _capacity)
            Reserve(newSize);

        _size = newSize;
    }

    /**
     * @brief Pakeicia vektoriaus dydi ir naujus elementus uzpildo reiksme.
     *
     * Jei naujas dydis didesnis uz dabartini, nauji elementai uzpildomi value.
     *
     * @param newSize Naujas vektoriaus dydis.
     * @param value Reiksme naujiems elementams.
     * @throws std::out_of_range Jei newSize yra neigiamas.
     */
    void Resize(int newSize, const T &value)
    {
        if (newSize < 0)
            throw std::out_of_range("Size cannot be negative");

        if (newSize > _capacity)
            Reserve(newSize);

        for (int i = _size; i < newSize; i++)
        {
            _data[i] = value;
        }

        _size = newSize;
    }

    /**
     * @brief Sumazina talpa iki dabartinio dydzio.
     *
     * Po funkcijos capacity() tampa lygi size().
     */
    void ShrinkToFit()
    {
        if (_capacity == _size)
            return;

        T *newData = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = std::move(_data[i]);
        }

        delete[] _data;
        _data = newData;
        _capacity = _size;
    }

    /**
     * @brief Pasalina elementa pagal indeksa.
     *
     * Elementai po pasalinto elemento pastumiami viena pozicija i kaire.
     *
     * @param index Salinamo elemento indeksas.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    void Erase(int index)
    {
        if (index >= _size || index < 0)
            throw std::out_of_range("Index is out of range");

        for (int i = index; i < _size - 1; i++)
        {
            _data[i] = std::move(_data[i + 1]);
        }

        _size--;
    }

    /**
     * @brief Iterpia elementa i nurodyta pozicija.
     *
     * Elementai nuo nurodytos pozicijos pastumiami viena pozicija i desine.
     *
     * @param index Pozicija, i kuria iterpiama reiksme.
     * @param value Iterpiama reiksme.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    void Insert(int index, T value)
    {
        if (index > _size || index < 0)
            throw std::out_of_range("Index is out of range");

        if (_size == _capacity)
            Grow();

        for (int i = _size; i > index; i--)
        {
            _data[i] = std::move(_data[i - 1]);
        }

        _data[index] = std::move(value);
        _size++;
    }

    /**
     * @brief Apkeicia dvieju vektoriu turini.
     *
     * @param other Kitas MyVector objektas.
     */
    void Swap(MyVector &other) noexcept
    {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
    }

    /**
     * @brief Pakeicia vektoriaus turini nurodytu kiekiu vienodu reiksmiu.
     *
     * Senas loginis turinys pakeiciamas nauju.
     *
     * @param newSize Naujas elementu skaicius.
     * @param value Reiksme, kuria uzpildomas vektorius.
     * @throws std::out_of_range Jei newSize yra neigiamas.
     */
    void Assign(int newSize, const T &value)
    {
        if (newSize < 0)
            throw std::out_of_range("Size cannot be negative");

        if (newSize > _capacity)
            Reserve(newSize);

        for (int i = 0; i < newSize; i++)
        {
            _data[i] = value;
        }

        _size = newSize;
    }

    /**
     * @brief Sukuria ir prideda elementa i vektoriaus pabaiga.
     *
     * Elementas sukuriamas is perduotu argumentu.
     *
     * @tparam Args Argumentu tipai.
     * @param args Argumentai, perduodami T konstruktoriui.
     */
    template <typename... Args>
    void EmplaceBack(Args &&...args)
    {
        if (_size == _capacity)
            Grow();

        _data[_size] = T(std::forward<Args>(args)...);
        _size++;
    }

    /**
     * @brief Grazina elementa pagal indeksa.
     *
     * Sioje realizacijoje operator[] tikrina ribas.
     *
     * @param index Elemento indeksas.
     * @return Nuoroda i elementa.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    T &operator[](int index)
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    /**
     * @brief Grazina elementa pagal indeksa const vektoriui.
     *
     * @param index Elemento indeksas.
     * @return Const nuoroda i elementa.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    const T &operator[](int index) const
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }

    /**
     * @brief Grazina pirma vektoriaus elementa.
     *
     * @return Nuoroda i pirma elementa.
     * @throws std::out_of_range Jei vektorius tuscias.
     */
    T &Front()
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[0];
    }

    /**
     * @brief Grazina pirma vektoriaus elementa const vektoriui.
     *
     * @return Const nuoroda i pirma elementa.
     * @throws std::out_of_range Jei vektorius tuscias.
     */
    const T &Front() const
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[0];
    }

    /**
     * @brief Grazina paskutini vektoriaus elementa.
     *
     * @return Nuoroda i paskutini elementa.
     * @throws std::out_of_range Jei vektorius tuscias.
     */
    T &Back()
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[_size - 1];
    }

    /**
     * @brief Grazina paskutini vektoriaus elementa const vektoriui.
     *
     * @return Const nuoroda i paskutini elementa.
     * @throws std::out_of_range Jei vektorius tuscias.
     */
    const T &Back() const
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[_size - 1];
    }

    /**
     * @brief Grazina elementa pagal indeksa su ribu tikrinimu.
     *
     * @param index Elemento indeksas.
     * @return Nuoroda i elementa.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    T &At(int index)
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index is out of range");

        return _data[index];
    }

    /**
     * @brief Grazina elementa pagal indeksa su ribu tikrinimu const vektoriui.
     *
     * @param index Elemento indeksas.
     * @return Const nuoroda i elementa.
     * @throws std::out_of_range Jei indeksas yra uz ribu.
     */
    const T &At(int index) const
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index is out of range");

        return _data[index];
    }
};


/**
 * @brief Kopijavimo konstruktoriaus realizacija.
 *
 * Sukuria nauja vektoriu su atskira atmintimi ir nukopijuoja elementus.
 *
 * @tparam T Elementu tipas.
 * @param other Vektorius, is kurio kopijuojama.
 */
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &other)
{
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];

    for (int i = 0; i < _size; i++)
    {
        _data[i] = other._data[i];
    }
}

/**
 * @brief Perkelimo konstruktoriaus realizacija.
 *
 * Perima kito vektoriaus vidini masyva ir palieka kita objekta tuscia.
 *
 * @tparam T Elementu tipas.
 * @param other Vektorius, is kurio perkeliami duomenys.
 */
template <typename T>
MyVector<T>::MyVector(MyVector<T> &&other) noexcept
{
    _data = other._data;
    _capacity = other._capacity;
    _size = other._size;

    other._data = nullptr;
    other._capacity = 0;
    other._size = 0;
}

/**
 * @brief Kopijavimo priskyrimo operatoriaus realizacija.
 *
 * @tparam T Elementu tipas.
 * @param other Vektorius, is kurio kopijuojama.
 * @return Nuoroda i dabartini objekta.
 */
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other)
{
    if (this == &other)
        return *this;

    T *newData = new T[other._capacity];

    for (int i = 0; i < other._size; i++)
    {
        newData[i] = other._data[i];
    }

    delete[] _data;

    _data = newData;
    _size = other._size;
    _capacity = other._capacity;

    return *this;
}

/**
 * @brief Perkelimo priskyrimo operatoriaus realizacija.
 *
 * @tparam T Elementu tipas.
 * @param other Vektorius, is kurio perkeliami duomenys.
 * @return Nuoroda i dabartini objekta.
 */
template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) noexcept
{
    if (this == &other)
        return *this;

    delete[] _data;

    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;

    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;

    return *this;
}

/**
 * @brief Initializer_list konstruktoriaus realizacija.
 *
 * Sukuria vektoriu is pradiniu reiksmiu saraso.
 *
 * @tparam T Elementu tipas.
 * @param values Pradiniu reiksmiu sarasas.
 */
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> values)
{
    _size = static_cast<int>(values.size());
    _capacity = static_cast<int>(values.size());
    _data = new T[_capacity];

    int i = 0;
    for (const T &value : values)
    {
        _data[i] = value;
        i++;
    }
}

/**
 * @brief Patikrina, ar du vektoriai yra lygus.
 *
 * Vektoriai laikomi lygiais, jei ju dydziai sutampa ir visi elementai yra lygus.
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei vektoriai lygus, false kitu atveju.
 */
template <typename T>
bool operator==(const MyVector<T> &a, const MyVector<T> &b)
{
    if (a.size() != b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

/**
 * @brief Patikrina, ar du vektoriai nera lygus.
 *
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei vektoriai nelygus, false kitu atveju.
 */
template <typename T>
bool operator!=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(a == b);
}

/**
 * @brief Patikrina, kuris vektorius yra didesnis.
 *
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei a yra mazesnis uz b, false kitu atveju.
 */
template <typename T>
bool operator<(const MyVector<T> &a, const MyVector<T> &b)
{
    int minSize;

    if (a.size() < b.size())
        minSize = a.size();
    else
        minSize = b.size();

    for (int i = 0; i < minSize; i++)
    {
        if (a[i] < b[i])
            return true;

        if (b[i] < a[i])
            return false;
    }

    return a.size() < b.size();
}

/**
 * @brief Patikrina, kuris vektorius yra mazesnis.
 *
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei b yra mazesnis uz a, false kitu atveju.
 */
template <typename T>
bool operator>(const MyVector<T> &a, const MyVector<T> &b)
{
    return b < a;
}

/**
 * @brief Patikrina, ar pirmas vektorius yra mazesnis arba lygus antram.
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei a yra mazesnis arba lygus b, false kitu atveju.
 */
template <typename T>
bool operator<=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(b < a);
}

/**
 * @brief Patikrina, ar pirmas vektorius yra didesnis arba lygus antram.
 *
 * @tparam T Elementu tipas.
 * @param a Pirmas vektorius.
 * @param b Antras vektorius.
 * @return true jei a yra didesnis arba lygus b, false kitu atveju.
 */
template <typename T>
bool operator>=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(a < b);
}

#endif