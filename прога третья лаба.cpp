#include <iostream>
#include <Windows.h>
using namespace std;
const int sizeOfMatrix = 10;
const int blockSize = sizeOfMatrix / 2;
int const maxx = sizeOfMatrix* sizeOfMatrix;
int const minn = 0;


void getMatrix(int* matrix) {
    int* index = matrix;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j, index++) {
            *index = rand() % (maxx - minn + 1) + minn;;
        }
    }
}

void printMatrix(int* matrix) {
    int* index = matrix;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j, index++) {
            if (j == blockSize) {
                cout << "| ";
            }
            cout << *index << " ";
        }
        if (i == blockSize - 1) {
            cout << '\n';
            for (int i(0); i < sizeOfMatrix; i++) {
                cout << "- -";
            }
        }
        cout << std::endl;
    }
    cout << "\n";
}

//задание 1

void ulitka(int arr[sizeOfMatrix][sizeOfMatrix], int arr1[sizeOfMatrix][sizeOfMatrix], int arr2[sizeOfMatrix][sizeOfMatrix], int arr3[sizeOfMatrix][sizeOfMatrix], int arr4[sizeOfMatrix][sizeOfMatrix]) {
    int top = 0, bottom = sizeOfMatrix - 1;
    int left = 0, right = (sizeOfMatrix - 1)*3;
    int *ind = &arr[0][0];
    while (top <= bottom && left <= right) {
        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = left; i <= right; i+=3) {
            destCoord.X = i;
            destCoord.Y = top;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *ind << '\r';
            cout.flush();
            Sleep(100);
            arr1[top][i / 3] = *ind;
            arr2[top][i / 3] = *ind;
            arr3[top][i / 3] = *ind;
            arr4[top][i / 3] = *ind;
            ind++;

        }
        top++;


        for (int i = top; i <= bottom; i++) {
            destCoord.X = right;
            destCoord.Y = i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *ind << '\r';
            cout.flush();
            Sleep(100);
            arr1[i][right / 3] = *ind;
            arr2[i][right / 3] = *ind;
            arr3[i][right / 3] = *ind;
            arr4[i][right / 3] = *ind;
            ind++;

        }
        right-=3;

        if (top <= bottom) {
            for (int i = right; i >= left; i-=3) {
                destCoord.X = i;
                destCoord.Y = bottom;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *ind << '\r';
                cout.flush();
                Sleep(100);
                arr1[bottom][i / 3] = *ind;
                arr2[bottom][i / 3] = *ind;
                arr3[bottom][i / 3] = *ind;
                arr4[bottom][i / 3] = *ind;
                ind++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                destCoord.X = left;
                destCoord.Y = i;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *ind << '\r';
                cout.flush();
                Sleep(100);
                arr1[i][left / 3] = *ind;
                arr2[i][left / 3] = *ind;
                arr3[i][left / 3] = *ind;
                arr4[i][left / 3] = *ind;
                ind++;
            }
            left+=3;
        }
    }
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = sizeOfMatrix;
    destCoord.Y = sizeOfMatrix;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "\n\n" << '\r';
    cout.flush();
    Sleep(100);
}

void snake(int arr[sizeOfMatrix][sizeOfMatrix], int arr1[sizeOfMatrix][sizeOfMatrix], int arr2[sizeOfMatrix][sizeOfMatrix], int arr3[sizeOfMatrix][sizeOfMatrix], int arr4[sizeOfMatrix][sizeOfMatrix]) {
    int top = 0, bottom = sizeOfMatrix - 1;
    int left = 0, right = (sizeOfMatrix - 1) * 3;
    int* ind = &arr[0][0];

    while (top <= bottom && left <= right) {
        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = top; i <= bottom; i++) {
            destCoord.X = left;
            destCoord.Y = i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *ind << '\r';
            cout.flush();
            Sleep(100);
            arr1[i][left / 3] = *ind;
            arr2[i][left / 3] = *ind;
            arr3[i][left / 3] = *ind;
            arr4[i][left / 3] = *ind;
            ind++;

        }
        left+=3;

        for (int i = bottom; i >= top; --i) {
            destCoord.X = left;
            destCoord.Y = i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *ind << '\r';
            cout.flush();
            Sleep(100);
            arr1[i][left / 3] = *ind;
            arr2[i][left / 3] = *ind;
            arr3[i][left / 3] = *ind;
            arr4[i][left / 3] = *ind;
            ind++;
        }
        left += 3;
    }
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = sizeOfMatrix;
    destCoord.Y = sizeOfMatrix;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "\n\n" << '\r';
    cout.flush();
    Sleep(100);
}



//задание 2

void getPtr(int* matrix, int x1, int y1, int x2, int y2) {
    for (int i = 0; i < blockSize; ++i) {
        for (int j = 0; j < blockSize; ++j) {
            int* ptr1 = matrix + (x1 * blockSize + i) * sizeOfMatrix + (y1 * blockSize + j);
            int* ptr2 = matrix + (x2 * blockSize + i) * sizeOfMatrix + (y2 * blockSize + j);

            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }
    }
}

