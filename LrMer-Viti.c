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
} screw;

typedef struct {
    char *thread_type;
    int diameter;
    int thickness;
    char *material;
    char *shape;
    char *strenght;
} nut;

typedef struct {
    screw *screws;
    nut *nuts;
    int screw_count;
    int nut_count;
    int screw_capacity;
    int nut_capacity;
} Screw_nuts;

/* =========== FUNCTION DECLARATON ========== */

Screw_nuts* initStruct(int nut_cout, int screw_cout);
void addScrews(Screw_nuts* list);
void addNuts(Screw_nuts* list);

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




/* ======== MAIN ======== */

int main(void) {
    int init_nut_cap = 5;
    int init_screw_cap = 5;
    Screw_nuts *list = NULL;

    list = initStruct(init_nut_cap, init_screw_cap);
    
    return 0;
}
