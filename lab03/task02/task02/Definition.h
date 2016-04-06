#pragma once

static const unsigned LEN_FN_COMMAND = 3;
static const unsigned LEN_VAR_COMMAND = 4;
static const unsigned LEN_LET_COMMAND = 4;
static const unsigned LEN_PRINT_COMMAND = 6;
enum class GetError
{
	noValue,		// нет значения
	valueIsFound	// значение найдено
};

enum class WasError
{
	idNameNotCorrect,		// переменная введена некорректно
	numberNotCorrect,		// число введено некорректно
	FnUsesIdName,			// существует функция с именем переменной
	varUsesIdName,			// существует переменная с именем функции
	valueSecondIdNotFound,	// не найдено значение второго идентификатора
	valueThirdIdNotFound,	// не найдено значение третьего идентификатора
	AllOk					// все норм
};

enum class OperandType
{
	Add,	// сложение																
	Sub,	// вычитание
	Div,	// деление
	Mul		// умножение
};

struct GetValInfo
{
	GetError wasError;
	double value;
};
 
struct GetFnInfo
{
	GetError wasError;
	bool twoOperators;
	std::string firstVal;
	OperandType operand;
	std::string secondVal;
};


static const std::map<std::string, OperandType> OPERAND_MAP
{
	{ "+", OperandType::Add },
	{ "-", OperandType::Sub },
	{ "/", OperandType::Div },
	{ "*", OperandType::Mul }
};