#ifndef __SC2336P_CMOS_EX_H_
#define __SC2336P_CMOS_EX_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef ARCH_CV182X
#include "cvi_vip_cif_uapi.h"
#else
#include "cif_uapi.h"
#endif
#include "cvi_type.h"
#include "cvi_sns_ctrl.h"

#define syslog(level, fmt, ...)            \
do {                                                   \
	printf(fmt, ##__VA_ARGS__);                \
} while (0)

enum sc2336p_linear_regs_e {
	LINEAR_SHS1_0_ADDR,
	LINEAR_SHS1_1_ADDR,
	LINEAR_SHS1_2_ADDR,
	LINEAR_AGAIN_0_ADDR,
	LINEAR_DGAIN_0_ADDR,
	LINEAR_DGAIN_1_ADDR,
	LINEAR_VMAX_0_ADDR,
	LINEAR_VMAX_1_ADDR,
	LINEAR_REGS_NUM
};


typedef enum _SC2336P_MODE_E {
	SC2336P_MODE_1080P30 = 0,
	SC2336P_MODE_LINEAR_NUM,
	SC2336P_MODE_NUM
} SC2336P_MODE_E;

typedef struct _SC2336P_STATE_S {
	CVI_U32		u32Sexp_MAX;	/* (2*{16’h3e23,16’h3e24} – 'd10)/2 */
} SC2336P_STATE_S;

typedef struct _SC2336P_MODE_S {
	ISP_WDR_SIZE_S astImg[2];
	CVI_FLOAT f32MaxFps;
	CVI_FLOAT f32MinFps;
	CVI_U32 u32HtsDef;
	CVI_U32 u32VtsDef;
	SNS_ATTR_S stExp[2];
	SNS_ATTR_S stAgain[2];
	SNS_ATTR_S stDgain[2];
	CVI_U16 u16SexpMaxReg;		/* {16’h3e23,16’h3e24} */
	char name[64];
} SC2336P_MODE_S;

/****************************************************************************
 * external variables and functions                                         *
 ****************************************************************************/

extern ISP_SNS_STATE_S *g_pastSC2336P[VI_MAX_PIPE_NUM];
extern ISP_SNS_COMMBUS_U g_aunSC2336P_BusInfo[];
extern CVI_U16 g_au16SC2336P_GainMode[];
extern CVI_U16 g_au16SC2336P_L2SMode[];
extern const CVI_U8 sc2336p_i2c_addr;
extern const CVI_U32 sc2336p_addr_byte;
extern const CVI_U32 sc2336p_data_byte;
extern void sc2336p_init(VI_PIPE ViPipe);
extern void sc2336p_exit(VI_PIPE ViPipe);
extern void sc2336p_standby(VI_PIPE ViPipe);
extern void sc2336p_restart(VI_PIPE ViPipe);
extern int  sc2336p_write_register(VI_PIPE ViPipe, int addr, int data);
extern int  sc2336p_read_register(VI_PIPE ViPipe, int addr);
extern void sc2336p_mirror_flip(VI_PIPE ViPipe, ISP_SNS_MIRRORFLIP_TYPE_E eSnsMirrorFlip);
extern int  sc2336p_probe(VI_PIPE ViPipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif /* __SC2336P_CMOS_EX_H_ */
