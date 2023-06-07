# Algoritmai ir duomenų struktūros 3 užduotis
## Realaus pasaulio modeliavimas
## 8. Poliklinika

    Procesas 1: poliklinikoje dirba tik įvairių sričių specialistai, pacientas kreipiasi į specialistą savo nuožiūra, šis arba pacientą pagydo, arba pasiunčia pas tą specialistą, kuris gali pacientą pagydyti, arba informuoja pacientą, kad šis sveikas. Procesas 2: pacientai gali kreipiasi tik į apylinkės gydytoją, kuris pasiunčia pas tą specialistą, kuris gali pacientą pagydyti, arba informuoja pacientą, kad šis sveikas. Patyrinėkime, kiek apylinkės gydytojų poliklinikai tikslinga turėti ekonominiu požiūriu (jų atlyginimas mažesnis nei specialistų ir jie žymiai greičiau priima sprendimą) ir kaip tai paveiks pacientų pasitenkinimą (minimalus, vidutinis ir maksimalus pilno aptarnavimo laikas). Visi kiti rodikliai, nuo kurių priklauso procesas, įvedami kaip programos parametrai.

Darant užduotį reikėjo panaudoti ADT: eilė, ilgas sveikas skaičius\
Eilę paskolinau iš kolegos Faustas Gudas\
Ilgą sveiką skaičių iš https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/

### Programos pradiniai duomenys
Programai reikalingi 9 argumentai:\
1. Proceso numeris (1 arba 2)
2. Darbo dienos ilgis
3. Paciento atvykimo tikimybe kiekvieną laiko intervalą
4. Specialistų skaičius
5. Specialistų dienos alga
6. Specialistų aptarnavimo laikas
7. Aplylinkės gydytojų skaičius
8. Aplylinkės gydytojų alga
9. Aplylinkės gydytojų aptarnavimo laikas

Argumentai surašomi iš eilės tokią tvarką į *data.txt* failą

Programą kompiliuojama ir paleidžiama *Go.cmd* failu. Skaičiavimo rezultatai atsiranda *result.txt* faile