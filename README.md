🎬 Cinematograph Manager — Singly Linked List (C)
📖 Project Overview

This project is a menu-driven C console application that manages a list of cinemas (cinematografe) using a singly linked list.
Each node stores cinema information (name, location, contact, capacity, ticket price) and supports operations such as insertion, deletion, search, sorting, reversing the list, and full memory cleanup.

It is designed as an educational project to practice dynamic memory allocation and linked list operations in C.

✅ Features

✅ Store cinema records in a singly linked list
✅ Add multiple elements interactively
✅ Display all cinemas with full details
✅ Search cinemas by multiple criteria
✅ Sort list by chosen field (bubble sort style swap of data)
✅ Insert:

at the end

at the beginning

at a specific position
✅ Delete node at a specific position
✅ Reverse the list (pointer reversal)
✅ Free all allocated memory (clear list)

🏗️ Data Structures
🎟️ Cinematograf

Each cinema record includes:

nume – cinema name

locatie – city/location

contact – phone/contact string

capacitate – number of seats

cost_bilet – ticket price (MDL)

🔗 struct Nod

Linked list node containing:

data (Cinematograf)

next pointer to the next node

Global list head:

Nod* head = NULL;
🧠 Implemented Operations
1️⃣ Add Elements (citireLista)

Adds multiple cinema nodes until the user stops (d/n).

2️⃣ Display List (afisareLista)

Prints all cinemas with formatted details and index.

3️⃣ Search (cautareElement)

Search criteria:

Name

Location

Contact

Capacity

Ticket price

Prints all matches and their positions.

4️⃣ Clear Memory (eliberareMemorie)

Frees every node and resets head = NULL.

5️⃣ Sort (sortareLista)

Sorts by one chosen criterion (same as search criteria).
Implementation swaps cinema data between nodes (not node pointers).

6️⃣ Insert End (inserareSfarsit)

Adds a new node at the end.

7️⃣ Insert Beginning (inserareInceput)

Adds a new node at the beginning.

8️⃣ Insert At Position (inserarePozitie)

Inserts at a given index:

if position is too large → inserts at end (with a warning)

9️⃣ Delete At Position (stergerePozitie)

Deletes node at a given index (0 = head).

🔟 Reverse List (inversareLista)

Reverses the list by re-linking pointers iteratively.

🖥️ Menu Options
1. Adăugare elemente
2. Afișare cinematografe
3. Căutare cinematograf
4. Golire totală memorie
5. Sortare
6. Adăugare la final
7. Adăugare la început
8. Adăugare la poziție
9. Ștergere de la poziție
10. Inversează lista
0. Ieșire
   
Tema: Implementarea tipului de date abstract “Listă simplu înlănțuită” în limbajul C.
Scopul lucrării: Scopul lucrării este de a familiariza studentul cu mecanismul de creare a listelor simplu înlănțuite și operații elementare asupra acestuia, utilizând pentru aceasta limbajul C.
Problema: Să se elaboreze un program ce va aloca dinamic o listă simplu înlănțuită de structuri și va realiza următoarele funcții, unde funcțiile date reprezintă opțiuni organizate într-un meniu în cadrul programului, fiecare student trebuie să aleagă o structură originală față de alți studenți, structura trebuie să aibă minim 5 cîmpuri, structura aleasă poate fi ca de exemplu (struct Student, struct Car, struct House, struct Work, etc.)
2.	Citirea de la tastatură a elementelor listei;
3.	Afișarea la consolă a elementelor listei;
4.	Căutarea unui element după o valoarea a unui cîmp din structură și returnarea poziției unde se află primul element găsit;
5.	Eliberarea memoriei listei;
6.	Sortarea elementelor după un câmp a structurii;
7.	Inserarea unui element nou la capătul listei;
8.	Inserarea unui element nou la începutul listei;
9.	Inserarea unui element la o poziție X (introdusă de la tastatură) în cadrul listei;
10.	Ștergerea unui element de pe o poziție X ( introdusă de la tastatură) din cadrul listei;
11.	Inversarea ordinii elementelor din listă;
12.	Curățarea listei.

[Chiochiu Vladislav TI-244 Lab 2 SDA.docx](https://github.com/user-attachments/files/25425337/Chiochiu.Vladislav.TI-244.Lab.2.SDA.docx)
