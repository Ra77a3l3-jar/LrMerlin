#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char *head_type;
    char *drive_type;
    char *tread_type;
    int lenght;
    int diameter;
    char *material;
    char *tip_type;
    char *tollerance;
    char *shelf_position;
    int quantity;
} Screw;

typedef struct {
    int ID;
    char *thread_type;
    int diameter;
    int thickness;
    char *material;
    char *shape;
    char *strenght;
    char *shelf_position;
    int quantity;
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
void searchScrews(Screw_nuts *list);
void searchNuts(Screw_nuts *list);
void removeScrews(Screw_nuts *list);
void removeNuts(Screw_nuts *list);
void displayFoundScrews(Screw_nuts *list, int *found_indices, int found_count);
void displayFoundNuts(Screw_nuts *list, int *found_indices, int found_count);
void showStatistics(Screw_nuts *list);
void advancedSearchScrews(Screw_nuts *list);
void advancedSearchNuts(Screw_nuts *list);

/* ========== FUNCTION IMPLEMENTATION ============ */

Screw_nuts* initStruct(int nut_cout, int screw_cout) {
    Screw_nuts *list = malloc(sizeof(Screw_nuts));
    if(list == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Allocate memory for screws array
    list->screws = malloc(sizeof(Screw) * screw_cout);
    if(list->screws == NULL) {
        printf("Memory allocation failed for screws!\n");
        free(list);
        return NULL;
    }
    
    // Allocate memory for nuts array
    list->nuts = malloc(sizeof(Nut) * nut_cout);
    if(list->nuts == NULL) {
        printf("Memory allocation failed for nuts!\n");
        free(list->screws);
        free(list);
        return NULL;
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
            return;
        }

        list->screws = newScrew;
        list->screw_capacity = new_capacity;
    }

    // Allocate memory for strings
    char buffer[256];
    
    // Add new screw data
    Screw *current_screw = &list->screws[list->screw_count];
    
    printf("\n=== Adding New Screw ===\n");
    
    // Set ID
    current_screw->ID = list->screw_count + 1;
    printf("Screw ID: %d\n", current_screw->ID);
    
    // Get head type
    printf("Enter head type: ");
    scanf("%255[^\n]", buffer);
    current_screw->head_type = malloc(strlen(buffer) + 1);
    strcpy(current_screw->head_type, buffer);
    
    // Get drive type
    printf("Enter drive type: ");
    scanf("%255[^\n]", buffer);
    current_screw->drive_type = malloc(strlen(buffer) + 1);
    strcpy(current_screw->drive_type, buffer);
    
    // Get thread type
    printf("Enter thread type: ");
    scanf("%255[^\n]", buffer);
    current_screw->tread_type = malloc(strlen(buffer) + 1);
    strcpy(current_screw->tread_type, buffer);
    
    // Get length
    printf("Enter length (mm): ");
    scanf("%d", &current_screw->lenght);
    
    // Get diameter
    printf("Enter diameter (mm): ");
    scanf("%d", &current_screw->diameter);
    
    // Clear buffer
    getchar();
    
    // Get material
    printf("Enter material: ");
    scanf("%255[^\n]", buffer);
    current_screw->material = malloc(strlen(buffer) + 1);
    strcpy(current_screw->material, buffer);
    
    // Get tip type
    printf("Enter tip type: ");
    scanf("%255[^\n]", buffer);
    current_screw->tip_type = malloc(strlen(buffer) + 1);
    strcpy(current_screw->tip_type, buffer);
    
    // Get tolerance
    printf("Enter tolerance: ");
    scanf("%255[^\n]", buffer);
    current_screw->tollerance = malloc(strlen(buffer) + 1);
    strcpy(current_screw->tollerance, buffer);
    
    // Get shelf position
    printf("Enter shelf position: ");
    scanf("%255[^\n]", buffer);
    current_screw->shelf_position = malloc(strlen(buffer) + 1);
    strcpy(current_screw->shelf_position, buffer);
    
    // Get quantity
    printf("Enter quantity: ");
    scanf("%d", &current_screw->quantity);
    
    list->screw_count++;
    printf("\n✅ Screw added successfully!\n");
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
            return;
        }

        list->nuts = newNut;
        list->nut_capacity = new_capacity;
    }

    // Allocate memory for strings
    char buffer[256];
    
    // Add new nut data
    Nut *current_nut = &list->nuts[list->nut_count];
    
    printf("\n=== Adding New Nut ===\n");
    
    // Set ID
    current_nut->ID = list->nut_count + 1;
    printf("Nut ID: %d\n", current_nut->ID);
    
    // Get thread type
    printf("Enter thread type: ");
    scanf("%255[^\n]", buffer);
    current_nut->thread_type = malloc(strlen(buffer) + 1);
    strcpy(current_nut->thread_type, buffer);
    
    // Get diameter
    printf("Enter diameter (mm): ");
    scanf("%d", &current_nut->diameter);
    
    // Get thickness
    printf("Enter thickness (mm): ");
    scanf("%d", &current_nut->thickness);
    
    // Clear buffer
    getchar();
    
    // Get material
    printf("Enter material: ");
    scanf("%255[^\n]", buffer);
    current_nut->material = malloc(strlen(buffer) + 1);
    strcpy(current_nut->material, buffer);
    
    // Get shape
    printf("Enter shape: ");
    scanf("%255[^\n]", buffer);
    current_nut->shape = malloc(strlen(buffer) + 1);
    strcpy(current_nut->shape, buffer);
    
    // Get strength
    printf("Enter strength: ");
    scanf("%255[^\n]", buffer);
    current_nut->strenght = malloc(strlen(buffer) + 1);
    strcpy(current_nut->strenght, buffer);
    
    // Get shelf position
    printf("Enter shelf position: ");
    scanf("%255[^\n]", buffer);
    current_nut->shelf_position = malloc(strlen(buffer) + 1);
    strcpy(current_nut->shelf_position, buffer);
    
    // Get quantity
    printf("Enter quantity: ");
    scanf("%d", &current_nut->quantity);
    
    list->nut_count++;
    printf("\n✅ Nut added successfully!\n");
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
            printf("\n--- Screw #%d (ID: %d) ---\n", i + 1, list->screws[i].ID);
            printf("Head Type:    %s\n", list->screws[i].head_type ? list->screws[i].head_type : "N/A");
            printf("Drive Type:   %s\n", list->screws[i].drive_type ? list->screws[i].drive_type : "N/A");
            printf("Thread Type:  %s\n", list->screws[i].tread_type ? list->screws[i].tread_type : "N/A");
            printf("Length:       %d mm\n", list->screws[i].lenght);
            printf("Diameter:     %d mm\n", list->screws[i].diameter);
            printf("Material:     %s\n", list->screws[i].material ? list->screws[i].material : "N/A");
            printf("Tip Type:     %s\n", list->screws[i].tip_type ? list->screws[i].tip_type : "N/A");
            printf("Tolerance:    %s\n", list->screws[i].tollerance ? list->screws[i].tollerance : "N/A");
            printf("Shelf Pos:    %s\n", list->screws[i].shelf_position ? list->screws[i].shelf_position : "N/A");
            printf("Quantity:     %d\n", list->screws[i].quantity);
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
            printf("\n--- Nut #%d (ID: %d) ---\n", i + 1, list->nuts[i].ID);
            printf("Thread Type:  %s\n", list->nuts[i].thread_type ? list->nuts[i].thread_type : "N/A");
            printf("Diameter:     %d mm\n", list->nuts[i].diameter);
            printf("Thickness:    %d mm\n", list->nuts[i].thickness);
            printf("Material:     %s\n", list->nuts[i].material ? list->nuts[i].material : "N/A");
            printf("Shape:        %s\n", list->nuts[i].shape ? list->nuts[i].shape : "N/A");
            printf("Strength:     %s\n", list->nuts[i].strenght ? list->nuts[i].strenght : "N/A");
            printf("Shelf Pos:    %s\n", list->nuts[i].shelf_position ? list->nuts[i].shelf_position : "N/A");
            printf("Quantity:     %d\n", list->nuts[i].quantity);
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

