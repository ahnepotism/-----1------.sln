#include <iostream>
#include <fstream>
#include <clocale>
#include <cstring>
using namespace std;

struct Student {
    char secondName[50];
    char name[50];
    char dad[50];
    bool pol;
    int id;
    int group;
    int notes[8];
};

const int maxNum = 100;

void printStudent(Student* bro) {
    cout << "ФИО: " << bro->secondName << " " << bro->name << " " << bro->dad << "\nПол: " << (bro->pol ? "female" : "male") << "\nНомер в группе: " << bro->id << "\nГруппа: " << bro->group << "\nОценки за семестр:\nМатан - " << bro->notes[0] << "\nАиг - " << bro->notes[1] << "\nПрограммирование - " << bro->notes[2] << "\nФизика - " << bro->notes[3] << "\nФизкультура - " << bro->notes[4] << "\nФилософия - " << bro->notes[5] << "\nАнглийский язык - " << bro->notes[6] << "\nИнформатика - " << bro->notes[7] << "\nСредний балл за семестр: " << float(bro->notes[0] + bro->notes[1] + bro->notes[2] + bro->notes[3] + bro->notes[4] + bro->notes[5] + bro->notes[6] + bro->notes[7]) / 8 << "\n\n";
}

float sredBall(Student students[maxNum], int inde) {
    float ball = float((students[inde].notes[0] + students[inde].notes[1] + students[inde].notes[2] + students[inde].notes[3] + students[inde].notes[4] + students[inde].notes[5] + students[inde].notes[6] + students[inde].notes[7])) / 8;
    return float(ball);
}

void printStudentByNum(Student students[maxNum], int counter) {
    int flagg = 0;
    int searchNum;
    cout << "Введите номер, по которому будем искать студента: ";
    cin >> searchNum;
    for (int aydi(0); aydi < counter; aydi++) {
        if (students[aydi].id == searchNum) {
            cout << "\nМы нашли студента под номером " << searchNum << ", вот информация о нём:\n";
            printStudent(students + aydi);
            flagg++;
        }
        if (flagg == 2) {
            break;
        }
    }
}

void theBest(Student students[maxNum], int counter) {
    float maximus = sredBall(students, 0);
    for (int i(1); i < counter; i++) {
        float newBall = sredBall(students, i);
        if (newBall > maximus) {
            maximus = newBall;
        }
    }
    for (int cou(0); cou < counter; cou++) {
        float studBall = sredBall(students, cou);
        if (studBall == maximus) {
            int num = 1;
            cout << num << ". " << students[cou].secondName << " " << students[cou].name << " " << students[cou].dad << " " << studBall << "\n";
            num++;
        }
    }
}

void polGroup(Student students[maxNum], int counter) {
    cout << "Кого будем выводить?:\n1 - девочек\n2 - мальчиков\n";
    int userPol;
    cin >> userPol;
    int answer = 0;
    if (userPol == 1) {
        for (int i(0); i < counter; i++) {
            if (students[i].pol == 1) {
                answer++;
            }
        }
        cout << "\nСтудентов женского пола: " << answer;
    }
    else {
        for (int i(0); i < counter; i++) {
            if (students[i].pol == 0) {
                answer++;
            }
        }
        cout << "\nСтудентов мужского пола: " << answer;
    }
    
}

void printGroup(Student students[maxNum], int counter) {
    int userGr;
    cout << "\nВыберети группу, студентов которой Вы хотите вывести: ";
    cin >> userGr;
    for (int i(0); i < counter; i++) {
        if (students[i].group == userGr) {
            printStudent(students + i);
        }
    }
}

void printAll(Student students[maxNum], int count) {
    for (int per(0); per < count; per++)
    {
        printStudent(students + per);
    }
}

