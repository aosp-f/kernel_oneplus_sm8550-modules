/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2018-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2021 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _KALAMA_PORT_CONFIG
#define _KALAMA_PORT_CONFIG

#include <soc/swr-common.h>

#define WSA_MSTR_PORT_MASK 0xFF
/*
 * Add port configuration in the format
 *{ si, off1, off2, hstart, hstop, wd_len, bp_mode, bgp_ctrl, lane_ctrl, dir,
 *  stream_type}
 */

static struct port_params wsa_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{7,    1,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* SPKR1 */
	{31,   3,    7,    0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* CMP1 */
	{63,   5,    31,   0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* SB1 */
	{7,    2,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* SPKR2 */
	{31,   4,    7,    0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* CMP2 */
	{63,   21,   31,   0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* SB2 */
	{399,  0xFF, 0xFF, 8,    0xFF, 8,    0xFF, 0xFF, 0xFF, 0x00, 0x01}, /* PBR */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* HAPT */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01}, /* OCPM */
	{15,   6,    0xFF, 0xFF, 15,   0xFF, 1,    0xFF, 0xFF, 0x01, 0x00}, /* IVS1 */
	{15,   13,   0xFF, 0xFF, 15,   0xFF, 1,    0xFF, 0xFF, 0x01, 0x00}, /* IVS2 */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01}, /* ICPM */
	{799,  0xFF, 0xFF, 15,   15,   24,   0xFF, 0xFF, 0xFF, 0x01, 0x01}, /* CPS */

};

static struct port_params wsa_frame_params_receiver[SWR_MSTR_PORT_LEN] = {
	{3,    1,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* SPKR1 */
	{31,   3,    7,    0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* CMP1 */
	{63,   5,    31,   0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* SB1 */
	{3,    2,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* SPKR2 */
	{31,   4,    7,    0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* CMP2 */
	{63,   21,   31,   0xFF, 0xFF, 0xFF, 1,    0xFF, 0xFF, 0x00, 0x00}, /* SB2 */
	{399,  0xFF, 0xFF, 8,    0xFF, 8,    0xFF, 0xFF, 0xFF, 0x00, 0x01}, /* PBR */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00}, /* HAPT */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01}, /* OCPM */
	{15,   6,    0xFF, 0xFF, 15,   0xFF, 1,    0xFF, 0xFF, 0x01, 0x00}, /* IVS1 */
	{15,   13,   0xFF, 0xFF, 15,   0xFF, 1,    0xFF, 0xFF, 0x01, 0x00}, /* IVS2 */
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01}, /* ICPM */
	{799,  0xFF, 0xFF, 15,   15,   24,   0xFF, 0xFF, 0xFF, 0x01, 0x01}, /* CPS */
};

static struct port_params rx_frame_params_dsd[SWR_MSTR_PORT_LEN] = {
	{3,     0,    0,    0xFF, 0xFF, 1,    0xFF, 0xFF, 1,    0x00, 0x00}, /* HPH/EAR */
	{31,    0,    0,    3,    6,    7,    0,    0xFF, 0,    0x00, 0x02}, /* HPH_CLH */
	{31,    11,   11,   0xFF, 0xFF, 4,    1,    0xFF, 0,    0x00, 0x02}, /* HPH_CMP */
	{7,     9,    0,    0xFF, 0xFF, 0xFF, 0xFF, 1,    0,    0x00, 0x00}, /* LO/AUX */
	{3,     1,    0,    0xFF, 0xFF, 0xFF, 0xFF, 3,    0,    0x00, 0x00}, /* DSD */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* GPPO */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HAPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HIFI */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HPHT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* CMPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* IPCM */
};

/* Headset + PCM Haptics */
static struct port_params rx_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{3,     0,    0,    0xFF, 0xFF, 1,    0xFF, 0xFF, 1,    0x00, 0x00}, /* HPH/EAR */
	{31,    0,    0,    3,    6,    7,    0,    0xFF, 0,    0x00, 0x02}, /* HPH_CLH */
	{31,    11,   11,   0xFF, 0xFF, 4,    1,    0xFF, 0,    0x00, 0x02}, /* HPH_CMP */
	{7,     1,    0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0,    0x00, 0x00}, /* LO/AUX */
	{0,     0,    0,    0xFF, 0xFF, 0xFF, 0xFF, 0,    0,    0x00, 0x00}, /* DSD */
	{0x18F, 0,    0,    0x8,  0x8,  0x0F, 0x00, 0,    0,    0x00, 0x01}, /* PCM_OUT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* GPPO */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HAPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HIFI */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HPHT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* CMPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* IPCM */

};

/* Headset(44.1K) + PCM Haptics */
static struct port_params rx_frame_params_44p1KHz[SWR_MSTR_PORT_LEN] = {
	{3,     0,    0,    0xFF, 0xFF, 1,    0xFF, 0xFF, 1,    0x00, 0x00}, /* HPH/EAR */
	{63,    0,    0,    3,    6,    7,    0,    0xFF, 0,    0x00, 0x02}, /* HPH_CLH */
	{31,    11,   11,   0xFF, 0xFF, 4,    1,    0xFF, 0,    0x00, 0x02}, /* HPH_CMP */
	{3,     1,    0,    0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0,    0x00, 0x00}, /* LO/AUX */
	{0,     0,    0,    0xFF, 0xFF, 0xFF, 0xFF, 0,    0,    0x00, 0x00}, /* DSD */
	{0x1FF, 0,    0,    0x8,  0x8,  0x0F, 0,    0,    0,    0x00, 0x01}, /* PCM_OUT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* GPPO */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HAPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HIFI */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* HPHT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* CMPT */
	{0xFF,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* IPCM */
};

static struct swr_mstr_port_map sm_port_map[] = {
	{RX_MACRO, SWR_UC0, rx_frame_params_default},
	{RX_MACRO, SWR_UC1, rx_frame_params_dsd},
	{RX_MACRO, SWR_UC2, rx_frame_params_44p1KHz},
	{WSA_MACRO, SWR_UC0, wsa_frame_params_default},
	{WSA_MACRO, SWR_UC1, wsa_frame_params_receiver},
	{WSA2_MACRO, SWR_UC0, wsa_frame_params_default},
	{WSA2_MACRO, SWR_UC1, wsa_frame_params_receiver},
};

#endif /* _KALAMA_PORT_CONFIG */