void diagonals(int* matrix) {

    int xOne = 0;
    int yOne = 0;
    int xTwo = 1;
    int yTwo = 1;
    int xThree = 1;
    int yThree = 0;
    int xFour = 0;
    int yFour = 1;
    getPtr(matrix, xOne, yOne, xTwo, yTwo);
    getPtr(matrix, xThree, yThree, xFour, yFour);
}

void mirrorVertical(int* matrix) {

    int xOne = 0;
    int yOne = 0;
    int xTwo = 0;
    int yTwo = 1;
    int xThree = 1;
    int yThree = 0;
    int xFour = 1;
    int yFour = 1;

    getPtr(matrix, xOne, yOne, xTwo, yTwo);
    getPtr(matrix, xThree, yThree, xFour, yFour);
}

void mirrorHorizontal(int* matrix) {

    int xOne = 1;
    int yOne = 0;
    int xTwo = 0;
    int yTwo = 0;
    int xThree = 1;
    int yThree = 1;
    int xFour = 0;
    int yFour = 1;
    getPtr(matrix, xOne, yOne, xTwo, yTwo);
    getPtr(matrix, xThree, yThree, xFour, yFour);
}

void circle(int* matrix) {
    mirrorHorizontal(matrix);
    int xOne = 1;
    int yOne = 0;
    int xTwo = 0;
    int yTwo = 1;
    getPtr(matrix, xOne, yOne, xTwo, yTwo);
}

//задание 3

void swap(int* numOne, int* numTwo) {
    int temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}

void quickSort(int* matrix, int left, int right) {
    int* ptr = matrix;
    if (left < right) {
        int end = *(ptr + right);
        int indexLeast = left - 1;

        for (int i = left; i <= right - 1; i++) {
            if (*(ptr+i) < end) {
                indexLeast++;
                swap(*(ptr+indexLeast), *(ptr+i));
            }
        }
        swap(*(ptr+ indexLeast + 1), *(ptr+ right));
        int mid = indexLeast + 1;

        quickSort(matrix, left, mid - 1);
        quickSort(matrix, mid + 1, right);
    }
}

void shakerSort(int* matrix) {
    bool swapped = true;
    int* ptr = matrix;
    int left = 0, right = sizeOfMatrix * sizeOfMatrix - 1;
    while (swapped) {
        swapped = false;
        for (int i = left; i < right; ++i) {
            if (*(ptr + i) > *(ptr + i + 1)) {
                swap(*(ptr + i), *(ptr + i + 1));
                swapped = true;
            }
        }
        if (!swapped) break;
        --right;

        for (int i = right - 1; i >= left; --i) {
            if (*(ptr+i) > *(ptr +i + 1)) swap(*(ptr + i), *(ptr + i + 1));
            swapped = true;
        }
        ++left;
    }
}

void insertionSort(int* matrix) {
    for (int i = 1; i < sizeOfMatrix * sizeOfMatrix; ++i) {
        int* ptr = matrix;
        int key = *(ptr + i);
        int j = i - 1;

        while (j >= 0 && *(ptr + j) > key) {
            *(ptr + j + 1) = *(ptr + j);
            --j;
        }
        *(ptr + j + 1) = key;
    }
}

void combSort(int* matrix) {
    int* ptr = matrix;
    const double shrink = 1.247;  // Оптимальный коэффициент уменьшения
    int gap = sizeOfMatrix * sizeOfMatrix;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = static_cast<int>(gap / shrink);
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i + gap < sizeOfMatrix * sizeOfMatrix; ++i) {
            if (*(ptr + i) > *(ptr + i + gap)) {
                swap(*(ptr + i), *(ptr + i + gap));
                swapped = true;
            }
        }
    }
}

//задание 4

void operationsMatrix(int* matrix) {
    int userChoice;
    int number;
    cout << "Введите число: ";
    cin >> number;
    cout << "Выберите тип операции:\n1. Сложение\n2. Вычетание\n3. Умножение\n4. Деление\nВаш выбор: ";
    cin >> userChoice;
    int* indexOne = matrix;
    switch (userChoice) {
    case 1:
        for (int i = 0; i < sizeOfMatrix; ++i) {
            for (int j = 0; j < sizeOfMatrix; ++j, indexOne++) {
                *indexOne += number;
            }
        }
        cout << "\n";
        printMatrix(matrix);
        break;
    case 2:
        for (int i = 0; i < sizeOfMatrix; ++i) {
            for (int j = 0; j < sizeOfMatrix; ++j, indexOne++) {
                *indexOne -= number;
            }
        }
        cout << "\n";
        printMatrix(matrix);
        break;
    case 3:
        for (int i = 0; i < sizeOfMatrix; ++i) {
            for (int j = 0; j < sizeOfMatrix; ++j, indexOne++) {
                *indexOne *= number;
            }
        }
        cout << "\n";
        printMatrix(matrix);
        break;
    case 4:
        for (int i = 0; i < sizeOfMatrix; ++i) {
            for (int j = 0; j < sizeOfMatrix; ++j, indexOne++) {
                *indexOne /= number;
            }
        }
        cout << "\n";
        printMatrix(matrix);
        break;
    default:
        cout << "\nКакая-то ошибка\n";
        break;
    }

}

