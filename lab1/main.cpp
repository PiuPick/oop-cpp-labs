#include <iostream> // Библиотека для ввода-вывода
#include <climits> // Библиотека для целочисленных типов (INT_MIN, INT_MAX и тд.)
#include <windows.h> // Для установки кодировки консоли

using namespace std;

bool belongsToInterval(double x, double bottom, double top);
int minValue(int a, int b);
float minValue(float a, float b);
int order(long long number);
void showTypeInfo();
int getLetterCode(char symbol);
bool isPrime(int n);
bool isValidInput();

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Практическая работа №1 ===" << endl;

    bool isRunning = true;

    while (isRunning)
    {
        cout << "\nНажмите клавишу для проверки функции:" << endl;
        cout << " i - Принадлежность числа интервалу" << endl;
        cout << " m - Минимальное значение из двух аргументов" << endl;
        cout << " o - Количество знаков числа" << endl;
        cout << " t - Информация по примитивным типам" << endl;
        cout << " c - Числовой код символа" << endl;
        cout << " p - Проверка числа на простоту" << endl;
        cout << " a - Тестовые сценарии" << endl;
        cout << " e - Выход из программы" << endl;
        cout << "> Ваш выбор: ";

        char userChoice;
        cin >> userChoice;
        isValidInput();

        switch (userChoice)
        {
        case 'i':
            {
                double x, bottom, top;

                cout << "Введите x=";
                cin >> x;
                isValidInput();

                cout << "Введите bottom=";
                cin >> bottom;
                isValidInput();

                cout << "Введите top=";
                cin >> top;
                isValidInput();

                if (bottom > top)
                {
                    double tmp = bottom;
                    bottom = top;
                    top = tmp;
                }

                cout << "Число x=" << x
                << (belongsToInterval(x, bottom, top) ? " принадлежит" : " не принадлежит")
                << " интервалу [" << bottom << ", " << top << "]" << endl;
                break;
            }

        case 'm':
            {
                char typeChoice;
                cout << "Выберите тип (i - int, f - float): ";
                cin >> typeChoice;
                isValidInput();

                if (typeChoice == 'i')
                {
                    int a, b;
                    cout << "Введите целое число a=";
                    cin >> a;
                    isValidInput();

                    cout << "Введите целое число b=";
                    cin >> b;
                    isValidInput();

                    cout << "Минимальное из чисел: " << minValue(a, b) << endl;
                }
                else if (typeChoice == 'f')
                {
                    float a, b;
                    cout << "Введите вещественное число a=";
                    cin >> a;
                    isValidInput();

                    cout << "Введите вещественное число b=";
                    cin >> b;
                    isValidInput();

                    cout << "Минимальное из чисел: " << minValue(a, b) << endl;
                }
                else
                    cout << "Ошибка выбора типа" << endl;
                break;
            }

        case 'o':
            {
                long long num;
                cout << "Введите целое число num=";
                cin >> num;
                cout << "Количество знаков: " << order(num) << endl;
                break;
            }

        case 't':
            showTypeInfo();
            break;

        case 'c':
            {
                char symbol;
                cout << "Введите символ: ";
                cin >> symbol;
                cout << "Код символа: " << getLetterCode(symbol) << endl;
                break;
            }

        case 'p':
            {
                int num;
                cout << "Введите целое число num=";
                cin >> num;
                cout << (isPrime(num) ? "Простое" : "Не простое") << endl;
                break;
            }

        case 'a':
            {
                cout << "=== Тестовые сценарии ===" << endl;
                cout << "belongsToInterval(5,1,10): "
                    << belongsToInterval(5, 1, 10) << endl;
                cout << "minValue(3,7): " << minValue(3, 7) << endl;
                cout << "minValue(2.5f,1.5f): "
                    << minValue(2.5f, 1.5f) << endl;
                cout << "order(-2147483648): "
                    << order(INT_MIN) << endl;
                cout << "isPrime(29): " << isPrime(29) << endl;
                break;
            }

        case 'e':
            isRunning = false;
            break;

        default:
            cout << "Неизвестная команда\n";
        }
    }

    return 0;
}

// Функция проверки принадлежности числа интервалу [bottom, top]
bool belongsToInterval(double x, double bottom, double top)
{
    return x >= bottom && x <= top;
}

// Функции нахождения минимального значения из двух аргументов
int minValue(int a, int b)
{
    return a < b ? a : b;
}

// Перегрузка для типа float
float minValue(float a, float b)
{
    return a < b ? a : b;
}

// Функция подсчёта количества знаков в числе
int order(long long number)
{
    if (number == 0) return 1;

    int count = 0;
    while (number != 0)
    {
        ++count;
        number /= 10;
    }
    return count;
}

// Функция вывода информации по примитивным типам
void showTypeInfo()
{
    cout << "char: size=" << sizeof(char)
        << " min=" << CHAR_MIN
        << " max=" << CHAR_MAX << endl;
    cout << "short: size=" << sizeof(short)
        << " min=" << SHRT_MIN
        << " max=" << SHRT_MAX << endl;
    cout << "int: size=" << sizeof(int)
        << " min=" << INT_MIN
        << " max=" << INT_MAX << endl;
    cout << "long: size=" << sizeof(long)
        << " min=" << LONG_MIN
        << " max=" << LONG_MAX << endl;
    cout << "long long: size=" << sizeof(long long)
        << " min=" << LLONG_MIN
        << " max=" << LLONG_MAX << endl;
}

// Функция получения числового кода символа
int getLetterCode(char symbol)
{
    return static_cast<unsigned char>(symbol);
}

// Функция проверки числа на простоту
bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i < n; i += 2)
        if (n % i == 0) return false;
    return true;
}

// Функция проверки корректности ввода
bool isValidInput()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Некорректный ввод. Попробуйте снова." << endl;
        return false;
    }
    return true;
}