#include <token.hh>

// Implementación de Token
Token::Token(size_t inicio, size_t fin) : inicio_(inicio), fin_(fin) {}

size_t Token::inicio() const { return inicio_; }

size_t Token::fin() const { return fin_; }

// Implementación de TokenOperador
TokenOperador::TokenOperador(size_t inicio, size_t fin, char operador)
    : Token(inicio, fin), operador_(operador) {}

char TokenOperador::operador() const { return operador_; }

bool TokenOperador::IsNumber() const { return false; }

bool TokenOperador::IsOperator() const { return true; }

bool TokenOperador::IsLeftParenthesis() const { return operador_ == '('; }

bool TokenOperador::IsRightParenthesis() const { return operador_ == ')'; }

int TokenOperador::GetPrecedence() const {
    switch (operador_) {
        case '*':
            return 0;
        case '+':
        case '-':
            return 1;
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Implementación de TokenNumero
TokenNumero::TokenNumero(size_t inicio, size_t fin, double valor)
    : Token(inicio, fin), valor_(valor) {}

double TokenNumero::valor() const { return valor_; }

bool TokenNumero::IsNumber() const { return true; }

bool TokenNumero::IsOperator() const { return false; }