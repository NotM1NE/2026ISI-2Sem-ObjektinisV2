#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "MyVector.h"
#include <utility>
#include <string>

TEST_CASE("Default konstruktorius")
{
    MyVector<int> v;

    CHECK(v.size() == 0);
    CHECK(v.capacity() == 1);
    CHECK(v.empty() == true);
}

TEST_CASE("PushBack elementu pridejimas - int")
{
    MyVector<int> v;

    v.PushBack(10);
    v.PushBack(20);
    v.PushBack(30);

    CHECK(v.size() == 3);
    CHECK(v[0] == 10);
    CHECK(v[1] == 20);
    CHECK(v[2] == 30);
}

TEST_CASE("PushBack elementu pridejimas - float")
{
    MyVector<float> v;

    v.PushBack(10.20f);
    v.PushBack(20.67f);
    v.PushBack(30.69f);

    CHECK(v.size() == 3);
    CHECK(v[0] == doctest::Approx(10.20f));
    CHECK(v[1] == doctest::Approx(20.67f));
    CHECK(v[2] == doctest::Approx(30.69f));
}

TEST_CASE("PushBack elementu pridejimas - string")
{
    MyVector<std::string> v;

    v.PushBack("miau");
    v.PushBack("miau1");
    v.PushBack("miau2");

    CHECK(v.size() == 3);
    CHECK(v[0] == "miau");
    CHECK(v[1] == "miau1");
    CHECK(v[2] == "miau2");
}

TEST_CASE("PopBack istrina paskutini elementa")
{
    MyVector<int> v = {1, 2, 3};

    v.PopBack();

    CHECK(v.size() == 2);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
}

TEST_CASE("PopBack throws kai vektorius yra tuscias")
{
    MyVector<int> v;

    CHECK_THROWS_AS(v.PopBack(), std::out_of_range);
}

TEST_CASE("Front ir Back")
{
    MyVector<int> v = {10, 20, 30};

    CHECK(v.Front() == 10);
    CHECK(v.Back() == 30);

    v.Front() = 99;
    v.Back() = 77;

    CHECK(v[0] == 99);
    CHECK(v[2] == 77);
}

TEST_CASE("At patikrinimas")
{
    MyVector<int> v = {1, 2, 3};

    CHECK(v.At(0) == 1);
    CHECK(v.At(2) == 3);

    CHECK_THROWS_AS(v.At(-1), std::out_of_range);
    CHECK_THROWS_AS(v.At(3), std::out_of_range);
}

