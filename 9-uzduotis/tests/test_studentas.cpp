#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "student.h"
#include <utility>

using std::move;

TEST_CASE("Default konstruktorius")
{
    Studentas s;

    CHECK(s.vardas() == "");
    CHECK(s.pavarde() == "");
    CHECK(s.egz() == 0);
    CHECK(s.vid() == doctest::Approx(0.0));
    CHECK(s.med() == doctest::Approx(0.0));
    CHECK(s.paz().empty());
}

TEST_CASE("Setteriai ir getteriai")
{
    Studentas s;

    s.SetVardas("Jonas");
    s.SetPavarde("Jonaitis");
    s.SetEgz(10);
    s.SetVid(9.5);
    s.SetMed(9.0);
    s.AddPaz(8);
    s.AddPaz(9);

    CHECK(s.vardas() == "Jonas");
    CHECK(s.pavarde() == "Jonaitis");
    CHECK(s.egz() == 10);
    CHECK(s.vid() == doctest::Approx(9.5));
    CHECK(s.med() == doctest::Approx(9.0));
    CHECK(s.paz().size() == 2);
    CHECK(s.paz()[0] == 8);
    CHECK(s.paz()[1] == 9);
}

TEST_CASE("MedIrVidSkaciavimas sy lyginiais pazymiais")
{
    Studentas s;

    s.AddPaz(8);
    s.AddPaz(9);
    s.AddPaz(10);
    s.SetEgz(10);

    s.MedIrVidSkaciavimas(27);

    CHECK(s.vid() == doctest::Approx(9.6));
    CHECK(s.med() == doctest::Approx(9.6));
}

TEST_CASE("MedIrVidSkaciavimas sy nelyginiais pazymiais")
{
    Studentas s;

    s.AddPaz(8);
    s.AddPaz(10);
    s.SetEgz(10);

    s.MedIrVidSkaciavimas(18);

    CHECK(s.vid() == doctest::Approx(9.6));
    CHECK(s.med() == doctest::Approx(9.6));
}

TEST_CASE("MedIrVidSkaciavimas be pazymiu")
{
    Studentas s;

    s.SetEgz(10);
    s.MedIrVidSkaciavimas(0);

    CHECK(s.vid() == doctest::Approx(6.0));
    CHECK(s.med() == doctest::Approx(6.0));
}

TEST_CASE("ClearPaz istrina pazymius")
{
    Studentas s;

    s.AddPaz(8);
    s.AddPaz(9);
    s.ClearPaz();

    CHECK(s.paz().empty());
}

TEST_CASE("Konstruktoriaus kopijavimas")
{
    Studentas s1;
    s1.SetVardas("Jonas");
    s1.SetPavarde("Jonaitis");
    s1.SetEgz(10);
    s1.AddPaz(8);
    s1.AddPaz(9);
    s1.MedIrVidSkaciavimas(17);

    Studentas s2(s1);

    CHECK(s2.vardas() == s1.vardas());
    CHECK(s2.pavarde() == s1.pavarde());
    CHECK(s2.egz() == s1.egz());
    CHECK(s2.paz().size() == s1.paz().size());
    CHECK(s2.vid() == doctest::Approx(s1.vid()));
    CHECK(s2.med() == doctest::Approx(s1.med()));
}

TEST_CASE("Kopijavimo priskyrimo operatorius")
{
    Studentas s1;
    s1.SetVardas("Petras");
    s1.SetPavarde("Petraitis");
    s1.SetEgz(9);
    s1.AddPaz(7);
    s1.AddPaz(8);
    s1.MedIrVidSkaciavimas(15);

    Studentas s2;
    s2 = s1;

    CHECK(s2.vardas() == s1.vardas());
    CHECK(s2.pavarde() == s1.pavarde());
    CHECK(s2.egz() == s1.egz());
    CHECK(s2.paz().size() == s1.paz().size());
    CHECK(s2.vid() == doctest::Approx(s1.vid()));
    CHECK(s2.med() == doctest::Approx(s1.med()));
}

TEST_CASE("Perkelimo konstruktorius")
{
    Studentas s1;
    s1.SetVardas("Ona");
    s1.SetPavarde("Onaite");
    s1.SetEgz(10);
    s1.AddPaz(10);
    s1.AddPaz(9);
    s1.MedIrVidSkaciavimas(19);

    Studentas s2(move(s1));

    CHECK(s2.vardas() == "Ona");
    CHECK(s2.pavarde() == "Onaite");
    CHECK(s2.egz() == 10);
    CHECK(s2.paz().size() == 2);
    CHECK(s2.vid() == doctest::Approx(9.8));
    CHECK(s2.med() == doctest::Approx(9.8));
}

TEST_CASE("Perkelimo priskyrimo operatorius")
{
    Studentas s1;
    s1.SetVardas("Ieva");
    s1.SetPavarde("Ievaite");
    s1.SetEgz(8);
    s1.AddPaz(7);
    s1.AddPaz(8);
    s1.MedIrVidSkaciavimas(15);

    Studentas s2;
    s2 = move(s1);

    CHECK(s2.vardas() == "Ieva");
    CHECK(s2.pavarde() == "Ievaite");
    CHECK(s2.egz() == 8);
    CHECK(s2.paz().size() == 2);
    CHECK(s2.vid() == doctest::Approx(7.8));
    CHECK(s2.med() == doctest::Approx(7.8));
}

TEST_CASE("MedIrVidSkaciavimas su lyginiais pazymiais bet kokia tvarka")
{
    Studentas s;

    s.AddPaz(10);
    s.AddPaz(6);
    s.AddPaz(8);
    s.SetEgz(4);

    s.MedIrVidSkaciavimas(24);

    CHECK(s.vid() == doctest::Approx(5.6));
    CHECK(s.med() == doctest::Approx(5.6));
}

TEST_CASE("MedIrVidSkaciavimas su nelyginiais pazymiais bet kokia tvarka")
{
    Studentas s;

    s.AddPaz(3);
    s.AddPaz(9);
    s.AddPaz(7);
    s.AddPaz(5);
    s.SetEgz(5);

    s.MedIrVidSkaciavimas(24);

    CHECK(s.vid() == doctest::Approx(5.4));
    CHECK(s.med() == doctest::Approx(5.4));
}