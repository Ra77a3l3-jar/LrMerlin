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
void display(Screw_nuts *list);
void save_to_file(const Screw_nuts *list, const char *filename);
void load_from_file(Screw_nuts *list, const char *filename);

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

void display(Screw_nuts *list) {
    // Display all screws
    printf("\n===============================\n");
    printf("         SCREWS INVENTORY\n");
    printf("===============================\n");
    
    if(list->screw_count == 0) {
        printf("No screws in inventory.\n");
    } else {
        for(int i = 0; i < list->screw_count; i++) {
            printf("\n--- Screw #%d ---\n", i + 1);
            printf("Head Type:    %s\n", list->screws[i].head_type ? list->screws[i].head_type : "N/A");
            printf("Drive Type:   %s\n", list->screws[i].drive_type ? list->screws[i].drive_type : "N/A");
            printf("Thread Type:  %s\n", list->screws[i].tread_type ? list->screws[i].tread_type : "N/A");
            printf("Length:       %d mm\n", list->screws[i].lenght);
            printf("Diameter:     %d mm\n", list->screws[i].diameter);
            printf("Material:     %s\n", list->screws[i].material ? list->screws[i].material : "N/A");
            printf("Tip Type:     %s\n", list->screws[i].tip_type ? list->screws[i].tip_type : "N/A");
            printf("Tolerance:    %s\n", list->screws[i].tollerance ? list->screws[i].tollerance : "N/A");
        }
    }
    
    // Display all nuts
    printf("\n===============================\n");
    printf("          NUTS INVENTORY\n");
    printf("===============================\n");
    
    if(list->nut_count == 0) {
        printf("No nuts in inventory.\n");
    } else {
        for(int i = 0; i < list->nut_count; i++) {
            printf("\n--- Nut #%d ---\n", i + 1);
            printf("Thread Type:  %s\n", list->nuts[i].thread_type ? list->nuts[i].thread_type : "N/A");
            printf("Diameter:     %d mm\n", list->nuts[i].diameter);
            printf("Thickness:    %d mm\n", list->nuts[i].thickness);
            printf("Material:     %s\n", list->nuts[i].material ? list->nuts[i].material : "N/A");
            printf("Shape:        %s\n", list->nuts[i].shape ? list->nuts[i].shape : "N/A");
            printf("Strength:     %s\n", list->nuts[i].strenght ? list->nuts[i].strenght : "N/A");
        }
    }
    
    // Display summary
    printf("\n===============================\n");
    printf("           SUMMARY\n");
    printf("===============================\n");
    printf("Total Screws: %d/%d\n", list->screw_count, list->screw_capacity);
    printf("Total Nuts:   %d/%d\n", list->nut_count, list->nut_capacity);
    printf("===============================\n");
}




/* ======== MAIN ======== */

int main(void) {
    int init_nut_cap = 5;
    int init_screw_cap = 5;
    Screw_nuts *list = NULL;

    list = initStruct(init_nut_cap, init_screw_cap);
    
    return 0;
}
