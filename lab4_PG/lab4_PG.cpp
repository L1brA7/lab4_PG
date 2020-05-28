#include <iostream>

using namespace std;

int N_INPUT();
void array_out(int *ARRAY, int N);
int *array_input(int N);
int min_negative(int *ARRAY, int N);
int min(int *ARRAY, int N, int I, int MIN);
int sum(int N, int I, int elem);
int funcF(int N);
int funcG(int N);

int main()
{
    int number;
    cout << "Enter the number, or enter 0 to close - ";
    cin >> number;
    while (number) {
        if (number == 1) {
            int N = N_INPUT();
            int *ARRAY = array_input(N);
            array_out(ARRAY, N);
            cout << min_negative(ARRAY, N) << endl;
        }
        if (number == 2) {
            int N = N_INPUT();
            printf("Sum = %i\n", sum(N, 1, 1));
        }
        if (number == 3) {
            printf("F(n):\n");
            for (int i = 1; i <= 10; i++) {
                printf("%6i|%2i\n", funcF(i), i);
            }
            printf("G(n):\n");
            for (int i = 1; i <= 10; i++) {
                printf("%6i|%2i\n", funcG(i), i);
            }
        }
        cout << "Enter the number, or enter 0 to close - ";
        cin >> number;
    }
}

int N_INPUT() {
    int N;
    cout << "Enter N >= 0 - ";
    cin >> N;
    while (N < 0) {
        cout << "ERROR.Enter N >= 0 - ";
        cin >> N;
    }
    return N;
}

void array_out(int* ARRAY, int N) {
    for (int i = 0; i < N; i++) {
        cout << ARRAY[i] << " ";
    }
    cout << endl;
}

int* array_input(int N) {
    int *ARRAY = new int[N];
    for (int i = 0; i < N; i++)
        cin >> ARRAY[i];
    return ARRAY;
}

int min_negative(int* ARRAY, int N) {
    int startI, MIN;

    bool okey = false;
    for (int i = 0; i < N; i++) {
        if (ARRAY[i] < 0) {
            MIN = ARRAY[i];
            startI = i;
            okey = true;
            break;
        }
    }

    if (okey) {
        return min(ARRAY, N, startI, MIN);
    }
    else {
        return 0;
    }
}

int min(int *ARRAY, int N, int I, int MIN) {
    if (I == N) return MIN;
    if (ARRAY[I] < MIN) MIN  = ARRAY[I];
    return MIN = min(ARRAY, N, I + 1, MIN);
}

int sum(int N, int I, int elem) {
    int first_element = 1;
    int denom = 3;
    if (I == N) {
        cout << elem << endl;
        return first_element;
    }
    cout << elem << endl;
    elem *= denom;
    return elem + sum(N, I + 1, elem);
}

int funcF(int N) {
    if (N == 1) return 0;
    int value = -4 * funcF(N - 1) + funcG(N - 1);
    return value;
}

int funcG(int N) {
    if (N == 1) return 1;
    int value = -4 * funcF(N - 1) * funcG(N - 1);
    return value;
}