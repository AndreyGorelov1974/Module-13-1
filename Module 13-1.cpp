/*Задача 1
Что нужно сделать
Необходимо из заданного пользователем вектора удалить число X.

Как работает программа
Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
Пользователь вводит n целых чисел, которые заполняют вектор.
Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны заданному значению.
В конце программы необходимо вывести итоговое состояние вектора.
Пример выполнения
Input vector size: 5
Input numbers: 1 3 3 5 1
Input number to delete: 3
Result: 1 5 1

Пояснение

Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1 и потом число 3. В векторе должны остаться числа 1, 5, 1, которые надо вывести на экран.

Что оценивается
Не удалено лишних элементов.
Все элементы, которые необходимо удалить, удалены.
Для удаления элементов из вектора использована функция pop_back()
Удаления из вектора совершены in-place, т.е. при удалении из вектора не используются дополнительные структуры данных или переменные.
Решение использует только один вектор.*/

#include <iostream>
#include <vector>

int main()
{
	int vectorSize;
	std::cout << "Input vector size: ";
	std::cin >> vectorSize;
	std::vector<int> userVector(vectorSize);

	std::cout << "Input numbers: ";
	int elements = 0;

	for (int i = 0; i < userVector.size(); ++i)
	{
		std::cin >> elements;
		userVector[i] = elements;
	}

	std::cout << "Input number to delete: ";
	int deleteValue = 0;
	std::cin >> deleteValue;
	for (uint32_t i = 0; i < userVector.size(); ++i)
	{
		if (userVector[i] == deleteValue) {
			//при помощи обмена перемещаем элемент в конец вектора
			for (std::size_t j = i; j < userVector.size() - 1; ++j) {
				std::swap(userVector[j], userVector[j + 1]);
			}
			userVector.pop_back();
			//уменьшаем счётчик цикла что бы не пропустить следующий элемент
			--i;
		}
	}

	std::cout << "Result: ";
	for (int i = 0; i < userVector.size(); ++i)
	{
		std::cout << userVector[i] << " ";
	}

}