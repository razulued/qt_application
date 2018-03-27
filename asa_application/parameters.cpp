#include "parameters.h"
#include <QtDebug>
#include <QDateTime>

#define SIMULATION (1)

QString gen_stat_ecuid;
double gen_stat_prodtype;
double gen_stat_msgtype;
double gen_stat_swver;
double gen_stat_hwver;
double gen_stat_txseqnum;
double gen_stat_sysuptime;
double gen_stat_gpslat;
double gen_stat_gpslong;
double gen_stat_gprs_rssi;
double gen_stat_batlevel;
QString gen_stat_debugmsg;
double gen_stat_numresets;
double gen_stat_databyaddr;
double gen_stat_gprs_ber;
QString gen_stat_datetime;
double gen_stat_authlevel;
double gen_parm_sec_challenge;
double car_stat_shit_level;
double car_stat_sens_ph_in;
double car_stat_sens_sst_in;
double car_stat_sens_caudal_in;
double car_stat_diag_mot1;
double car_stat_mot1_volt12;
double car_stat_mot1_volt23;
double car_stat_mot1_volt13;
double car_stat_mot1_amp1;
double car_stat_mot1_amp2;
double car_stat_mot1_amp3;
double car_stat_mot1_freq;
double car_stat_mot1_cosphi;
double car_stat_mot1_pfac;
double car_stat_diag_mot2;
double car_stat_mot2_volt12;
double car_stat_mot2_volt23;
double car_stat_mot2_volt13;
double car_stat_mot2_amp1;
double car_stat_mot2_amp2;
double car_stat_mot2_amp3;
double car_stat_mot2_freq;
double car_stat_mot2_cosphi;
double car_stat_mot2_pfac;
double car_stat_diag_warn_ind;
double car_stat_sens_turbidez_in;
double car_parm_off_level;
double car_parm_setp_lev1;
double car_parm_setp_lev2;
double car_parm_setp_lev3;
double car_parm_time_alt_max;
double car_ctrl_target_opmode;
double car_ctrl_drive_mot1;
double car_ctrl_drive_mot2;
double car_ctrl_drive_warn_ind;
double rea_stat_o2_sens_1_level;
double rea_stat_o2_sens_2_level;
double rea_stat_diag_mot1;
double rea_stat_mot1_volt12;
double rea_stat_mot1_volt23;
double rea_stat_mot1_volt13;
double rea_stat_mot1_amp1;
double rea_stat_mot1_amp2;
double rea_stat_mot1_amp3;
double rea_stat_mot1_freq;
double rea_stat_mot1_cosphi;
double rea_stat_mot1_pfac;
double rea_stat_diag_mot2;
double rea_stat_mot2_volt12;
double rea_stat_mot2_volt23;
double rea_stat_mot2_volt13;
double rea_stat_mot2_amp1;
double rea_stat_mot2_amp2;
double rea_stat_mot2_amp3;
double rea_stat_mot2_freq;
double rea_stat_mot2_cosphi;
double rea_stat_mot2_pfac;
double rea_stat_diag_mot3;
double rea_stat_mot3_volt12;
double rea_stat_mot3_volt23;
double rea_stat_mot3_volt13;
double rea_stat_mot3_amp1;
double rea_stat_mot3_amp2;
double rea_stat_mot3_amp3;
double rea_stat_mot3_freq;
double rea_stat_mot3_cosphi;
double rea_stat_mot3_pfac;
double rea_stat_sens_presion_1;
double rea_parm_o2_level_MIN;
double rea_parm_o2_level_MAX;
double rea_parm_time_on_min;
double rea_parm_time_alt_max;
double rea_parm_prog_time_on;
double rea_parm_prog_time_off;
double rea_ctrl_target_opmode;
double rea_ctrl_drive_mot1;
double rea_ctrl_drive_mot2;
double rea_ctrl_drive_mot3;
double cla_stat_press_val;
double cla_stat_diag_NC_valve1;
double cla_parm_press_thresh_OPT;
double cla_parm_press_thresh_MAX;
double cla_ctrl_target_opmode;
double cla_ctrl_drive_NC_valve1;
double misc_stat_sens_ph_out;
double misc_stat_sens_sst_out;
double misc_stat_sens_caudal_out;
double misc_stat_sens_turbidez_out;
double misc_stat_sens_presion_2;
double misc_stat_sens_presion_3;
char* NO_DATA = "NO DATA";

