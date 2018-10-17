#include "asa_protocol.h"
#include <QHash>
#include <QDebug>
#include <QMutex>
#include "asa_conversions.h"
#include "parameters.h"

const ASA_protocol_element_t supported_ASA_IDs[] =
{
/*+++++++++++++++++++++ COMMON ++++++++++++++++++++++*/

/*---- 0:status ID ----*/
/* Ping LE             */ 0x0000,   ASA_TYPE_NONE,      NULL,      conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Ping BE             */ 0x0001,   ASA_TYPE_NONE,      NULL,      conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Serialnumber        */ 0x0002,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* HWinfo              */ 0x0003,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* BOOTinfo            */ 0x0004,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* APPLinfo            */ 0x0005,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* GPS lat             */ 0x0006,   ASA_TYPE_DECIMAL,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* GPS long            */ 0x0007,   ASA_TYPE_DECIMAL,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Customer            */ 0x0008,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 1:status COM ---*/
/* SIG Rssi            */ 0x0100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* SIG Ber             */ 0x0101,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* txseqnum            */ 0x0102,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_bytes      */ 0x0103,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_prepbal    */ 0x0104,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_expiry     */ 0x0105,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 2:status ECU ---*/
/* Sysuptime           */ 0x0200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Session             */ 0x0201,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Numresets           */ 0x0202,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* HW reset reason     */ 0x0203,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* SW reset reason     */ 0x0204,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Main supply type    */ 0x0205,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Main supply level   */ 0x0206,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Backup supply type  */ 0x0207,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Backup supply level */ 0x0208,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Debug message       */ 0x0209,   ASA_TYPE_STRING,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Token Owner         */ 0x020A,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Shutdown warning    */ 0x020B,   ASA_TYPE_NONE,      NULL,      conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 3:status IO ----*/
/* Raw data array      */ 0x0300,   ASA_TYPE_BUFFER,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Uint data value     */ 0x0301,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* CRC of memory range */ 0x0302,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Rawdata RX Count    */ 0x0303,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- 4:status MISC --*/
/* OK response         */ 0x0400,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* FAIL response       */ 0x0401,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* datetime            */ 0x0402,   ASA_TYPE_STRING,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 5: parm ECU ----*/
    //none
/*---- 6: parm IO -----*/
/* Set memory OP addr  */ 0x0600,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Set memory OP len   */ 0x0601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- 7: param COMM --*/
/* OP1 UDP IP          */ 0x0700,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 UDP Port        */ 0x0701,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 UDP IP          */ 0x0702,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 UDP Port        */ 0x0703,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 TCP IP          */ 0x0704,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 TCP Port        */ 0x0705,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 TCP IP          */ 0x0706,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 TCP Port        */ 0x0707,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 UDP IP        */ 0x0708,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 UDP Port      */ 0x0709,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 UDP IP        */ 0x070A,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 UDP Port      */ 0x070B,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 TCP IP        */ 0x070C,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 TCP Port      */ 0x070D,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 TCP IP        */ 0x070E,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 TCP Port      */ 0x070F,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Phone number        */ 0x0710,   ASA_TYPE_STRING,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer BS max     */ 0x0711,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer ST min     */ 0x0712,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Connection timeout  */ 0x0713,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Prescale Div        */ 0x0714,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 8: parm MISC ---*/
    //none
/*---- 9:control ECU --*/
/* Reset controller    */ 0x0900,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Switch session      */ 0x0901,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Emergency shut-off  */ 0x0902,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- a:control IO ---*/
/* Control panel LED   */ 0x0A00,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Start memory OP cmd */ 0x0A01,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Read ID             */ 0x0A02,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Write ID            */ 0x0A03,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer BC         */ 0x0A04,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- b:control COM --*/
/* Start connection    */ 0x0B00,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* End connection      */ 0x0B01,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- c:control MISC -*/
    //none
/*---- d: special 1 ---*/
/* CRC capsule         */ 0x0D00,   ASA_TYPE_BUFFER,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Sec challenge       */ 0x0D01,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Sec key             */ 0x0D02,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Token Transfer      */ 0x0D03,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* User Authority      */ 0x0D04,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- e: special 2 ---*/
    //none
/*---- f: special 3 ---*/
    //none

/* ALARMAS */
    0x1006,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1007,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1008,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1009,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x100A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x100B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x101E,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x101F,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1020,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1021,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1022,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1023,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x103C,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x103D,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x103E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x103F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1040,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1041,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x1042,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x1043,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x1044,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1045,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1046,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1047,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x1048,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1049,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x104A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x104B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x104C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x104D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x1060,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1061,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x1062,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1063,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1064,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1065,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x1090,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
    0x1091,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
    0x1092,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1093,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1094,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1095,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x109C,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
    0x109D,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
    0x109E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x109F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10A0,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10A1,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

/* FILTRO ALARMAS */
    0x10A2,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10A3,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10A4,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10A5,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10A6,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10A7,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10A8,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10A9,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10AA,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10AB,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10AC,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10AD,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10AE,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10AF,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10B0,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B1,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B2,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B3,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10B4,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10B5,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
    0x10B6,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B7,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B8,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10B9,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10D8,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10D9,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10DA,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10DB,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10DC,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10DD,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10DE,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10DF,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10E0,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10E1,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10E2,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10E3,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10EA,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10EB,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10EC,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10ED,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10EE,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10EF,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10F0,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10F1,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
    0x10F2,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10F3,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10F4,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10F5,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x10FC,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x10FD,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x10FE,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x10FF,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1101,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

    0x1102,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x1103,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
    0x1104,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1105,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1106,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
    0x1107,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",

/*+++++++++++++++++++++ Commands Database ++++++++++++++++++++++*/
    0x1800,   ASA_TYPE_INTEGER,   Query_ID_last_activity,   conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1801,   ASA_TYPE_INTEGER,   Query_ID_last_record,     conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1802,   ASA_TYPE_INTEGER,   Query_N_record,           conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1803,   ASA_TYPE_INTEGER,   Query_last_log,           conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1880,   ASA_TYPE_INTEGER,   Store_activity,           conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1881,   ASA_TYPE_INTEGER,   Store_record,             conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1882,   ASA_TYPE_INTEGER,   Edit_activity,            conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1883,   ASA_TYPE_INTEGER,   Edit_record,              conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1884,   ASA_TYPE_INTEGER,   Delete_activity,          conv_none_or_passthru,          conv_none_or_passthru,          0,    "",
    0x1885,   ASA_TYPE_INTEGER,   Delete_record,            conv_none_or_passthru,          conv_none_or_passthru,          0,    "",


/*+++++++++++++++++++++ PTAR ++++++++++++++++++++++*/
/*----- 2:Plant Cfg	0:config DIG OUT type1 --------*/
/* cfg RELE out 1      */ 0x2000,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg RELE out 2      */ 0x2001,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg RELE out 3      */ 0x2002,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg RELE out 4      */ 0x2003,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*----- 2:Plant Cfg	0:config DIG OUT type2 --------*/
/* cfg LED out 1       */ 0x2040,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg LED out 2       */ 0x2041,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg LED out 3       */ 0x2042,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* cfg LED out 4       */ 0x2043,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*----- 2:Plant Cfg	1:config ANA IN       --------*/
/* ana IN 1            */ 0x2100,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 2            */ 0x2101,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 3            */ 0x2102,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 4            */ 0x2103,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 5            */ 0x2104,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 6            */ 0x2105,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 7            */ 0x2106,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 8            */ 0x2107,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* ana IN 9            */ 0x2108,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*----- 2:Plant Cfg	2:config MODBUS_A     --------*/
/* dig IN dev ADDR0    */ 0x2200,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR1    */ 0x2201,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR2    */ 0x2202,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR3    */ 0x2203,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR4    */ 0x2204,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR5    */ 0x2205,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR6    */ 0x2206,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR7    */ 0x2207,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR8    */ 0x2208,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDR9    */ 0x2209,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRa    */ 0x220A,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRb    */ 0x220B,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRc    */ 0x220C,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRd    */ 0x220D,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRe    */ 0x220E,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig IN dev ADDRf    */ 0x220F,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*----- 2:Plant Cfg	3:config MODBUS_B     --------*/
/* dig DATA addr0 ch0  */ 0x2300,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr0 ch1  */ 0x2301,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr0 ch2  */ 0x2302,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr0 ch3  */ 0x2303,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr1 ch0  */ 0x2304,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr1 ch1  */ 0x2305,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr1 ch2  */ 0x2306,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dig DATA addr1 ch3  */ 0x2307,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*----- 3:Plant Carcamo	0:Status:Electricos ------*/
/* Motor1 State        */ 0x3000,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat1                */ 0x3001,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x3002,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x3003,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x3004,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x3005,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x3006,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x3007,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x3008,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x3009,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x300A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat11               */ 0x300B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat12               */ 0x300C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat13               */ 0x300D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat14               */ 0x300E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat15               */ 0x300F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Motor2 State        */ 0x3010,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat1                */ 0x3011,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x3012,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x3013,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x3014,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x3015,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x3016,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x3017,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x3018,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x3019,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x301A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat11               */ 0x301B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat12               */ 0x301C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat13               */ 0x301D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat14               */ 0x301E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat15               */ 0x301F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Motor3 State        */ 0x3020,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat1                */ 0x3021,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x3022,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x3023,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x3024,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x3025,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x3026,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x3027,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x3028,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x3029,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x302A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat11               */ 0x302B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat12               */ 0x302C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat13               */ 0x302D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat14               */ 0x302E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat15               */ 0x302F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Motor4 State        */ 0x3030,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat1                */ 0x3031,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x3032,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x3033,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x3034,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x3035,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x3036,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x3037,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x3038,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x3039,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x303A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat11               */ 0x303B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat12               */ 0x303C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat13               */ 0x303D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat14               */ 0x303E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* dat15               */ 0x303F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*----- 3:Plant Carcamo	1:Status:MISC       ------*/
/* Alert Indication    */ 0x3100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*----- 3:Plant Carcamo	2:Status:Fisicos    ------*/
/* Sens 1 State        */ 0x3200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* s1 value            */ 0x3201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,   "longitud",
/* Sens 2 State        */ 0x3202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_integer_multiply_by, 0,    "",
/* s2 value            */ 0x3203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x3204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* s3 value            */ 0x3205,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "presion",
/* Sens 4 State        */ 0x3206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* s4 value            */ 0x3207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*----- 3:Plant Carcamo	3:Status:Quimicos   ------*/
/* Sens 1 State        */ 0x3300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,      "",
/* s1 value            */ 0x3301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x3302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,      "",
/* s2 value            */ 0x3303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x3304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,      "",
/* s3 value            */ 0x3305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x3306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,      "",
/* s4 value            */ 0x3307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 3:Plant Carcamo	4:Parametric:OPlevels ----*/
/* Alert level         */ 0x3400,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
/* Off Level           */ 0x3401,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
/* Level ON1           */ 0x3402,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
/* Level ON2           */ 0x3403,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
/*----- 3:Plant Carcamo	5:Parametric:OPtimings ---*/
/* Tipo alternado      */ 0x3500,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time Alt Max        */ 0x3501,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time On Min         */ 0x3502,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time Off Min        */ 0x3503,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 3:Plant Carcamo	6:CONTROL              ---*/
/* Subsystem OPMODE    */ 0x3600,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Alert actuator over */ 0x3601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 1 override    */ 0x3602,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 2 override    */ 0x3603,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 3 override    */ 0x3604,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 4 override    */ 0x3605,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 4:Plant Reactores 0:Status:Electricos ----*/
/* Motor1 State        */ 0x4000,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x4001,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x4002,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x4003,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x4004,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x4005,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x4006,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x4007,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x4008,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x4009,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x400A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x400B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x400C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x400D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x400E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x400F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor2 State        */ 0x4010,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x4011,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x4012,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x4013,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x4014,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x4015,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x4016,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x4017,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x4018,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x4019,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x401A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x401B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x401C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x401D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x401E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x401F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor3 State        */ 0x4020,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x4021,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x4022,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x4023,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x4024,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x4025,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x4026,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x4027,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x4028,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x4029,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x402A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x402B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x402C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x402D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x402E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x402F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor4 State        */ 0x4030,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x4031,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x4032,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x4033,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x4034,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x4035,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x4036,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x4037,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x4038,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x4039,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x403A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x403B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x403C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x403D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x403E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x403F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 4:Plant Reactores 1:Status:MISC       ----*/
    //none
/*----- 4:Plant Reactores 2:Status:Fisicos    ----*/
/* Sens 1 State        */ 0x4200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s1 value            */ 0x4201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2, conv_integer_multiply_by, 100,   "longitud",
/* Sens 2 State        */ 0x4202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x4203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x4204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x4205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion_2,   conv_integer_presion_inv_2, 0,    "presion",
/* Sens 4 State        */ 0x4206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x4207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 4:Plant Reactores 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x4300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x4301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x4302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x4303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x4304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x4305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x4306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x4307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 4:Plant Reactores 4:Parametric:OPlevels --*/
/* O2 level min        */ 0x4400,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/* O2 level max        */ 0x4401,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 4:Plant Reactores 5:Parametric:OPtimings--*/
/* Tipo alternado      */ 0x4500,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time Alt Max        */ 0x4501,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time On Min         */ 0x4502,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Time Off Min        */ 0x4503,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Prog time ON        */ 0x4540,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Prog time OFF       */ 0x4541,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 4:Plant Reactores	6:CONTROL          ---*/
/* Subsystem OPMODE    */ 0x4600,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 1 override    */ 0x4601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 2 override    */ 0x4602,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 3 override    */ 0x4603,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 4 override    */ 0x4604,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 5:Plant Clarificador 0:Status:Electricos -*/
/* Actuator 1 state    */ 0x5000,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 5:Plant Clarificador 1:Status:MISC  ------*/
    //none
/*----- 5:Plant Clarificador 2:Status:Fisicos ----*/
/* Sens 1 State        */ 0x5200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s1 value            */ 0x5201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2, conv_integer_multiply_by, 100,   "longitud",
/* Sens 2 State        */ 0x5202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x5203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x5204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x5205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Sens 4 State        */ 0x5206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x5207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 5:Plant Clarificador 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x5300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x5301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x5302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x5303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x5304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x5305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x5306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x5307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 5:Plant Clarificador 4:Parametric:OPlevels -*/
/* Pressure OPT        */ 0x5400,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Pressure MAX        */ 0x5401,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/*----- 5:Plant Clarificador 5:Parametric:OPtimings -*/
    //none
/*----- 5:Plant Clarificador 6:CONTROL -*/
/* Subsystem OPMODE    */ 0x5600,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valvula 1 override  */ 0x5601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 6:Plant Clorador 0:Status:Electricos  -----*/
/*----- 6:Plant Clorador 1:Status:MISC      -------*/
/*----- 6:Plant Clorador 2:Status:Phys      -------*/
/* Sens 1 State        */ 0x6200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s1 value            */ 0x6201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2, conv_integer_multiply_by, 100,   "longitud",
/* Sens 2 State        */ 0x6202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x6203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x6204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x6205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Sens 4 State        */ 0x6206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x6207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 6:Plant Clorador 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x6300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x6301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x6302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x6303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x6304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x6305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x6306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x6307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 7:Plant Digestor 0:Status:Electricos  -----*/
/*----- 7:Plant Digestor 1:Status:MISC      -------*/
/*----- 7:Plant Digestor 2:Status:Phys      -------*/
/* Sens 1 State        */ 0x7200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s1 value            */ 0x7201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2, conv_integer_multiply_by, 100,   "longitud",
/* Sens 2 State        */ 0x7202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x7203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x7204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x7205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Sens 4 State        */ 0x7206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x7207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 7:Plant Digestor 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x7300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x7301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x7302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x7303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x7304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x7305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x7306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x7307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 8:Plant Secado 0:Status:Electricos  -----*/
/*----- 8:Plant Secado 1:Status:MISC      -------*/
/*----- 8:Plant Secado 2:Status:Phys      -------*/
/* Sens 1 State        */ 0x8200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s1 value            */ 0x8201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2, conv_integer_multiply_by, 100,   "longitud",
/* Sens 2 State        */ 0x8202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x8203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal,      conv_integer_caudal_inv,  0,    "caudal",
/* Sens 3 State        */ 0x8204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x8205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Sens 4 State        */ 0x8206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x8207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 8:Plant Secado 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x8300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x8301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x8302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x8303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x8304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x8305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x8306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x8307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/*----- 9:Plant Filtro 0:Status:Electricos  -----*/
/* Motor1 State        */ 0x9000,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x9001,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x9002,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x9003,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x9004,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x9005,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x9006,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x9007,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x9008,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x9009,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x900A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x900B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x900C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x900D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x900E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x900F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor2 State        */ 0x9010,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x9011,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x9012,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x9013,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x9014,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x9015,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x9016,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x9017,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x9018,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x9019,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x901A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x901B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x901C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x901D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x901E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x901F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor3 State        */ 0x9020,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x9021,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x9022,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x9023,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x9024,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x9025,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x9026,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x9027,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x9028,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x9029,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x902A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x902B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x902C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x902D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x902E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x902F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor4 State        */ 0x9030,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x9031,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x9032,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x9033,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x9034,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x9035,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x9036,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x9037,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x9038,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x9039,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x903A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x903B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x903C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x903D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x903E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x903F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",

/* Motor1 State        */ 0x9080,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat1                */ 0x9081,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat2                */ 0x9082,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat3                */ 0x9083,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " V",
/* dat4                */ 0x9084,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat5                */ 0x9085,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat6                */ 0x9086,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by, 1000, " A",
/* dat7                */ 0x9087,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,   " Hz",
/* dat8                */ 0x9088,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat9                */ 0x9089,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,  "",
/* dat10               */ 0x908A,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat11               */ 0x908B,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat12               */ 0x908C,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat13               */ 0x908D,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat14               */ 0x908E,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* dat15               */ 0x908F,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",

/* Valvula 1 state     */ 0x9100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valvula 3(S) state  */ 0x9101,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valvula 2 state     */ 0x9102,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 9:Plant Filtro 1:Status:MISC      -------*/
/* Valvula 1 state     */ 0x9100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valvula 2 state     */ 0x9101,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valvula 3(S) state  */ 0x9102,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Alert Indication    */ 0x9180,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 9:Plant Filtro 2:Status:Phys      -------*/
/* Sens 1 State        */ 0x9200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
///* s1 value            */ 0x9201,   ASA_TYPE_INTEGER,   NULL,   conv_nivel_1,             conv_nivel_1_inv, 0,   "longitud",
/* s1 value            */ 0x9201,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
/* Sens 2 State        */ 0x9202,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s2 value            */ 0x9203,   ASA_TYPE_INTEGER,   NULL,   conv_integer_caudal_2,    conv_integer_caudal_inv_2,  0,    "caudal",
/* Sens 3 State        */ 0x9204,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s3 value            */ 0x9205,   ASA_TYPE_INTEGER,   NULL,   conv_integer_presion,     conv_integer_presion_inv, 0,    "presion",
/* Sens 4 State        */ 0x9206,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* s4 value            */ 0x9207,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/*----- 8:Plant Secado 3:Status:Quimicos   ----*/
/* Sens 1 State        */ 0x9300,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x9301,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x9302,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x9303,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x9304,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x9305,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x9306,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x9307,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",
/* Sens 1 State        */ 0x9310,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s1 value            */ 0x9311,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " ph",
/* Sens 2 State        */ 0x9312,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s2 value            */ 0x9313,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 10,     " NTU",
/* Sens 3 State        */ 0x9314,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s3 value            */ 0x9315,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " mg/l",
/* Sens 4 State        */ 0x9316,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,      "",
/* s4 value            */ 0x9317,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,   conv_integer_multiply_by, 100,    " PPM",

/* CALIBRACIONES*/
0x9400,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
0x9401,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
0x9402,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by_pres2,   conv_integer_multiply_by,   100,    "longitud",
0x9403,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,         conv_integer_multiply_by,   10,     " NTU",
0x9404,   ASA_TYPE_INTEGER,   NULL,   conv_integer_divide_by,         conv_integer_multiply_by,   10,     " NTU",

0x9500,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,       "",
0x9501,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,       "",
0x9502,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,       "",
0x9503,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,       "",
0x9504,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,       "",

/*----- 8:Plant Filtro	6:CONTROL              ---*/
/* Subsystem OPMODE    */ 0x9600,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 1 override    */ 0x9601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 2 override    */ 0x9602,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 3 override    */ 0x9603,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",

/* Valve 1 override    */ 0x9640,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valve 2 override    */ 0x9641,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Valve 3 override    */ 0x9642,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",

/* Subsystem OPMODE    */ 0x9700,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
/* Motor 4 override    */ 0x9701,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,  0,    "",
};

