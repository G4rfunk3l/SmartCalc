#include "calculator.h"

double m_proccesing(char* input_str, double x) {
  struct stack* operations = NULL;
  char symbol[256], temp_symbol[256], outstring[1000];
  int check = 1;
  double res = 0.0;
  check = is_correct_symbols(input_str, symbol);
  if (check) {
    check = is_correct_input(symbol);
    unary_between_brackets_processing(symbol, temp_symbol);
  }
  if (check) {
    check = outstring_processing(temp_symbol, outstring, operations);
  }
  if (check) {
    double stack_of_notion[1000];
    int stack_point = calculation_proccesing(outstring, stack_of_notion, x);
    res = stack_of_notion[stack_point - 1];
  } else {
    res = NAN;
  }
  return res;
}

int is_correct_symbols(char* instring, char* symbol) {
  /* Функция проверяет введенную строку на неизвестные символы, удаляет пробелы,
     вызывает function_processing возвращает результат проверки */
  int check = 1;
  int instring_point = 0;
  int symbol_point = 0;
  while (instring[instring_point] != '\0' && instring[instring_point] != '=') {
    if (instring[instring_point] != ' ') {
      char temp_symbol = function_processing(instring, &instring_point);
      if (temp_symbol) {
        if (temp_symbol == 1) {
          check = 0;
          break;
        }
        symbol[symbol_point] = temp_symbol;
        symbol_point++;
      }
    } else {
      instring_point++;
    }
  }
  symbol[symbol_point] = '\0';
  return check;
}

char function_processing(char* symbol, int* symbol_point) {
  /* Функция заменяет вызовы арифмитических функций на однобуквенную
     интерпретацию возвращает соответствующую однобуквенную интерпретацию в
     случае успеха либо код ошибки */
  char res = 0;
  res = function_checking(symbol, symbol_point, "mod", '%');
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "cos", 'c');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "sin", 's');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "tan", 't');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "acos", 'o');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "asin", 'i');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "atan", 'a');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "sqrt", 'q');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "ln", 'l');
  }
  if (res == 2) {
    res = function_checking(symbol, symbol_point, "log", 'g');
  }
  if (res == 2 && !is_number(symbol[*symbol_point]) &&
      !is_bracket(symbol[*symbol_point]) &&
      !is_operation_symbol(symbol[*symbol_point]) &&
      symbol[*symbol_point] != 'x') {
    res = 1;
  }
  if (res == 2) {
    res = symbol[*symbol_point];
    *symbol_point += 1;
  }
  return res;
}

char function_checking(const char* symbol, int* symbol_point,
                       char* function_calling, char expected_res) {
  /* Служебная функция для проверки части строки ввода на соответствие с
     шаблоном вызова арифмитической функции возвращает соответствующую
     однобуквенную интерпретацию арифмитической функции в случае успеха либо код
     ошибки */
  char res = 0;
  int len = strlen(function_calling);
  for (int i = 0; i < len; i++) {
    if (symbol[*symbol_point] != function_calling[i]) {
      res = 2;
    }
    *symbol_point += 1;
  }
  if (res != 2) {
    res = expected_res;
  } else {
    *symbol_point -= len;
  }
  return res;
}

