#ifndef TOKEN_AUTH_H
#define TOKEN_AUTH_H
#include <QString>
#include <Qt>

bool check_user_password(QString str);

void validate_token(bool val);

bool get_validity_state();

#endif // TOKEN_AUTH_H