QHash<uint, uint> hash_indices;
QHash<uint, QVariant> hash_values;
QMutex data_mutex;

QString units_longitud;
QString units_presion;
QString units_caudal;
QString units_tiempo;

float factor_longitud;
float factor_presion;
float factor_caudal;
float factor_tiempo;

void ASA_protocol_init()
{
    uint i = 0;

    //Store in known IDs and hash their index
    for(i = 0; i < (sizeof(supported_ASA_IDs) / sizeof(ASA_protocol_element_t)); i++)
    {
        hash_indices.insert(supported_ASA_IDs[i].id, i);
    }

    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Units");
    switch(conf.value("longitud").toInt())
    {
        case 1:
            units_longitud = "cm";
            factor_longitud = 100;
        break;
        case 2:
            units_longitud = "ft";
            factor_longitud = 3.28;
        break;
        default:
        case 0:
            units_longitud = "m";
            factor_longitud = 1;
        break;
    }

    switch(conf.value("presion").toInt())
    {
        case 1:
            units_presion = "kg/cm²";
            factor_presion = 0.0703;
        break;
        case 2:
            units_presion = "Bar";
            factor_presion = 0.0689;
        break;
        case 3:
            units_presion ="m.c.a";
            factor_presion = 0.703;
        break;
        default:
        case 0:
            units_presion = "PSI";
            factor_presion = 1;
        break;
    }

    switch(conf.value("caudal").toInt())
    {
        case 1:
            units_caudal = "l/m";
            factor_caudal = 1;
        break;
        case 2:
            units_caudal = "l/h";
            factor_caudal = 60;
        break;
        case 3:
            units_caudal = "gal/s";
            factor_caudal = 0.0044;
        break;
        case 4:
            units_caudal = "gal/m";
            factor_caudal = 0.264;
        break;
        case 5:
            units_caudal = " gal/h";
            factor_caudal = 15.84;
        break;
        case 6:
            units_caudal = "m³/h";
            factor_caudal = 0.004616;
        break;
        default:
        case 0:
            units_caudal = "l/s";
            factor_caudal = 0.0167;
        break;
    }

    switch(conf.value("tiempo").toInt())
    {
        case 1:
            units_tiempo = "min";
            factor_tiempo = 60;
        break;
        case 2:
            units_tiempo = "h";
            factor_tiempo = 3600;
        break;
        default:
        case 0:
            units_tiempo = "s";
            factor_tiempo = 1;
        break;
    }
    conf.endGroup();

    load_active_parameters();
}

