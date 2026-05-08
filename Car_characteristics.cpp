
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;
struct cars {
    char name[100];
    char clas;
    int year;
    int Power;
    int Length; //длина
    int Width; //Ширина
    int Height; //Высота
    int Wheelbase; //Колесная база
    float mileage; //пробег в тыс. км
    float engine_displacement; //объем двигателя
};

void setColor(int color) { // для красоты
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}

int stoi(char str[]);
void mein_menu(cars c10[]);
void garage(cars c10[]);
void print_c10(cars c10[]);
void race(cars c10[]);
void garage(cars c10[]);
void compare_cars(cars c10[]);
void statistics(cars c10[]);
void filter_by_class(cars c10[]);

int main()
{
    setlocale(LC_ALL, "");
    system("chcp 65001");
    
    cars c10[10] = {
            {"Toyota Camry", 'D', 2020, 181, 4885, 1840, 1455, 2825, 45.2, 2.5},
            {"BMW 3 Series", 'D', 2019, 184, 4709, 1827, 1442, 2851, 60.0, 2.0},
            {"Mercedes C-Class", 'D', 2018, 156, 4686, 1810, 1442, 2840, 70.5, 1.6},
            {"Audi A4", 'D', 2021, 190, 4762, 1847, 1431, 2820, 30.0, 2.0},
            {"Volkswagen Passat", 'D', 2017, 150, 4767, 1832, 1456, 2791, 85.0, 1.8},
            {"Ford Focus", 'C', 2016, 125, 4358, 1823, 1484, 2648, 95.0, 1.6},
            {"Honda Civic", 'C', 2020, 158, 4656, 1799, 1416, 2700, 40.0, 2.0},
            {"Hyundai Elantra", 'C', 2021, 147, 4675, 1825, 1430, 2720, 25.0, 2.0},
            {"Kia Sportage", 'J', 2019, 150, 4485, 1855, 1635, 2670, 55.0, 2.0},
            {"Nissan Qashqai", 'J', 2018, 144, 4394, 1806, 1590, 2646, 65.0, 2.0}
    };
    
    mein_menu(c10);

    return 0;
}

int stoi(char str[]) {
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {  // проверяем что символ является цифрой
            return -1;
        }
        num = num * 10 + (str[i] - '0'); // преобразуем символ в число
    }

    return num;
}

void mein_menu(cars c10[]) {
    while (true) {
        system("cls");
        setColor(14);
        cout << "\n========================================\n"
            << "                 МЕНЮ\n"
            << "========================================\n\n";
        setColor(7);

        setColor(11);
        cout << "  1. ";
        setColor(15);
        cout << "Гараж (выбрать машину)\n";

        setColor(11);
        cout << "  2. ";
        setColor(15);
        cout << "Характеристики всех машин\n";

        setColor(11);
        cout << "  3. ";
        setColor(15);
        cout << "Гонки\n";

        setColor(11);
        cout << "  4. ";
        setColor(15);
        cout << "Сравнение двух машин\n";

        setColor(11);
        cout << "  5. ";
        setColor(15);
        cout << "Статистика каталога\n";

        setColor(11);
        cout << "  6. ";
        setColor(15);
        cout << "Фильтрация по классу\n";

        setColor(9);
        cout << "Выберите пункт: ";
        setColor(7);

        char input[100];
        cin.getline(input, 100);

        int choice = stoi(input);

        if (choice == -1) {
            setColor(12);
            cout << "Ошибка: вводите только числа!\n";
            setColor(7);
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            garage(c10);
            break;
        case 2:
            system("cls");
            print_c10(c10);
            system("pause");
            break;
        case 3:
            race(c10);
            break;
        case 4:
            compare_cars(c10);
            break;
        case 5:
            statistics(c10);
            break;
        case 6:
            filter_by_class(c10);
            break;
        default:
            setColor(12);
            cout << "Нет такого пункта!\n";
            setColor(7);
            system("pause");
            break;
        }
    }
}

