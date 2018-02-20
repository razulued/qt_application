/*
 * my_crc_api.h
 *
 *  Created on: Oct 19, 2017
 *      Author: hood
 */

#ifndef UTIL_MY_CRC_API_H_
#define UTIL_MY_CRC_API_H_

// Returns Calculated CRC value
    // Seed for CRC calculation
    // Pointer to byte array to perform CRC on
    // Number of bytes to CRC
uint16_t CalculateCRC16(uint16_t crc, uint8_t *c_ptr, int len);

#endif /* UTIL_MY_CRC_API_H_ */