void save_to_file(const Screw_nuts *list, const char *filename) {
    printf("\n💾 Saving screws and nuts to file...\n");
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("❌ Error opening file for writing.\n");
        return;
    }

    // Write header with counts
    fprintf(file, "SCREWS %d\n", list->screw_count);
    
    // Save screws
    for (int i = 0; i < list->screw_count; ++i) {
        fprintf(file, "%d|%s|%s|%s|%d|%d|%s|%s|%s\n", 
            list->screws[i].ID,
            list->screws[i].head_type ? list->screws[i].head_type : "N/A",
            list->screws[i].drive_type ? list->screws[i].drive_type : "N/A",
            list->screws[i].tread_type ? list->screws[i].tread_type : "N/A",
            list->screws[i].lenght,
            list->screws[i].diameter,
            list->screws[i].material ? list->screws[i].material : "N/A",
            list->screws[i].tip_type ? list->screws[i].tip_type : "N/A",
            list->screws[i].tollerance ? list->screws[i].tollerance : "N/A");
    }
    
    // Write nuts header
    fprintf(file, "NUTS %d\n", list->nut_count);
    
    // Save nuts
    for (int i = 0; i < list->nut_count; ++i) {
        fprintf(file, "%d|%s|%d|%d|%s|%s|%s\n", 
            list->nuts[i].ID,
            list->nuts[i].thread_type ? list->nuts[i].thread_type : "N/A",
            list->nuts[i].diameter,
            list->nuts[i].thickness,
            list->nuts[i].material ? list->nuts[i].material : "N/A",
            list->nuts[i].shape ? list->nuts[i].shape : "N/A",
            list->nuts[i].strenght ? list->nuts[i].strenght : "N/A");
    }

    fclose(file);
    printf("✅ Screws and nuts saved successfully!\n");
}