void garage(cars c10[]) {
    while (true) {
        system("cls");
        setColor(14);
        cout << "\n========== ГАРАЖ ==========\n\n";
        setColor(7);

        for (int i = 0; i < 10; i++) {
            setColor(15);
            cout << i + 1 << ". " << c10[i].name << endl;
        }

        setColor(11);
        cout << "0. ";
        setColor(15);
        cout << "Назад в меню\n\n";

        setColor(9);
        cout << "Выберите машину: ";
        setColor(7);

        char input[100];
        cin.getline(input, 100);

        int choice = stoi(input);

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > 10) {
            setColor(12);
            cout << "Неверный выбор!\n";
            setColor(7);
            system("pause");
            continue;
        }

        int car_index = choice - 1;
        system("cls");

        setColor(14);
        cout << "\n========== ДЕТАЛИ АВТОМОБИЛЯ ==========\n\n";
        setColor(15);
        cout << "Модель: " << c10[car_index].name << endl;

        setColor(7);
        cout << "Класс: ";
        setColor(10);
        cout << c10[car_index].clas << endl;

        setColor(7);
        cout << "Год выпуска: ";
        setColor(9);
        cout << c10[car_index].year << endl;

        setColor(7);
        cout << "Мощность: ";
        setColor(12);
        cout << c10[car_index].Power << " л.с." << endl;

        setColor(7);
        cout << "Длина: ";
        setColor(11);
        cout << c10[car_index].Length << " мм" << endl;

        setColor(7);
        cout << "Ширина: ";
        setColor(11);
        cout << c10[car_index].Width << " мм" << endl;

        setColor(7);
        cout << "Высота: ";
        setColor(11);
        cout << c10[car_index].Height << " мм" << endl;

        setColor(7);
        cout << "Колесная база: ";
        setColor(13);
        cout << c10[car_index].Wheelbase << " мм" << endl;

        setColor(7);
        cout << "Пробег: ";
        setColor(10);
        cout << c10[car_index].mileage << " тыс.км" << endl;

        setColor(7);
        cout << "Объем двигателя: ";
        setColor(9);
        cout << c10[car_index].engine_displacement << " л" << endl;

        setColor(7);
        cout << "\n";
        system("pause");
    }
}

