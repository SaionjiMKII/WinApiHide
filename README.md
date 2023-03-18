# WinApiHide
Этот проект демонстрирует метод скрытия вызовов WinAPI функций путем вызова их по хеш-значениям. Он может быть полезен для обфускации кода или создания приложений, которые осложняют статический анализ.

# Особенности
 Вычисление хеша имени функции с использованием алгоритма djb2
 Получение адреса функции по хеш-значению
 Пример вызова MessageBoxA из библиотеки user32.dll по хеш-значению
 
# Как использовать
1. Клонируйте этот репозиторий
2. Откройте исходный код проекта (например, WinApiHide.cpp) в вашей любимой среде разработки или текстовом редакторе.
3. Адаптируйте код для вызова других WinAPI функций, заменив имя функции и её хеш-значение в соответствии с вашими требованиями.
4. Скомпилируйте и запустите проект, используя компилятор, совместимый с C++.

=======================================================================================================================================================================

This project demonstrates a method of hiding WinAPI function calls by calling them by hash values. It can be useful for obfuscating code or creating applications that complicate static analysis.

# Features
 Calculating the hash of the function name using the djb2 algorithm
 Getting the function address by hash value
 Example of calling MessageBoxA from the library user32.dll by hash value
 
# How to use
1. Clone this repository
2. Open the source code of the project (for example, WinApiHide.cpp ) in your favorite development environment or text editor.
3. Adapt the code to call other WinAPI functions by replacing the function name and its hash value according to your requirements.
4. Compile and run the project using a C++ compatible compiler.