void load_from_file(Screw_nuts *list, const char *filename) {
    printf("\n📂 Loading screws and nuts from file...\n");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("❌ Error opening file for reading.\n");
        return;
    }

    char line[1024];
    char section[20];
    int count;
    
    // Reset counts
    list->screw_count = 0;
    list->nut_count = 0;
    
    // Read screws section
    if (fgets(line, sizeof(line), file) && sscanf(line, "%s %d", section, &count) == 2) {
        if (strcmp(section, "SCREWS") == 0) {
            for (int i = 0; i < count && i < list->screw_capacity; i++) {
                if (fgets(line, sizeof(line), file)) {
                    char *token = strtok(line, "|");
                    if (token) list->screws[i].ID = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->screws[i].head_type = malloc(strlen(token) + 1);
                        strcpy(list->screws[i].head_type, token);
                    } else {
                        list->screws[i].head_type = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->screws[i].drive_type = malloc(strlen(token) + 1);
                        strcpy(list->screws[i].drive_type, token);
                    } else {
                        list->screws[i].drive_type = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->screws[i].tread_type = malloc(strlen(token) + 1);
                        strcpy(list->screws[i].tread_type, token);
                    } else {
                        list->screws[i].tread_type = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token) list->screws[i].lenght = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token) list->screws[i].diameter = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->screws[i].material = malloc(strlen(token) + 1);
                        strcpy(list->screws[i].material, token);
                    } else {
                        list->screws[i].material = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->screws[i].tip_type = malloc(strlen(token) + 1);
                        strcpy(list->screws[i].tip_type, token);
                    } else {
                        list->screws[i].tip_type = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token) {
                        // Remove newline character
                        token[strcspn(token, "\n")] = 0;
                        if (strcmp(token, "N/A") != 0) {
                            list->screws[i].tollerance = malloc(strlen(token) + 1);
                            strcpy(list->screws[i].tollerance, token);
                        } else {
                            list->screws[i].tollerance = NULL;
                        }
                    }
                    
                    list->screw_count++;
                }
            }
        }
    }
    
    // Read nuts section
    if (fgets(line, sizeof(line), file) && sscanf(line, "%s %d", section, &count) == 2) {
        if (strcmp(section, "NUTS") == 0) {
            for (int i = 0; i < count && i < list->nut_capacity; i++) {
                if (fgets(line, sizeof(line), file)) {
                    char *token = strtok(line, "|");
                    if (token) list->nuts[i].ID = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->nuts[i].thread_type = malloc(strlen(token) + 1);
                        strcpy(list->nuts[i].thread_type, token);
                    } else {
                        list->nuts[i].thread_type = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token) list->nuts[i].diameter = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token) list->nuts[i].thickness = atoi(token);
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->nuts[i].material = malloc(strlen(token) + 1);
                        strcpy(list->nuts[i].material, token);
                    } else {
                        list->nuts[i].material = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token && strcmp(token, "N/A") != 0) {
                        list->nuts[i].shape = malloc(strlen(token) + 1);
                        strcpy(list->nuts[i].shape, token);
                    } else {
                        list->nuts[i].shape = NULL;
                    }
                    
                    token = strtok(NULL, "|");
                    if (token) {
                        // Remove newline character
                        token[strcspn(token, "\n")] = 0;
                        if (strcmp(token, "N/A") != 0) {
                            list->nuts[i].strenght = malloc(strlen(token) + 1);
                            strcpy(list->nuts[i].strenght, token);
                        } else {
                            list->nuts[i].strenght = NULL;
                        }
                    }
                    
                    list->nut_count++;
                }
            }
        }
    }

    fclose(file);
    printf("✅ Screws and nuts loaded successfully!\n");
}