void race(cars c10[]) {
    srand(time(0));
    system("cls");

    setColor(14);
    cout << "\n========== ВЫБОР МАШИНЫ ДЛЯ ГОНКИ ==========\n\n";
    setColor(7);
    
    for (int i = 0; i < 10; i++) {
        setColor(15);
        cout << i + 1 << ". " << c10[i].name << endl;
    }
    
    setColor(9);
    cout << "\nВыберите вашу машину: ";
    setColor(7);
    
    char input[100];
    cin.getline(input, 100);
    
    int car1 = stoi(input) - 1;
    
    if (car1 < 0 || car1 > 9) {
        setColor(12);
        cout << "Неверный выбор!\n";
        setColor(7);
        system("pause");
        return;
    }
    
    int car2 = rand() % 10;
    while (car2 == car1) {
        car2 = rand() % 10; // перевыбор машины чтобф не гоняли две одинаковых
    }
    
    system("cls");

    setColor(14);
    cout << "\n=============== ГОНКА ===============\n\n";
    setColor(7);

    float pos1 = 0, pos2 = 0;
    float distance = 100;
    int steed_race = 100; // по стандарту 10 но можно ставить 100 если хотите чтобы гонка была не такой быстрой

    setColor(15);
    cout << "Участники: " << endl;
    setColor(10);
    cout << "1. " << c10[car1].name << "\n";
    setColor(13);
    cout << "2. " << c10[car2].name << "\n\n";

    setColor(7);
    cout << "Начало гонки!\n";
    system("pause");
    system("cls");
    int offset = 0;
    while (pos1 < distance && pos2 < distance) {
        // Скорость зависит от мощности
        float speed1 = (rand() % (c10[car1].Power / steed_race + 2));
        float speed2 = (rand() % (c10[car2].Power / steed_race + 2));

        pos1 += speed1;
        pos2 += speed2;

        if (pos1 > distance) pos1 = distance;
        if (pos2 > distance) pos2 = distance;
        // АНИМАЦИИ
//  _____
// /|_||_\`.__
//(   _    _ _\
//=`-(_)--(_)-'


       

        cout << "\n";
        setColor(10);
        cout << "   1.\n";
        for (int i = 0; i < pos1; i++) cout << " ";
        cout << "  ____\n";
        for (int i = 0; i < pos1; i++) { setColor(8); cout << "-"; }
        setColor(10);
        cout << " /|_||_\`.__ "; for (int i = 0; i < distance-pos1-12+20; i++) { setColor(8); cout << "-"; }
        cout << "\n";
        setColor(10);
        for (int i = 0; i < pos1; i++) cout << " ";
        cout << "(   _    _ _\\\n";
        for (int i = 0; i < pos1; i++) {
            setColor(8); {
                if ((i + offset) % 8 < 4)
                    cout << "="; else cout << " ";
            }
        }
        setColor(10);
        cout << "=`-(_)--(_)-'";
        for (int i = 0; i < distance - pos1 - 13 + 20; i++) {
            setColor(8); {
                if ((i + offset) % 8 < 4)
                    cout << "="; else cout << " ";
            }
        }
        cout << "\n\n";
        for (int i = 0; i < distance + 20; i++) cout << "-";
        cout << "\n";
        setColor(10);
        cout << "   " << (pos1 * 100 / distance) << "%\n";

        cout << "\n";
        setColor(13);

        cout << "   2.\n";
        
        for (int i = 0; i < pos2; i++) cout << " ";
        cout << "  ____\n";
        for (int i = 0; i < pos2; i++) { setColor(8); cout << "-"; }
        setColor(13);
        cout << " /|_||_\`.__ "; for (int i = 0; i < distance - pos2 - 12 + 20; i++) { setColor(8); cout << "-"; }
        cout << "\n";
        setColor(13);
        for (int i = 0; i < pos2; i++) cout << " ";
        cout << "(   _    _ _\\\n";
        for (int i = 0; i < pos2; i++) {
            setColor(8); {
                if ((i + offset) % 8 < 4)
                    cout << "="; else cout << " ";
            }
        }
        setColor(13);
        cout << "=`-(_)--(_)-'";
        for (int i = 0; i < distance - pos2 - 13 + 20; i++) {
            setColor(8); {
                if ((i + offset) % 8 < 4)
                    cout << "="; else cout << " ";
            }
        }
        cout << "\n\n";
        for (int i = 0; i < distance + 20; i++) cout << "-";
        cout << "\n";
        
        
        setColor(13);
        cout << "   " << (pos2 * 100 / distance) << "%\n";

        setColor(7);
        offset+=20;
        Sleep(150); // можно поменять на 300 чтобы не было дерганое но будет медленее
        system("cls");
    }

    system("cls");
    setColor(14);
    cout << "\n=============== РЕЗУЛЬТАТ ГОНКИ ===============\n\n";
    setColor(7);

    if (pos1 > pos2) {
        setColor(10);
        cout << "ВЫ ВЫИГРАЛИ! ";
		setColor(9);
        cout << c10[car1].name << " - ПОБЕДИТЕЛЬ!\n";
        cout << c10[car2].name << " - Машина противника\n";

    }
    else if (pos2 > pos1) {
        setColor(12);
        cout << "ВЫ ПРОИГРАЛИ!\n";
        setColor(9);
        cout << "Победитель: " << c10[car2].name << "\n";
        cout << "Выша машина: " << c10[car1].name << "\n\n";
    }
    else {
        setColor(14);
        cout << "⭐ НИЧЬЯ! Оба автомобиля финишировали одновременно!\n\n";
    }

    setColor(7);
    system("pause");
    system("cls");
    print_c10(c10);
}