int is_correct_input(char* symbol) {
  /* Функция проверяет корректность использования арифмитических функций и
     операций во входной строке и их взаимодействие с числами возвращает код
     ошибки */
  int check = 1;
  int count_of_brackets = 0;
  int symbol_point = 0;
  while (symbol[symbol_point] != '\0' && symbol[symbol_point] != '=') {
    if (symbol[symbol_point] == '(') {
      count_of_brackets++;
      if (symbol[symbol_point + 1] == ')') {
        count_of_brackets = 0;
        check = 0;
      }
    }
    if (symbol[symbol_point] == ')') {
      count_of_brackets--;
    }
    if (count_of_brackets < 0) {
      check = 0;
    }
    if ((is_number(symbol[symbol_point]) || symbol[symbol_point] == 'x') &&
        (symbol[symbol_point - 1] == ')' || symbol[symbol_point + 1] == '(')) {
      check = 0;
    }
    if (is_operation_symbol(symbol[symbol_point]) &&
        is_operation_symbol(symbol[symbol_point + 1])) {
      check = 0;
    }
    if (is_operation_symbol(symbol[symbol_point]) &&
        (symbol[symbol_point + 1] == '\0' || symbol[symbol_point + 1] == '=' ||
         symbol[symbol_point + 1] == ')')) {
      check = 0;
    }
    if (is_operation_symbol(symbol[symbol_point]) &&
        (symbol[symbol_point] != '-' && symbol[symbol_point] != '+') &&
        (symbol_point == 0 || symbol[symbol_point - 1] == '(')) {
      check = 0;
    }
    if (is_function_symbol(symbol[symbol_point]) &&
        symbol[symbol_point + 1] != '(') {
      check = 0;
    }
    if (symbol[symbol_point] == 'x') {
      if (!(symbol_point == 0 &&
            (symbol[symbol_point + 1] == '\0' ||
             is_operation_symbol(symbol[symbol_point + 1])))) {
        if (!is_operation_symbol(symbol[symbol_point - 1]) &&
            !is_operation_symbol(symbol[symbol_point + 1]) &&
            symbol[symbol_point - 1] != '(' &&
            symbol[symbol_point + 1] != ')') {
          check = 0;
        }
      }
    }
    if (check == 0) {
      break;
    }
    symbol_point++;
  }
  if (count_of_brackets != 0) {
    check = 0;
  }
  return check;
}

void unary_between_brackets_processing(const char* symbol, char* outstring) {
  /* Функция обрабатывает юнарный оператор между двумя открывающими скобками для
   * корректного знака у операции внутри скобки */
  int symbol_point = 0;
  int outstring_point = 0;
  while (symbol[symbol_point] != '\0' && symbol[symbol_point] != '=') {
    if ((symbol[symbol_point] == '(' &&
         (symbol[symbol_point + 1] == '-' || symbol[symbol_point + 1] == '+') &&
         symbol[symbol_point + 2] == '(') ||
        (symbol_point == 0 &&
         (symbol[symbol_point] == '-' || symbol[symbol_point] == '+') &&
         symbol[symbol_point + 1] == '(')) {
      char unary = 0;
      if (symbol_point == 0) {
        unary = symbol[symbol_point];
        outstring[outstring_point++] = unary;
      } else {
        unary = symbol[symbol_point + 1];
        outstring[outstring_point++] = '(';
        outstring[outstring_point++] = unary;
      }
      outstring[outstring_point++] = '1';
      outstring[outstring_point++] = '*';
      outstring[outstring_point++] = '(';
      if (symbol_point == 0) {
        symbol_point += 2;
      } else {
        symbol_point += 3;
      }
    } else {
      outstring[outstring_point++] = symbol[symbol_point++];
    }
  }
  outstring[outstring_point] = '\0';
}

int outstring_processing(char* symbol, char* outstring, stack* operations) {
  /* Функция переформатирует входную строку в постфиксный формат польской
   * нотации */
  int check = 1;
  int symbol_point = 0;
  int outstring_point = 0;
  while (symbol[symbol_point] != '\0' && symbol[symbol_point] != '=') {
    if (symbol[symbol_point] == ')') {
      while ((operations->stack_symbol) != '(') {
        outstring[outstring_point++] = cut_symbol_from_stack(&operations);
        outstring[outstring_point++] = ' ';
      }
      cut_symbol_from_stack(&operations);
    }
    check =
        numbers_processing(symbol, outstring, &symbol_point, &outstring_point);
    if (check) {
      if (symbol[symbol_point] == '(') {
        operations = push(operations, '(');
      }
      if (is_operation_symbol(symbol[symbol_point]) ||
          is_function_symbol(symbol[symbol_point])) {
        if (operations == NULL) {
          operations = push(operations, symbol[symbol_point]);
        } else {
          if (priority_of_symbols(operations->stack_symbol) <
              priority_of_symbols(symbol[symbol_point])) {
            operations = push(operations, symbol[symbol_point]);
          } else {
            while ((operations != NULL) &&
                   (priority_of_symbols(operations->stack_symbol) >=
                    priority_of_symbols(symbol[symbol_point]))) {
              outstring[outstring_point++] = cut_symbol_from_stack(&operations);
              outstring[outstring_point++] = ' ';
            }
            operations = push(operations, symbol[symbol_point]);
          }
        }
      }
      symbol_point++;
    } else {
      break;
    }
  }
  while (operations != NULL) {
    if (operations->stack_symbol != '(') {
      outstring[outstring_point++] = cut_symbol_from_stack(&operations);
      outstring[outstring_point++] = ' ';
    } else {
      cut_symbol_from_stack(&operations);
    }
  }
  outstring[outstring_point] = '\0';
  return check;
}

