#include "parameters.h"
#include <QtDebug>
char* gen_stat_ecuid;
unsigned int gen_stat_prodtype;
unsigned int gen_stat_msgtype;
unsigned int gen_stat_swver;
unsigned int gen_stat_hwver;
unsigned int gen_stat_txseqnum;
unsigned int gen_stat_sysuptime;
unsigned int gen_stat_gpslat;
unsigned int gen_stat_gpslong;
unsigned int gen_stat_gprs_rssi;
unsigned int gen_stat_batlevel;
char* gen_stat_debugmsg;
unsigned int gen_stat_numresets;
unsigned int gen_stat_databyaddr;
unsigned int gen_stat_gprs_ber;
unsigned int gen_stat_authlevel;
unsigned int gen_parm_sec_challenge;
unsigned int car_stat_shit_level;
unsigned int car_stat_sens_ph_in;
unsigned int car_stat_sens_sst_in;
unsigned int car_stat_sens_caudal_in;
unsigned int car_stat_diag_mot1;
unsigned int car_stat_mot1_volt12;
unsigned int car_stat_mot1_volt23;
unsigned int car_stat_mot1_volt13;
unsigned int car_stat_mot1_amp1;
unsigned int car_stat_mot1_amp2;
unsigned int car_stat_mot1_amp3;
unsigned int car_stat_mot1_freq;
unsigned int car_stat_mot1_cosphi;
unsigned int car_stat_mot1_pfac;
unsigned int car_stat_diag_mot2;
unsigned int car_stat_mot2_volt12;
unsigned int car_stat_mot2_volt23;
unsigned int car_stat_mot2_volt13;
unsigned int car_stat_mot2_amp1;
unsigned int car_stat_mot2_amp2;
unsigned int car_stat_mot2_amp3;
unsigned int car_stat_mot2_freq;
unsigned int car_stat_mot2_cosphi;
unsigned int car_stat_mot2_pfac;
unsigned int car_stat_diag_warn_ind;
unsigned int car_stat_sens_turbidez_in;
unsigned int car_parm_off_level;
unsigned int car_parm_setp_lev1;
unsigned int car_parm_setp_lev2;
unsigned int car_parm_setp_lev3;
unsigned int car_parm_time_alt_max;
unsigned int car_ctrl_target_opmode;
unsigned int car_ctrl_drive_mot1;
unsigned int car_ctrl_drive_mot2;
unsigned int car_ctrl_drive_warn_ind;
unsigned int rea_stat_o2_sens_1_level;
unsigned int rea_stat_o2_sens_2_level;
unsigned int rea_stat_diag_mot1;
unsigned int rea_stat_mot1_volt12;
unsigned int rea_stat_mot1_volt23;
unsigned int rea_stat_mot1_volt13;
unsigned int rea_stat_mot1_amp1;
unsigned int rea_stat_mot1_amp2;
unsigned int rea_stat_mot1_amp3;
unsigned int rea_stat_mot1_freq;
unsigned int rea_stat_mot1_cosphi;
unsigned int rea_stat_mot1_pfac;
unsigned int rea_stat_diag_mot2;
unsigned int rea_stat_mot2_volt12;
unsigned int rea_stat_mot2_volt23;
unsigned int rea_stat_mot2_volt13;
unsigned int rea_stat_mot2_amp1;
unsigned int rea_stat_mot2_amp2;
unsigned int rea_stat_mot2_amp3;
unsigned int rea_stat_mot2_freq;
unsigned int rea_stat_mot2_cosphi;
unsigned int rea_stat_mot2_pfac;
unsigned int rea_stat_diag_mot3;
unsigned int rea_stat_mot3_volt12;
unsigned int rea_stat_mot3_volt23;
unsigned int rea_stat_mot3_volt13;
unsigned int rea_stat_mot3_amp1;
unsigned int rea_stat_mot3_amp2;
unsigned int rea_stat_mot3_amp3;
unsigned int rea_stat_mot3_freq;
unsigned int rea_stat_mot3_cosphi;
unsigned int rea_stat_mot3_pfac;
unsigned int rea_stat_sens_presion_1;
unsigned int rea_parm_o2_level_MIN;
unsigned int rea_parm_o2_level_MAX;
unsigned int rea_parm_time_on_min;
unsigned int rea_parm_time_alt_max;
unsigned int rea_parm_prog_time_on;
unsigned int rea_parm_prog_time_off;
unsigned int rea_ctrl_target_opmode;
unsigned int rea_ctrl_drive_mot1;
unsigned int rea_ctrl_drive_mot2;
unsigned int rea_ctrl_drive_mot3;
unsigned int cla_stat_press_val;
unsigned int cla_stat_diag_NC_valve1;
unsigned int cla_parm_press_thresh_OPT;
unsigned int cla_parm_press_thresh_MAX;
unsigned int cla_ctrl_target_opmode;
unsigned int cla_ctrl_drive_NC_valve1;
unsigned int misc_stat_sens_ph_out;
unsigned int misc_stat_sens_sst_out;
unsigned int misc_stat_sens_caudal_out;
unsigned int misc_stat_sens_turbidez_out;
unsigned int misc_stat_sens_presion_2;
unsigned int misc_stat_sens_presion_3;


