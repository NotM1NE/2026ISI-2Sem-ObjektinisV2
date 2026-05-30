# Associative Containers Text Analysis

Programa analizuoja tekstinį failą ir naudoja `std::string`, `std::map` bei `std::set`.

## Funkcionalumas

Programa:
- suskaičiuoja, kiek kartų pasikartoja kiekvienas žodis;
- išveda žodžius, kurie pasikartojo daugiau nei vieną kartą;
- sugeneruoja cross-reference lentelę su eilučių numeriais;
- suranda URL adresus tekste;
- URL tikrinimui naudoja TLD sąrašą.

## Failai

Įvesties failai:

- `Data/input.txt`
- `Data/tldList.txt`

Rezultatų failai:

- `Results/word_count.txt`
- `Results/cross_reference.txt`
- `Results/urls.txt`

## TLD sąrašas

TLD sąrašas paimtas iš oficialaus IANA šaltinio:

https://data.iana.org/TLD/tlds-alpha-by-domain.txt

Šis sąrašas naudojamas URL galūnių tikrinimui, pvz. `.lt`, `.com`, `.org`.
