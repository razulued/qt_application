#ifndef ASA_CONF_STRING_H
#define ASA_CONF_STRING_H
#include <Qt>
#include "configuration.h"

void init_out_string();
QString build_out_string(configuration_id *conf);
void get_plant_config();
void output_control_toggle(uint id);
void output_token_transfer(bool val);
void synch_config_string();
void output_op_mode(QString id, QString val);

QString get_id_state(QString str_id);
void synch_output_state();

QString get_config_string();
uint motor_state(QString motor_control);
void set_calibration(QString str);
void emergency_stop(bool val);

void add_to_one_time_transmit(QString str);

void get_calibrations_and_set_config_str();
void save_calibrations();

void demo_set_percentaje(int per);

#endif // ASA_CONF_STRING_H