void displayFoundScrews(Screw_nuts *list, int *found_indices, int found_count) {
    printf("\n=======================================\n");
    printf("         FOUND SCREWS (%d items)\n", found_count);
    printf("=======================================\n");
    
    for(int i = 0; i < found_count; i++) {
        int index = found_indices[i];
        printf("\n--- Screw #%d (ID: %d) ---\n", index + 1, list->screws[index].ID);
        printf("Head Type:    %s\n", list->screws[index].head_type ? list->screws[index].head_type : "N/A");
        printf("Drive Type:   %s\n", list->screws[index].drive_type ? list->screws[index].drive_type : "N/A");
        printf("Thread Type:  %s\n", list->screws[index].tread_type ? list->screws[index].tread_type : "N/A");
        printf("Length:       %d mm\n", list->screws[index].lenght);
        printf("Diameter:     %d mm\n", list->screws[index].diameter);
        printf("Material:     %s\n", list->screws[index].material ? list->screws[index].material : "N/A");
        printf("Tip Type:     %s\n", list->screws[index].tip_type ? list->screws[index].tip_type : "N/A");
        printf("Tolerance:    %s\n", list->screws[index].tollerance ? list->screws[index].tollerance : "N/A");
    }
    printf("\n=======================================\n");
}

void displayFoundNuts(Screw_nuts *list, int *found_indices, int found_count) {
    printf("\n=====================================\n");
    printf("         FOUND NUTS (%d items)\n", found_count);
    printf("=====================================\n");
    
    for(int i = 0; i < found_count; i++) {
        int index = found_indices[i];
        printf("\n--- Nut #%d (ID: %d) ---\n", index + 1, list->nuts[index].ID);
        printf("Thread Type:  %s\n", list->nuts[index].thread_type ? list->nuts[index].thread_type : "N/A");
        printf("Diameter:     %d mm\n", list->nuts[index].diameter);
        printf("Thickness:    %d mm\n", list->nuts[index].thickness);
        printf("Material:     %s\n", list->nuts[index].material ? list->nuts[index].material : "N/A");
        printf("Shape:        %s\n", list->nuts[index].shape ? list->nuts[index].shape : "N/A");
        printf("Strength:     %s\n", list->nuts[index].strenght ? list->nuts[index].strenght : "N/A");
    }
    printf("\n=====================================\n");
}