// ИДЗ

void sled(int* matrix) {

    int* ptr = matrix;
    int answer = 0;
    int coord = 20;
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = 0;
    destCoord.Y = sizeOfMatrix + 2;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << "След Матрицы Равен: "<< '\r';
    for (int i(0); i < sizeOfMatrix; i++) {
        for (int j(0); j < sizeOfMatrix * 3; j += 3, ptr++) {
            destCoord.X = j;
            destCoord.Y = i;
            SetConsoleCursorPosition(hStdout, destCoord);
            if (i == j/3) {
                answer += *ptr;
                cout << "\033[31m" << *ptr << "\033[0m " << '\r';
                destCoord.X = coord;
                destCoord.Y = sizeOfMatrix + 2;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << answer << '\r';
            }
            else {
                cout << *ptr  << ' ' << '\r';
            }
            cout.flush();
            Sleep(100);
        }
    }
}



int main()
{
    
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int arr[sizeOfMatrix][sizeOfMatrix];
    int arr1[sizeOfMatrix][sizeOfMatrix];
    int arr2[sizeOfMatrix][sizeOfMatrix];
    int arr3[sizeOfMatrix][sizeOfMatrix];
    int arr4[sizeOfMatrix][sizeOfMatrix];
    int choice;
    while (true) {

        cout << "\n\n\n\n\n\n\n\n\n\n\nВыберите комманду: \n";
        cout << "1 - задание 1\n";
        cout << "2 - задание 2\n";
        cout << "3 - задание 3\n";
        cout << "4 - задание 4\n";
        cout << "5 - ИДЗ 26\n";
        cout << "0 - выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            int number;
            getMatrix(*arr);
            cout << "\nКакой вывод вы хотите?:\n1 - спираль\n2 - змейка\n" << endl;
            cin >> number;
            if (number == 1) {
                ulitka(arr, arr1, arr2, arr3, arr4);
            }
            else {
                snake(arr, arr1, arr2, arr3, arr4);
            }
            break;
        case 2:
            int num;
            cout << "\nНаша матрица:\n";
            printMatrix(*arr1);
            cout << "\nНаша матрица после смещения блоков по кругу:\n";
            circle(*arr1);
            printMatrix(*arr1);
            cout << "Для продолжение нажмите 1\n";
            cin >> num;
            cout << "\nНаша матрица:\n";
            printMatrix(*arr2);
            cout << "\nНаша матрица после смены блоков по диагоналям:\n";
            diagonals(*arr2);
            printMatrix(*arr2);
            cout << "Для продолжение нажмите 1\n";
            cin >> num;
            cout << "\nНаша матрица:\n";
            printMatrix(*arr3);
            cout << "\nНаша матрица после смены блоков относительно вертикальной оси:\n";
            mirrorVertical(*arr3);
            printMatrix(*arr3);
            cout << "Для продолжение нажмите 1\n";
            cin >> num;
            cout << "\nНаша матрица:\n";
            printMatrix(*arr4);
            cout << "\nНаша матрица после смены блоков относительно горизонтальной оси:\n";
            mirrorHorizontal(*arr4);
            printMatrix(*arr4);
            break;

        case 3:
            int numUser;
            cout << "Отсортируем первую матрицу через Shaker sort\n";
            cout << "Исходная матрица:\n";
            printMatrix(*arr1);
            shakerSort(*arr1);
            cout << "Отсортированная матрица:\n";
            printMatrix(*arr1);
            cout << "Для продолжение нажмите 1\n";
            cin >> numUser;
            cout << "Отсортируем вторую матрицу через Comb sort\n";
            cout << "Исходная матрица:\n";
            printMatrix(*arr2);
            combSort(*arr2);
            cout << "Отсортированная матрица:\n";
            printMatrix(*arr2);
            cout << "Для продолжение нажмите 1\n";
            cin >> numUser;
            cout << "Отсортируем третью матрицу через Insesrt sort\n";
            cout << "Исходная матрица:\n";
            printMatrix(*arr3);
            insertionSort(*arr3);
            cout << "Отсортированная матрица:\n";
            printMatrix(*arr3);
            cout << "Для продолжение нажмите 1\n";
            cin >> numUser;
            cout << "Отсортируем четвёртую матрицу через Quick sort\n";
            cout << "Исходная матрица:\n";
            printMatrix(*arr4);
            quickSort(*arr4, 0, sizeOfMatrix * sizeOfMatrix - 1);
            cout << "Отсортированная матрица:\n";
            printMatrix(*arr4);
            break;
        case 4:
            operationsMatrix(*arr1);
            break;
        case 5:
            getMatrix(*arr);
            sled(*arr);
        default:
            std::cout << "\nНеверный выбор. Пожалуйста, попробуйте снова.";
            break;
        case 0:
            return 0;
            break;
        }
    }
    return 0;
}