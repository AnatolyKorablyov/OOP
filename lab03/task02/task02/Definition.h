#pragma once

static const unsigned LEN_FN_COMMAND = 3;
static const unsigned LEN_VAR_COMMAND = 4;
static const unsigned LEN_LET_COMMAND = 4;
static const unsigned LEN_PRINT_COMMAND = 6;

enum class FoundValueInfo
{
	noValue,		// ��� ��������
	valueIsFound	// �������� �������
};

enum class WasError
{
	idNameNotCorrect,		// ���������� ������� �����������
	numberNotCorrect,		// ����� ������� �����������
	FnUsesIdName,			// ���������� ������� � ������ ����������
	varUsesIdName,			// ���������� ���������� � ������ �������
	valueSecondIdNotFound,	// �� ������� �������� ������� ��������������
	valueThirdIdNotFound,	// �� ������� �������� �������� ��������������
	AllOk					// ��� ����
};

enum class OperandType
{
	Add,	// ��������																
	Sub,	// ���������
	Div,	// �������
	Mul		// ���������
};

struct GetValInfo
{
	FoundValueInfo valueInfo;
	double value;
};
 
struct GetFnInfo
{
	FoundValueInfo valueInfo;
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