parameter_config_t  all_parameters[]=
{
    {0,		false,	"gen_stat_ecuid",				&gen_stat_ecuid,                   TYPE_STRING},
    {1,		false,	"gen_stat_prodtype",	        &gen_stat_prodtype,                TYPE_HEX},
    {2,		false,	"gen_stat_msgtype",		        &gen_stat_msgtype,                 TYPE_HEX},
    {3,		false,	"gen_stat_swver",		        &gen_stat_swver,                   TYPE_HEX},
    {4,		false,	"gen_stat_hwver",		        &gen_stat_hwver,                   TYPE_HEX},
    {5,		false,	"gen_stat_txseqnum",		    &gen_stat_txseqnum,                TYPE_HEX},
    {6,		false,	"gen_stat_sysuptime",	        &gen_stat_sysuptime,               TYPE_HEX},
    {7,		false,	"gen_stat_gpslat",		        &gen_stat_gpslat,                  TYPE_DECIMAL},
    {8,		false,	"gen_stat_gpslong",		        &gen_stat_gpslong,                 TYPE_DECIMAL},
    {9,		false,	"gen_stat_gprs_rssi",           &gen_stat_gprs_rssi,               TYPE_HEX},
    {10,	false,	"gen_stat_batlevel",            &gen_stat_batlevel,                TYPE_HEX},
    {11,	false,	"gen_stat_debugmsg",            &gen_stat_debugmsg,                TYPE_STRING },
    {12,	false,	"gen_stat_numresets",           &gen_stat_numresets,               TYPE_HEX},
    {13,	false,	"gen_stat_databyaddr",          &gen_stat_databyaddr,              TYPE_HEX},
    {15,	false,	"gen_stat_gprs_ber",            &gen_stat_gprs_ber,                TYPE_HEX},
    {22,	false,	"gen_stat_authlevel",           &gen_stat_authlevel,               TYPE_HEX},
    {23,	false,	"gen_parm_sec_challenge",       &gen_parm_sec_challenge,           TYPE_HEX},
    {40,	false,	"ND",                           &car_stat_shit_level,              TYPE_HEX},
    {41,	false,	"car_stat_sens_ph_in",          &car_stat_sens_ph_in,              TYPE_HEX},
    {42,	false,	"car_stat_sens_sst_in",         &car_stat_sens_sst_in,             TYPE_HEX},
    {43,	false,	"Q",                            &car_stat_sens_caudal_in,          TYPE_HEX},
    {44,	false,	"car_stat_diag_mot1",           &car_stat_diag_mot1,               TYPE_HEX},
    {45,	true,	"Vp",                           &car_stat_mot1_volt12,             TYPE_HEX},
    {46,	false,	"car_stat_mot1_volt23",         &car_stat_mot1_volt23,             TYPE_HEX},
    {47,	false,	"car_stat_mot1_volt13",         &car_stat_mot1_volt13,             TYPE_HEX},
    {48,	false,	"Ap",                           &car_stat_mot1_amp1,               TYPE_HEX},
    {49,	false,	"car_stat_mot1_amp2",           &car_stat_mot1_amp2,               TYPE_HEX},
    {50,	false,	"car_stat_mot1_amp3",           &car_stat_mot1_amp3,               TYPE_HEX},
    {51,	false,	"car_stat_mot1_freq",           &car_stat_mot1_freq,               TYPE_HEX},
    {52,	false,	"car_stat_mot1_cosphi",         &car_stat_mot1_cosphi,             TYPE_HEX},
    {53,	true,	"FP",                           &car_stat_mot1_pfac,               TYPE_HEX},
    {54,	false,	"car_stat_diag_mot2",           &car_stat_diag_mot2,               TYPE_HEX},
    {55,	false,	"car_stat_mot2_volt12",         &car_stat_mot2_volt12,             TYPE_HEX},
    {56,	false,	"car_stat_mot2_volt23",         &car_stat_mot2_volt23,             TYPE_HEX},
    {57,	false,	"car_stat_mot2_volt13",         &car_stat_mot2_volt13,             TYPE_HEX},
    {58,	false,	"car_stat_mot2_amp1",           &car_stat_mot2_amp1,               TYPE_HEX},
    {59,	false,	"car_stat_mot2_amp2",           &car_stat_mot2_amp2,               TYPE_HEX},
    {60,	false,	"car_stat_mot2_amp3",           &car_stat_mot2_amp3,               TYPE_HEX},
    {61,	false,	"car_stat_mot2_freq",           &car_stat_mot2_freq,               TYPE_HEX},
    {62,	false,	"car_stat_mot2_cosphi",         &car_stat_mot2_cosphi,             TYPE_HEX},
    {63,	false,	"car_stat_mot2_pfac",           &car_stat_mot2_pfac,               TYPE_HEX},
    {64,	false,	"car_stat_diag_warn_ind",       &car_stat_diag_warn_ind,           TYPE_HEX},
    {65,	false,	"car_stat_sens_turbidez_in",    &car_stat_sens_turbidez_in,        TYPE_HEX},
    {70,	false,	"car_parm_off_level",           &car_parm_off_level,               TYPE_HEX},
    {71,	false,	"car_parm_setp_lev1",           &car_parm_setp_lev1,               TYPE_HEX},
    {72,	false,	"car_parm_setp_lev2",           &car_parm_setp_lev2,               TYPE_HEX},
    {73,	false,	"car_parm_setp_lev3",           &car_parm_setp_lev3,               TYPE_HEX},
    {74,	false,	"car_parm_time_alt_max",        &car_parm_time_alt_max,            TYPE_HEX},
    {80,	false,	"car_ctrl_target_opmode",       &car_ctrl_target_opmode,           TYPE_HEX},
    {81,	false,	"car_ctrl_drive_mot1",          &car_ctrl_drive_mot1,              TYPE_HEX},
    {82,	false,	"car_ctrl_drive_mot2",          &car_ctrl_drive_mot2,              TYPE_HEX},
    {83,	false,	"car_ctrl_drive_warn_ind",      &car_ctrl_drive_warn_ind,          TYPE_HEX},
    {90,	false,	"OD",                           &rea_stat_o2_sens_1_level,         TYPE_HEX},
    {91,	false,	"rea_stat_o2_sens_2_level",     &rea_stat_o2_sens_2_level,         TYPE_HEX},
    {92,	false,	"rea_stat_diag_mot1",           &rea_stat_diag_mot1,               TYPE_HEX},
    {93,	false,	"Vp",                           &rea_stat_mot1_volt12,             TYPE_HEX},
    {94,	false,	"rea_stat_mot1_volt23",         &rea_stat_mot1_volt23,             TYPE_HEX},
    {95,	false,	"rea_stat_mot1_volt13",         &rea_stat_mot1_volt13,             TYPE_HEX},
    {96,	false,	"Ap",                           &rea_stat_mot1_amp1,               TYPE_HEX},
    {97,	false,	"rea_stat_mot1_amp2",           &rea_stat_mot1_amp2,               TYPE_HEX},
    {98,	false,	"rea_stat_mot1_amp3",           &rea_stat_mot1_amp3,               TYPE_HEX},
    {99,	false,	"rea_stat_mot1_freq",           &rea_stat_mot1_freq,               TYPE_HEX},
    {100,	false,	"rea_stat_mot1_cosphi",         &rea_stat_mot1_cosphi,             TYPE_HEX},
    {101,	false,	"FP",                           &rea_stat_mot1_pfac,               TYPE_HEX},
    {102,	false,	"rea_stat_diag_mot2",           &rea_stat_diag_mot2,               TYPE_HEX},
    {103,	false,	"rea_stat_mot2_volt12",         &rea_stat_mot2_volt12,             TYPE_HEX},
    {104,	false,	"rea_stat_mot2_volt23",         &rea_stat_mot2_volt23,             TYPE_HEX},
    {105,	false,	"rea_stat_mot2_volt13",         &rea_stat_mot2_volt13,             TYPE_HEX},
    {106,	false,	"rea_stat_mot2_amp1",           &rea_stat_mot2_amp1,               TYPE_HEX},
    {107,	false,	"rea_stat_mot2_amp2",           &rea_stat_mot2_amp2,               TYPE_HEX},
    {108,	false,	"rea_stat_mot2_amp3",           &rea_stat_mot2_amp3,               TYPE_HEX},
    {109,	false,	"rea_stat_mot2_freq",           &rea_stat_mot2_freq,               TYPE_HEX},
    {110,	false,	"rea_stat_mot2_cosphi",         &rea_stat_mot2_cosphi,             TYPE_HEX},
    {111,	false,	"rea_stat_mot2_pfac",           &rea_stat_mot2_pfac,               TYPE_HEX},
    {112,	false,	"rea_stat_diag_mot3",           &rea_stat_diag_mot3,               TYPE_HEX},
    {113,	false,	"rea_stat_mot3_volt12",         &rea_stat_mot3_volt12,             TYPE_HEX},
    {114,	false,	"rea_stat_mot3_volt23",         &rea_stat_mot3_volt23,             TYPE_HEX},
    {115,	false,	"rea_stat_mot3_volt13",         &rea_stat_mot3_volt13,             TYPE_HEX},
    {116,	false,	"rea_stat_mot3_amp1",           &rea_stat_mot3_amp1,               TYPE_HEX},
    {117,	false,	"rea_stat_mot3_amp2",           &rea_stat_mot3_amp2,               TYPE_HEX},
    {118,	false,	"rea_stat_mot3_amp3",           &rea_stat_mot3_amp3,               TYPE_HEX},
    {119,	false,	"rea_stat_mot3_freq",           &rea_stat_mot3_freq,               TYPE_HEX},
    {120,	false,	"rea_stat_mot3_cosphi",         &rea_stat_mot3_cosphi,             TYPE_HEX},
    {121,	false,	"rea_stat_mot3_pfac",           &rea_stat_mot3_pfac,               TYPE_HEX},
    {122,	false,	"rea_stat_sens_presion_1",      &rea_stat_sens_presion_1,          TYPE_HEX},
    {126,	false,	"rea_parm_o2_level_MIN",        &rea_parm_o2_level_MIN,            TYPE_HEX},
    {127,	false,	"rea_parm_o2_level_MAX",        &rea_parm_o2_level_MAX,            TYPE_HEX},
    {128,	false,	"rea_parm_time_on_min",         &rea_parm_time_on_min,             TYPE_HEX},
    {129,	false,	"rea_parm_time_alt_max",        &rea_parm_time_alt_max,            TYPE_HEX},
    {130,	false,	"rea_parm_prog_time_on",        &rea_parm_prog_time_on,            TYPE_HEX},
    {131,	false,	"rea_parm_prog_time_off",       &rea_parm_prog_time_off,           TYPE_HEX},
    {135,	false,	"rea_ctrl_target_opmode",       &rea_ctrl_target_opmode,           TYPE_HEX},
    {136,	false,	"rea_ctrl_drive_mot1",          &rea_ctrl_drive_mot1,              TYPE_HEX},
    {137,	false,	"rea_ctrl_drive_mot2",          &rea_ctrl_drive_mot2,              TYPE_HEX},
    {138,	false,	"rea_ctrl_drive_mot3",          &rea_ctrl_drive_mot3,              TYPE_HEX},
    {145,	false,	"ND",                           &cla_stat_press_val,               TYPE_HEX},
    {146,	false,	"cla_stat_diag_NC_valve1",      &cla_stat_diag_NC_valve1,          TYPE_HEX},
    {150,	false,	"cla_parm_press_thresh_OPT",    &cla_parm_press_thresh_OPT,        TYPE_HEX},
    {151,	false,	"cla_parm_press_thresh_MAX",    &cla_parm_press_thresh_MAX,        TYPE_HEX},
    {155,	false,	"cla_ctrl_target_opmode",       &cla_ctrl_target_opmode,           TYPE_HEX},
    {156,	false,	"cla_ctrl_drive_NC_valve1",     &cla_ctrl_drive_NC_valve1,         TYPE_HEX},
    {160,	false,	"pH",                           &misc_stat_sens_ph_out,            TYPE_HEX},
    {161,	false,	"SST",                          &misc_stat_sens_sst_out,           TYPE_HEX},
    {162,	false,	"Q",                            &misc_stat_sens_caudal_out,        TYPE_HEX},
    {163,	false,	"Turbidez",                     &misc_stat_sens_turbidez_out,      TYPE_HEX},
    {165,	false,	"P",                            &misc_stat_sens_presion_2,         TYPE_HEX},
    {166,	false,	"misc_stat_sens_presion_3",     &misc_stat_sens_presion_3,         TYPE_HEX},
};
#define SIZE_OF_TABLE   (sizeof(all_parameters)/sizeof (parameter_config_t))
void InitRandomParameters()
{
    unsigned int i;

    unsigned int *uint_ptr;

    for(i = 0; i < SIZE_OF_TABLE; i++)
    {
        if(TYPE_HEX == all_parameters[i].type)
        {
            uint_ptr = (unsigned int *)all_parameters[i].param;
            *uint_ptr = (unsigned int)qrand() % 50;
            qDebug() << "Param: "<< all_parameters[i].name <<*uint_ptr;
        }
    }
}