TEST_CASE("Resize be value")
{
    MyVector<int> v = {1, 2, 3};

    v.Resize(5);

    CHECK(v.size() == 5);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("Resize su value")
{
    MyVector<int> v = {1, 2, 3};

    v.Resize(5, 5);

    CHECK(v.size() == 5);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
    CHECK(v[3] == 5);
    CHECK(v[4] == 5);
}

TEST_CASE("Uzrezervuoti atminti")
{
    MyVector<int> v = {1, 2, 3};

    v.Reserve(100);

    CHECK(v.size() == 3);
    CHECK(v.capacity() == 100);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("Shrink to fit sulygina capacity")
{
    MyVector<int> v = {1, 2, 3};

    v.Reserve(50);
    CHECK(v.capacity() == 50);

    v.ShrinkToFit();

    CHECK(v.size() == v.capacity());
}

TEST_CASE("Kintamuju pridejimas pabaigoje")
{
    MyVector<int> v = {1, 2, 3};

    v.Insert(v.size(), 4);

    CHECK(v.size() == 4);
    CHECK(v[3] == 4);
}

TEST_CASE("Kintamuju pridejimas nurodytoje vietoje")
{
    MyVector<int> v = {1, 2, 3};

    v.Insert(2, 69);

    CHECK(v.size() == 4);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 69);
    CHECK(v[3] == 3);
}

TEST_CASE("Copy assignment sukuria kopija")
{
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = {9, 9};

    b = a;

    CHECK(a == b);

    b[1] = 88;

    CHECK(a[1] == 2);
    CHECK(b[1] == 88);
}

TEST_CASE("Move constructor perkelia duomenis")
{
    MyVector<int> a = {1, 2, 3};

    MyVector<int> b = std::move(a);

    CHECK(b.size() == 3);
    CHECK(b[0] == 1);
    CHECK(b[1] == 2);
    CHECK(b[2] == 3);

    CHECK(a.size() == 0);
    CHECK(a.capacity() == 0);
}

TEST_CASE("Move assignment perkelia duomenis")
{
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = {9, 9};

    b = std::move(a);

    CHECK(b.size() == 3);
    CHECK(b[0] == 1);
    CHECK(b[1] == 2);
    CHECK(b[2] == 3);

    CHECK(a.size() == 0);
    CHECK(a.capacity() == 0);
}

TEST_CASE("Lyginamieji operatoriai")
{
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = {1, 2, 3};
    MyVector<int> c = {1, 2, 4};

    CHECK(a == b);
    CHECK(a != c);
    CHECK(a < c);
    CHECK(c > a);
    CHECK(a <= b);
    CHECK(a >= b);
}

TEST_CASE("Erase istrina elemnta nurodytoje vietoje")
{
    MyVector<int> v = {1, 2, 3, 4};

    v.Erase(1);

    CHECK(v.size() == 3);
    CHECK(v[0] == 1);
    CHECK(v[1] == 3);
    CHECK(v[2] == 4);
}

TEST_CASE("Copy constructor sukuria kopija")
{
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = a;

    CHECK(a == b);

    b[0] = 99;

    CHECK(a[0] == 1);
    CHECK(b[0] == 99);
}

TEST_CASE("Insert meta klaida su blogu indeksu")
{
    MyVector<int> v = {1, 2, 3};

    CHECK_THROWS_AS(v.Insert(-1, 10), std::out_of_range);
    CHECK_THROWS_AS(v.Insert(4, 10), std::out_of_range);
}

TEST_CASE("Erase meta klaida su blogu indeksu")
{
    MyVector<int> v = {1, 2, 3};

    CHECK_THROWS_AS(v.Erase(-1), std::out_of_range);
    CHECK_THROWS_AS(v.Erase(3), std::out_of_range);
}

TEST_CASE("Clear isvalo vektoriu bet palieka capacity")
{
    MyVector<int> v = {1, 2, 3};

    v.Reserve(20);
    v.Clear();

    CHECK(v.size() == 0);
    CHECK(v.capacity() == 20);
    CHECK(v.empty() == true);
}

TEST_CASE("EmplaceBack sukuria elementa vietoje")
{
    MyVector<std::string> v;

    v.EmplaceBack(5, 'a');

    CHECK(v.size() == 1);
    CHECK(v[0] == "aaaaa");
}

TEST_CASE("Swap apkeicia dvieju vektoriu turini")
{
    MyVector<int> a = {1, 2, 3};
    MyVector<int> b = {9, 8};

    a.Swap(b);

    CHECK(a.size() == 2);
    CHECK(a[0] == 9);
    CHECK(a[1] == 8);

    CHECK(b.size() == 3);
    CHECK(b[0] == 1);
    CHECK(b[1] == 2);
    CHECK(b[2] == 3);
}

TEST_CASE("Konstruktorius su dydziu")
{
    MyVector<int> v(5);

    CHECK(v.size() == 5);
    CHECK(v.capacity() == 5);
}

TEST_CASE("Konstruktorius su dydziu ir reiksme")
{
    MyVector<int> v(4, 9);

    CHECK(v.size() == 4);
    CHECK(v[0] == 9);
    CHECK(v[1] == 9);
    CHECK(v[2] == 9);
    CHECK(v[3] == 9);
}

TEST_CASE("Resize meta klaida su neigiamu dydziu")
{
    MyVector<int> v;

    CHECK_THROWS_AS(v.Resize(-1), std::out_of_range);
}
