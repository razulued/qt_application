#ifndef TOKEN_AUTH_H
#define TOKEN_AUTH_H
#include <QString>
#include <Qt>

bool check_user_password(QString str);

void validate_token(bool val);

bool get_validity_state();
QString get_user_name();
QString get_user_initials(void);
bool get_super_user();

#endif // TOKEN_AUTH_H