int getParamIndex(unsigned int id)
{
    int i;
    for(i = 0; SIZE_OF_TABLE; i++)
    {
        if(all_parameters[i].id == id)
        {
            break;
        }
    }

    return i;
}

data_type_t getParamType(unsigned int id)
{
    return all_parameters[getParamIndex(id)].type;
}

QString getParamName(unsigned int id)
{
    return all_parameters[getParamIndex(id)].name;
}

QString getParamValue(unsigned int id)
{
    QString str;
    unsigned int *uint_ptr;

    switch(getParamType(id))
    {
    case TYPE_NONE:
        break;
    case TYPE_STRING:
        str = "hola";
        break;
    case TYPE_DECIMAL:
    case TYPE_HEX:
        uint_ptr = (unsigned int *)all_parameters[getParamIndex(id)].param;
        str = QString::number(*uint_ptr);
        break;
    }
    return str;
}

bool getParamActiveShow(unsigned int id)
{
    return all_parameters[getParamIndex(id)].active_show;
}

void toggleParamActiveShow(unsigned int id)
{
    if(true == all_parameters[getParamIndex(id)].active_show)
    {
        all_parameters[getParamIndex(id)].active_show = false;
    }
    else
    {
        all_parameters[getParamIndex(id)].active_show = true;
    }

}
