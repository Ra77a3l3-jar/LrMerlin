#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *head_type;
    char *drive_type;
    char *tread_type;
    int lenght;
    int diameter;
    char *material;
    char *tip_type;
    char *tollerance;
} Screw;

typedef struct {
    char *thread_type;
    int diameter;
    int thickness;
    char *material;
    char *shape;
    char *strenght;
} Nut;

typedef struct {
    Screw *screws;
    Nut *nuts;
    int screw_count;
    int nut_count;
    int screw_capacity;
    int nut_capacity;
} Screw_nuts;

/* =========== FUNCTION DECLARATON ========== */

Screw_nuts* initStruct(int nut_cout, int screw_cout);
void addScrews(Screw_nuts *list);
void addNuts(Screw_nuts *list);

/* ========== FUNCTION IMPLEMENTATION ============ */

Screw_nuts* initStruct(int nut_cout, int screw_cout) {
    Screw_nuts *list = malloc(sizeof(Screw_nuts));
    if(list == NULL) {
        printf("Memory allocation failed!\n");
    }

    list->nut_capacity = nut_cout;
    list->screw_capacity = screw_cout;
    list->nut_count = 0;
    list->screw_count = 0;
    return list;
}

void addScrews(Screw_nuts *list) {
    if(list->screw_count >= list->screw_capacity) {
        int new_capacity = 0;
        printf("The array is full add more space: ");
        scanf("%d", &new_capacity);
        printf("\n");
        new_capacity += list->screw_capacity;

        Screw *newScrew = realloc(list->screws, sizeof(Screw) * new_capacity);
        if(newScrew == NULL) {
            printf("Memory allocation failed\n");
        }

        list->screws = newScrew;
        list->screw_capacity = new_capacity;
    }
}

void addNuts(Screw_nuts *list) {
    if(list->nut_count >= list->nut_capacity) {
        int new_capacity = 0;
        printf("Array full add more space: ");
        scanf("%d", &new_capacity);
        printf("\n");
        new_capacity += list->nut_capacity;

        Nut *newNut = realloc(list->nuts, sizeof(Nut) * new_capacity);
        if(newNut == NULL) {
            printf("Memory allocation failed\n");
        }

        list->nuts = newNut;
        list->nut_capacity = new_capacity;
    }
}




/* ======== MAIN ======== */

int main(void) {
    int init_nut_cap = 5;
    int init_screw_cap = 5;
    Screw_nuts *list = NULL;

    list = initStruct(init_nut_cap, init_screw_cap);
    
    return 0;
}
