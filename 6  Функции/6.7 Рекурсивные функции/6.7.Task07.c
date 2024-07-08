/*Подвиг 7* (обратный подвигу 6). Напишите программу, которая читает закодированную строку с помощью азбуки Морзе. Коды разделены между собой пробелом. Необходимо ее раскодировать, используя азбуку Морзе из предыдущего занятия:
| A | .-   | J | .--- | S | ...   | 2 | ..--- |
|---|------|---|------|---|-------|---|-------|
| B | -... | K | -.-  | T | -     | 3 | ...-- |
| C | -.-. | L | .-.. | U | ..-   | 4 | ....- |
| D | -..  | M | --   | V | ...-  | 5 | ..... |
| E | .    | N | -.   | W | .--   | 6 | -.... |
| F | ..-. | O | ---  | X | -..-  | 7 | --... |
| G | --.  | P | .--. | Y | -.--  | 8 | ---.. |
| H | .... | Q | --.- | Z | --..  | 9 | ----. |
| I | ..   | R | .-.  | 1 | .---- | 0 | ----- |
Пробел    -...-
Полученное сообщение (строку) вывести в консоль.
P. S. Декодирование лучше реализовать в виде отдельной функции, которой передается формируемая строка, исходная строка и массив азбуки Морзе.
Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.7.7*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void strtomorse(char *in, char *out);
void morsetostr(char *in, char *out);
char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";

char *morse[] = {".-", ".---",	"...", "..---", "-...", "-.-", "-", "...--", "-.-.", ".-..", "..-", "....-", 
  "-..", "--", "...-", ".....", ".", "-.", ".--", "-....", "..-.", "---", "-..-", "--...",
  "--.", ".--.", "-.--", "---..", "....", "--.-", "--..", "----.", "..", ".-.", ".----", "-----", "-...-"};


int main(void) {
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    char out[100] = "";
    morsetostr(str, out); 
    puts(out);
    return 0;
}

/* ПЕРЕВОДИТ МАССИВ СИМВОЛОВ В АЗБУКУ МОРЗЕ */
void strtomorse(char *in, char *out){
  size_t length_in = strlen(in);
  size_t length_symbols = strlen(symbols);
  for(int i = 0; i < length_in; ++i){
    for(int j = 0; j < length_symbols; ++j)
      if(toupper(in[i]) == symbols[j])
        strcat(out, morse[j]);
    strcat(out, " ");
  }
}

/* ПЕРЕВОДИТ СТРОКУ АЗБУКИ МОРЗЕ В МАССИВ СИМВОЛОВ */
void morsetostr(char *in, char *out){
  char temp[100][8] = {0};                               
  int k = 0;
  int j = 0;                                               // Сколько всего будет букв на выходе
  for(int i = 0; in[i] != '\0' && in[i] != '\n' && k < 100; ++i, ++j){
    int k = 0;
    for(; in[i + k] != ' ' && in[i + k] != '\0'; ++k)     // Здесь бежим до пробелов или конца строки
      temp[j][k] = in[i + k];
    i += k;                                               // Обработка символа закончена, переходим к следующему
  }
    
  // Заполняем выходной массив, сравнивая содержимое элементов temp с элементами morse
  for(int i = 0; i < j; ++i)
    for(int y = 0; y < 37; ++y)
      if(strcmp(temp[i], morse[y]) == 0) out[i] = symbols[y];
}