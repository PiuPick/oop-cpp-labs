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

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    bool isRunning = true;
    char userChoice;

    cout << "=== Практическая работа №1 ===\n";

    while (isRunning)
    {
        cout << "\nНажмите клавишу для проверки функции:\n";
        cout << " i - Принадлежность числа интервалу\n";
        cout << " m - Минимальное значение из двух аргументов\n";
        cout << " o - Количество знаков числа\n";
        cout << " t - Информация по примитивным типам\n";
        cout << " c - Числовой код символа\n";
        cout << " p - Проверка числа на простоту\n";
        cout << " a - Тестовые сценарии\n";
        cout << " e - Выход из программы\n";
        cout << "> Ваш выбор: ";

        cin >> userChoice;

        switch (userChoice)
        {
        case 'i':
            {
                double x, bottom, top;
                cout << "Введите x: ";
                if (!(cin >> x)) break;
                cout << "Введите bottom: ";
                if (!(cin >> bottom)) break;
                cout << "Введите top: ";
                if (!(cin >> top)) break;

                if (bottom > top)
                {
                    double tmp = bottom;
                    bottom = top;
                    top = tmp;
                }

                cout << (belongsToInterval(x, bottom, top) ? "Принадлежит" : "Не принадлежит")
                    << " интервалу [" << bottom << ", " << top << "]\n";
                break;
            }

        case 'm':
            {
                char typeChoice;
                cout << "Выберите тип (i - int, f - float): ";
                cin >> typeChoice;

                if (typeChoice == 'i')
                {
                    int a, b;
                    cout << "Введите два целых числа: ";
                    if (!(cin >> a >> b)) break;
                    cout << "Минимальное: " << minValue(a, b) << "\n";
                }
                else if (typeChoice == 'f')
                {
                    float a, b;
                    cout << "Введите два вещественных числа: ";
                    if (!(cin >> a >> b)) break;
                    cout << "Минимальное: " << minValue(a, b) << "\n";
                }
                else
                {
                    cout << "Ошибка выбора типа\n";
                }
                break;
            }

        case 'o':
            {
                long long num;
                cout << "Введите целое число: ";
                if (!(cin >> num)) break;
                cout << "Количество знаков: " << order(num) << "\n";
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
                cout << "Код символа: " << getLetterCode(symbol) << "\n";
                break;
            }

        case 'p':
            {
                int num;
                cout << "Введите целое число: ";
                if (!(cin >> num)) break;
                cout << (isPrime(num) ? "Простое" : "Не простое") << "\n";
                break;
            }

        case 'a':
            {
                cout << "=== Тестовые сценарии ===\n";
                cout << "belongsToInterval(5,1,10): "
                    << belongsToInterval(5, 1, 10) << "\n";
                cout << "minValue(3,7): " << minValue(3, 7) << "\n";
                cout << "minValue(2.5f,1.5f): "
                    << minValue(2.5f, 1.5f) << "\n";
                cout << "order(-2147483648): "
                    << order(INT_MIN) << "\n";
                cout << "isPrime(29): " << isPrime(29) << "\n";
                break;
            }

        case 'e':
            isRunning = false;
            break;

        default:
            cout << "Неизвестная команда\n";
        }

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода\n";
        }
    }

    return 0;
}

bool belongsToInterval(double x, double bottom, double top)
{
    return x >= bottom && x <= top;
}

int minValue(int a, int b)
{
    return a < b ? a : b;
}

float minValue(float a, float b)
{
    return a < b ? a : b;
}

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

void showTypeInfo()
{
    cout << "char: size=" << sizeof(char)
        << " min=" << CHAR_MIN
        << " max=" << CHAR_MAX << "\n";
    cout << "short: size=" << sizeof(short)
        << " min=" << SHRT_MIN
        << " max=" << SHRT_MAX << "\n";
    cout << "int: size=" << sizeof(int)
        << " min=" << INT_MIN
        << " max=" << INT_MAX << "\n";
    cout << "long: size=" << sizeof(long)
        << " min=" << LONG_MIN
        << " max=" << LONG_MAX << "\n";
    cout << "long long: size=" << sizeof(long long)
        << " min=" << LLONG_MIN
        << " max=" << LLONG_MAX << "\n";
}

int getLetterCode(char symbol)
{
    return static_cast<unsigned char>(symbol);
}

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