void changeStudent(Student students[maxNum], int counter) {
    int poradok;
    int chooseGroup;
    cout << "\nВведите группу, студента из которой будем менять: ";
    cin >> chooseGroup;
    cout << "\nВведите номер студента, которого будем менять: ";
    cin >> poradok;
    if (chooseGroup == 5376) {
        poradok += 28;
    }
    

    int user;
    cout << "Выберете параметр студента, который Вы хотите изменить:\n1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Пол\n5 - Айди\n6 - Номер группы\n7 - Оценки по одной из дисциплин\n0 - Выход\n";
    cin >> user;
    int fi = 0;
    int oi = 0;
    int ni = 0;
    int flaghok = 0;
    switch(user) {
    case 1:
        cout << "\nВведите новую фамилию: ";
        char newSec[50];
        cin >> newSec;

        while (newSec[fi] != '\0' && fi < 50) {
            students[poradok-1].secondName[fi] = newSec[fi];
            fi++;
        }
        students[poradok-1].secondName[fi] = '\0';
        break;

    case 2:
        cout << "\nВведите новое имя: ";
        char newName[50];
        cin >> newName;

        while (newName[ni] != '\0' && ni < 50) {
            students[poradok-1].name[ni] = newName[ni];
            ni++;
        }
        students[poradok-1].name[ni] = '\0';
        break;

    case 3:
        cout << "\nВведите новое отчество: ";
        char newDad[50];
        cin >> newDad;

        while (newDad[oi] != '\0' && oi < 50) {
            students[poradok-1].dad[oi] = newDad[oi];
            oi++;
        }
        students[poradok-1].dad[oi] = '\0';
        break;

    case 4:
        if (students[poradok - 1].pol) {
            students[poradok - 1].pol = 0;
        }
        else {
            students[poradok - 1].pol = 1;
        }
        break;

    case 5:
        cout << "\nВведите новый айди студента: ";
        int newId;
        cin >> newId;
        for (int i(0); i < counter; i++) {
            if (students[i].id == newId) {
                flaghok += 1;

            }
        }
        if (flaghok == 0) {
            students[poradok - 1].group = newId;
        }
        else {
            cout << "\nТакой номер уже есть!\n";
            break;
        }
        break;

    case 6:
        cout << "\nВведите новый номер группы: ";
        int newGroup;
        
        cin >> newGroup;
        students[poradok - 1].group = newGroup;
        break;

    case 7:
        cout << "Выберите дисциплиную, оценку по которой вы хотите исправить:\n1 - Матан\n2- Аиг\n3 - Программирование\n4 - Физика\n5 - Физкультура\n6 - Философия\n7 - Английский язык\n8 - Информатика\n";
        int userChoice;
        cin >> userChoice;
        cout << "\nВведите оценку, на которую вы хотите заменить текущую: ";
        int usersNote;
        cin >> usersNote;
        students[poradok - 1].notes[userChoice - 1] = usersNote;
        break;
    case 0:
        break;
    }
}

void sortirovka(Student students[maxNum], int counter) {
    cout << "\nНе получат степендию:\n\n";
    for (int i(0); i < counter; i++) {
        if (students[i].notes[0] == 2 || students[i].notes[1] <= 3 || students[i].notes[2] <= 3 || students[i].notes[3] <= 3 || students[i].notes[4] <= 3 || students[i].notes[5] <= 3 || students[i].notes[6] <= 3 || students[i].notes[7] <= 3) {
            printStudent(students + i);
        }
    }
    cout << "\nУчатся на хорошо и отлично:\n\n";
    for (int i(0); i < counter; i++) {
        if (students[i].notes[0] > 3 && students[i].notes[1] > 3 && students[i].notes[2] > 3 && students[i].notes[3] > 3 && students[i].notes[4] > 3 && students[i].notes[5] > 3 && students[i].notes[6] > 3 && students[i].notes[7] > 3 && sredBall(students, i) < 5) {
            printStudent(students + i);
        }
    }
    cout << "\nУчатся на отлично:\n\n";
    for (int i(0); i < counter; i++) {
        if (sredBall(students, i) == 5) {
            printStudent(students + i);
        }
    }

}