int numbers_processing(char* symbol, char* outstring, int* symbol_point,
                       int* outstring_point) {
  /* Служебная функция для работы с числами при переформатировании в постфиксный
   * формат польской нотации */
  int check = 1;
  char unary = 0;
  int temp_symbol_point = *symbol_point;
  int temp_outstring_point = *outstring_point;
  if ((symbol[temp_symbol_point] == '+' || symbol[temp_symbol_point] == '-') &&
      (temp_symbol_point == 0 || symbol[temp_symbol_point - 1] == '(')) {
    unary = symbol[temp_symbol_point];
    temp_symbol_point++;
  }
  if (is_number(symbol[temp_symbol_point])) {
    int dot_counter = 0;
    outstring[temp_outstring_point++] = symbol[temp_symbol_point];
    temp_symbol_point++;
    while (is_number(symbol[temp_symbol_point])) {
      if (symbol[temp_symbol_point] == '.') {
        dot_counter++;
      }
      if (dot_counter > 1) {
        check = 0;
        break;
      }
      outstring[temp_outstring_point++] = symbol[temp_symbol_point];
      temp_symbol_point++;
    }
    temp_symbol_point--;
    if (unary) {
      outstring[temp_outstring_point++] = unary;
    }
    outstring[temp_outstring_point++] = ' ';
  }
  if (symbol[temp_symbol_point] == 'x') {
    outstring[temp_outstring_point++] = symbol[temp_symbol_point];
    temp_symbol_point++;
    if (unary) {
      outstring[temp_outstring_point++] = unary;
    }
    outstring[temp_outstring_point++] = ' ';
  }
  *symbol_point = temp_symbol_point;
  *outstring_point = temp_outstring_point;
  return check;
}

int calculation_proccesing(char* outstring, double* stack_of_notion, double x) {
  /* Функция выполняет арифмитические вычисления с строкой в постфиксном формате
     польской нотации возвращает указатель на последнюю заполненную ячейку стэка
     с выполненными расчетами */
  int outstring_point = 0;
  int stack_point = 0;
  while (outstring[outstring_point] != '\0') {
    switch (outstring[outstring_point]) {
      case '\0':
      case '=':
      case ' ':
        break;
      case 'x':
        stack_of_notion[stack_point++] = x;
        break;
      case '+':
        stack_of_notion[stack_point - 2] =
            stack_of_notion[stack_point - 2] + stack_of_notion[stack_point - 1];
        stack_point--;
        break;
      case '-':
        stack_of_notion[stack_point - 2] =
            stack_of_notion[stack_point - 2] - stack_of_notion[stack_point - 1];
        stack_point--;
        break;
      case '*':
        stack_of_notion[stack_point - 2] =
            stack_of_notion[stack_point - 2] * stack_of_notion[stack_point - 1];
        stack_point--;
        break;
      case '/':
        stack_of_notion[stack_point - 2] =
            stack_of_notion[stack_point - 2] / stack_of_notion[stack_point - 1];
        stack_point--;
        break;
      case '%':
        stack_of_notion[stack_point - 2] = fmod(
            stack_of_notion[stack_point - 2], stack_of_notion[stack_point - 1]);
        stack_point--;
        break;
      case '^':
        stack_of_notion[stack_point - 2] = pow(
            stack_of_notion[stack_point - 2], stack_of_notion[stack_point - 1]);
        stack_point--;
        break;
      case 'c':
        stack_of_notion[stack_point - 1] =
            cos(stack_of_notion[stack_point - 1]);
        break;
      case 's':
        stack_of_notion[stack_point - 1] =
            sin(stack_of_notion[stack_point - 1]);
        break;
      case 't':
        stack_of_notion[stack_point - 1] =
            tan(stack_of_notion[stack_point - 1]);
        break;
      case 'o':
        stack_of_notion[stack_point - 1] =
            acos(stack_of_notion[stack_point - 1]);
        break;
      case 'i':
        stack_of_notion[stack_point - 1] =
            asin(stack_of_notion[stack_point - 1]);
        break;
      case 'a':
        stack_of_notion[stack_point - 1] =
            atan(stack_of_notion[stack_point - 1]);
        break;
      case 'q':
        stack_of_notion[stack_point - 1] =
            sqrt(stack_of_notion[stack_point - 1]);
        break;
      case 'l':
        stack_of_notion[stack_point - 1] =
            log(stack_of_notion[stack_point - 1]);
        break;
      case 'g':
        stack_of_notion[stack_point - 1] =
            log10(stack_of_notion[stack_point - 1]);
        break;
      default:
        stack_of_notion[stack_point++] = atof(&outstring[outstring_point]);
        while (outstring[outstring_point] != ' ' &&
               outstring[outstring_point] != '\0') {
          if (outstring[outstring_point] == '-') {
            stack_of_notion[stack_point - 1] *= (-1);
          }
          outstring_point++;
        }
    }
    outstring_point++;
    stack_of_notion[stack_point] = '\0';
  }
  return stack_point;
}

