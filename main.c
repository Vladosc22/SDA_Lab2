#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[50];
    char locatie[50];
    char contact[15];
    int capacitate;
    float cost_bilet;
} Cinematograf;

typedef struct Nod {
    Cinematograf data;
    struct Nod* next;
} Nod;

Nod* head = NULL;

//  funcții
Nod* creazaNod();
void citireLista();
void afisareLista();
void cautareElement();
void eliberareMemorie();
void sortareLista();
void inserareSfarsit();
void inserareInceput();
void inserarePozitie(int poz);
void stergerePozitie(int poz);
void inversareLista();

int main() {
    int optiune;
    do {
        printf("\n--- Meniu Cinematografe ---\n");
        printf("1. Adăugare elemente\n");
        printf("2. Afișare cinematografe\n");
        printf("3. Căutare cinematograf\n");
        printf("4. Golire totală memorie\n");
        printf("5. Sortare\n");
        printf("6. Adăugare la final\n");
        printf("7. Adăugare la început\n");
        printf("8. Adăugare la poziție\n");
        printf("9. Ștergere de la poziție\n");
        printf("10. Inversează lista\n");
        printf("0. Ieșire\n");
        printf("Alege: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1: citireLista(); break;
            case 2: afisareLista(); break;
            case 3: cautareElement(); break;
            case 4: eliberareMemorie(); break;
            case 5: sortareLista(); break;
            case 6: inserareSfarsit(); break;
            case 7: inserareInceput(); break;
            case 8: {
                int poz;
                printf("Poziția: ");
                scanf("%d", &poz);
                inserarePozitie(poz);
                break;
            }
            case 9: {
                int poz;
                printf("Poziția: ");
                scanf("%d", &poz);
                stergerePozitie(poz);
                break;
            }
            case 10: inversareLista(); break;
            case 0: eliberareMemorie(); printf("Ieșire...\n"); break;
            default: printf("Opțiune invalidă!\n");
        }
    } while (optiune != 0);

    return 0;
}
//// Functia pentru crearea unui nod nou
Nod* creazaNod() {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (!nou) {
        printf("Eroare de alocare!\n");
        return NULL;
    }
    printf("Nume: "); scanf("%s", nou->data.nume);
    printf("Locație: "); scanf("%s", nou->data.locatie);
    printf("Contact: "); scanf("%s", nou->data.contact);
    printf("Capacitate: "); scanf("%d", &nou->data.capacitate);
    printf("Cost bilet: "); scanf("%f", &nou->data.cost_bilet);
    nou->next = NULL;
    return nou;
}

void citireLista() {
    char raspuns;
    do {
        Nod* nou = creazaNod();
        if (!nou) return; // Daca nu s-a putut aloca nodul, ieșim

        if (!head) {
            head = nou;
        } else {
            Nod* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = nou;
        }

        printf("Mai adaugi? (d/n): ");
        scanf(" %c", &raspuns);
    } while (raspuns == 'd' || raspuns == 'D');
}

void afisareLista() {
    if (!head) {
        printf("Lista este goală!\n");
        return;
    }

    Nod* temp = head;
    int idx = 1;
    while (temp) {
        printf("\nCinematograf #%d\n", idx++);
        printf("Nume: %s\n", temp->data.nume);
        printf("Locație: %s\n", temp->data.locatie);
        printf("Contact: %s\n", temp->data.contact);
        printf("Capacitate: %d locuri\n", temp->data.capacitate);
        printf("Cost bilet: %.2f MDL\n", temp->data.cost_bilet);
        temp = temp->next;
    }
}