//void ASA_protocol::store_value_by_ID(uint id, QString str_value)
void store_value_by_ID(uint id, QString str_value)
{
    uint index = 0;

    if(0 != id)
    {
        data_mutex.lock();

        hash_values.insert(id, str_value);

        // Check its index in the table and run its Received function, if present.
        //Index in table (for functions)
        index = hash_indices.value(id);

        if(0 != index)
        {
            if(supported_ASA_IDs[index].receive_hanlder != NULL)
            {
                (void)supported_ASA_IDs[index].receive_hanlder(str_value);
            }
        }

        data_mutex.unlock();
    }
}

//void ASA_protocol::get_value_by_ID(uint id)
QString get_value_by_ID(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);

    //Apply scale by units
    float number = str.toFloat();
    str = units_scale(id, number);

    data_mutex.unlock();

    return str;
}

QString get_value_by_ID_base_units(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);
    //qDebug() << "Id: " << QString::number(id, 16) << ": " << hash_values[id].value<QString>() << "at index " << hash_indices.value(id);
    data_mutex.unlock();

    return str;
}

QString inverse_value_by_ID_base_units(uint id, float value)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].inverse_hanlder(QString::number(value), supported_ASA_IDs[index].param1);
    //qDebug() << "Id: " << QString::number(id, 16) << ": " << hash_values[id].value<QString>() << "at index " << hash_indices.value(id);
    data_mutex.unlock();

    return str;
}