stack* push(struct stack* head_of_stack, char symbol) {
  /* Служебная функция push записывает на стек (на веpшину котоpого указывает
     head_of_stack) символ symbol; возвpащает указатель на новую веpшину стека
   */
  struct stack* new_head;
  if ((new_head = malloc(sizeof(struct stack))) == NULL) {
    puts("нет памяти");
    exit(-1);
  }
  new_head->stack_symbol = symbol;
  new_head->next = head_of_stack;
  return new_head;
}

char cut_symbol_from_stack(struct stack** head_of_stack) {
  /* Служебная функция cut_symbol_from_stack удаляет символ с веpшины стека,
     возвpащает удаляемый символ, изменяет указатель на веpшину стека */
  struct stack* new_head;
  char symbol;
  if (*head_of_stack == NULL) {
    return '\0';
  }
  new_head = *head_of_stack;
  symbol = new_head->stack_symbol;
  *head_of_stack = new_head->next;
  free(new_head);
  return symbol;
}

int priority_of_symbols(char symbol) {
  /* Служебная функция priority_of_symbols возвpащает пpиоpитет аpифм. опеpации
   */
  switch (symbol) {
    case 'c':
    case 's':
    case 't':
    case 'o':
    case 'i':
    case 'a':
    case 'q':
    case 'l':
    case 'g':
      return 5;
    case '^':
      return 4;
    case '*':
    case '/':
    case '%':
      return 3;

    case '-':
    case '+':
      return 2;

    case '(':
      return 1;
  }
  return 0;
}

int is_number(char symbol) {
  /* Служебная функция для проверки является ли символ числом */
  int res = 0;
  if ((symbol >= '0' && symbol <= '9') || symbol == '.') {
    res = 1;
  }
  return res;
}

int is_bracket(char symbol) {
  /* Служебная функция для проверки является ли символ скобкой */
  int res = 0;
  if (symbol == '(' || symbol == ')') {
    res = 1;
  }
  return res;
}

int is_operation_symbol(char symbol) {
  /* Служебная функция для проверки является ли символ знаком арифмитической
   * операции */
  int res = 0;
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
      symbol == '%' || symbol == '^') {
    res = 1;
  }
  return res;
}

int is_function_symbol(char symbol) {
  /* Служебная функция для проверки является ли символ однобуквенным
   * интерпретатором арифмитической функции */
  int res = 0;
  if (symbol == 'c' || symbol == 's' || symbol == 't' || symbol == 'o' ||
      symbol == 'i' || symbol == 'a' || symbol == 'q' || symbol == 'l' ||
      symbol == 'g') {
    res = 1;
  }
  return res;
}
