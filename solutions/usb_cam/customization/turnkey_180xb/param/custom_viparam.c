/*
 * Copyright (C) Cvitek Co., Ltd. 2019-2020. All rights reserved.
 *
 * File Name: custom_viparam.c
 * Description:
 *   ....
 */
#include "custom_param.h"
#define BIN_DATA_SIZE       174513
extern unsigned char rgb_color_mode_param[];
PARAM_CLASSDEFINE(PARAM_SNS_CFG_S,SENSORCFG,CTX,Sensor)[] = {
    {
        .enSnsType = CONFIG_SNS0_TYPE,
        .s32I2cAddr = 0x32,
        .s8I2cDev = 1,
        .u32Rst_port_idx = 2,
        .u32Rst_pin = 8,
        .u32Rst_pol = OF_GPIO_ACTIVE_LOW,
        // .bSetDevAttrMipi = CVI_TRUE,
        // .as16LaneId = {3, 4, 2, -1, -1},
        // .as8PNSwap = {1, 1, 1, 0, 0},
        // .bSetDevAttr = CVI_TRUE,
        // .s16MacClk = RX_MAC_CLK_200M,
        // .u8MclkCam = 0,
        // .u8MclkFreq = CAMPLL_FREQ_27M,
    }
};

PARAM_CLASSDEFINE(PARAM_ISP_CFG_S,ISPCFG,CTX,ISP)[] = {
    {
        .bMonoSet = {0},
        .bUseSingleBin = 1,
        .stPQBinDes =
        {
            .pIspBinData = rgb_color_mode_param,
            .u32IspBinDataLen = BIN_DATA_SIZE,
        },
    },
};

PARAM_VI_CFG_S g_stViCtx = {
    .u32WorkSnsCnt = 1,
    .pstSensorCfg = PARAM_CLASS(SENSORCFG,CTX,Sensor),
    .pstIspCfg = PARAM_CLASS(ISPCFG,CTX,ISP),
};

PARAM_VI_CFG_S * PARAM_GET_VI_CFG(void) {
    return &g_stViCtx;
}