QString get_value_units(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    if(supported_ASA_IDs[index].units == "longitud")
    {
        str = " " +units_longitud;
    }
    else if(supported_ASA_IDs[index].units == "presion")
    {
        str = " " +units_presion;
    }
    else if(supported_ASA_IDs[index].units == "caudal")
    {
        str = " " +units_caudal;
    }
    else if(supported_ASA_IDs[index].units == "tiempo")
    {
        str = " " +units_tiempo;
    }
    else
    {
        str = supported_ASA_IDs[index].units;
    }

    data_mutex.unlock();

    return str;
}

QString units_scale(uint id, float value)
{
    float val;
    uint index = 0;
    //Index in table (for conversions)
    index = hash_indices.value(id);
    if(supported_ASA_IDs[index].units == "longitud")
    {
        val = value * factor_longitud;
    }
    else if(supported_ASA_IDs[index].units == "presion")
    {
        val = value * factor_presion;
    }
    else if(supported_ASA_IDs[index].units == "caudal")
    {
        val = value * factor_caudal;
    }
    else if(supported_ASA_IDs[index].units == "tiempo")
    {
        val = value * factor_tiempo;
    }
    else
    {
        val = value;
    }
    return QString::number(val,'f',2);
}

QString get_units_longitud(void)
{
    return units_longitud;
}

QString get_units_presion(void)
{
    return units_presion;
}

QString get_units_caudal(void)
{
    return units_caudal;
}

QString get_units_tiempo(void)
{
    return units_tiempo;
}