void cautareElement() {
    if (!head) {
        printf("Lista goală!\n");
        return;
    }

    int criteriu;
    printf("Caută după:\n1.Nume\n2.Locație\n3.Contact\n4.Capacitate\n5.Cost bilet\nAlege: ");
    scanf("%d", &criteriu);

    char val_cautare[50];
    int val_int;
    float val_float;

    switch (criteriu) {
        case 1: case 2: case 3:
            printf("Introdu valoarea: ");
            scanf("%s", val_cautare);
            break;
        case 4:
            printf("Introdu capacitatea: ");
            scanf("%d", &val_int);
            break;
        case 5:
            printf("Introdu costul: ");
            scanf("%f", &val_float);
            break;
        default:
            printf("Criteriu invalid!\n");
            return;
    }

    Nod* temp = head;
    int poz = 0;
    int gasit = 0;

    while (temp) {
        int match = 0;
        switch (criteriu) {
            case 1: match = (strcmp(temp->data.nume, val_cautare) == 0); break;
            case 2: match = (strcmp(temp->data.locatie, val_cautare) == 0); break;
            case 3: match = (strcmp(temp->data.contact, val_cautare) == 0); break;
            case 4: match = (temp->data.capacitate == val_int); break;
            case 5: match = (temp->data.cost_bilet == val_float); break;
        }

        if (match) {
            printf("\n=== Rezultat găsit la poziția %d ===\n", poz);
            printf("Nume: %s\n", temp->data.nume);
            printf("Locație: %s\n", temp->data.locatie);
            printf("Contact: %s\n", temp->data.contact);
            printf("Capacitate: %d\n", temp->data.capacitate);
            printf("Cost bilet: %.2f MDL\n", temp->data.cost_bilet);
            gasit = 1;
        }
        temp = temp->next;
        poz++;
    }

    if (!gasit) {
        printf("Nu s-a găsit niciun cinematograf cu aceste criterii!\n");
    }
}

void eliberareMemorie() {
    Nod* current = head;
    while (current) {
        Nod* urmator = current->next;
        free(current);
        current = urmator;
    }
    head = NULL;
    printf("Memorie eliberată!\n");
}

void sortareLista() {
    if (!head || !head->next) {
        printf("Lista are maxim un element!\n");
        return;
    }

    int criteriu;
    printf("Sortează după:\n1.Nume\n2.Locație\n3.Contact\n4.Capacitate\n5.Cost bilet\nAlege: ");
    scanf("%d", &criteriu);

    int modificat;
    Nod* ptr;
    Nod* ultim = NULL;

    do {
        modificat = 0;
        ptr = head;
        while (ptr->next != ultim) {
            int compara = 0;
            switch (criteriu) {
                case 1:
                    compara = strcmp(ptr->data.nume, ptr->next->data.nume);
                    break;
                case 2:
                    compara = strcmp(ptr->data.locatie, ptr->next->data.locatie);
                    break;
                case 3:
                    compara = strcmp(ptr->data.contact, ptr->next->data.contact);
                    break;
                case 4:
                    compara = ptr->data.capacitate - ptr->next->data.capacitate;
                    break;
                case 5:
                    if (ptr->data.cost_bilet > ptr->next->data.cost_bilet) {
                        compara = 1;
                    } else if (ptr->data.cost_bilet < ptr->next->data.cost_bilet) {
                        compara = -1;
                    } else {
                        compara = 0;
                    }
                    break;
                default:
                    printf("Criteriu invalid!\n");
                    return;
            }

            if (compara > 0) {
                Cinematograf temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                modificat = 1;
            }
            ptr = ptr->next;
        }
        ultim = ptr;
    } while (modificat);
}

void inserareSfarsit() {
    Nod* nou = creazaNod(); //Inițializarea pointerului la următorul nod cu NULL
    if (!head) {
        head = nou; // Întoarcerea pointerului către noul nod
        return;
    }

    Nod* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = nou;
}

void inserareInceput() {
    Nod* nou = creazaNod();
    nou->next = head;
    head = nou;
}

void inserarePozitie(int poz) {
    if (poz < 0) {
        printf("Poziție invalidă!\n");
        return;
    }

    Nod* nou = creazaNod();
    if (poz == 0) {
        nou->next = head;
        head = nou;
        return;
    }

    Nod* temp = head;
    for (int i = 0; temp && i < poz - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        printf("Poziție prea mare! Se adaugă la final.\n");
        inserareSfarsit();
        free(nou);
    } else {
        nou->next = temp->next;
        temp->next = nou;
    }
}

void stergerePozitie(int poz) {
    if (!head || poz < 0) {
        printf("Listă goală sau poziție invalidă!\n");
        return;
    }

    if (poz == 0) {
        Nod* deSters = head;
        head = head->next;
        free(deSters);
        return;
    }

    Nod* temp = head;
    for (int i = 0; temp && i < poz - 1; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        printf("Poziție invalidă!\n");
        return;
    }

    Nod* deSters = temp->next;
    temp->next = deSters->next;
    free(deSters);
}

void inversareLista() {
    Nod* prev = NULL;
    Nod* current = head;
    Nod* urmator = NULL;

    while (current) {
        urmator = current->next;
        current->next = prev;
        prev = current;
        current = urmator;
    }

    head = prev;
}