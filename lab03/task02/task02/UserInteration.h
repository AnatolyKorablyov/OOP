#pragma once
#include "Calculator.h"

using namespace std;

void PrintAllError(const WasError & wasError);
void CommandSetVar(CCalculator & calc, const string & mainRequest, size_t posStart);
void CommandSetLet(CCalculator & calc, const string & mainRequest, size_t posStart);
void CommandSetFn(CCalculator & calc, const string & mainRequest, size_t posStart);
void CommandPrint(CCalculator & calc, const string & mainRequest, size_t posStart);
void CommandPrintvars(CCalculator & calc);
void CommandPrintfns(CCalculator & calc);
void HandlerCommands(CCalculator & calc, const string & mainRequest);

void Mathematician();