void compare_cars(cars c10[]) {
    while (true) {
        system("cls");
        setColor(14);
        cout << "\n========== СРАВНЕНИЕ ДВУХ МАШИН ==========\n\n";
        setColor(7);

        cout << "Список машин:\n\n";
        for (int i = 0; i < 10; i++) {
            setColor(15);
            cout << i + 1 << ". " << c10[i].name << endl;
        }
        
        cout << "0. Назад в меню\n\n";

        setColor(9);
        cout << "Выберите первую машину (1-10): ";
        setColor(7);
        char input1[100];
        cin.getline(input1, 100);
        int car1 = stoi(input1) - 1;

        if (car1 < 0 || car1 > 9) {
            if (car1 == -1) {
                return;
            }
            setColor(12);
            cout << "Неверный выбор!\n";
            setColor(7);
            system("pause");
            continue;
        }

        setColor(9);
        cout << "Выберите вторую машину (1-10): ";
        setColor(7);
        char input2[100];
        cin.getline(input2, 100);
        int car2 = stoi(input2) - 1;

        if (car2 < 0 || car2 > 9 || car1 == car2) {
            setColor(12);
            cout << "Неверный выбор или выбрана одна машина!\n";
            setColor(7);
            system("pause");
            continue;
        }

        system("cls");
        setColor(14);
        cout << "\n========== СРАВНЕНИЕ ==========\n\n";

        setColor(7);
        cout << "Параметр";
        cout << "\t\t\t";
        setColor(10);
        cout << c10[car1].name;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].name << endl;
        setColor(7);
        cout << "======================================================================\n";

        cout << "Класс\t\t\t";
        setColor(10);
        cout << c10[car1].clas;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].clas << endl;

        cout << "   ";
        setColor(10);
        cout << c10[car1].year;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].year << endl;

        cout << "Мощность (л.с.)\t\t";
        setColor(10);
        cout << c10[car1].Power;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].Power << endl;

        cout << "Длина (мм)\t\t";
        setColor(10);
        cout << c10[car1].Length;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].Length << endl;

        cout << "Ширина (мм)\t\t";
        setColor(10);
        cout << c10[car1].Width;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].Width << endl;

        cout << "Высота (мм)\t\t";
        setColor(10);
        cout << c10[car1].Height;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].Height << endl;

        cout << "Колесная база (мм)\t";
        setColor(10);
        cout << c10[car1].Wheelbase;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].Wheelbase << endl;

        cout << "Пробег (тыс.км)\t\t";
        setColor(10);
        cout << c10[car1].mileage;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].mileage << endl;

        cout << "Объем двигателя (л)\t";
        setColor(10);
        cout << c10[car1].engine_displacement;
        setColor(7);
        cout << " | ";
        setColor(13);
        cout << c10[car2].engine_displacement << endl;

        setColor(7);
        cout << "\n";
        system("pause");
    }
}

void statistics(cars c10[]) {
    system("cls");
    setColor(14);
    cout << "\n========== СТАТИСТИКА КАТАЛОГА ==========\n\n";
    setColor(7);
    
    int max_power = 0, max_power_idx = 0;
    int max_year = 0, max_year_idx = 0;
    int min_year = 9999, min_year_idx = 0;
    float max_mileage = 0, max_mileage_idx = 0;
    float min_mileage = 99999, min_mileage_idx = 0;
    
    for (int i = 0; i < 10; i++) {
        if (c10[i].Power > max_power) {
            max_power = c10[i].Power;
            max_power_idx = i;
        }
        if (c10[i].year > max_year) {
            max_year = c10[i].year;
            max_year_idx = i;
        }
        if (c10[i].year < min_year) {
            min_year = c10[i].year;
            min_year_idx = i;
        }
        if (c10[i].mileage > max_mileage) {
            max_mileage = c10[i].mileage;
            max_mileage_idx = i;
        }
        if (c10[i].mileage < min_mileage) {
            min_mileage = c10[i].mileage;
            min_mileage_idx = i;
        }
    }
    
    setColor(11);
    cout << "Самая мощная машина:\n";
    setColor(12);
    cout << "  " << c10[max_power_idx].name << " - " << max_power << " л.с.\n\n";
    
    setColor(11);
    cout << "Самая новая машина:\n";
    setColor(9);
    cout << "  " << c10[max_year_idx].name << " - " << max_year << " год\n\n";
    
    setColor(11);
    cout << "Самая старая машина:\n";
    setColor(9);
    cout << "  " << c10[min_year_idx].name << " - " << min_year << " год\n\n";
    
    setColor(11);
    cout << "Машина с наибольшим пробегом:\n";
    setColor(10);
    cout << "  " << c10[(int)max_mileage_idx].name << " - " << c10[(int)max_mileage_idx].mileage << " тыс.км\n\n";
    
    setColor(11);
    cout << "Машина с наименьшим пробегом:\n";
    setColor(10);
    cout << "  " << c10[(int)min_mileage_idx].name << " - " << c10[(int)min_mileage_idx].mileage << " тыс.км\n\n";
    
    setColor(7);
    system("pause");
}

