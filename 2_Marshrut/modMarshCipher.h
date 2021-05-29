/**  @file
* *  @author Шикин В.В.
* *  @version 1.0.0
* *  @date 29.05.2021
* *  @copyright ИБСТ ПГУ
* *  @brief Заголовочный файл для модуля modMarshCipher
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
using namespace std;
/*** @class modAlphaCipher
* * @author Шикин В.В.
* * @date 29.05.20
* * @file modAlphaCipher.h
* * @brief Шифрование методом Гронсфельда
* * @details Для зашифрования и расшифрования сообщения
предназначны методы encrypt и decrypt соответственно.*
Текст на обработку передается в качестве параметра.
* * @warnings Реализация только для английского языка!*/
class modMarshCipher
{
private:
    int key; ///<ключ
    /**
    * @brief Метод класса, проверяющий текст на валидность.
    * @param [in] s Открытый текст на английском языке.
    * @return result
    * */
    std::string getValidOpenText(const std::string & s);
    /**
    * @brief Метод класса, проверяющий расшифрованный текст
    на валидность.
    * @param [in] s Зашифрованный текст на английском языке.
    * @return result
    * */
    std::string getValidCipherText(const std::string & s);
    /**
    * @brief Метод класса, проверяющий ключ на валидность.
    * @param [in] s Ключ.
    * @return result
    * */
    std::string getValidKey(const std::string & s);
public:
    modMarshCipher()=delete; ///<запретим конструктор без параметров
    /**
    * @brief Конструктор для создания объекта, хранящего в
    себе ключ шифрования.
    * * @param [in] text Открытый текст на английском языке.
    * @warnings Текст не должен быть пустой строкой. Текст не
    должен содержать пробелы. В тексте могут содержаться
    знаки препинания и цифры.
    * */
    modMarshCipher(const std::string& key1); ///<конструктор для установки ключа
    /**
    * * @brief Зашифрование
    * * @param [in] text Открытый текст на английском языке.
    Текст не должен быть пустой строкой.* Текст может
    содержать пробелы.
    * * В тексте могут содержаться знаки препинания и цифры.
    * * @return result Зашифрованный текст.
    * */
    std::string encrypt(const std::string& open_text); ///<зашифрование
    /**
    * * @brief Расшифрование
    * * @param [in] text Зашифрованный текст на английском
    языке. Текст не должен быть пустой строкой.* Текст не
    должен содержать пробелы.
    * * В тексте не могут содержаться знаки препинания и цифры.
    * * @return result Зашифрованный текст.
    * */
    std::string decrypt(const std::string& cipher_text);//<расшифрование
};
/*** @class cipher_error
* * @author Шикин В.В.
* * @date 29.05.20
* * @file modMarshCipher.h
* * @brief Класса-исключение
* * @details Для возбуждения исключений
*/
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