void searchScrews(Screw_nuts *list) {
    if(list->screw_count == 0) {
        printf("\n❌ No screws in inventory to search.\n");
        return;
    }
    
    printf("\n=== SEARCH SCREWS ===\n");
    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Head Type\n");
    printf("3. Drive Type\n");
    printf("4. Thread Type\n");
    printf("5. Length\n");
    printf("6. Diameter\n");
    printf("7. Material\n");
    printf("8. Tip Type\n");
    printf("9. Tolerance\n");
    printf("0. All characteristics\n");
    printf("Enter choice (0-9): ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // Clear buffer
    
    int found_indices[1000]; // Assuming max 1000 items
    int found_count = 0;
    char search_str[256];
    int search_int;
    
    switch(choice) {
        case 1: // Search by ID
            printf("Enter ID to search: ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].ID == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 2: // Search by Head Type
            printf("Enter head type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].head_type && strstr(list->screws[i].head_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 3: // Search by Drive Type
            printf("Enter drive type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].drive_type && strstr(list->screws[i].drive_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 4: // Search by Thread Type
            printf("Enter thread type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tread_type && strstr(list->screws[i].tread_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 5: // Search by Length
            printf("Enter length to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].lenght == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 6: // Search by Diameter
            printf("Enter diameter to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].diameter == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 7: // Search by Material
            printf("Enter material to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].material && strstr(list->screws[i].material, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 8: // Search by Tip Type
            printf("Enter tip type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tip_type && strstr(list->screws[i].tip_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 9: // Search by Tolerance
            printf("Enter tolerance to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tollerance && strstr(list->screws[i].tollerance, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 0: // Show all screws
            for(int i = 0; i < list->screw_count; i++) {
                found_indices[found_count++] = i;
            }
            break;
            
        default:
            printf("❌ Invalid choice!\n");
            return;
    }
    
    if(found_count == 0) {
        printf("\n❌ No screws found matching your criteria.\n");
    } else {
        displayFoundScrews(list, found_indices, found_count);
    }
}

void searchNuts(Screw_nuts *list) {
    if(list->nut_count == 0) {
        printf("\n❌ No nuts in inventory to search.\n");
        return;
    }
    
    printf("\n=== SEARCH NUTS ===\n");
    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Thread Type\n");
    printf("3. Diameter\n");
    printf("4. Thickness\n");
    printf("5. Material\n");
    printf("6. Shape\n");
    printf("7. Strength\n");
    printf("0. All characteristics\n");
    printf("Enter choice (0-7): ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // Clear buffer
    
    int found_indices[1000]; // Assuming max 1000 items
    int found_count = 0;
    char search_str[256];
    int search_int;
    
    switch(choice) {
        case 1: // Search by ID
            printf("Enter ID to search: ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].ID == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 2: // Search by Thread Type
            printf("Enter thread type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].thread_type && strstr(list->nuts[i].thread_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 3: // Search by Diameter
            printf("Enter diameter to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].diameter == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 4: // Search by Thickness
            printf("Enter thickness to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].thickness == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 5: // Search by Material
            printf("Enter material to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].material && strstr(list->nuts[i].material, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 6: // Search by Shape
            printf("Enter shape to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].shape && strstr(list->nuts[i].shape, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 7: // Search by Strength
            printf("Enter strength to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].strenght && strstr(list->nuts[i].strenght, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 0: // Show all nuts
            for(int i = 0; i < list->nut_count; i++) {
                found_indices[found_count++] = i;
            }
            break;
            
        default:
            printf("❌ Invalid choice!\n");
            return;
    }
    
    if(found_count == 0) {
        printf("\n❌ No nuts found matching your criteria.\n");
    } else {
        displayFoundNuts(list, found_indices, found_count);
    }
}

void removeScrews(Screw_nuts *list) {
    if(list->screw_count == 0) {
        printf("\n❌ No screws in inventory to remove.\n");
        return;
    }
    
    printf("\n=== REMOVE SCREWS ===\n");
    printf("Search screws to remove by:\n");
    printf("1. ID\n");
    printf("2. Head Type\n");
    printf("3. Drive Type\n");
    printf("4. Thread Type\n");
    printf("5. Length\n");
    printf("6. Diameter\n");
    printf("7. Material\n");
    printf("8. Tip Type\n");
    printf("9. Tolerance\n");
    printf("0. Show all screws\n");
    printf("Enter choice (0-9): ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // Clear buffer
    
    int found_indices[1000]; // Assuming max 1000 items
    int found_count = 0;
    char search_str[256];
    int search_int;
    
    // Search logic (same as searchScrews)
    switch(choice) {
        case 1: // Search by ID
            printf("Enter ID to search: ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].ID == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 2: // Search by Head Type
            printf("Enter head type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].head_type && strstr(list->screws[i].head_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 3: // Search by Drive Type
            printf("Enter drive type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].drive_type && strstr(list->screws[i].drive_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 4: // Search by Thread Type
            printf("Enter thread type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tread_type && strstr(list->screws[i].tread_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 5: // Search by Length
            printf("Enter length to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].lenght == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 6: // Search by Diameter
            printf("Enter diameter to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].diameter == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 7: // Search by Material
            printf("Enter material to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].material && strstr(list->screws[i].material, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 8: // Search by Tip Type
            printf("Enter tip type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tip_type && strstr(list->screws[i].tip_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 9: // Search by Tolerance
            printf("Enter tolerance to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->screw_count; i++) {
                if(list->screws[i].tollerance && strstr(list->screws[i].tollerance, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 0: // Show all screws
            for(int i = 0; i < list->screw_count; i++) {
                found_indices[found_count++] = i;
            }
            break;
            
        default:
            printf("❌ Invalid choice!\n");
            return;
    }
    
    if(found_count == 0) {
        printf("\n❌ No screws found matching your criteria.\n");
        return;
    }
    
    // Display found screws
    displayFoundScrews(list, found_indices, found_count);
    
    // Ask user to select which screw to remove by ID
    printf("\nEnter the ID of the screw to remove (or 0 to cancel): ");
    int remove_id;
    scanf("%d", &remove_id);
    
    if(remove_id == 0) {
        printf("❌ Removal cancelled.\n");
        return;
    }
    
    // Find the screw with the specified ID among found items
    int remove_index = -1;
    for(int i = 0; i < found_count; i++) {
        int index = found_indices[i];
        if(list->screws[index].ID == remove_id) {
            remove_index = index;
            break;
        }
    }
    
    if(remove_index == -1) {
        printf("❌ Screw with ID %d not found in the search results.\n", remove_id);
        return;
    }
    
    // Confirm removal
    printf("\n⚠️ Are you sure you want to remove screw with ID %d? (y/n): ", remove_id);
    char confirm;
    getchar(); // Clear buffer
    scanf("%c", &confirm);
    
    if(confirm != 'y' && confirm != 'Y') {
        printf("❌ Removal cancelled.\n");
        return;
    }
    
    // Free memory for strings
    free(list->screws[remove_index].head_type);
    free(list->screws[remove_index].drive_type);
    free(list->screws[remove_index].tread_type);
    free(list->screws[remove_index].material);
    free(list->screws[remove_index].tip_type);
    free(list->screws[remove_index].tollerance);
    
    // Shift all elements after the removed one
    for(int i = remove_index; i < list->screw_count - 1; i++) {
        list->screws[i] = list->screws[i + 1];
    }
    
    list->screw_count--;
    printf("\n✅ Screw with ID %d removed successfully!\n", remove_id);
}

void removeNuts(Screw_nuts *list) {
    if(list->nut_count == 0) {
        printf("\n❌ No nuts in inventory to remove.\n");
        return;
    }
    
    printf("\n=== REMOVE NUTS ===\n");
    printf("Search nuts to remove by:\n");
    printf("1. ID\n");
    printf("2. Thread Type\n");
    printf("3. Diameter\n");
    printf("4. Thickness\n");
    printf("5. Material\n");
    printf("6. Shape\n");
    printf("7. Strength\n");
    printf("0. Show all nuts\n");
    printf("Enter choice (0-7): ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // Clear buffer
    
    int found_indices[1000];
    int found_count = 0;
    char search_str[256];
    int search_int;
    
    // Search logic (same as searchNuts)
    switch(choice) {
        case 1: // Search by ID
            printf("Enter ID to search: ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].ID == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 2: // Search by Thread Type
            printf("Enter thread type to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].thread_type && strstr(list->nuts[i].thread_type, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 3: // Search by Diameter
            printf("Enter diameter to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].diameter == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 4: // Search by Thickness
            printf("Enter thickness to search (mm): ");
            scanf("%d", &search_int);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].thickness == search_int) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 5: // Search by Material
            printf("Enter material to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].material && strstr(list->nuts[i].material, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 6: // Search by Shape
            printf("Enter shape to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].shape && strstr(list->nuts[i].shape, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 7: // Search by Strength
            printf("Enter strength to search: ");
            scanf("%255[^\n]", search_str);
            for(int i = 0; i < list->nut_count; i++) {
                if(list->nuts[i].strenght && strstr(list->nuts[i].strenght, search_str)) {
                    found_indices[found_count++] = i;
                }
            }
            break;
            
        case 0: // Show all nuts
            for(int i = 0; i < list->nut_count; i++) {
                found_indices[found_count++] = i;
            }
            break;
            
        default:
            printf("❌ Invalid choice!\n");
            return;
    }
    
    if(found_count == 0) {
        printf("\n❌ No nuts found matching your criteria.\n");
        return;
    }
    
    // Display found nuts
    displayFoundNuts(list, found_indices, found_count);
    
    // Ask user to select which nut to remove by ID
    printf("\nEnter the ID of the nut to remove (or 0 to cancel): ");
    int remove_id;
    scanf("%d", &remove_id);
    
    if(remove_id == 0) {
        printf("❌ Removal cancelled.\n");
        return;
    }
    
    // Find the nut with the specified ID among found items
    int remove_index = -1;
    for(int i = 0; i < found_count; i++) {
        int index = found_indices[i];
        if(list->nuts[index].ID == remove_id) {
            remove_index = index;
            break;
        }
    }
    
    if(remove_index == -1) {
        printf("❌ Nut with ID %d not found in the search results.\n", remove_id);
        return;
    }
    
    // Confirm removal
    printf("\n⚠️ Are you sure you want to remove nut with ID %d? (y/n): ", remove_id);
    char confirm;
    getchar();
    scanf("%c", &confirm);
    
    if(confirm != 'y' && confirm != 'Y') {
        printf("❌ Removal cancelled.\n");
        return;
    }
    
    // Free memory for strings
    free(list->nuts[remove_index].thread_type);
    free(list->nuts[remove_index].material);
    free(list->nuts[remove_index].shape);
    free(list->nuts[remove_index].strenght);
    
    // Shift all elements after the removed one
    for(int i = remove_index; i < list->nut_count - 1; i++) {
        list->nuts[i] = list->nuts[i + 1];
    }
    
    list->nut_count--;
    printf("\n✅ Nut with ID %d removed successfully!\n", remove_id);
}





int main(void) {
    int init_nut_cap = 5;
    int init_screw_cap = 5;
    Screw_nuts *list = NULL;

    list = initStruct(init_nut_cap, init_screw_cap);
    
    int choice;

    while (1) {
        printf("\n=== SCREW AND NUT INVENTORY MANAGEMENT ===\n");
        printf("1. Add Screw\n");
        printf("2. Add Nut\n");
        printf("3. Display Inventory\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Search Screws\n");
        printf("7. Search Nuts\n");
        printf("8. Remove Screw\n");
        printf("9. Remove Nut\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addScrews(list);
            break;
        case 2:
            addNuts(list);
            break;
        case 3:
            display(list);
            break;
        case 4:
            save_to_file(list, "inventory.txt");
            break;
        case 5:
            load_from_file(list, "inventory.txt");
            break;
        case 6:
            searchScrews(list);
            break;
        case 7:
            searchNuts(list);
            break;
        case 8:
            removeScrews(list);
            break;
        case 9:
            removeNuts(list);
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}