void filter_by_class(cars c10[]) {
    while (true) {
        system("cls");
        setColor(14);
        cout << "\n========== ФИЛЬТРАЦИЯ ПО КЛАССУ ==========\n\n";
        setColor(7);

        cout << "Доступные классы:\n";
        cout << "  1 - D (Седаны)\n";
        cout << "  2 - C (Компактные)\n";
        cout << "  3 - J (Кроссоверы)\n\n";

        setColor(9);
        cout << "Выберите класс (1-3): ";
        setColor(7);
        char input[100];
        cin.getline(input, 100);

        int choice = stoi(input);
        char chosen_class;

        if (choice == 1) {
            chosen_class = 'D';
        }
        else if (choice == 2) {
            chosen_class = 'C';
        }
        else if (choice == 3) {
            chosen_class = 'J';
        }
        else if (choice == 0) {
            return;
        }
        else {
            setColor(12);
            cout << "Неверный выбор!\n";
            setColor(7);
            system("pause");
            continue;
        }

        system("cls");
        setColor(14);
        cout << "\n========== МАШИНЫ КЛАССА " << chosen_class << " ==========\n\n";
        setColor(7);

        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (c10[i].clas == chosen_class) {
                count++;
                setColor(15);
                cout << count << ". " << c10[i].name;
                setColor(10);
                cout << " [" << c10[i].clas << "]" << endl;

                setColor(7);
                cout << "   Год: ";
                setColor(9);
                cout << c10[i].year;

                setColor(7);
                cout << " | Мощность: ";
                setColor(12);
                cout << c10[i].Power << " л.с.";

                setColor(7);
                cout << " | Размеры: ";
                setColor(11);
                cout << c10[i].Length << "x" << c10[i].Width << "x" << c10[i].Height;
                setColor(7);
                cout << " мм" << endl;

                cout << "   База: ";
                setColor(13);
                cout << c10[i].Wheelbase;
                setColor(7);
                cout << " мм | Пробег: ";
                setColor(10);
                cout << c10[i].mileage;
                setColor(7);
                cout << " тыс.км | Объем: ";
                setColor(9);
                cout << c10[i].engine_displacement;
                setColor(7);
                cout << " л" << endl << endl;
            }
        }

        if (count == 0) {
            setColor(12);
            cout << "Машин этого класса не найдено!\n";
            setColor(7);
        }
        else {
            setColor(11);
            cout << "Всего машин: " << count << endl;
            setColor(7);
        }

        cout << "\n";
        system("pause");
    }
}

void print_c10(cars c10[]) {
    cout << endl;
    setColor(14);
    cout << "--------  ХАРАКТЕРИСТИКИ АВТО --------\n\n";
    setColor(7);

    for (int i = 0; i < 10; i++) {
        setColor(15);
        cout << i + 1 << ". " << c10[i].name;
        setColor(10);
        cout << " [" << c10[i].clas << "]" << endl;

        setColor(7);
        cout << "   Год: ";
        setColor(9);
        cout << c10[i].year;

        setColor(7);
        cout << " | Мощность: ";
        setColor(12);
        cout << c10[i].Power << " л.с.";

        setColor(7);
        cout << " | Размеры: ";
        setColor(11);
        cout << c10[i].Length << "x" << c10[i].Width << "x" << c10[i].Height;
        setColor(7);
        cout << " мм" << endl;

        cout << "   База: ";
        setColor(13);
        cout << c10[i].Wheelbase;
        setColor(7);
        cout << " мм | Пробег: ";
        setColor(10);
        cout << c10[i].mileage;
        setColor(7);
        cout << " тыс.км | Объем: ";
        setColor(9);
        cout << c10[i].engine_displacement;
        setColor(7);
        cout << " л" << endl;

        cout << endl;
    }
}