int getParamIndex(unsigned int id);

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
    {16,	false,	"gen_stat_datetime",            &gen_stat_datetime,                TYPE_STRING},
    {22,	false,	"gen_stat_authlevel",           &gen_stat_authlevel,               TYPE_HEX},
    {23,	false,	"gen_parm_sec_challenge",       &gen_parm_sec_challenge,           TYPE_HEX},
    {40,	false,	"ND",                           &car_stat_shit_level,              TYPE_HEX},
    {41,	false,	"car_stat_sens_ph_in",          &car_stat_sens_ph_in,              TYPE_HEX},
    {42,	false,	"car_stat_sens_sst_in",         &car_stat_sens_sst_in,             TYPE_HEX},
    {43,	false,	"Q",                            &car_stat_sens_caudal_in,          TYPE_HEX},
    {44,	false,	"car_stat_diag_mot1",           &car_stat_diag_mot1,               TYPE_HEX},
    {45,	false,	"Vp",                           &car_stat_mot1_volt12,             TYPE_HEX},
    {46,	false,	"car_stat_mot1_volt23",         &car_stat_mot1_volt23,             TYPE_HEX},
    {47,	false,	"car_stat_mot1_volt13",         &car_stat_mot1_volt13,             TYPE_HEX},
    {48,	false,	"Ap",                           &car_stat_mot1_amp1,               TYPE_HEX},
    {49,	false,	"car_stat_mot1_amp2",           &car_stat_mot1_amp2,               TYPE_HEX},
    {50,	false,	"car_stat_mot1_amp3",           &car_stat_mot1_amp3,               TYPE_HEX},
    {51,	false,	"car_stat_mot1_freq",           &car_stat_mot1_freq,               TYPE_HEX},
    {52,	false,	"car_stat_mot1_cosphi",         &car_stat_mot1_cosphi,             TYPE_HEX},
    {53,	false,	"FP",                           &car_stat_mot1_pfac,               TYPE_HEX},
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
    {255,	false,	"NO DATA",                      &NO_DATA,                          TYPE_STRING},

};
#define SIZE_OF_TABLE   (int)(sizeof(all_parameters)/sizeof(parameter_config_t))
void InitRandomParameters()
{
    unsigned int i,a;

    double *uint_ptr;

    for(i = 0; i < SIZE_OF_TABLE; i++)
    {
        if(TYPE_HEX == all_parameters[i].type)
        {
            uint_ptr = (double *)all_parameters[i].param;
            a = qrand() % 50;
            *uint_ptr = a;
            *uint_ptr = std::trunc(100 * *uint_ptr) / 100;
//            qDebug() << "Param: "<< all_parameters[i].name <<*uint_ptr;
        }
    }
}

void run_simulation()
{
    static uint state = 0;
    static uint last_time = 0;

    if(last_time == 0)
    {
        last_time = QDateTime::currentDateTime().toTime_t();
    }

    switch(state)
    {
    case 0:
        //Todo apagado
        *(double *)all_parameters[getParamIndex(44)].param = 0;
        *(double *)all_parameters[getParamIndex(92)].param = 0;

        //Caudal in (43)
        *(double *)all_parameters[getParamIndex(43)].param = 0;
        // Nivel
        *(double *)all_parameters[getParamIndex(40)].param = 5;
        break;
    case 1:
        // Entra flujo

        // Caudal in (43)
        *(double *)all_parameters[getParamIndex(43)].param = 10;
        break;

    case 2:
        // Sube Nivel carcamo
        *(double *)all_parameters[getParamIndex(40)].param = 20; //low
        break;
    case 3:
        *(double *)all_parameters[getParamIndex(40)].param = 40; // med
        break;
    case 4:
        *(double *)all_parameters[getParamIndex(40)].param = 80; // full
        break;

    case 5:
        // Se prenden motor
        *(double *)all_parameters[getParamIndex(44)].param = 1;
        break;

    case 6:
        // Se prende aereador en reactor
        *(double *)all_parameters[getParamIndex(92)].param = 1;
        break;

    case 7:
        // Retorno de lodo
        *(double *)all_parameters[getParamIndex(145)].param = 40;
        break;

    case 8:
        // Caudal out
        *(double *)all_parameters[getParamIndex(162)].param = 50;
        break;

    case 9:
        // Caudal in
        *(double *)all_parameters[getParamIndex(43)].param = 0;
        break;

    case 10:
        // Nivel de carcamo
        *(double *)all_parameters[getParamIndex(40)].param = 40; // med
        break;

    case 11:
        // Nivel de carcamo
        *(double *)all_parameters[getParamIndex(40)].param = 20; // low
        break;

    case 12:
        // Apagar carcamo
        *(double *)all_parameters[getParamIndex(44)].param = 0;
        // Apagar retorno de lodos
        *(double *)all_parameters[getParamIndex(145)].param = 0;
        break;

    case 13:
        // Se apaga aereador en reactor
        *(double *)all_parameters[getParamIndex(92)].param = 0;
        break;

    case 14:
        // Caudal out
        *(double *)all_parameters[getParamIndex(162)].param = 0;
        break;

    default:
        //back to 0
        state = 0;
        break;
    }


    if((QDateTime::currentDateTime().toTime_t() - last_time) > 4)
    {
        // Move to next state
        state++;
        last_time = QDateTime::currentDateTime().toTime_t();
        qDebug() << "Next state " << state;
    }
}

int getParamIndex(unsigned int id)
{
    int i;
    bool parameter_found = false;
    for(i = 0; i < SIZE_OF_TABLE; i++)
    {
        if(all_parameters[i].id == id)
        {
            parameter_found = true;
            break;
        }
    }

    if(parameter_found == false)
    {
        qDebug() << "Parameter" << id << "not found";

        id = 255;

        for(i = 0; i < SIZE_OF_TABLE; i++)
        {
            if(all_parameters[i].id == id)
            {
                qDebug() << "Set 255";
                parameter_found = true;
                break;
            }
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
    double *uint_ptr;

    switch(getParamType(id))
    {
    case TYPE_NONE:
        break;
    case TYPE_STRING:
        str = *(QString*)all_parameters[getParamIndex(id)].param;
        break;
    case TYPE_DECIMAL:
    case TYPE_HEX:
        uint_ptr = (double *)all_parameters[getParamIndex(id)].param;
        str = QString::number(*uint_ptr);
        break;
    }
    return str;
}

void setParamValue(unsigned int id,double value)
{
    double *uint_ptr;

#if (0 == SIMULATION)
    uint_ptr = (double *)all_parameters[getParamIndex(id)].param;
    *uint_ptr = value;
#endif
}

void setParamString(unsigned int id, QString value)
{
    QString *char_ptr;

    char_ptr = (QString *)all_parameters[getParamIndex(id)].param;
    *char_ptr = value;
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