void makeStudent(Student students[maxNum], int counter) {
    char userFamily[50], userName[50], userDad[50];
    bool userPol;
    int userId, userGroup;
    int userNotes[8];
    int flags = 0;
    cout << "Вы решили создать новую запись о студенте!\nВведите Фамилию, Имя и Отчесвто студента:\n";
    cin >> userFamily >> userName >> userDad;
    cout << "\nВведите пол студента (1 - женский; 0 - мужской):\n";
    cin >> userPol;
    
    cout << "\nВведите группу студента:\n";
    cin >> userGroup;
    cout << "\nВведите номер студента:\n";
    cin >> userId;
    for (int i(0); i < counter; i++) {
        if (students[i].id == userId) {
            flags += 1;
        }
    }
    
    int groupOne = 0;
    int groupTwo = 0;
    for (int i(0); i < counter; i++) {
        if (students[i].group == 5372) {
            groupOne += 1;
        }
        else {
            groupTwo += 2;
        }
    }

    if (flags == 0) {
        userId += 0;
    }


    else {
        if (userGroup == 5376) {
            userId == groupTwo + 1;
        }
        else {
            userId == groupOne + 1;
        }
    }




    cout << "\nВведите оценки студента:\n";
    for (int i = 0; i < 8; i++) {
        cin >> userNotes[i];
    }

    int per = 0;

    while (userFamily[per] != '\0' && per < 50) {
        students[counter].secondName[per] = userFamily[per];
        per++;
    }
    students[counter].secondName[per] = '\0';
    per = 0;

    while (userName[per] != '\0' && per < 50) {
        students[counter].name[per] = userName[per];
        per++;
    }
    students[counter].name[per] = '\0';
    per = 0;

    while (userDad[per] != '\0' && per < 50) {
        students[counter].dad[per] = userDad[per];
        per++;
    }
    students[counter].dad[per] = '\0';

    students[counter].pol = userPol;
    students[counter].id = userId;
    students[counter].group = userGroup;
    for (int i(0); i < 8; i++) {
        students[counter].notes[i] = userNotes[i];
    }

    ofstream outFile("group.txt", ios::app);
    if (outFile.is_open()) {
        outFile << students[counter].secondName << " " << students[counter].name << " " << students[counter].dad << " " << students[counter].pol << "\n" << students[counter].id << "\n" << students[counter].group << "\n" << students[counter].notes[0] << " " << students[counter].notes[1] << " " << students[counter].notes[2] << " " << students[counter].notes[3] << " " << students[counter].notes[4] << " " << students[counter].notes[5] << " " << students[counter].notes[6] << " " << students[counter].notes[7] << "\n";
        outFile.close();
        cout << "Данные добавлены!" << std::endl;
    }
    counter++;
}

int main() {
    setlocale(LC_ALL, "");
    Student students[maxNum];
    int count = 0;

    ifstream inFile("group.txt");
    if (inFile.is_open()) {
        while (count < maxNum &&
            inFile >> students[count].secondName >>
            students[count].name >>
            students[count].dad >>
            students[count].pol >>
            students[count].id >>
            students[count].group >>
            students[count].notes[0] >>
            students[count].notes[1] >>
            students[count].notes[2] >>
            students[count].notes[3] >>
            students[count].notes[4] >>
            students[count].notes[5] >>
            students[count].notes[6] >>
            students[count].notes[7]){
            count++;
        }
        inFile.close();
    }

    int vybor;
    while (true) {
        cout << "Какой номер будем решать?:\nЗадание 1: Создание новой записи о студенте\nЗадание 2: Внесение изменений в уже имеющуюся запись\nЗадание 3: Вывод всех данных о студентах\nЗадание 4: Вывод информации обо всех студентах группы N\nЗадание 5: Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию\nЗадание 6: Вывод количества студентов мужского и женского пола\nЗадание 7: Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»\nЗадание 8: Вывод данных о студентах, имеющих номер в списке – k\n\n";
        cin >> vybor;
        switch (vybor) {
        case 1:
            cout << "\nЗадание 1: Создание новой записи о студенте\n";
            makeStudent(students, count);
            break;
        case 2:
            cout << "\nЗадание 2: Внесение изменений в уже имеющуюся запись\n";
            changeStudent(students, count);
            break;
        case 3:
            cout << "\nЗадание 3: Вывод всех данных о студентах\n";
            printAll(students, count);
            break;
        case 4:
            cout << "\nЗадание 4: Вывод информации обо всех студентах группы N\n";
            printGroup(students, count);
            break;
        case 5:
            cout << "\nЗадание 5: Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию\n";
            theBest(students, count);
            break;
        case 6:
            cout << "\nЗадание 6: Вывод количества студентов мужского и женского пола\n";
            polGroup(students, count);
            break;
        case 7:
            cout << "\nЗадание 7: Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»\n";
            sortirovka(students, count);
            break;
        case 8:
            cout << "\nЗадание 8: Вывод данных о студентах, имеющих номер в списке – k\n";
            printStudentByNum(students, count);
            break;
        case 0:
            return 0;
            break;
        }
    }
    

    //polGroup(students, count);
    //sortirovka(students, count);
    //theBest(students, count);
    //printAll(students, count);
    //printStudentByNum(students);
    //makeStudent(students, count);
    //changeStudent(students);
    //printStudent(students);
    //for (struct Student *p = &students; p < students + n; p++) {
    //    printStudent(*p);
        //cout << students[i].secondName << " " << students[i].name << " " << students[i].dad << " " << students[i].pol << " " << students[i].id << " "  << students[i].group << " " << students[i].math << " " << students[i].proga << " " << students[i].aig << " " << students[i].fizika << " " << students[i].fizra << " " << students[i].english << " " << students[i].phylos << " " << students[i].infa  <<"\n\n\n";
    //}

    return 0;
}
