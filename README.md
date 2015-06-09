#Proiect examen POO

##Cerinta

Idem pentru matrici dreptunghiulare cu elemente de tip neprecizat, cu
supraîncărcarea operatorilor =, ==, +, - (unar si binar), *, [ ] (indexare)
şi conversie de la un obiect de tipul neprecizat dat la o matrice cu 1 linie şi 1
coloană. O matrice cu m linii şi n coloane se va reprezenta ca un vector
(adică pointer la tipul elementelor) format din liniile matricii aşezate
succesiv, adică a11, a12, ... a1n, a21, a22, ... a2n, ... ... am1, am2, ..., amn. Operatorul [
] va întoarce un pointer la începutul liniei al cărei număr este parametru,
numărându-se începand cu 0, în  reprezentarea,dată mai sus, adică, dacă a
este un obiect a clasei,  a[i] va fi pointer la tipul elementelor având ca
valoare adresa elementului a(i+1)1 în notaţia de mai sus, iar a[i][j] va fi
elementul a(i+1)(j+1) din aceeaşi notaţie, a doua utilizare a operatorului [ ]
fiind cea predefinită pentru pointeri la tipul elementelor matricii.

