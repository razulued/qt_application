#ifndef ASA_CONF_STRING_H
#define ASA_CONF_STRING_H
#include <Qt>
#include "configuration.h"

void init_plat_config();
QString build_string(configuration_id *conf);
void get_plant_config();
void output_control_toggle(uint id);
void output_token_transfer(bool val);
void synch_config_string();
void output_op_mode(uint id, QString val);

QString get_id_state(uint id);
void synch_output_state();

QString get_config_string();
uint motor_state(QString motor_control);

#endif // ASA_CONF_STRING_H
