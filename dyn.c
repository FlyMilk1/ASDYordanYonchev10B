//Dynamic Array
typedef struct {
    int**data;
    size_t size;      // number of elements currently stored
    size_t capacity;  // allocated space
} DynamicArray;
static void da_resize(DynamicArray *arr, size_t new_capacity) {
    int *new_data = realloc(arr->data, new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    arr->data = new_data;
    arr->capacity = new_capacity;
}

DynamicArray *da_create(size_t initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) return NULL;

    arr->data = malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void da_push_back(DynamicArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        da_resize(arr, arr->capacity * 2);
    }
    arr->data[arr->size++] = value;
}

int da_pop_back(DynamicArray *arr) {
    if (arr->size == 0) {
        fprintf(stderr, "Array underflow!\n");
        exit(EXIT_FAILURE);
    }
    return arr->data[--arr->size];
}

int da_get(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
    return arr->data[index];
}

void da_set(DynamicArray *arr, size_t index, int value) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
    arr->data[index] = value;
}

void da_insert(DynamicArray *arr, size_t index, int value) {
    if (index > arr->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }

    if (arr->size >= arr->capacity) {
        da_resize(arr, arr->capacity * 2);
    }

    memmove(&arr->data[index + 1], &arr->data[index], 
            (arr->size - index) * sizeof(int));

    arr->data[index] = value;
    arr->size++;
}

void da_remove(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }

    memmove(&arr->data[index], &arr->data[index + 1], 
            (arr->size - index - 1) * sizeof(int));

    arr->size--;
}

void da_free(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

